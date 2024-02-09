//
// Created by ahmad on 16.01.24.
//

#include "Hashmap.h"

KeyValuePair::KeyValuePair(const char* key, const char* value): key(key), value(value), next(nullptr) {
}

KeyValuePair::~KeyValuePair() {
    delete key;
    delete value;
    delete next;
}

Hashmap::Hashmap() : _size(0), _capacity(8) {
    _array = new KeyValuePair *[_capacity]{nullptr};
}

Hashmap::~Hashmap() {
    for (int i = 0; i < _capacity; i++) {
        delete _array[i];
    }

    delete _array;
}

void Hashmap::insert(const char* key, const char* value) {
    const auto index = hash(key);

    for (auto current = _array[index]; current; current = current->next) {
        if (*current->key == *key) {
            _array[index] = new KeyValuePair(key, value);

            return;
        }
    }

    const auto newPair = new KeyValuePair(key, value);

    // NOTE: Move current to next so to make space for new current
    newPair->next = _array[index];
    _array[index] = newPair;

    _size++;
}

const char* Hashmap::get(const char* key) const {
    const auto index = hash(key);

    for (auto current = _array[index]; current; current = current->next) {
        if (*current->key == *key) {
            return current->value;
        }
    }

    return nullptr;
}

int Hashmap::length() const {
    return _size;
}

unsigned Hashmap::hash(const char* key) const {
    unsigned code;

    for (code = 0; *key != '\0'; key++) {
        code = *key + 31 * code;
    }

    return code % _capacity;
}
