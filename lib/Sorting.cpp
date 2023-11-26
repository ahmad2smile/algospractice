//
// Created by ahmad on 16.11.23.
//

#include "Sorting.h"

#include <array>

/**
 * \brief
 * Time:
 *  Total: (n + n + n) * (log n) + (Other call but removed during simplification)
 *         (n) * (log n)
 *         O(n log n)
 * Space:
 *  Total: Recursive calls n + (n/2 + n/2)
 *         Recursive calls n + (n)
 *         O(n)
 */
void Sorting::merge_sort(int unsorted[], const int len) {
    if (len < 2) {
        return;
    }

    const int half = len / 2;
    int left[half];
    int right[len - half];

    // ==========================================================================> O(n)
    // Copy first half to left n second half to right
    for (int i = 0; i < len; i++) {
        if (i < half) {
            left[i] = unsorted[i];
        }
        else {
            right[i - half] = unsorted[i];
        }
    }

    const int leftLength = half;
    const int rightLength = len - half;

    // ==========================================================================> Recursive call: n/2 * n/4 * n/8 * n/16... 1 => O(log n)
    // ==========================================================================> 16, 8, 4, 2...1 => log n
    merge_sort(left, leftLength);
    // ==========================================================================> Recursive call: n/2 * n/4 * n/8 * n/16... 1 => O(log n)
    // ==========================================================================> 16, 8, 4, 2...1 => log n
    merge_sort(right, rightLength);

    int i = 0;
    int leftIndex = 0;
    int rightIndex = 0;

    // ==========================================================================> O(n)
    while (leftIndex < leftLength && rightIndex < rightLength) {
        if (left[leftIndex] <= right[rightIndex]) {
            unsorted[i] = left[leftIndex];
            leftIndex += 1;
        }
        else {
            unsorted[i] = right[rightIndex];
            rightIndex += 1;
        }

        i += 1;
    }

    // Insert whatever is left in original unsorted array
    while (leftIndex < leftLength) {
        unsorted[i] = left[leftIndex];
        leftIndex += 1;
        i += 1;
    }

    // ==========================================================================> O(n)
    while (rightIndex < rightLength) {
        unsorted[i] = right[rightIndex];
        rightIndex += 1;
        i += 1;
    }
}

/*
 */
void Sorting::quick_sort(int* unsorted, const int start_index, const int end_index) {
    if (end_index <= start_index) {
        return;
    }

    int* pivot = &unsorted[end_index];
    auto follow_index = start_index - 1;

    for (int i = start_index; i < end_index; i++) {
        if (int* current_ele = &unsorted[i]; *current_ele <= *pivot) {
            follow_index++;

            std::swap(unsorted[follow_index], *current_ele);
        }
    }

    follow_index++;
    std::swap(unsorted[follow_index], *pivot);

    // ===============================================================> n/2  2 * 2... n
    // ==========================================================================> O(2^n)
    quick_sort(unsorted, start_index, follow_index - 1);
    quick_sort(unsorted, follow_index + 1, end_index);
}
