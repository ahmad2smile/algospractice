#include "../lib/Fibonacci.h"
#include "gtest/gtest.h"

TEST(Fibonacci, BaseCaseTest) {
    const auto sut = new Fibonacci();

    EXPECT_EQ(sut->recursive(0), 1);
    EXPECT_EQ(sut->recursive(1), 1);
    EXPECT_EQ(sut->recursive(2), 1);
}

TEST(Fibonacci, NormalPathTest) {
    const auto sut = new Fibonacci();

    EXPECT_EQ(sut->recursive(3), 2);
    EXPECT_EQ(sut->recursive(10), 55);
    EXPECT_EQ(sut->recursive(15), 610);
}
