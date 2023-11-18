//
// Created by ahmad on 15.11.23.
//
#include <cstddef>

namespace Search {
    int binary_search(const int array_sorted[], const int size, const int query) {
        int left = 0;
        int right = size - 1;

        while (left <= right) {
            // 10 |-----------45--50--mid(55)---------------| 100
            // right - left => reset to true value if we started from 0, i.e 90
            //                    || then we move the reseted value by original shift
            //                    V
            //                 (left + Reseted Value) / 2 => MID = 55
            const int middle = left + (right - left >> 1);

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
