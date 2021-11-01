#ifndef ENGINE_CLASS
#define ENGINE_CLASS

#include <iostream>
#include <queue>
#include <vector>
#include "Order.h"

using namespace std;

class Engine
{
public:
	Engine();
	~Engine();

	void Receive(Order &order);
	bool MatchLimitOrder(Order &order);
	bool MatchMarketOrder(Order &order);

private:
	vector<Order> buy_orders;
	vector<Order> sell_orders;

	bool CheckIfPossibleLimitTrade(Order buy_order, Order sell_order);
	bool CheckIfPossibleMarketTrade(Order buy_order, Order sell_order);
	int calculateQuantity(Order& buy_order, Order& sell_order);
};

#endif