/*
 * test_mybit.cpp
 *
 *  Created on: Jan 8, 2019
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include "mybit.h"

TEST(mybittest, countOf1InNumber) {
    EXPECT_EQ(32, countOf1InNumber(-1));
    EXPECT_EQ(0, countOf1InNumber(0));
    EXPECT_EQ(1, countOf1InNumber(1));
    EXPECT_EQ(2, countOf1InNumber(9));

    EXPECT_EQ(32, countOf1InNumber(-1, false));
    EXPECT_EQ(0, countOf1InNumber(0, false));
    EXPECT_EQ(1, countOf1InNumber(1, false));
    EXPECT_EQ(2, countOf1InNumber(9, false));
}

TEST(mybittest, powerOf2) {
    EXPECT_FALSE(powerOf2(0));
    EXPECT_TRUE(powerOf2(1));
    EXPECT_TRUE(powerOf2(2));
    EXPECT_TRUE(powerOf2(1024));
    EXPECT_FALSE(powerOf2(1025));
}

