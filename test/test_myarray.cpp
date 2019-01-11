/*
 * test_array.cpp
 *
 *  Created on: Jan 4, 2019
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include "myarray.h"
#include "common.h"

TEST(myarraytest, contain) {
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

int cmp(const void* a, const void* b) {
    return *(char*) a - *(char*) b;
}
TEST(myarraytest, merge) {
    EXPECT_STREQ(NULL, merge(NULL, NULL, 1));

    char src[1024] = { 0 }, desc[2048] = { 0 };
    EXPECT_STREQ("", merge(src, desc, 1));

    strcpy(src, "abc");
    strcpy(desc, "bcd");
    EXPECT_STREQ(NULL, merge(src, desc, 5));
    EXPECT_EQ(2048, sizeof(desc));

    memset(src, 0, sizeof(src));
    memset(desc, 0, sizeof(desc));
    strcpy(src, "a");
    strcpy(desc, "");
    EXPECT_STREQ("a", merge(src, desc, sizeof(desc)));

    memset(src, 0, sizeof(src));
    memset(desc, 0, sizeof(desc));
    strcpy(src, "");
    strcpy(desc, "a");
    EXPECT_STREQ("a", merge(src, desc, sizeof(desc)));

    memset(src, 0, sizeof(src));
    memset(desc, 0, sizeof(desc));
    strcpy(src, "abcdefghiijkkklmn");
    strcpy(desc, "bcdfghiiikmn");
    EXPECT_STREQ("abbccddeffgghhiiiiijkkkklmmnn",
            merge(src, desc, sizeof(desc)));

    memset(src, 0, sizeof(src));
    memset(desc, 0, sizeof(desc));
    strcpy(src, "adfjalfdjall");
    strcpy(desc, "adjfajfdlkafd");
    qsort(src, strlen(src), sizeof(char), cmp);
    qsort(desc, strlen(desc), sizeof(char), cmp);
    EXPECT_STREQ("aaaaaadddddfffffjjjjkllll", merge(src, desc, sizeof(desc)));
}

TEST(myarraytest, printMatrixClockwisly) {
    //printMatrixClockwisly
    printMatrixClockwisly(NULL, 0, 0);

    std::vector<int> pOut;
    int array1[1];
    array1[0] = 0;
    printMatrixClockwisly(array1, 1, 1, &pOut);
    EXPECT_EQ(0, pOut.at(0));
    pOut.clear();

    int array2[5];
    for (int i = 0; i < 5; ++i) {
        array2[i] = i;
    }
    printMatrixClockwisly(array2, 5, 1, &pOut);
    EXPECT_EQ(0, pOut.at(0));
    EXPECT_EQ(4, pOut.at(4));
    EXPECT_EQ(5, pOut.size());
    pOut.clear();
    printMatrixClockwisly(array2, 1, 5, &pOut);
    EXPECT_EQ(0, pOut.at(0));
    EXPECT_EQ(4, pOut.at(4));
    EXPECT_EQ(5, pOut.size());
    pOut.clear();

    int array3[12];
    for (int i = 0; i < 12; ++i) {
        array3[i] = i;
    }
    printMatrixClockwisly(array3, 4, 3, &pOut);
    EXPECT_EQ(0, pOut.at(0));
    EXPECT_EQ(7, pOut.at(4));
    EXPECT_EQ(6, pOut.at(11));
    EXPECT_EQ(12, pOut.size());
    pOut.clear();
    printMatrixClockwisly(array3, 3, 4, &pOut);
    EXPECT_EQ(0, pOut.at(0));
    EXPECT_EQ(5, pOut.at(3));
    EXPECT_EQ(7, pOut.at(11));
    EXPECT_EQ(12, pOut.size());
    pOut.clear();
}





