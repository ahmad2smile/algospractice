//
// Created by a050313 on 13.11.23.

#include "Fibonacci.h"

unsigned int Fibonacci::recursive(const int nth) {
    if (nth <= 1) {
        return nth;
    }

    return recursive(nth - 2) + recursive(nth - 1);
}

unsigned Fibonacci::iterative(const int nth) {
    if (nth <= 1) {
        return nth;
    }

    int previous = 0;
    int current = 1;

    int temp = 0;

    for (int i = 2; i <= nth; i++) {
        temp = current;

        current = current + previous;
        
        previous = temp;
    }

    return current;
}
