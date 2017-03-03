#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <cstring>
#include "KMP.h"


TEST_CASE("Test the generation of partial match table.", "[map]") {
    std::string str = "ABCDABD";
    std::string pmt;
    PMT(str, pmt);
    const char *pmt_expected = "\0\0\0\0\x1\x2\0";

    REQUIRE ( std::memcmp(pmt.c_str(), pmt_expected, pmt.size()) == 0 );
}


TEST_CASE("Test KMP algorithm.", "[map]") {
    std::string str = "BBC ABCDAB ABCDABCDABDE";
    std::string substr = "ABCDABD";
    int idx = KMP(str, substr);

    REQUIRE ( idx == 15 );
}

