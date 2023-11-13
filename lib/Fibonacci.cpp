//
// Created by a050313 on 13.11.23.
//

#include "Fibonacci.h"

unsigned int Fibonacci::recursive(const int nth) {
    if (nth < 3) {
        return 1;
    }

    return recursive(nth - 2) + recursive(nth - 1);
}
