#ifndef ENGINE_CLASS
#define ENGINE_CLASS

#include <vector>
#include "Order.h"

using namespace std;

class Engine
{
public:
	Engine();
	~Engine();

private:
	vector<Order> buy_orders;
	vector<Order> sell_orders;

	void Receive(Order order);
	void Match();
	void Execute();
};

#endif