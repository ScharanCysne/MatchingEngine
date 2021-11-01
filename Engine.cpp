#include "Engine.h"

using namespace std;

Engine::Engine() {

}

Engine::~Engine() {

}

/* Match and Execute Order */ 
void Engine::Execute(Order &order) {
	// Match order to generate possible trade 
	if (order.getType() == "limit")
		this->MatchLimitOrder(order);
	else this->MatchMarketOrder(order);
	// Add orders to queue at end
	if (order.getSide() == "buy")
		this->buy_orders.push_back(order);
	else this->sell_orders.push_back(order);
}

/* Match a Limit Order with existing orders */
void Engine::MatchLimitOrder(Order &order) {
	bool result = false;					// Match Result
	int quantity_traded = 0;				// Quantity traded in total
	int price_traded = order.getPrice();	// Price of limit order

	if (order.getSide() == "buy") {
		// For a Buy Order, iterate over sell orders and try to match orders
		for (auto &sell_order : this->sell_orders) {
			if (this->CheckIfPossibleLimitTrade(order, sell_order)) {
				quantity_traded += calculateQuantity(order, sell_order);
				result = true;
			}
		}
	}
	else {
		// For a Sell Order, iterate over buy orders and try to match orders
		for (auto &buy_order: this->buy_orders) {
			if (this->CheckIfPossibleLimitTrade(buy_order, order)) {
				quantity_traded += calculateQuantity(buy_order, order);
				result = true;
			}
		}
	}

	// If Match occured, print Trade
	if(result)
		cout << "Trade, price: " << price_traded << ", qty: " << quantity_traded << endl;
}

/* Match a Market Order with existing orders */
void Engine::MatchMarketOrder(Order &order) {
	bool result = false;					// Match Result
	int quantity_traded = 0;				// Quantity traded in total
	vector<int> price_traded;				// vector of limit prices that generate trades

	if (order.getSide() == "buy") {
		// For a Buy Order, iterate over sell orders and try to match orders
		for (auto& sell_order : this->sell_orders) {
			if (this->CheckIfPossibleMarketTrade(order, sell_order)) {
				quantity_traded += calculateQuantity(order, sell_order);
				price_traded.push_back(sell_order.getPrice());
				result = true;
			}
		}
	}
	else {
		for (auto& buy_order : this->buy_orders) {
			// For a Sell Order, iterate over buy orders and try to match orders
			if (this->CheckIfPossibleMarketTrade(buy_order, order)) {
				quantity_traded += calculateQuantity(buy_order, order);
				price_traded.push_back(buy_order.getPrice());
				result = true;
			}
		}
	}
	
	// If Match occured, print Trade
	if (result) {
		// For all possible trade prices, find maximum (sell) or minimum (buy)
		int trade_price = price_traded[0];
		if(order.getSide() == "buy")
			for (auto& price : price_traded)
				if (price > trade_price)
					trade_price = price;
		if (order.getSide() == "sell")
			for (auto& price : price_traded)
				if (price < trade_price)
					trade_price = price;

		cout << "Trade, price: " << trade_price << ", qty: " << quantity_traded << endl;
	}
}

/* Check if trade is possible for a limit order */
bool Engine::CheckIfPossibleLimitTrade(Order buy_order, Order sell_order) {
	if (sell_order.getPrice() > buy_order.getPrice() && buy_order.getPrice() != 0)
		return false;
	if (sell_order.getQuantity() <= 0 || buy_order.getQuantity() <= 0)
		return false;

	return true;
}

/* Check if trade is possible for a market order */
bool Engine::CheckIfPossibleMarketTrade(Order buy_order, Order sell_order) {
	// Can't match two market orders, at least one of them must have price > 0
	if (sell_order.getPrice() == 0 && buy_order.getPrice() == 0)
		return false;
	// Can't match orders with one of them have zero or negative quantities available
	if (sell_order.getQuantity() <= 0 || buy_order.getQuantity() <= 0)
		return false;

	return true;
}

/* Calculate trade quantity given two orders */
int Engine::calculateQuantity(Order& buy_order, Order& sell_order) {
	// Check which one have more demand in quantity, and calculate available quantity for trade
	int quantity = 0;
	
	// If Buy Order has a higher demand
	if (buy_order.getQuantity() >= sell_order.getQuantity()) {
		quantity = sell_order.getQuantity();
		buy_order.setQuantity(buy_order.getQuantity() - sell_order.getQuantity());
		sell_order.setQuantity(0);
	}
	
	// If Sell Order has a higher demand
	if (buy_order.getQuantity() < sell_order.getQuantity()) {
		quantity = buy_order.getQuantity();
		sell_order.setQuantity(sell_order.getQuantity() - buy_order.getQuantity());
		buy_order.setQuantity(0);
	}
		
	return quantity;
}