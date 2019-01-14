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

static int numberOf1(unsigned int n) {
    int number = 0;
    while (n) {
        if (n % 10 == 1) {
            ++number;
        }
        n /= 10;
    }
    return number;
}

static int numberOf1ToN(unsigned int n) {
    int number = 0;
    for (unsigned int i = 1; i <= n; ++i) {
        number += numberOf1(i);
    }
    return number;
}

TEST(mynumbertest, countOf1Between1ToN) {
    EXPECT_EQ(0, countOf1Between1ToN(0));
    EXPECT_EQ(1, countOf1Between1ToN(1));
    EXPECT_EQ(5, countOf1Between1ToN(12));

    EXPECT_EQ(numberOf1ToN(100), countOf1Between1ToN(100));
    EXPECT_EQ(numberOf1ToN(12345), countOf1Between1ToN(12345));

}

static bool isUgly(unsigned int number) {
    while (number % 2 == 0) {
        number /= 2;
    }
    while (number % 3 == 0) {
        number /= 3;
    }
    while (number % 5 == 0) {
        number /= 5;
    }
    return number == 1;
}

static unsigned int getUgly(unsigned int n) {
    if (n == 0) {
        return 0;
    }
    unsigned int number = 0;
    unsigned int uglyFound = 0;
    while (uglyFound < n) {
        ++number;
        if (isUgly(number)) {
            ++uglyFound;
        }
    }
    return number;
}

TEST(mynumbertest, getUglyNumber) {
    EXPECT_EQ(1, getUglyNumber(1));
    EXPECT_EQ(2, getUglyNumber(2));
    EXPECT_EQ(3, getUglyNumber(3));
    EXPECT_EQ(4, getUglyNumber(4));
    EXPECT_EQ(5, getUglyNumber(5));
    EXPECT_EQ(5832, getUglyNumber(150));
    for (unsigned int i = 0; i < 200; ++i) {
        EXPECT_EQ(getUgly(i), getUglyNumber(i)) << " is differ at " << i
                << std::endl;
    }
}

