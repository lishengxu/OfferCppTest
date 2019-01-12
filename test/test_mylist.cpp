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
    deleteList(&pHead);
}

TEST(mylisttest, printlist) {
    std::vector<int> pOut;
    printList(NULL, true, &pOut);

    ListNode* pHead = NULL;
    printList(&pHead, true, &pOut);
    EXPECT_EQ(0, pOut.size());

    addToTail(&pHead, 1);
    printList(&pHead, true, &pOut);
    EXPECT_EQ(1, pOut.size());
    EXPECT_EQ(1, pOut.front());

    pOut.clear();
    printList(&pHead, false, &pOut);
    EXPECT_EQ(1, pOut.size());
    EXPECT_EQ(1, pOut.front());

    addToTail(&pHead, 2);
    addToTail(&pHead, 3);
    addToTail(&pHead, 4);
    pOut.clear();
    printList(&pHead, true, &pOut);
    EXPECT_EQ(4, pOut.size());
    EXPECT_EQ(1, pOut.front());
    EXPECT_EQ(4, pOut.back());

    pOut.clear();
    printList(&pHead, false, &pOut);
    EXPECT_EQ(4, pOut.size());
    EXPECT_EQ(4, pOut.front());
    EXPECT_EQ(1, pOut.back());
    deleteList(&pHead);
}

TEST(mylisttest, deleteNode) {
    deleteNode(NULL, NULL);

    ListNode* pHead = NULL;
    ListNode* pNode = addToTail(&pHead, 1);
    deleteNode(&pHead, pNode);
    EXPECT_EQ(NULL, pHead);

    pNode = addToTail(&pHead, 1);
    ListNode* pNodeTemp = addToTail(&pHead, 2);
    deleteNode(&pHead, pNode);
    EXPECT_EQ(2, pHead->mValue);
    EXPECT_EQ(NULL, pHead->mNext);
    deleteNode(&pHead, pNodeTemp);
    EXPECT_EQ(NULL, pHead);

    addToTail(&pHead, 2);
    pNodeTemp = addToTail(&pHead, 3);
    pNode = addToTail(&pHead, 4);
    EXPECT_EQ(4, pNodeTemp->mNext->mValue);
    EXPECT_EQ(pNode, pNodeTemp->mNext);
    deleteNode(&pHead, pNode);
    EXPECT_EQ(NULL, pNodeTemp->mNext);

    ListNode* pTemp = new ListNode();
    pTemp->mNext = NULL;
    pTemp->mValue = 10;
    try {
        deleteNode(&pHead, pTemp);
    } catch (std::exception& ex) {
        EXPECT_STREQ("toDel is not a node in list", ex.what());
    }
    deleteList(&pHead);
}

TEST(mylisttest, getKNodeToTail) {
    EXPECT_EQ(NULL, getKNodeToTail(NULL, 0));
    ListNode* pHead = NULL;

    addToTail(&pHead, 1);
    EXPECT_EQ(1, getKNodeToTail(&pHead, 1)->mValue);

    addToTail(&pHead, 2);
    addToTail(&pHead, 3);
    EXPECT_EQ(3, getKNodeToTail(&pHead, 1)->mValue);
    EXPECT_EQ(2, getKNodeToTail(&pHead, 2)->mValue);
    EXPECT_EQ(1, getKNodeToTail(&pHead, 3)->mValue);
    EXPECT_EQ(NULL, getKNodeToTail(&pHead, 4));
    deleteList(&pHead);
}

TEST(mylisttest, getMiddleNode) {
    EXPECT_EQ(NULL, getMiddleNode(NULL));
    ListNode* pHead = NULL;
    addToTail(&pHead, 1);
    EXPECT_EQ(1, getMiddleNode(&pHead)->mValue);

    addToTail(&pHead, 2);
    EXPECT_EQ(2, getMiddleNode(&pHead)->mValue);

    addToTail(&pHead, 3);
    EXPECT_EQ(2, getMiddleNode(&pHead)->mValue);

    addToTail(&pHead, 4);
    EXPECT_EQ(3, getMiddleNode(&pHead)->mValue);

    addToTail(&pHead, 5);
    EXPECT_EQ(3, getMiddleNode(&pHead)->mValue);

    deleteList(&pHead);
}

TEST(mylisttest, isCircleList) {
    EXPECT_FALSE(isCircleList(NULL));

    ListNode* pHead = NULL;
    ListNode* pNode = addToTail(&pHead, 1);
    EXPECT_FALSE(isCircleList(&pHead));
    pNode->mNext = pNode;
    EXPECT_TRUE(isCircleList(&pHead));
    pNode->mNext = NULL;
    addToTail(&pHead, 2);
    addToTail(&pHead, 3);
    pNode = addToTail(&pHead, 4);
    EXPECT_FALSE(isCircleList(&pHead));
    pNode->mNext = pHead;
    EXPECT_TRUE(isCircleList(&pHead));
    pNode->mNext = pNode;
    EXPECT_TRUE(isCircleList(&pHead));
    pNode->mNext = NULL;
    deleteList(&pHead);
}

TEST(mylisttest, reverseList) {
    EXPECT_EQ(NULL, reverseList(NULL));

    ListNode* pHead = NULL;
    addToTail(&pHead, 1);
    ListNode* pNode = reverseList(&pHead);
    EXPECT_EQ(1, pNode->mValue);
    EXPECT_EQ(NULL, pNode->mNext);

    addToTail(&pHead, 2);
    pNode = reverseList(&pHead);
    EXPECT_EQ(2, pNode->mValue);
    EXPECT_EQ(2, pHead->mValue);
    EXPECT_EQ(1, pNode->mNext->mValue);

    addToTail(&pHead, 3);
    pNode = reverseList(&pHead);
    EXPECT_EQ(3, pNode->mValue);
    EXPECT_EQ(1, pNode->mNext->mValue);

    deleteList(&pHead);
}

TEST(mylisttest, mergeList) {
    EXPECT_EQ(NULL, mergeSortedLists(NULL, NULL));

    ListNode* pLeft = NULL;
    ListNode* pRight = NULL;
    EXPECT_EQ(NULL, mergeSortedLists(&pLeft, &pRight));

    addToTail(&pLeft, 1);
    ListNode* pNew = mergeSortedLists(&pLeft, &pRight);
    EXPECT_EQ(1, pNew->mValue);
    EXPECT_EQ(NULL, pNew->mNext);
    pLeft = NULL, pRight = NULL;
    deleteList(&pNew);

    addToTail(&pLeft, 1);
    addToTail(&pRight, 3);
    pNew = mergeSortedLists(&pLeft, &pRight);
    EXPECT_EQ(1, pNew->mValue);
    EXPECT_EQ(3, pNew->mNext->mValue);
    pLeft = NULL, pRight = NULL;
    deleteList(&pNew);

    addToTail(&pLeft, 1);
    addToTail(&pRight, 3);
    addToTail(&pRight, 3);
    addToTail(&pRight, 4);
    addToTail(&pLeft, 3);
    addToTail(&pLeft, 4);
    addToTail(&pLeft, 5);
    pNew = mergeSortedLists(&pLeft, &pRight);
    EXPECT_EQ(1, pNew->mValue);
    EXPECT_EQ(3, pNew->mNext->mValue);
    EXPECT_EQ(3, pNew->mNext->mNext->mValue);
    EXPECT_EQ(3, pNew->mNext->mNext->mNext->mValue);
    EXPECT_EQ(4, pNew->mNext->mNext->mNext->mNext->mValue);
    EXPECT_EQ(4, pNew->mNext->mNext->mNext->mNext->mNext->mValue);
    EXPECT_EQ(5, pNew->mNext->mNext->mNext->mNext->mNext->mNext->mValue);
    EXPECT_EQ(NULL, pNew->mNext->mNext->mNext->mNext->mNext->mNext->mNext);
    deleteList(&pNew);

    EXPECT_EQ(NULL, mergeSortedLists(NULL, NULL, true));
    pLeft = NULL;
    pRight = NULL;
    EXPECT_EQ(NULL, mergeSortedLists(&pLeft, &pRight, true));

    addToTail(&pLeft, 1);
    pNew = mergeSortedLists(&pLeft, &pRight, true);
    EXPECT_EQ(1, pNew->mValue);
    EXPECT_EQ(NULL, pNew->mNext);
    pLeft = NULL, pRight = NULL;
    deleteList(&pNew);

    addToTail(&pLeft, 1);
    addToTail(&pRight, 3);
    pNew = mergeSortedLists(&pLeft, &pRight, true);
    EXPECT_EQ(1, pNew->mValue);
    EXPECT_EQ(3, pNew->mNext->mValue);
    pLeft = NULL, pRight = NULL;
    deleteList(&pNew);

    addToTail(&pLeft, 1);
    addToTail(&pRight, 3);
    addToTail(&pRight, 3);
    addToTail(&pRight, 4);
    addToTail(&pLeft, 3);
    addToTail(&pLeft, 4);
    addToTail(&pLeft, 5);
    pNew = mergeSortedLists(&pLeft, &pRight, true);
    EXPECT_EQ(1, pNew->mValue);
    EXPECT_EQ(3, pNew->mNext->mValue);
    EXPECT_EQ(3, pNew->mNext->mNext->mValue);
    EXPECT_EQ(3, pNew->mNext->mNext->mNext->mValue);
    EXPECT_EQ(4, pNew->mNext->mNext->mNext->mNext->mValue);
    EXPECT_EQ(4, pNew->mNext->mNext->mNext->mNext->mNext->mValue);
    EXPECT_EQ(5, pNew->mNext->mNext->mNext->mNext->mNext->mNext->mValue);
    EXPECT_EQ(NULL, pNew->mNext->mNext->mNext->mNext->mNext->mNext->mNext);
    deleteList(&pNew);
}

TEST(mylisttest, clone) {
    EXPECT_EQ(NULL, clone(NULL));
    ComplexListNode* pNode1 = new ComplexListNode();
    pNode1->mValue = 1;
    pNode1->mNext = NULL;
    pNode1->mSibling = NULL;

    ComplexListNode* pNode2 = clone(pNode1);
    EXPECT_EQ(1, pNode2->mValue);
    EXPECT_EQ(NULL, pNode2->mNext);
    EXPECT_EQ(NULL, pNode2->mSibling);
    pNode2->mValue = 2;
    pNode1->mNext = pNode2;

    ComplexListNode* pNode3 = clone(pNode1);
    EXPECT_EQ(2, pNode3->mNext->mValue);
    EXPECT_EQ(NULL, pNode3->mNext->mNext);
    EXPECT_EQ(NULL, pNode3->mNext->mSibling);
    pNode3->mValue = 3;
    pNode3->mNext->mValue = 4;

    pNode2->mNext = pNode3;
    pNode1->mSibling = pNode3;
    pNode2->mSibling = pNode3->mNext;
    pNode3->mSibling = pNode2;
    pNode3->mNext->mSibling = pNode1;

    ComplexListNode* pNode4 = clone(pNode1);
    EXPECT_EQ(1, pNode4->mValue);
    EXPECT_EQ(2, pNode4->mNext->mValue);
    EXPECT_EQ(3, pNode4->mNext->mNext->mValue);
    EXPECT_EQ(4, pNode4->mNext->mNext->mNext->mValue);
    EXPECT_EQ(1, pNode4->mNext->mNext->mNext->mSibling->mValue);
    EXPECT_EQ(2, pNode4->mNext->mNext->mSibling->mValue);
    EXPECT_EQ(3, pNode4->mSibling->mValue);
    EXPECT_EQ(4, pNode4->mNext->mSibling->mValue);
    EXPECT_EQ(NULL, pNode4->mNext->mNext->mNext->mNext);
}

