#include "../lib/Fibonacci.h"
#include "gtest/gtest.h"

TEST(Fibonacci, Recursive) {
    const auto sut = new Fibonacci();

    EXPECT_EQ(sut->recursive(0), 0);
    EXPECT_EQ(sut->recursive(1), 1);
    EXPECT_EQ(sut->recursive(2), 1);
    EXPECT_EQ(sut->recursive(3), 2);
    EXPECT_EQ(sut->recursive(10), 55);
    EXPECT_EQ(sut->recursive(15), 610);
    EXPECT_EQ(sut->recursive(45), 1134903170);
}

TEST(Fibonacci, Recursive_Cache) {
    const auto sut = new Fibonacci();
    auto cache = std::unordered_map<int, unsigned int>();

    EXPECT_EQ(sut->recursive_cached(0, cache), 0);
    EXPECT_EQ(sut->recursive_cached(1, cache), 1);
    EXPECT_EQ(sut->recursive_cached(2, cache), 1);
    EXPECT_EQ(sut->recursive_cached(3, cache), 2);
    EXPECT_EQ(sut->recursive_cached(10, cache), 55);
    EXPECT_EQ(sut->recursive_cached(15, cache), 610);
    EXPECT_EQ(sut->recursive_cached(45, cache), 1134903170);
}

TEST(Fibonacci, Iterative) {
    const auto sut = new Fibonacci();

    EXPECT_EQ(sut->iterative(0), 0);
    EXPECT_EQ(sut->iterative(1), 1);
    EXPECT_EQ(sut->iterative(2), 1);
    EXPECT_EQ(sut->iterative(3), 2);
    EXPECT_EQ(sut->iterative(10), 55);
    EXPECT_EQ(sut->iterative(15), 610);
    EXPECT_EQ(sut->iterative(45), 1134903170);
}
