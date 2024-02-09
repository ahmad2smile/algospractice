//
// Created by a050313 on 09.02.24.
//

#ifndef INTERVALMAP_H
#define INTERVALMAP_H
#include <map>


template<typename K, typename V>
class Intervalmap {
public:
    Intervalmap(V const &val);

    void assign(K const &keyBegin, K const &keyEnd, V const &val);

private:
    V const& operator[](K const &key) const;

    V m_valBegin;
    std::map<K, V> m_map;
};

#endif //INTERVALMAP_H
