#include <iostream>
#include <string>

#include "Order.h"
#include "Engine.h"

#define EXIT_CODE "exit"

using namespace std;

int main()
{
    // Initialize engine
    std::cout << "START - Matching Engine\n";
    // Matching Engine
    Engine engine;
    // User input order
    string order_str;
    
    cout << "Order: ";
    getline(cin, order_str);

    // Receive orders while 
    while (order_str.compare(EXIT_CODE) != 0) {
        if (Order::IsValid(order_str)) {
            Order order(order_str);
            engine.Receive(order);
        }

        cout << "Order: ";
        getline(cin, order_str);
    }
}

