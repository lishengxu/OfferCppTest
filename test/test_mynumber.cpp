/*
 * test_mynumber.cpp
 *
 *  Created on: Jan 8, 2019
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include "mynumber.h"

TEST(mynumbertest, fibonacci) {
    EXPECT_EQ(0, fibonacci(-1));
    EXPECT_EQ(0, fibonacci(0));
    EXPECT_EQ(1, fibonacci(1));
    EXPECT_EQ(1, fibonacci(2));

    EXPECT_EQ(55, fibonacci(10));
    EXPECT_EQ(6765, fibonacci(20));
}

TEST(mynumbertest, myPower) {
    EXPECT_FLOAT_EQ(0.0f, myPower(0.0f, 0));
    EXPECT_FLOAT_EQ(0.0f, myPower(0, 2));
    EXPECT_FLOAT_EQ(0.0f, myPower(0, -2));
    EXPECT_FLOAT_EQ(6.25f, myPower(2.5f, 2));
    EXPECT_FLOAT_EQ(6.25f, myPower(-2.5f, 2));
    EXPECT_FLOAT_EQ(0.25f, myPower(2.0f, -2));
    EXPECT_FLOAT_EQ(0.25f, myPower(-2.0f, -2));
}

TEST(mynumbertest, print1ToMaxOfNDigits) {
    std::vector<std::string> pOut;
    print1ToMaxOfNDigits(0, false, &pOut);
    EXPECT_EQ(0, pOut.size());

    print1ToMaxOfNDigits(1, false, &pOut);
    EXPECT_EQ(9, pOut.size());
    EXPECT_STREQ("1", pOut.at(0).c_str());
    EXPECT_STREQ("9", pOut.at(pOut.size() - 1).c_str());
    pOut.clear();

    print1ToMaxOfNDigits(2, false, &pOut);
    EXPECT_EQ(99, pOut.size());
    EXPECT_STREQ("1", pOut.at(0).c_str());
    EXPECT_STREQ("99", pOut.at(pOut.size() - 1).c_str());
    pOut.clear();

    print1ToMaxOfNDigits(5, false, &pOut);
    EXPECT_EQ(99999, pOut.size());
    EXPECT_STREQ("1", pOut.at(0).c_str());
    EXPECT_STREQ("99999", pOut.at(pOut.size() - 1).c_str());
    pOut.clear();

    print1ToMaxOfNDigits(0, true, &pOut);
    EXPECT_EQ(0, pOut.size());

    print1ToMaxOfNDigits(1, true, &pOut);
    EXPECT_EQ(9, pOut.size());
    EXPECT_STREQ("1", pOut.at(0).c_str());
    EXPECT_STREQ("9", pOut.at(pOut.size() - 1).c_str());
    pOut.clear();

    print1ToMaxOfNDigits(2, true, &pOut);
    EXPECT_EQ(99, pOut.size());
    EXPECT_STREQ("1", pOut.at(0).c_str());
    EXPECT_STREQ("99", pOut.at(pOut.size() - 1).c_str());
    pOut.clear();

    print1ToMaxOfNDigits(5, true, &pOut);
    EXPECT_EQ(99999, pOut.size());
    EXPECT_STREQ("1", pOut.at(0).c_str());
    EXPECT_STREQ("99999", pOut.at(pOut.size() - 1).c_str());
    pOut.clear();
}

TEST(mynumbertest, add) {
    EXPECT_EQ(NULL, add(NULL, NULL));
    EXPECT_EQ(NULL, add("", ""));

    EXPECT_STREQ("2", add("1", "1"));
    EXPECT_STREQ("22", add("11", "11"));

    EXPECT_STREQ("100000000", add("1", "99999999"));
    EXPECT_STREQ("155555554", add("77777777", "77777777"));
    EXPECT_STREQ("155555554", add("77777777", "+77777777"));
    EXPECT_STREQ("0", add("77777777", "-77777777"));

    EXPECT_STREQ("3456789", add("3456777", "12"));
    EXPECT_STREQ("1111111111111110", add("111111111111111", "999999999999999"));
    EXPECT_STREQ("74894", add("123456", "-48562"));
    EXPECT_STREQ("1", add("10000", "-9999"));
    EXPECT_STREQ("0", add("10000", "-10000"));
    EXPECT_STREQ("-464040", add("123456", "-587496"));
    EXPECT_STREQ("-464040", add("-587496", "123456"));
    EXPECT_STREQ("-710952", add("-123456", "-587496"));

    try {
        EXPECT_STREQ("144444444", add("777a7777", "77777777"));
        ADD_FAILURE();
    } catch (std::exception& ex) {
        EXPECT_STREQ("invalid input", ex.what());
    }

}









