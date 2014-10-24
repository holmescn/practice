/**
 * has_key is a utility function that test the given key is
 * in the given container. The goal is simple but the implement
 * that could cross the compiler is not as simple as I thought.
 *
 */

#include<algorithm>
#include<vector>
#include<map>
#include<set>

/**
 * This kind of implement could compile and pass the test
 * under gcc (4.8.3 in cygwin) and VS2013 (vc 12.0)
 *
 * The problem is that I should write each kind of
 * container that I want to support. That is not flexible
 * and perfect.
 */
#if 0
template<typename K, typename V>
bool has_key(const std::map<K, V> &m, const K &key) {
    return m.find(key) != m.end();
}
#endif

/**
 * Other sequence type container could do the same thing.
 */
#if 0
template<typename K>
bool has_key(const std::vector<K> &v, const K &key) {
    return std::find(v.begin(), v.end(), key) != v.end();
}

template<typename K>
bool has_key(const std::set<K> &s, const K &key) {
    return s.find(key) != s.end();
}
#endif


/**
 *  New implementation with SFINAE.
 *
 *  The std::set could not use this because of ambiguous.
 */
template<typename T>
bool has_key(const T &t, const typename T::key_type &key) {
    return t.find(key) != t.end();
}

template<typename T>
bool has_key(const T &t, const typename T::value_type &v) {
    for (auto i = t.begin(); i != t.end(); i++) {
        if (*i == v) return true;
    }
    return false;
}

