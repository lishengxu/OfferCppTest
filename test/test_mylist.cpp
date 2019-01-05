/*
 * test_mylist.cpp
 *
 *  Created on: Jan 5, 2019
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include "mylist.h"

TEST(mylisttest, deletelist) {
    deleteList(NULL);
    ListNode* pHead = NULL;
    deleteList(&pHead);
    EXPECT_TRUE(pHead == NULL);

    addToTail(&pHead, 1);
    deleteList(&pHead);
    EXPECT_TRUE(pHead == NULL);

    addToTail(&pHead, 1);
    addToTail(&pHead, 2);
    addToTail(&pHead, 3);
    addToTail(&pHead, 4);
    addToTail(&pHead, 5);
    addToTail(&pHead, 6);
    deleteList(&pHead);
    EXPECT_TRUE(pHead == NULL);
}

TEST(mylisttest, addtotail) {
    EXPECT_EQ(NULL, addToTail(NULL, 1));

    ListNode* pHead = NULL;
    ListNode* pNode = addToTail(&pHead, 1);
    EXPECT_EQ(1, pNode->mValue);
    EXPECT_EQ(NULL, pNode->mNext);
    EXPECT_EQ(1, pHead->mValue);
    EXPECT_EQ(NULL, pHead->mNext);

    pNode = addToTail(&pHead, 2);
    EXPECT_EQ(2, pNode->mValue);
    EXPECT_EQ(2, pHead->mNext->mValue);
    EXPECT_EQ(NULL, pHead->mNext->mNext);

    addToTail(&pHead, 3);
    pNode = addToTail(&pHead, 4);
    EXPECT_EQ(4, pNode->mValue);
    EXPECT_EQ(NULL, pNode->mNext);

    EXPECT_EQ(2, pHead->mNext->mValue);
    EXPECT_EQ(pNode, pHead->mNext->mNext->mNext);
    deleteList(&pHead);
    EXPECT_TRUE(pHead == NULL);
}

TEST(mylisttest, removeNode) {
    removeNode(NULL, 0);

    ListNode* pHead = NULL;
    addToTail(&pHead, 1);
    removeNode(&pHead, 1);
    EXPECT_TRUE(pHead == NULL);

    addToTail(&pHead, 1);
    addToTail(&pHead, 1);
    addToTail(&pHead, 1);
    addToTail(&pHead, 1);
    addToTail(&pHead, 1);
    addToTail(&pHead, 1);
    addToTail(&pHead, 1);
    removeNode(&pHead, 1);
    EXPECT_TRUE(pHead == NULL);

    addToTail(&pHead, 1);
    removeNode(&pHead, 0);
    EXPECT_EQ(1, pHead->mValue);
    EXPECT_EQ(NULL, pHead->mNext);

    addToTail(&pHead, 2);
    ListNode* pNode = addToTail(&pHead, 3);
    addToTail(&pHead, 4);
    addToTail(&pHead, 5);
    addToTail(&pHead, 5);
    removeNode(&pHead, 2);
    EXPECT_EQ(3, pHead->mNext->mValue);
    EXPECT_EQ(pNode, pHead->mNext);

    pNode = addToTail(&pHead, 6);
    removeNode(&pHead, 3);
    removeNode(&pHead, 4);
    removeNode(&pHead, 5);
    EXPECT_EQ(6, pHead->mNext->mValue);
    EXPECT_EQ(pNode, pHead->mNext);
    EXPECT_EQ(NULL, pHead->mNext->mNext);
}
