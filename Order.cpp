#include <iostream>
#include <vector>
#include <string>

#include "Order.h"
#include "utils.h"

using namespace std;

Order::Order(string order) {
    vector<string> arr = split(order);
    this->type = arr[0];
    this->side = arr[1];
    if (this->type == "limit") {
        this->price = stoi(arr[2]);
        this->quantity = stoi(arr[3]);
    }
    else {
        this->price = 0;
        this->quantity = stoi(arr[2]);
    }
}

Order::~Order() {

}

bool Order::IsValid(string order) {
    // Supported types: "limit", "market"
    // Supported types: "buy", "sell"
    // Supported range: > 0
    // Supported range: > 0

    vector<string> arr = split(order);
    
    if (arr[0] != "limit" && arr[0] != "market") {
        cout << "Invalid Order Type!" << endl;
        return false;
    }
    else if (arr[1] != "buy" && arr[1] != "sell") {
        cout << "Invalid Order Side!" << endl;
        return false;
    }
    else if (arr[0] == "limit") {
        if (stoi(arr[2]) < 0) {
            cout << "Invalid Order Price!" << endl;
            return false;
        }
        else if (stoi(arr[3]) < 0) {
            cout << "Invalid Order Quantity!" << endl;
            return false;
        }
    }
    else if (arr[0] == "market") {
        if (stoi(arr[2]) < 0) {
            cout << "Invalid Order Quantity!" << endl;
            return false;
        }
    }
    
    return true;
}

// Getter - type
string Order::getType() {
    return this->type;
}
// Setter - type
void Order::setType(string type) {
    this->type = type;
}
// Getter - side
string Order::getSide() {
    return this->side;
}
// Setter - side
void Order::setSide(string side) {
    this->side = side;
}
// Getter - price
int Order::getPrice() {
    return this->price;
}
// Setter - price
void Order::setPrice(int price) {
    this->price = price;
}
// Getter - quantity
int Order::getQuantity() {
    return this->quantity;
}
// Setter - quantity
void Order::setQuantity(int qty) {
    this->quantity = qty;
}