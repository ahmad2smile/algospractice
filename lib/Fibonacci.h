//
// Created by ahmad on 13.11.23.
//

#ifndef FIBONACCI_H
#define FIBONACCI_H
#include <unordered_map>


class Fibonacci {
public:
    static unsigned int recursive(int nth);

    static unsigned int recursive_cached(int nth, std::unordered_map<int, unsigned int>&cache);

    static unsigned int iterative(int nth);
};


#endif //FIBONACCI_H
