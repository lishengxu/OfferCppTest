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

TEST(mystringTest, permutation) {
    std::vector<std::string> pOut;
    permutation(NULL, &pOut);

    char a[] = "a";
    permutation(a, &pOut);
    EXPECT_STREQ("a", pOut.at(0).c_str());
    pOut.clear();

    char ab[] = "ab";
    permutation(ab, &pOut);
    EXPECT_STREQ("ab", pOut.at(0).c_str());
    EXPECT_STREQ("ba", pOut.at(1).c_str());
    pOut.clear();

    char abc[] = "abc";
    permutation(abc, &pOut);
    EXPECT_EQ(6, pOut.size());
    EXPECT_STREQ("abc", pOut.at(0).c_str());
    EXPECT_STREQ("acb", pOut.at(1).c_str());
    EXPECT_STREQ("bac", pOut.at(2).c_str());
    EXPECT_STREQ("bca", pOut.at(3).c_str());
    EXPECT_STREQ("cba", pOut.at(4).c_str());
    EXPECT_STREQ("cab", pOut.at(5).c_str());
    pOut.clear();

    char abcdefg[] = "abcdefg";
    permutation(abcdefg, &pOut);
    EXPECT_EQ(7 * 6 * 5 * 4 * 3 * 2, pOut.size());
    pOut.clear();
}

TEST(mystringTest, combination) {
    std::vector<std::string> pOut;
    combination(NULL, &pOut);

    char a[] = "a";
    combination(a, &pOut);
    EXPECT_STREQ("a", pOut.at(0).c_str());
    pOut.clear();

    char ab[] = "ab";
    combination(ab, &pOut);
    EXPECT_STREQ("a", pOut.at(0).c_str());
    EXPECT_STREQ("b", pOut.at(1).c_str());
    EXPECT_STREQ("ab", pOut.at(2).c_str());
    pOut.clear();

    char abc[] = "abc";
    combination(abc, &pOut);
    EXPECT_EQ(7, pOut.size());
    EXPECT_STREQ("a", pOut.at(0).c_str());
    EXPECT_STREQ("b", pOut.at(1).c_str());
    EXPECT_STREQ("c", pOut.at(2).c_str());
    EXPECT_STREQ("ab", pOut.at(3).c_str());
    EXPECT_STREQ("ac", pOut.at(4).c_str());
    EXPECT_STREQ("bc", pOut.at(5).c_str());
    EXPECT_STREQ("abc", pOut.at(6).c_str());
    pOut.clear();

    char abcd[] = "abcd";
    combination(abcd, &pOut);
    EXPECT_EQ(15, pOut.size());
    pOut.clear();

    char abcdefg[] = "abcdefg";
    combination(abcdefg, &pOut);
    EXPECT_EQ(7 + 21 + 35 + 35 + 21 + 7 + 1, pOut.size());
    pOut.clear();
}
