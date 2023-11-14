//
// Created by ahmad on 13.11.23.

#include "Fibonacci.h"

#include <unordered_map>

/**
 * \brief
 * Time:
 *  Total calls (iterations) on each call => 2 + 2 + 2 ... n => 2^n => O(2^n)
 * Space:
 *  Max calls in the stack => n-1 or n calls at a time => O(n)
 */
unsigned int Fibonacci::recursive(const int nth) {
    if (nth <= 1) {
        return nth;
    }

    return recursive(nth - 2) + recursive(nth - 1);
}

/**
 * \brief
 * Time:
 *  Initial 2 subsequent calls for each call get improved by cache
 *  => 6 => 6(4, 5) => 4(2, 3) + 5(3, 4) => 2(0, 1) + 3(1, 2) => n calls => O(n)
 * Space:
 *  Total call at a time in stack => n => O(n)
 */
unsigned Fibonacci::recursive_cached(const int nth, std::unordered_map<int, unsigned int>&cache) {
    if (nth <= 1) {
        return nth;
    }

    if (cache.contains(nth)) {
        return cache[nth];
    }

    const auto result = recursive_cached(nth - 2, cache) + recursive_cached(nth - 1, cache);

    cache[nth] = result;

    return result;
}


/**
 * \brief
 * Time:
 *  Single loop n-2 iterations => O(n-2) => O(n)
 * Space:
 *  No new variables/allocations/stack calls based on input => O(1)
 */
unsigned Fibonacci::iterative(const int nth) {
    if (nth <= 1) {
        return nth;
    }

    int previous = 0;
    int current = 1;

    for (int i = 2; i <= nth; i++) {
        const int temp = current;

        current = current + previous;

        previous = temp;
    }

    return current;
}
