/*
 * test_mytree.cpp
 *
 *  Created on: Jan 6, 2019
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include "mytree.h"
#include "common.h"

static int preOrder1[] = { 0 };
static int inOrder1[] = { 0 };
static int postOrder1[] = { 0 };
static int levelOrder1[] = { 0 };

static int preOrder2[] = { 1, 2, 3, 4 };
static int inOrder2[] = { 4, 3, 2, 1 };
static int postOrder2[] = { 4, 3, 2, 1 };
static int levelOrder2[] = { 1, 2, 3, 4 };

static int preOrder3[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
static int inOrder3[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
static int postOrder3[] = { 7, 4, 2, 5, 8, 6, 3, 1 };
static int levelOrder3[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

static int preOrder4[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
static int inOrder4[] = { 4, 7, 2, 1, 5, 3, 9, 6 };

TEST(mytreetest, construct) {
    EXPECT_EQ(NULL, construct(NULL, NULL, 0));

    BinaryTreeNode* pNode = construct(preOrder1, inOrder1,
            ARRAY_LEN(preOrder1));
    EXPECT_EQ(0, pNode->mValue);
    EXPECT_EQ(NULL, pNode->mLeft);
    EXPECT_EQ(NULL, pNode->mRight);
    destoryTree(&pNode);

    pNode = construct(preOrder2, inOrder2, ARRAY_LEN(preOrder2));
    EXPECT_TRUE(pNode != NULL);
    EXPECT_EQ(1, pNode->mValue);
    EXPECT_EQ(NULL, pNode->mRight);
    EXPECT_EQ(2, pNode->mLeft->mValue);
    EXPECT_EQ(NULL, pNode->mLeft->mRight);
    EXPECT_EQ(3, pNode->mLeft->mLeft->mValue);
    EXPECT_EQ(NULL, pNode->mLeft->mLeft->mRight);
    EXPECT_EQ(4, pNode->mLeft->mLeft->mLeft->mValue);
    EXPECT_EQ(NULL, pNode->mLeft->mLeft->mLeft->mLeft);
    EXPECT_EQ(NULL, pNode->mLeft->mLeft->mLeft->mRight);
    destoryTree(&pNode);

    pNode = construct(preOrder3, inOrder3, ARRAY_LEN(preOrder3));
    EXPECT_EQ(1, pNode->mValue);
    EXPECT_EQ(2, pNode->mLeft->mValue);
    EXPECT_EQ(NULL, pNode->mLeft->mRight);
    EXPECT_EQ(4, pNode->mLeft->mLeft->mValue);
    EXPECT_EQ(NULL, pNode->mLeft->mLeft->mLeft);
    EXPECT_EQ(7, pNode->mLeft->mLeft->mRight->mValue);
    EXPECT_EQ(NULL, pNode->mLeft->mLeft->mRight->mLeft);
    EXPECT_EQ(NULL, pNode->mLeft->mLeft->mRight->mRight);
    EXPECT_EQ(3, pNode->mRight->mValue);
    EXPECT_EQ(5, pNode->mRight->mLeft->mValue);
    EXPECT_EQ(NULL, pNode->mRight->mLeft->mLeft);
    EXPECT_EQ(NULL, pNode->mRight->mLeft->mRight);
    EXPECT_EQ(6, pNode->mRight->mRight->mValue);
    EXPECT_EQ(NULL, pNode->mRight->mRight->mRight);
    EXPECT_EQ(8, pNode->mRight->mRight->mLeft->mValue);
    EXPECT_EQ(NULL, pNode->mRight->mRight->mLeft->mLeft);
    EXPECT_EQ(NULL, pNode->mRight->mRight->mLeft->mRight);
    destoryTree(&pNode);

    try {
        pNode = construct(preOrder4, inOrder4, ARRAY_LEN(preOrder4));
        ADD_FAILURE();
    } catch (std::exception& ex) {
        EXPECT_STREQ("Invalid input: the inOrder can not find 8", ex.what());
    }
    if (pNode != NULL) {
        destoryTree(&pNode);
    }
}

TEST(mytreetest, destoryTree) {
    destoryTree(NULL);

    BinaryTreeNode* pNode = construct(preOrder1, inOrder1,
            ARRAY_LEN(preOrder1));
    destoryTree(&pNode);
    EXPECT_EQ(NULL, pNode);

    pNode = construct(preOrder2, inOrder2, ARRAY_LEN(preOrder2));
    destoryTree(&pNode);
    EXPECT_EQ(NULL, pNode);

    pNode = construct(preOrder3, inOrder3, ARRAY_LEN(preOrder3));
    destoryTree(&pNode);
    EXPECT_EQ(NULL, pNode);
}

TEST(mytreetest, preorder) {
    std::vector<int> pOut;
    preOrder(NULL, true, &pOut);

    BinaryTreeNode* pNode = construct(preOrder1, inOrder1,
            ARRAY_LEN(preOrder1));
    preOrder(pNode, true, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(preOrder1); ++i) {
        EXPECT_EQ(preOrder1[i], pOut.at(i));
    }
    pOut.clear();
    preOrder(pNode, false, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(preOrder1); ++i) {
        EXPECT_EQ(preOrder1[i], pOut.at(i));
    }

    destoryTree(&pNode);
    pOut.clear();

    pNode = construct(preOrder2, inOrder2, ARRAY_LEN(preOrder2));
    preOrder(pNode, true, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(preOrder2); ++i) {
        EXPECT_EQ(preOrder2[i], pOut.at(i));
    }
    pOut.clear();
    preOrder(pNode, false, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(preOrder2); ++i) {
        EXPECT_EQ(preOrder2[i], pOut.at(i));
    }

    destoryTree(&pNode);
    pOut.clear();

    pNode = construct(preOrder3, inOrder3, ARRAY_LEN(preOrder3));
    preOrder(pNode, true, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(preOrder3); ++i) {
        EXPECT_EQ(preOrder3[i], pOut.at(i));
    }
    pOut.clear();
    preOrder(pNode, false, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(preOrder3); ++i) {
        EXPECT_EQ(preOrder3[i], pOut.at(i));
    }

    destoryTree(&pNode);
    pOut.clear();
}

TEST(mytreetest, inOrder) {
    std::vector<int> pOut;
    inOrder(NULL, true, &pOut);

    BinaryTreeNode* pNode = construct(preOrder1, inOrder1,
            ARRAY_LEN(preOrder1));
    inOrder(pNode, true, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(inOrder1); ++i) {
        EXPECT_EQ(inOrder1[i], pOut.at(i));
    }
    pOut.clear();
    inOrder(pNode, false, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(inOrder1); ++i) {
        EXPECT_EQ(inOrder1[i], pOut.at(i));
    }

    destoryTree(&pNode);
    pOut.clear();

    pNode = construct(preOrder2, inOrder2, ARRAY_LEN(preOrder2));
    inOrder(pNode, true, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(inOrder2); ++i) {
        EXPECT_EQ(inOrder2[i], pOut.at(i));
    }
    pOut.clear();
    inOrder(pNode, false, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(inOrder2); ++i) {
        EXPECT_EQ(inOrder2[i], pOut.at(i));
    }

    destoryTree(&pNode);
    pOut.clear();

    pNode = construct(preOrder3, inOrder3, ARRAY_LEN(preOrder3));
    inOrder(pNode, true, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(inOrder3); ++i) {
        EXPECT_EQ(inOrder3[i], pOut.at(i));
    }
    pOut.clear();
    inOrder(pNode, false, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(inOrder3); ++i) {
        EXPECT_EQ(inOrder3[i], pOut.at(i));
    }

    destoryTree(&pNode);
    pOut.clear();
}

TEST(mytreetest, postorder) {
    std::vector<int> pOut;
    postOrder(NULL, true, &pOut);

    BinaryTreeNode* pNode = construct(preOrder1, inOrder1,
            ARRAY_LEN(preOrder1));
    postOrder(pNode, true, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(postOrder1); ++i) {
        EXPECT_EQ(postOrder1[i], pOut.at(i));
    }
    pOut.clear();
    postOrder(pNode, false, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(postOrder1); ++i) {
        EXPECT_EQ(postOrder1[i], pOut.at(i));
    }

    destoryTree(&pNode);
    pOut.clear();

    pNode = construct(preOrder2, inOrder2, ARRAY_LEN(preOrder2));
    postOrder(pNode, true, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(postOrder2); ++i) {
        EXPECT_EQ(postOrder2[i], pOut.at(i));
    }
    pOut.clear();
    postOrder(pNode, false, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(postOrder2); ++i) {
        EXPECT_EQ(postOrder2[i], pOut.at(i));
    }

    destoryTree(&pNode);
    pOut.clear();

    pNode = construct(preOrder3, inOrder3, ARRAY_LEN(preOrder3));
    postOrder(pNode, true, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(postOrder3); ++i) {
        EXPECT_EQ(postOrder3[i], pOut.at(i));
    }
    pOut.clear();
    postOrder(pNode, false, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(postOrder3); ++i) {
        EXPECT_EQ(postOrder3[i], pOut.at(i));
    }

    destoryTree(&pNode);
    pOut.clear();

}

TEST(mytreetest, levelorder) {
    std::vector<int> pOut;
    levelOrder(NULL, &pOut);

    BinaryTreeNode* pNode = construct(preOrder1, inOrder1,
            ARRAY_LEN(preOrder1));
    levelOrder(pNode, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(levelOrder1); ++i) {
        EXPECT_EQ(levelOrder1[i], pOut.at(i));
    }

    destoryTree(&pNode);
    pOut.clear();

    pNode = construct(preOrder2, inOrder2, ARRAY_LEN(preOrder2));
    levelOrder(pNode, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(levelOrder2); ++i) {
        EXPECT_EQ(levelOrder2[i], pOut.at(i));
    }

    destoryTree(&pNode);
    pOut.clear();

    pNode = construct(preOrder3, inOrder3, ARRAY_LEN(preOrder3));
    levelOrder(pNode, &pOut);
    for (unsigned int i = 0; i < ARRAY_LEN(levelOrder3); ++i) {
        EXPECT_EQ(levelOrder3[i], pOut.at(i));
    }

    destoryTree(&pNode);
    pOut.clear();
}
