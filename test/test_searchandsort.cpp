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
    quickSort(NULL, 0, true);

    int arraySort1[] = { };
    quickSort(arraySort1, ARRAY_LEN(arraySort1), true);

    int arrayNoSort2[] = { 4, 3, 2, 6, 9, 1, 0, 7, 8, 5 };
    quickSort(arrayNoSort2, ARRAY_LEN(arrayNoSort2), true);
    int arraySort2[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0; i < ARRAY_LEN(arrayNoSort2); ++i) {
        EXPECT_EQ(arrayNoSort2[i], arraySort2[i]);
    }

    int arrayNoSort3[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    quickSort(arrayNoSort3, ARRAY_LEN(arrayNoSort3), true);
    int arraySort3[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0; i < ARRAY_LEN(arrayNoSort3); ++i) {
        EXPECT_EQ(arrayNoSort3[i], arraySort3[i]);
    }

    int arrayNoSort4[] = { 4, 3, 2, 6, 9, 1, 0, 7, 8, 5 };
    quickSort(arrayNoSort4, ARRAY_LEN(arrayNoSort4), false);
    int arraySort4[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0, size = ARRAY_LEN(arrayNoSort4); i < size; ++i) {
        EXPECT_EQ(arrayNoSort4[i], arraySort4[size - i - 1]);
    }

    int arrayNoSort5[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    quickSort(arrayNoSort5, ARRAY_LEN(arrayNoSort5), false);
    int arraySort5[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0, size = ARRAY_LEN(arrayNoSort5); i < size; ++i) {
        EXPECT_EQ(arrayNoSort5[i], arraySort5[size - i - 1]);
    }
}

TEST(searchandsorttest, findMin) {
    try {
        findMin(NULL, 0);
        int array0[] = { };
        findMin(array0, ARRAY_LEN(array0));
        ADD_FAILURE();
    } catch (std::exception& ex) {
        EXPECT_STREQ("invalid input", ex.what());
    }

    int array1[] = { 1 };
    EXPECT_EQ(1, findMin(array1, ARRAY_LEN(array1)));

    int array2[] = { 1, 0, 1, 1, 1 };
    EXPECT_EQ(0, findMin(array2, ARRAY_LEN(array2)));

    int array3[] = { 1, 1, 1, 0, 1 };
    EXPECT_EQ(0, findMin(array3, ARRAY_LEN(array3)));

    int array4[] = { 0, 1, 2, 3, 4, 5, 6 };
    EXPECT_EQ(0, findMin(array4, ARRAY_LEN(array4)));

    int array5[] = { 3, 4, 5, 6, 0, 1, 2, 3 };
    EXPECT_EQ(0, findMin(array5, ARRAY_LEN(array5)));
}

TEST(searchandsorttest, reOrderOddEven) {
    reOrderOddEven(NULL, 0);

    int array1[] = { 1 };
    reOrderOddEven(array1, ARRAY_LEN(array1));
    int array1result[] = { 1 };
    for (int i = 0, size = ARRAY_LEN(array1); i < size; ++i) {
        EXPECT_EQ(array1result[i], array1[i]);
    }

    int array2[] = { 2 };
    reOrderOddEven(array2, ARRAY_LEN(array2));
    int array2result[] = { 2 };
    for (int i = 0, size = ARRAY_LEN(array2); i < size; ++i) {
        EXPECT_EQ(array2result[i], array2[i]);
    }

    int array3[] = { 1, 3, 5, 7, 9, 11 };
    reOrderOddEven(array3, ARRAY_LEN(array3));
    int array3result[] = { 1, 3, 5, 7, 9, 11 };
    for (int i = 0, size = ARRAY_LEN(array3); i < size; ++i) {
        EXPECT_EQ(array3result[i], array3[i]);
    }

    int array4[] = { 2, 4, 6, 8, 10, 12 };
    reOrderOddEven(array4, ARRAY_LEN(array4));
    int array4result[] = { 2, 4, 6, 8, 10, 12 };
    for (int i = 0, size = ARRAY_LEN(array4); i < size; ++i) {
        EXPECT_EQ(array4result[i], array4[i]);
    }

    int array5[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    reOrderOddEven(array5, ARRAY_LEN(array5));
    int array5result[] = { 1, 9, 3, 7, 5, 6, 4, 8, 2, 10 };
    for (int i = 0, size = ARRAY_LEN(array5); i < size; ++i) {
        EXPECT_EQ(array5result[i], array5[i]);
    }

    int array6[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    reOrderOddEven(array6, ARRAY_LEN(array6), false);
    int array6result[] = { 10, 2, 8, 4, 6, 5, 7, 3, 9, 1 };
    for (int i = 0, size = ARRAY_LEN(array6); i < size; ++i) {
        EXPECT_EQ(array6result[i], array6[i]);
    }
}

TEST(searchandsorttest, moreThanHalfNum) {
    try {
        moreThanHalfNum(NULL, 0, true);
        ADD_FAILURE();
    } catch (std::invalid_argument& ex) {
        EXPECT_STREQ("invalid input", ex.what());
    }

    int array1[] = { 1 };
    EXPECT_EQ(1, moreThanHalfNum(array1, ARRAY_LEN(array1), true));

    int array2[] = { 1, 2, 2 };
    EXPECT_EQ(2, moreThanHalfNum(array2, ARRAY_LEN(array2), true));

    int array3[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
    EXPECT_EQ(2, moreThanHalfNum(array3, ARRAY_LEN(array3), true));

    int array4[] = { 1, 2, 3, 5, 2, 2, 8, 2 };
    try {
        EXPECT_EQ(2, moreThanHalfNum(array4, ARRAY_LEN(array4), true));
        ADD_FAILURE();
    } catch (std::invalid_argument& ex) {
        EXPECT_STREQ("invalid input", ex.what());
    }

    try {
        moreThanHalfNum(NULL, 0, false);
        ADD_FAILURE();
    } catch (std::invalid_argument& ex) {
        EXPECT_STREQ("invalid input", ex.what());
    }

    int array21[] = { 1 };
    EXPECT_EQ(1, moreThanHalfNum(array21, ARRAY_LEN(array21), false));

    int array22[] = { 1, 2, 2 };
    EXPECT_EQ(2, moreThanHalfNum(array22, ARRAY_LEN(array22), false));

    int array23[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
    EXPECT_EQ(2, moreThanHalfNum(array23, ARRAY_LEN(array23), false));

    int array24[] = { 1, 2, 3, 5, 2, 2, 8, 2 };
    try {
        EXPECT_EQ(2, moreThanHalfNum(array24, ARRAY_LEN(array24), false));
        ADD_FAILURE();
    } catch (std::invalid_argument& ex) {
        EXPECT_STREQ("invalid input", ex.what());
    }
}

TEST(searchandsorttest, findLeastNumbers) {
    std::vector<int> pOut;
    findLeastNumbers(NULL, 0, 0, false, &pOut);

    int array1[] = { 1 };
    findLeastNumbers(array1, ARRAY_LEN(array1), 1, false, &pOut);
    EXPECT_EQ(1, pOut.at(0));
    pOut.clear();

    int array2[] = { 1, 2 };
    findLeastNumbers(array2, ARRAY_LEN(array2), 1, false, &pOut);
    EXPECT_EQ(1, pOut.at(0));
    pOut.clear();

    findLeastNumbers(array2, ARRAY_LEN(array2), 2, false, &pOut);
    EXPECT_EQ(2, pOut.at(0));
    EXPECT_EQ(1, pOut.at(1));
    pOut.clear();

    int array3[] = { 1, 3, 6, 7, 4, 3, 6, 2, 1, 8, 5 };
    findLeastNumbers(array3, ARRAY_LEN(array3), 4, false, &pOut);
    EXPECT_EQ(3, pOut.at(0));
    EXPECT_EQ(2, pOut.at(1));
    EXPECT_EQ(1, pOut.at(2));
    EXPECT_EQ(1, pOut.at(3));
    pOut.clear();

    findLeastNumbers(NULL, 0, 0, true, &pOut);

    int array21[] = { 1 };
    findLeastNumbers(array21, ARRAY_LEN(array21), 1, true, &pOut);
    EXPECT_EQ(1, pOut.at(0));
    pOut.clear();

    int array22[] = { 1, 2 };
    findLeastNumbers(array22, ARRAY_LEN(array22), 1, true, &pOut);
    EXPECT_EQ(1, pOut.at(0));
    pOut.clear();

    findLeastNumbers(array22, ARRAY_LEN(array22), 2, true, &pOut);
    EXPECT_EQ(1, pOut.at(0));
    EXPECT_EQ(2, pOut.at(1));
    pOut.clear();

    int array23[] = { 1, 3, 6, 7, 4, 3, 6, 2, 1, 8, 5 };
    findLeastNumbers(array23, ARRAY_LEN(array23), 4, true, &pOut);
    EXPECT_EQ(1, pOut.at(0));
    EXPECT_EQ(1, pOut.at(1));
    EXPECT_EQ(2, pOut.at(2));
    EXPECT_EQ(3, pOut.at(3));
    pOut.clear();
}

TEST(searchandsorttest, findMaxSumOfSubArray) {
    try {
        findMaxSumOfSubArray(NULL, 0);
        int array[] = { };
        findMaxSumOfSubArray(array, ARRAY_LEN(array));
        ADD_FAILURE();
    } catch (std::invalid_argument& ex) {
        EXPECT_STREQ("invalid input", ex.what());
    }

    int array1[] = { 1 };
    EXPECT_EQ(1, findMaxSumOfSubArray(array1, ARRAY_LEN(array1)));

    int array2[] = { 1, -2, 3 };
    EXPECT_EQ(3, findMaxSumOfSubArray(array2, ARRAY_LEN(array2)));

    int array3[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
    EXPECT_EQ(18, findMaxSumOfSubArray(array3, ARRAY_LEN(array3)));
}

TEST(searchandsorttest, printMinNumber) {
    std::string str;
    printMinNumber(NULL, 0, str);
    EXPECT_EQ(0, str.length());

    int array1[] = { 1 };
    printMinNumber(array1, ARRAY_LEN(array1), str);
    EXPECT_STREQ("1", str.c_str());
    str.clear();

    int array2[] = { 1, 21, 112, 1212, 3, 321 };
    printMinNumber(array2, ARRAY_LEN(array2), str);
    EXPECT_STREQ("11121212213213", str.c_str());
    str.clear();
}

TEST(searchandsorttest, getInversePairs) {
    EXPECT_EQ(0, getInversePairs(NULL, 0));
    int array1[] = { 0 };
    EXPECT_EQ(0, getInversePairs(array1, ARRAY_LEN(array1)));

    int array2[] = { 1, 0 };
    EXPECT_EQ(1, getInversePairs(array2, ARRAY_LEN(array2)));

    int array3[] = { 7, 5, 6, 4 };
    EXPECT_EQ(5, getInversePairs(array3, ARRAY_LEN(array3)));
}

TEST(searchandsorttest, countOfK) {
    EXPECT_EQ(0, countOfK(NULL, 0, 0));

    int array1[] = { 1 };
    EXPECT_EQ(0, countOfK(array1, ARRAY_LEN(array1), 0));
    EXPECT_EQ(1, countOfK(array1, ARRAY_LEN(array1), 1));

    int array2[] = { 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5, 5, 5, 6, 7, 8 };
    EXPECT_EQ(2, countOfK(array2, ARRAY_LEN(array2), 3));
    EXPECT_EQ(3, countOfK(array2, ARRAY_LEN(array2), 2));
    EXPECT_EQ(6, countOfK(array2, ARRAY_LEN(array2), 5));
}

