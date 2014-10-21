#include "KMP.h"
#include "gtest/gtest.h"


TEST(KMPTest, PMTGenerate) {
    std::string str = "ABCDABD";
    std::string pmt;
    PMT(str, pmt);
    bool match = true;
    const char *pmt_expected = "\0\0\0\0\x1\x2\0";
    for (size_t i = 0; i < pmt.size(); i++) {
        if (pmt[i] != pmt_expected[i]) {
            match = false;
            break;
        }
    }

    EXPECT_TRUE(match);
}

