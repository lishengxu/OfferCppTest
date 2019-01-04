/*
 * test_factorial.cpp
 *
 *  Created on: Jan 4, 2019
 *      Author: lsx
 */
#include "gtest/gtest.h"
#include "factorial.h"

TEST(factorialtest, positive) {
    EXPECT_EQ(1, factorial(1));
}



