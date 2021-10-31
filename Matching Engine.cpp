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
    Engine* engine = new Engine();
    // User input order
    string order;
    
    cout << "Order: ";
    getline(cin, order);

    // Receive orders while 
    while (order.compare(EXIT_CODE) != 0) {
        if (Order::is_valid(order))
            Order *new_order = new Order(order);



        cout << "Order: ";
        getline(cin, order);
    }
    
}

