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
	static bool IsValid(string order);

	// Getter - type
	string getType();
	// Setter - type
	void setType(string type);
	// Getter - side
	string getSide();
	// Setter - side
	void setSide(string side);
	// Getter - price
	int getPrice();
	// Setter - price
	void setPrice(int price);
	// Getter - quantity
	int getQuantity();
	// Setter - quantity
	void setQuantity(int qty);

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