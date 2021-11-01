#include <iostream>
#include <string>

#include "Order.h"
#include "Engine.h"

#define EXIT_CODE "exit"

using namespace std;

int main()
{
    // Start Engine
    std::cout << "START - Matching Engine" << endl;
    // Initialize Matching Engine
    Engine engine;
    // User input order
    string order_str;
    
    cout << endl << "Order: ";
    getline(cin, order_str);

    // Receive orders until exit code "exit" 
    while (order_str != EXIT_CODE) {
        if (Order::IsValid(order_str)) {
            Order order(order_str);
            engine.Execute(order);
        }
        // Request new order from user
        cout << "Order: ";
        getline(cin, order_str);
    }
    // End Engine
    std::cout << endl << "END - Matching Engine" << endl;
}

