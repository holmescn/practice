#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include <string>
#include "itoa.h"

TEST_CASE("itoa using division and modulus operator.", "[itoa_1]") {

    SECTION("Given integer 0") {
        char buffer[32] = {0};
        std::string result = itoa_1(0, buffer);
        REQUIRE ( result == "0" );
    }

    SECTION("Given integer 1 which is one digit") {
        char buffer[32] = {0};
        std::string result = itoa_1(1, buffer);
        REQUIRE ( result == "1" );
    }

    SECTION("Given integer 10 which is two digits") {
        char buffer[32] = {0};
        std::string result = itoa_1(10, buffer);
        REQUIRE ( result == "10" );
    }

    SECTION("Given integer 321 which is three digits") {
        char buffer[32] = {0};
        std::string result = itoa_1(321, buffer);
        REQUIRE ( result == "321" );
    }
}

TEST_CASE("itoa without division and modulus operator.", "[itoa_2]") {

    SECTION("Given integer 0") {
        char buffer[32] = {0};
        std::string result = itoa_2(0, buffer);
        REQUIRE ( result == "0" );
    }

    SECTION("Given integer 1 which is one digit") {
        char buffer[32] = {0};
        std::string result = itoa_2(1, buffer);
        REQUIRE ( result == "1" );
    }

    SECTION("Given integer 10 which is two digits") {
        char buffer[32] = {0};
        std::string result = itoa_2(10, buffer);
        REQUIRE ( result == "10" );
    }

    SECTION("Given integer 321 which is three digits") {
        char buffer[32] = {0};
        std::string result = itoa_2(321, buffer);
        REQUIRE ( result == "321" );
    }
}
