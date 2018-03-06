# RPC

A simple distributed computing environment consisting of a multiple Clients and a Server.  

The system is implemented in C or C++ and using the rpcgen utility.

Server:  The Server will be multi-threaded and support the following functions:
1.  Path – Returns the current path as obtained from the pwd command.
2.  Sort – Accepts an unsorted list and returns its sorted version.
3.  Echo – Returns whatever a Client sends as an input.
4.  Check – Checks if a file is available in the current directory or not and displays a messageaccordingly.
5.  Multiplier – Accepts two integer matrices and returns their multiplication.

Clients:  There will be multiple clients and they will concurrently invoke various functions on theserver.
