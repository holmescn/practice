#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "SFINAE03.h"

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

struct TestClass_Error_Signature {
    int member_func();
};


TEST_CASE("Test typedef.", "[typedef]") {
    REQUIRE(has_typedef_foo<TestClass_Pass>::value == true);
    REQUIRE(has_typedef_foo<TestClass_Empty>::value == false);
}

TEST_CASE("Test member function.", "[memberfunc]") {
    REQUIRE(has_member_func<TestClass_Pass>::value == true);
    REQUIRE(has_member_func<TestClass_Empty>::value == false);
    REQUIRE(has_member_func<TestClass_ErrorType>::value == false);
    REQUIRE(has_member_func<TestClass_Error_Signature>::value == false);
}


TEST_CASE("Test member variable.", "[membervar]") {
    REQUIRE(has_member_var_int<TestClass_Pass>::value == true);
    REQUIRE(has_member_var_int<TestClass_Empty>::value == false);
    REQUIRE(has_member_var_int<TestClass_ErrorType>::value == false);
}

