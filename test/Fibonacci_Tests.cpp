#include "../lib/Fibonacci.h"
#include "gtest/gtest.h"

TEST(Fibonacci, Recursive) {
    const auto sut = new Fibonacci();

    EXPECT_EQ(sut->recursive(0), 1);
    EXPECT_EQ(sut->recursive(1), 1);
    EXPECT_EQ(sut->recursive(2), 1);
    EXPECT_EQ(sut->recursive(3), 2);
    EXPECT_EQ(sut->recursive(10), 55);
    EXPECT_EQ(sut->recursive(15), 610);
    EXPECT_EQ(sut->recursive(45), 1134903170);
}

TEST(Fibonacci, Iterative) {
    const auto sut = new Fibonacci();

    EXPECT_EQ(sut->iterative(0), 1);
    EXPECT_EQ(sut->iterative(1), 1);
    EXPECT_EQ(sut->iterative(2), 1);
    EXPECT_EQ(sut->iterative(3), 2);
    EXPECT_EQ(sut->iterative(10), 55);
    EXPECT_EQ(sut->iterative(15), 610);
    EXPECT_EQ(sut->iterative(45), 1134903170);
}
