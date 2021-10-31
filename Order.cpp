#include <iostream>
#include <vector>

#include "Order.h"
#include "utils.h"

using namespace std;

Order::Order(string order) {
    vector<string> arr = split(order);
    this->type = arr[0];
    this->side = arr[1];
    this->price = stoi(arr[2]);
    this->quantity = stoi(arr[3]);
}

Order::~Order() {

}

bool Order::is_valid(string order) {
    // Supported types: "limit", "market"
    // Supported types: "buy", "sell"
    // Supported range: > 0
    // Supported range: > 0

    vector<string> arr = split(order);
    
    if (arr[0].compare("limit") != 0 && arr[0].compare("market") != 0) {
        cout << "Invalid Order Type!" << endl;
        return false;
    }
    else if (arr[1].compare("buy") != 0 && arr[1].compare("sell") != 0) {
        cout << "Invalid Order Side!" << endl;
        return false;
    }
    else if (stoi(arr[2]) < 0) {
        cout << "Invalid Order Price!" << endl;
        return false;
    }
    else if (stoi(arr[3]) < 0) {
        cout << "Invalid Order Quantity!" << endl;
        return false;
    }
    else return true;
}
