//
// Created by ahmad on 15.11.23.
//
#include "gtest/gtest.h"
#include "../lib/Search.h"

TEST(Search, Binary_Search) {
    constexpr int size = 14;
    const int data[] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};

    for (int i = data[0]; i <= data[size - 1]; i++) {
        EXPECT_EQ(Search::binary_search(data, size, 6), 6);
    }
}
