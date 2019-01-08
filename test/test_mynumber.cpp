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
    EXPECT_FLOAT_EQ(6.25f, myPower(2.5f, 2));
    EXPECT_FLOAT_EQ(0.25f, myPower(2.0f, -2));
}





