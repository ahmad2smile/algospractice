//
// Created by a050313 on 13.11.23.

#include "Fibonacci.h"

unsigned int Fibonacci::recursive(const int nth) {
    if (nth < 3) {
        return 1;
    }

    return recursive(nth - 2) + recursive(nth - 1);
}

unsigned Fibonacci::iterative(const int nth) {
    if (nth < 3) {
        return 1;
    }

    int previous = 1;
    int current = 1;

    int temp = 0;

    for (int i = 3; i <= nth; i++) {
        temp = current;

        current = current + previous;
        
        previous = temp;
    }

    return current;
}
