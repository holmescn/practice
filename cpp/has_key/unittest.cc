#include <limits.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "has_key.h"
#include "gtest/gtest.h"

using namespace std;

TEST(HasKeyTest, MapIntInt) {
    map<int, int> m1;
    for (int i = 0, j = 0; i < 10; i++, j++)
        m1[i] = j;

    bool ExpectTrue = has_key(m1, 2);
    bool ExpectFalse = has_key(m1, 12);

    EXPECT_TRUE(ExpectTrue);
    EXPECT_FALSE(ExpectFalse);
}

TEST(HasKeyTest, MapStringInt) {
    map<string, int> m1;
    string key = "a";
    for (int i = 0, j = 0; i < 10; i++, j++) {
        key[0] = 'a' + i;
        m1[key] = j;
    }

    bool ExpectTrue = has_key(m1, string("a"));
    bool ExpectFalse = has_key(m1, string("0"));

    EXPECT_TRUE(ExpectTrue);
    EXPECT_FALSE(ExpectFalse);
}



TEST(HasKeyTest, VectorInt) {
    vector<int> v1;
    for (int i = 0; i < 10; i++) v1.push_back(i);

    bool ExpectTrue = has_key(v1, 2);
    bool ExpectFalse = has_key(v1, 12);

    EXPECT_TRUE(ExpectTrue);
    EXPECT_FALSE(ExpectFalse);
}

TEST(HasKeyTest, SetInt) {
    set<int> s1;
    for (int i = 0; i < 10; i++) s1.insert(i);

    bool ExpectTrue = has_key(s1, 2);
    bool ExpectFalse = has_key(s1, 12);

    EXPECT_TRUE(ExpectTrue);
    EXPECT_FALSE(ExpectFalse);
}

