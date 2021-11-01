#include "Engine.h"

using namespace std;

Engine::Engine() {

}

Engine::~Engine() {

}

void Engine::Receive(Order &order) {
	// Match order to generate possible trade 
	bool result;
	if (order.getType() == "limit")
		result = this->MatchLimitOrder(order);
	else result = this->MatchMarketOrder(order);
	// If cannot match order, add to queue
	if (!result) {
		if (order.getSide() == "buy")
			this->buy_orders.push_back(order);
		else this->sell_orders.push_back(order);
	}
}

bool Engine::MatchLimitOrder(Order &order) {
	bool result = false;
	int quantity_traded = 0;
	int price_traded = order.getPrice();

	if (order.getSide() == "buy") {
		for (auto &sell_order : this->sell_orders) {
			if (this->CheckIfPossibleLimitTrade(order, sell_order)) {
				quantity_traded += calculateQuantity(order, sell_order);
				result = true;
			}
		}
	}
	else {
		for (auto &buy_order: this->buy_orders) {
			if (this->CheckIfPossibleLimitTrade(buy_order, order)) {
				quantity_traded += calculateQuantity(buy_order, order);
				result = true;
			}
		}
	}

	if(result)
		cout << "Trade, price: " << price_traded << ", qty: " << quantity_traded << endl;

	return result;
}

bool Engine::MatchMarketOrder(Order &order) {
	bool result = false;
	int quantity_traded = 0;
	int price_traded;

	if (order.getSide() == "buy") {
		for (auto& sell_order : this->sell_orders) {
			if (this->CheckIfPossibleMarketTrade(order, sell_order)) {
				quantity_traded += calculateQuantity(order, sell_order);
				price_traded = sell_order.getPrice();
				result = true;
			}
		}
	}
	else {
		for (auto& buy_order : this->buy_orders) {
			if (this->CheckIfPossibleMarketTrade(buy_order, order)) {
				quantity_traded += calculateQuantity(buy_order, order);
				price_traded = buy_order.getPrice();
				result = true;
			}
		}
	}

	if (result)
		cout << "Trade, price: " << price_traded << ", qty: " << quantity_traded << endl;

	return result;
}

bool Engine::CheckIfPossibleLimitTrade(Order buy_order, Order sell_order) {
	if (sell_order.getPrice() > buy_order.getPrice())
		return false;
	if (sell_order.getQuantity() <= 0 || buy_order.getQuantity() <= 0)
		return false;

	return true;
}

bool Engine::CheckIfPossibleMarketTrade(Order buy_order, Order sell_order) {
	if (sell_order.getQuantity() <= 0 || buy_order.getQuantity() <= 0)
		return false;

	return true;
}

int Engine::calculateQuantity(Order& buy_order, Order& sell_order) {
	int quantity;

	if (buy_order.getQuantity() >= sell_order.getQuantity()) {
		quantity = sell_order.getQuantity();
		buy_order.setQuantity(buy_order.getQuantity() - sell_order.getQuantity());
		sell_order.setQuantity(0);
	}
	if (buy_order.getQuantity() < sell_order.getQuantity()) {
		quantity = buy_order.getQuantity();
		sell_order.setQuantity(sell_order.getQuantity() - buy_order.getQuantity());
		buy_order.setQuantity(0);
	}
		
	return quantity;
}