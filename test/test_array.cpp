/*
 * test_array.cpp
 *
 *  Created on: Jan 4, 2019
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include "array.h"

TEST(getNumbertest, positive) {
    EXPECT_EQ(1, getNumber(1));
}

TEST(containtest, positive) {
    // Recursive
    EXPECT_FALSE(contain(NULL, 0, 0, 0, 0, 0, 0, 1));
    // NonRecursive
    EXPECT_FALSE(contain(NULL, 0, 0, 0, 0, 0, 0, 1, false));

    int array1[] = { 1 };
    // Recursive
    EXPECT_FALSE(contain(array1, 0, 0, 0, 0, 1, 1, 2));
    EXPECT_TRUE(contain(array1, 0, 0, 0, 0, 1, 1, 1));
    // NonRecursive
    EXPECT_FALSE(contain(array1, 0, 0, 0, 0, 1, 1, 2, false));
    EXPECT_TRUE(contain(array1, 0, 0, 0, 0, 1, 1, 1, false));

    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    // Recursive
    EXPECT_FALSE(contain(array, -1, -1, -1, -1, -1, -1, 1));
    EXPECT_FALSE(contain(array, 2, 1, 0, 0, 0, 0, 1));
    EXPECT_FALSE(contain(array, 0, 0, 2, 1, 0, 0, 1));
    EXPECT_FALSE(contain(array, 1, 2, 1, 2, 0, 0, 1));

    EXPECT_FALSE(contain(array, 0, 3, 0, 3, 4, 4, 0));
    EXPECT_FALSE(contain(array, 0, 3, 0, 3, 4, 4, 17));

    EXPECT_TRUE(contain(array, 0, 3, 0, 3, 4, 4, 1));
    EXPECT_TRUE(contain(array, 0, 3, 0, 3, 4, 4, 4));
    EXPECT_TRUE(contain(array, 0, 3, 0, 3, 4, 4, 13));
    EXPECT_TRUE(contain(array, 0, 3, 0, 3, 4, 4, 16));
    EXPECT_TRUE(contain(array, 0, 3, 0, 3, 4, 4, 10));
    // NonRecursive
    EXPECT_FALSE(contain(array, -1, -1, -1, -1, -1, -1, 1, false));
    EXPECT_FALSE(contain(array, 2, 1, 0, 0, 0, 0, 1, false));
    EXPECT_FALSE(contain(array, 0, 0, 2, 1, 0, 0, 1, false));
    EXPECT_FALSE(contain(array, 1, 2, 1, 2, 0, 0, 1, false));

    EXPECT_FALSE(contain(array, 0, 3, 0, 3, 4, 4, 0, false));
    EXPECT_FALSE(contain(array, 0, 3, 0, 3, 4, 4, 17, false));

    EXPECT_TRUE(contain(array, 0, 3, 0, 3, 4, 4, 1, false));
    EXPECT_TRUE(contain(array, 0, 3, 0, 3, 4, 4, 4, false));
    EXPECT_TRUE(contain(array, 0, 3, 0, 3, 4, 4, 13, false));
    EXPECT_TRUE(contain(array, 0, 3, 0, 3, 4, 4, 16, false));
    EXPECT_TRUE(contain(array, 0, 3, 0, 3, 4, 4, 10, false));

    int array2[] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
    // Recursive
    EXPECT_FALSE(contain(array2, 0, 3, 0, 3, 4, 4, 0));
    EXPECT_FALSE(contain(array2, 0, 3, 0, 3, 4, 4, 19));
    EXPECT_FALSE(contain(array2, 0, 3, 0, 3, 4, 4, 3));

    EXPECT_TRUE(contain(array2, 0, 3, 0, 3, 4, 4, 1));
    EXPECT_TRUE(contain(array2, 0, 3, 0, 3, 4, 4, 6));
    EXPECT_TRUE(contain(array2, 0, 3, 0, 3, 4, 4, 9));
    EXPECT_TRUE(contain(array2, 0, 3, 0, 3, 4, 4, 15));
    EXPECT_TRUE(contain(array2, 0, 3, 0, 3, 4, 4, 2));

    EXPECT_FALSE(contain(array2, 1, 2, 1, 2, 4, 4, 11));
    EXPECT_TRUE(contain(array2, 1, 2, 1, 2, 4, 4, 10));
    // NonRecursive
    EXPECT_FALSE(contain(array2, 0, 3, 0, 3, 4, 4, 0, false));
    EXPECT_FALSE(contain(array2, 0, 3, 0, 3, 4, 4, 19, false));
    EXPECT_FALSE(contain(array2, 0, 3, 0, 3, 4, 4, 3, false));

    EXPECT_TRUE(contain(array2, 0, 3, 0, 3, 4, 4, 1, false));
    EXPECT_TRUE(contain(array2, 0, 3, 0, 3, 4, 4, 6, false));
    EXPECT_TRUE(contain(array2, 0, 3, 0, 3, 4, 4, 9, false));
    EXPECT_TRUE(contain(array2, 0, 3, 0, 3, 4, 4, 15, false));
    EXPECT_TRUE(contain(array2, 0, 3, 0, 3, 4, 4, 2, false));

    EXPECT_FALSE(contain(array2, 1, 2, 1, 2, 4, 4, 11, false));
    EXPECT_TRUE(contain(array2, 1, 2, 1, 2, 4, 4, 10, false));

}

