/*
 * test_researchandsort.cpp
 *
 *  Created on: Jan 7, 2019
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include "searchandsort.h"
#include "common.h"

TEST(searchandsorttest, binarySearch) {

    EXPECT_FALSE(binarySearch(NULL, 0, 0));

    int array1[] = { };
    EXPECT_FALSE(binarySearch(array1, ARRAY_LEN(array1), 0));

    int array2[] = { 0 };
    EXPECT_TRUE(binarySearch(array2, ARRAY_LEN(array2), 0));
    EXPECT_FALSE(binarySearch(array2, ARRAY_LEN(array2), 1));

    int array3[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    EXPECT_TRUE(binarySearch(array3, ARRAY_LEN(array3), 0));
    EXPECT_TRUE(binarySearch(array3, ARRAY_LEN(array3), 10));
    EXPECT_TRUE(binarySearch(array3, ARRAY_LEN(array3), 4));
    EXPECT_FALSE(binarySearch(array3, ARRAY_LEN(array3), 11));
}

TEST(searchandsorttest, quickSort) {
    quickSort(NULL, 0);

    int arraySort1[] = { };
    quickSort(arraySort1, ARRAY_LEN(arraySort1));

    int arrayNoSort2[] = { 4, 3, 2, 6, 9, 1, 0, 7, 8, 5 };
    quickSort(arrayNoSort2, ARRAY_LEN(arrayNoSort2));
    int arraySort2[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0; i < ARRAY_LEN(arrayNoSort2); ++i) {
        EXPECT_EQ(arrayNoSort2[i], arraySort2[i]);
    }

    int arrayNoSort3[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    quickSort(arrayNoSort3, ARRAY_LEN(arrayNoSort3));
    int arraySort3[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0; i < ARRAY_LEN(arrayNoSort3); ++i) {
        EXPECT_EQ(arrayNoSort3[i], arraySort3[i]);
    }

}






