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

	void Execute(Order &order);				// Match and Execute Order
	void MatchLimitOrder(Order &order);		// Match a Limit Order with existing orders
	void MatchMarketOrder(Order &order);	// Match a Market Order with existing orders

private:
	vector<Order> buy_orders;				// List of Buy Orders
	vector<Order> sell_orders;				// List of Sell Orders

	bool CheckIfPossibleLimitTrade(Order buy_order, Order sell_order);	// Check if trade is possible for a limit order
	bool CheckIfPossibleMarketTrade(Order buy_order, Order sell_order);	// Check if trade is possible for a market order
	int calculateQuantity(Order& buy_order, Order& sell_order);			// Calculate trade quantity given two orders
};

#endif