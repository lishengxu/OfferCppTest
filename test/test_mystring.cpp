/*
 * test_string.cpp
 *
 *  Created on: Jan 4, 2019
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include "mystring.h"

/**
 * 注意，该测试用例没有去释放replaceString返回的指针
 */
TEST(mystringTest, replaceString) {
    EXPECT_TRUE(replaceString(NULL, NULL, NULL) == NULL);
    EXPECT_STREQ(replaceString("", "", ""), "");
    EXPECT_STREQ(replaceString("a", "", "b"), "a");
    EXPECT_STREQ(replaceString("a", " ", "b"), "a");
    EXPECT_STREQ(replaceString("a", "a", ""), "");

    EXPECT_STREQ(replaceString("We are happy.", " ", "%20"),
            "We%20are%20happy.");
    EXPECT_STREQ(replaceString("   ", " ", "%20"), "%20%20%20");
    EXPECT_STREQ(replaceString("   ", "  ", "%20"), "%20 ");
    EXPECT_STREQ(replaceString("       ", "  ", "%20"), "%20%20%20 ");
    EXPECT_STREQ(replaceString("   ", "    ", "%20"), "   ");
    EXPECT_STREQ(
            replaceString(replaceString("a b c d e f ", " ", "%02"), "%02",
                    " "), "a b c d e f ");
    EXPECT_STREQ(replaceString(" a b c d e f", " ", "%02"),
            "%02a%02b%02c%02d%02e%02f");

    EXPECT_TRUE(replaceString(NULL, NULL, NULL, false) == NULL);
    EXPECT_STREQ(replaceString("", "", "", false), "");
    EXPECT_STREQ(replaceString("a", "", "b", false), "a");
    EXPECT_STREQ(replaceString("a", " ", "b", false), "a");
    EXPECT_STREQ(replaceString("a", "a", "", false), "");

    EXPECT_STREQ(replaceString("We are happy.", " ", "%20", false),
            "We%20are%20happy.");
    EXPECT_STREQ(replaceString("   ", " ", "%20", false), "%20%20%20");
    EXPECT_STREQ(replaceString("   ", "  ", "%20", false), " %20");
    EXPECT_STREQ(replaceString("       ", "  ", "%20", false), " %20%20%20");
    EXPECT_STREQ(replaceString("   ", "    ", "%20", false), "   ");
    EXPECT_STREQ(
            replaceString(replaceString("a b c d e f ", " ", "%02", false),
                    "%02", " ", false), "a b c d e f ");
    EXPECT_STREQ(replaceString(" a b c d e f", " ", "%02", false),
            "%02a%02b%02c%02d%02e%02f");
}

