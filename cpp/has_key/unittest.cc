#include <limits.h>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <string>
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

TEST(HasKeyTest, VectorInt) {
    vector<int> v1;
    for (int i = 0; i < 10; i++) v1.push_back(i);

    bool ExpectTrue = has_key(v1, 2);
    bool ExpectFalse = has_key(v1, 12);

    EXPECT_TRUE(ExpectTrue);
    EXPECT_FALSE(ExpectFalse);
}

