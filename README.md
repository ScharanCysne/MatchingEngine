# Matching Engine

## About the Project

A Matching Engine is a system designed to cross orders on an exchange quickly and fairly. This project replicates its behavior based on orders given by user input.

The following assumptions were followed in designing the project:

1. The engine will trade only 1 asset;
2. There are two types of possible orders: 'limit' and 'market';
3. It is not necessary to store trades and orders;
4. No need to think about cloud hardware and tools scalability and elasticity;

For market orders that would allow several limit orders to be executed, it was decided that for buy orders the lowest order price would be 
executed for all, and the highest for all sell orders. For example:

-> limit sell 20 100

-> limit sell 10 100

-> market buy 200

Trade, price: 20, qty: 200

OR

-> limit buy 20 100

-> limit buy 10 100

-> market sell 200

Trade, price: 10, qty: 200

As for runtime complexity, the matching algorithm iterates over a queue of orders searching for the best match, so it runs in O(n) complexity, 
n being the number of orders currently in queue. Because it iterates over a ordered vector (queue) it, always respects the position of arrival of orders.


## Configuration and Installation Instructions

The project was developed in C++, with no extra dependencies besides standard libraries. Since it was made in Microsoft Visual Studio Community 2019, 
it is recommended that compilation and debug are made through a Visual Studio version with C++ dependencies installed. 

To run the project, clone or download repository in a folder of your own choosing and execute file ".\Debug\Matching Engine.exe". To terminate the execution, type "exit"
as the order input.

