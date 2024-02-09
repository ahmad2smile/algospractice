//
// Created by ahmad on 16.01.24.
//

#include "../lib/Hashmap.h"
#include "gtest/gtest.h"

TEST(Hashmap, Empty) {
    const auto sut = new Hashmap();

    EXPECT_EQ(sut->get("0"), nullptr);
    EXPECT_EQ(sut->get("abc"), nullptr);
    EXPECT_EQ(sut->get("01208skjnsd"), nullptr);
    EXPECT_EQ(sut->get(static_cast<char *>(malloc(100))), nullptr);
    EXPECT_EQ(sut->get(static_cast<char *>(malloc(1000))), nullptr);
    EXPECT_EQ(sut->get(static_cast<char *>(malloc(10000000))), nullptr);
}

TEST(Hashmap, GetValueBack) {
    const auto sut = new Hashmap();

    sut->insert("0", "0");
    sut->insert("abc", "abc");
    sut->insert("01208skjnsd", "01208skjnsd");

    EXPECT_STREQ(sut->get("0"), "0");
    EXPECT_STREQ(sut->get("abc"), "abc");
    EXPECT_STREQ(sut->get("01208skjnsd"), "01208skjnsd");
    EXPECT_STREQ(sut->get("01208skjnsd"), "01208skjnsd");
    EXPECT_STREQ(sut->get("abc"), "abc");
    EXPECT_STREQ(sut->get("0"), "0");
}

TEST(Hashmap, CorrectLength) {
    const auto sut = new Hashmap();

    sut->insert("abc", "abc");
    sut->insert("01208skjnsd", "01208skjnsd");

    EXPECT_EQ(sut->length(), 2);
}
