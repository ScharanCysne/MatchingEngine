#ifndef ORDER_CLASS
#define ORDER_CLASS

#include <string>

using namespace std;

class Order
{
public:
	Order(string order);
	~Order();

	// Check if input order is valid
	static bool is_valid(string order);

private:
	// Supported types: "limit", "market"
	string type;
	// Supported types: "buy", "sell"
	string side;
	// Supported range: > 0
	int price;
	// Supported range: > 0
	int quantity;
};

#endif