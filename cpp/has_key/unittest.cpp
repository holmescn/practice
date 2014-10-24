#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <string>
#include <map>
#include <vector>
#include <set>
#include "has_key.h"

TEST_CASE("Test if there is a key in the given map.", "[map]") {

    SECTION("map<int, int>") {
        std::map<int, int> m1;
        m1[1] = 1; m1[2] = 1; m1[3] = 1; m1[4] = 1;
        REQUIRE ( has_key(m1, 1) == true );
        REQUIRE ( has_key(m1, 2) == true );
        REQUIRE ( has_key(m1, 5) == false );
        REQUIRE ( has_key(m1, 9) == false );
    }

    SECTION("map<string, int>") {
        std::map<std::string, int> m2;
        m2["1"] = 1; m2["2"] = 1; m2["3"] = 1; m2["4"] = 1;

        REQUIRE ( has_key(m2, "1") == true );
        REQUIRE ( has_key(m2, "2") == true );
        REQUIRE ( has_key(m2, "8") == false );
        REQUIRE ( has_key(m2, "9") == false );
    }
}


TEST_CASE("Test if there is a value in the given vector.", "[vector]") {
    SECTION("vector<int>") {
        std::vector<int> v;
        v.push_back(1); v.push_back(2); v.push_back(3);

        REQUIRE( has_key(v, 1) == true);
        REQUIRE( has_key(v, 2) == true);
        REQUIRE( has_key(v, 8) == false);
        REQUIRE( has_key(v, 9) == false);
    }

    SECTION("vector<string>") {
        std::vector<std::string> v;
        v.push_back("1"); v.push_back("2"); v.push_back("3");

        REQUIRE( has_key(v, "1") == true);
        REQUIRE( has_key(v, "2") == true);
        REQUIRE( has_key(v, "8") == false);
        REQUIRE( has_key(v, "9") == false);
    }
}


TEST_CASE("Test if there is a value in the given set.", "[set]") {

    SECTION("set<int>") {
        std::set<int> s1;
        s1.insert(1); s1.insert(2); s1.insert(3);

        //REQUIRE ( has_key(s1, 1) == true );
        //REQUIRE ( has_key(s1, 2) == true );
        //REQUIRE ( has_key(s1, 5) == false );
        REQUIRE ( has_key(s1, 9) == false );
    }

    SECTION("set<string>") {
        std::set<std::string> s2;
        s2.insert("1"); s2.insert("2"); s2.insert("3");

        //REQUIRE ( has_key(s2, "1") == true );
        //REQUIRE ( has_key(s2, "2") == true );
        //REQUIRE ( has_key(s2, "8") == false );
        REQUIRE ( has_key(s2, "9") == false );
    }
}


