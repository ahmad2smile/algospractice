//
// Created by ahmad on 09.02.24.
//

#include "gtest/gtest.h"

#define private public

#include "../lib/Intervalmap.h"

// NOTE: Is needed due to template
#include "../lib/Intervalmap.cpp"

class Key {
public:
    explicit Key(int start): x(start) {
    }

    explicit Key(const Key &key): x(key.x) {
    }

    int x;

    auto& operator=(const Key &other) {
        if (this != &other) {
            x = other.x;
        }

        return *this;
    }

    auto operator<(const Key &k) const {
        return x < k.x;
    }
};

class Value {
public:
    explicit Value(char start): x(start) {
    }

    char x;

    auto& operator=(const Value &other) {
        if (this != &other) {
            x = other.x;
        }

        return *this;
    }

    auto operator==(const Value &v) const {
        return x == v.x;
    }
};

TEST(Intervalmap, Multiple_Same_Enteries) {
    Intervalmap<int, std::string> sut{"A"};

    sut.assign(1, 5, "A");
    sut.assign(1, 5, "A");
    sut.assign(1, 5, "A");
    sut.assign(1, 5, "A");
    sut.assign(1, 5, "A");
    sut.assign(5, 15, "B");

    EXPECT_EQ(sut[3], "A");
    EXPECT_EQ(sut[-3], "A");
    EXPECT_EQ(sut[255], "B");
    EXPECT_EQ(sut[-1000], "A");
}

TEST(Intervalmap, Sparse_Ranges) {
    Intervalmap<int, char> sut{'A'};

    sut.assign(1, 2, 'B');
    sut.assign(3, 15, 'A');

    EXPECT_EQ(sut[-2], 'A');
    EXPECT_EQ(sut[-1], 'A');
    EXPECT_EQ(sut[0], 'A');
    EXPECT_EQ(sut[1], 'B');
    EXPECT_EQ(sut[2], 'B');
    EXPECT_EQ(sut[3], 'A');
    EXPECT_EQ(sut[4], 'A');
    EXPECT_EQ(sut[5], 'A');
}

TEST(Intervalmap, Overlaping_Ranges) {
    Intervalmap<int, char> sut{'A'};


    sut.assign(1, 5, 'A');
    sut.assign(10, 15, 'B');
    sut.assign(20, 25, 'E');
    sut.assign(30, 35, 'F');
    sut.assign(20, 25, 'B');
    sut.assign(23, 35, 'A');
    sut.assign(40, 45, 'A');
    sut.assign(41, 500, 'C');
    sut.assign(100, 500, 'D');

    char current = 'A';
    for (int i = -1000; i < 1000; ++i) {
        if (i >= 10) current = 'B';
        if (i >= 23) current = 'A';
        if (i >= 41) current = 'C';
        if (i >= 100) current = 'D';

        EXPECT_EQ(sut[i], current);
    }
}

TEST(Intervalmap, Increase_Ranges) {
    Intervalmap<int, char> sut{'A'};


    sut.assign(1, 5, 'A');
    // sut.assign(100, 199, 'F');
    sut.assign(200, 500, 'B');
    sut.assign(10, 200, 'B');
    sut.assign(500, 1000, 'C');

    char current = 'A';
    for (int i = -1; i < 1000; ++i) {
        if (i >= 10) current = 'B';
        if (i >= 500) current = 'C';

        EXPECT_EQ(sut[i], current) << i;
    }
}


TEST(Intervalmap, Canonical) {
    Intervalmap<int, char> sut{'A'};

    sut.assign(1, 5, 'A');
    sut.assign(10, 15, 'B');
    sut.assign(20, 25, 'B');
    sut.assign(23, 35, 'A');
    sut.assign(40, 45, 'A');
    sut.assign(41, 500, 'C');
    sut.assign(100, 500, 'D');

    EXPECT_NE(sut.m_map.at(10), sut.m_valBegin);

    char prv_val = NULL;

    for (auto [key, val]: sut.m_map) {
        if (prv_val != NULL) {
            EXPECT_NE(prv_val, val);
        }

        prv_val = val;
    }
}

TEST(Intervalmap, KV_Multiple_Same_Enteries) {
    Intervalmap<Key, Value> sut{Value{'A'}};

    sut.assign(Key{1}, Key{1}, Value{'A'});
    sut.assign(Key{1}, Key{1}, Value{'A'});
    sut.assign(Key{1}, Key{1}, Value{'A'});
    sut.assign(Key{1}, Key{1}, Value{'A'});
    sut.assign(Key{1}, Key{1}, Value{'A'});

    EXPECT_EQ(sut[Key{ 3 }].x, 'A');
    EXPECT_EQ(sut[Key{ -3 }].x, 'A');
    EXPECT_EQ(sut[Key{ 1000 }].x, 'A');
    EXPECT_EQ(sut[Key{ -1000 }].x, 'A');
}

TEST(Intervalmap, KV_Sparse_Ranges) {
    Intervalmap<Key, Value> sut{Value{'A'}};

    sut.assign(Key{1}, Key{5}, Value{'B'});
    sut.assign(Key{10}, Key{15}, Value{'C'});
    sut.assign(Key{20}, Key{25}, Value{'D'});
    sut.assign(Key{30}, Key{35}, Value{'E'});
    sut.assign(Key{40}, Key{45}, Value{'F'});

    EXPECT_EQ(sut[Key{-1000}].x, 'A');
    EXPECT_EQ(sut[Key{-3}].x, 'A');
    EXPECT_EQ(sut[Key{3}].x, 'B');
    EXPECT_EQ(sut[Key{10}].x, 'C');
    EXPECT_EQ(sut[Key{24}].x, 'D');
    EXPECT_EQ(sut[Key{39}].x, 'E');
    EXPECT_EQ(sut[Key{1000}].x, 'F');
}

TEST(Intervalmap, KV_Overlaping_Ranges) {
    Intervalmap<Key, Value> sut{Value{'A'}};

    sut.assign(Key{1}, Key{5}, Value{'A'});
    sut.assign(Key{10}, Key{15}, Value{'B'});
    sut.assign(Key{20}, Key{25}, Value{'E'});
    sut.assign(Key{30}, Key{35}, Value{'F'});
    sut.assign(Key{20}, Key{25}, Value{'B'});
    sut.assign(Key{23}, Key{35}, Value{'A'});
    sut.assign(Key{40}, Key{45}, Value{'A'});
    sut.assign(Key{41}, Key{500}, Value{'C'});
    sut.assign(Key{100}, Key{500}, Value{'D'});

    char current = 'A';
    for (int i = -1000; i < 1000; ++i) {
        if (i >= 10) current = 'B';
        if (i >= 23) current = 'A';
        if (i >= 41) current = 'C';
        if (i >= 100) current = 'D';

        EXPECT_EQ(sut[Key{i}].x, current);
    }
}

TEST(Intervalmap, KV_Increase_Ranges) {
    Intervalmap<Key, Value> sut{Value{'A'}};


    sut.assign(Key{1}, Key{5}, Value{'A'});
    sut.assign(Key{100}, Key{199}, Value{'F'});
    sut.assign(Key{200}, Key{500}, Value{'B'});
    sut.assign(Key{10}, Key{200}, Value{'B'});
    sut.assign(Key{500}, Key{1000}, Value{'C'});

    char current = 'A';
    for (int i = -1; i < 1000; ++i) {
        if (i >= 10) current = 'B';
        if (i >= 500) current = 'C';

        EXPECT_EQ(sut[Key{i}].x, current) << i;
    }
}


TEST(Intervalmap, KV_Canonical) {
    Intervalmap<Key, Value> sut{Value{'A'}};

    sut.assign(Key{1}, Key{5}, Value{'A'});
    sut.assign(Key{10}, Key{15}, Value{'B'});
    sut.assign(Key{20}, Key{25}, Value{'B'});
    sut.assign(Key{23}, Key{35}, Value{'A'});
    sut.assign(Key{40}, Key{45}, Value{'A'});
    sut.assign(Key{41}, Key{500}, Value{'C'});
    sut.assign(Key{100}, Key{500}, Value{'D'});

    EXPECT_NE(sut.m_map.at(Key{10}), sut.m_valBegin);

    char prv_val = NULL;

    for (auto [key, val]: sut.m_map) {
        if (prv_val != NULL) {
            EXPECT_NE(prv_val, val.x);
        }

        prv_val = val.x;
    }
}
