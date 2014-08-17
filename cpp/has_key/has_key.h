/**
 * has_key is a utility function that test the given key is
 * in the given container. The goal is simple but the implement
 * that could cross the compiler is not as simple as I thought.
 *
 */

#include<map>
#include<vector>
#include<algorithm>

/**
 * This kind of implement could compile and pass the test
 * under gcc (4.8.3 in cygwin)
 *
 * The other problem is that I should write each kind of
 * container that I want to support. That is not flexible
 * and perfect.
 */
template<typename K, typename V>
bool has_key(const std::map<K, V> &m, const K &key) {
    return m.find(key) != m.end();
}

/**
 * Other sequence type container could do the same thing.
 */
template<typename K>
bool has_key(const std::vector<K> &v, const K &key) {
    return std::find(v.begin(), v.end(), key) != v.end();
}

