#include "SFINAE11.h"
#include "gtest/gtest.h"

using namespace std;

struct TestClass_Pass {
    typedef char foo;
    int member_var_int;
    void member_func();
};

struct TestClass_Empty {};

struct TestClass_ErrorType {
    int member_func;
    float member_var_int;
};

struct TestClass_ErrorSignature {
    int member_func();
};


TEST(SFINAETest, HasTypedef) {
    EXPECT_TRUE(has_typedef_foo<TestClass_Pass>::value);
    EXPECT_FALSE(has_typedef_foo<TestClass_Empty>::value);
}

TEST(SFINAETest, HasMemberFunc) {
    EXPECT_TRUE(has_member_func<TestClass_Pass>::value);
    EXPECT_FALSE(has_member_func<TestClass_Empty>::value);
    EXPECT_FALSE(has_member_func<TestClass_ErrorType>::value);
    EXPECT_FALSE(has_member_func<TestClass_ErrorSignature>::value);
}

TEST(SFINAETest, HasMemberVar) {
    EXPECT_TRUE(has_member_var_int<TestClass_Pass>::value);
    EXPECT_FALSE(has_member_var_int<TestClass_Empty>::value);
    EXPECT_FALSE(has_member_var_int<TestClass_ErrorType>::value);
}

