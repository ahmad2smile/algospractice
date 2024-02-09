//
// Created by a050313 on 09.02.24.
//

#include "Intervalmap.h"

template<typename K, typename V>
Intervalmap<K, V>::Intervalmap(V const &val)
    : m_valBegin(val) {
}

template<typename K, typename V>
void Intervalmap<K, V>::assign(K const &keyBegin, K const &keyEnd, V const &val) {
    if (!(keyBegin < keyEnd)) {
        return;
    }

    auto it_begin = m_map.lower_bound(keyBegin);
    auto it_end = m_map.lower_bound(keyEnd);

    auto it_back_check = it_begin;

    auto is_same_as_begin_val = (it_begin == m_map.begin() && m_valBegin == val);
    auto is_same_as_prev_val = (it_back_check != m_map.begin() && (--it_back_check)->second == val);
    // Same key and value
    auto contains_key = m_map.find(keyBegin) != m_map.end();
    auto is_same_as_existing_val = contains_key && it_begin->second == val;

    if (is_same_as_begin_val || is_same_as_prev_val || is_same_as_existing_val) {
        // Nothing to insert so only clear range and done.
        m_map.erase(it_begin, it_end);

        return;
    }

    // If next element has same value, repr by it_end as it's exclusive in current range,
    // Make it_end inclusive to include it_end range in current range
    if (it_end != m_map.end() && it_end->second == val) {
        ++it_end;
    }

    // valid range
    m_map.erase(it_begin, it_end);

    // auto pair = std::make_pair(keyBegin, val);
    m_map.emplace(keyBegin, val);

}

template<typename K, typename V>
V const& Intervalmap<K, V>::operator[](K const &key) const {
    auto it = m_map.upper_bound(key);
    if (it == m_map.begin()) {
        return m_valBegin;
    }
    else {
        return (--it)->second;
    }
}
