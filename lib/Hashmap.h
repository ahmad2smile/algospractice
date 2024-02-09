//
// Created by ahmad on 16.01.24.
//

#ifndef HASHMAP_H
#define HASHMAP_H

struct KeyValuePair {
    KeyValuePair(const char* key, const char* value);

    ~KeyValuePair();

    const char* key;
    const char* value;
    KeyValuePair* next;
};

class Hashmap {
public:
    Hashmap();

    ~Hashmap();

    void insert(const char* key, const char* value);

    const char* get(const char* key) const;

    int length() const;

private:
    unsigned hash(const char* key) const;

    int _size;
    int _capacity;
    KeyValuePair** _array;
};


#endif //HASHMAP_H
