//
// Created by ahmad on 15.11.23.
//
#include <cstddef>

namespace Search {
    int binary_search(const int array_sorted[], const int size, const int query) {
        int left = 0;
        int right = size - 1;

        while (left <= right) {
            // 10 |--------------mid---------------| 100
            //                          Reset start, end to 0-MAX
            //                 (MAX - Reset) / 2 => MID
            const int middle = right - (right - left) / 2;

            const int current = array_sorted[middle];

            if (current == query) {
                return current;
            }

            if (current > query) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }

        return NULL;
    }
}
