//
// Created by ahmad on 18.11.23.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../lib/Sorting.h"

TEST(Sorting, Merge_Sort) {
    for (int i = 1; i <= 1000; i++) {
        int unsorted[i];

        for (int j = 0; j < i; j++) {
            unsorted[j] = 1 + rand() % i;
        }

        Sorting::merge_sort(unsorted, i);

        for (int j = 1; j < i; j++) {
            const auto prev = unsorted[j - 1];
            const auto curr = unsorted[j];

            ASSERT_TRUE(prev <= curr) << "Expected [" << j - 1 << "] <= [" << j << "] " << prev << " <= " << curr;
        }
    }
}

TEST(Sorting, Quick_Sort) {
    for (int i = 2; i <= 1000; i++) {
        int unsorted[i];

        for (int j = 0; j < i; j++) {
            unsorted[j] = 1 + rand() % i;
        }

        Sorting::quick_sort(unsorted, 0, i - 1);

        for (int j = 1; j < i; j++) {
            const auto prev = unsorted[j - 1];
            const auto curr = unsorted[j];

            ASSERT_TRUE(prev <= curr) << "Expected [" << j - 1 << "] <= [" << j << "] " << prev << " <= " << curr;
        }
    }
}