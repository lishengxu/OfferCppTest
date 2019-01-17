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

TEST(mytreetest, hasChildTree) {
    EXPECT_FALSE(hasChildTree(NULL, NULL));

    BinaryTreeNode* pRoot = construct(preOrder1, inOrder1,
            ARRAY_LEN(preOrder1));
    BinaryTreeNode* pChildRoot = construct(preOrder1, inOrder1,
            ARRAY_LEN(preOrder1));
    EXPECT_TRUE(hasChildTree(pRoot, pChildRoot));
    destoryTree(&pRoot);
    destoryTree(&pChildRoot);

    pRoot = construct(preOrder2, inOrder2, ARRAY_LEN(preOrder2));
    pChildRoot = construct(preOrder2, inOrder2, ARRAY_LEN(preOrder2));
    EXPECT_TRUE(hasChildTree(pRoot, pChildRoot));
    destoryTree(&pRoot);
    destoryTree(&pChildRoot);

    pRoot = construct(preOrder3, inOrder3, ARRAY_LEN(preOrder3));
    pChildRoot = construct(preOrder3, inOrder3, ARRAY_LEN(preOrder3));
    EXPECT_TRUE(hasChildTree(pRoot, pChildRoot));
    destoryTree(&pRoot);
    destoryTree(&pChildRoot);

    int preOrder11[] = { 0 };
    int inOrder11[] = { 0 };
    int preOrder12[] = { 0, 2, 3, 4 };
    int inOrder12[] = { 4, 3, 2, 0 };
    pRoot = construct(preOrder12, inOrder12, ARRAY_LEN(preOrder12));
    pChildRoot = construct(preOrder11, inOrder11, ARRAY_LEN(preOrder11));
    EXPECT_TRUE(hasChildTree(pRoot, pChildRoot));
    destoryTree(&pRoot);
    destoryTree(&pChildRoot);

    pRoot = construct(preOrder3, inOrder3, ARRAY_LEN(preOrder3));
    int preOrder13[] = { 3, 5, 6 };
    int inOrder13[] = { 5, 3, 6 };
    pChildRoot = construct(preOrder13, inOrder13, ARRAY_LEN(preOrder13));
    EXPECT_TRUE(hasChildTree(pRoot, pChildRoot));
    destoryTree(&pChildRoot);

    int preOrder14[] = { 2, 5, 6 };
    int inOrder14[] = { 5, 2, 6 };
    pChildRoot = construct(preOrder14, inOrder14, ARRAY_LEN(preOrder14));
    EXPECT_FALSE(hasChildTree(pRoot, pChildRoot));
    destoryTree(&pRoot);
    destoryTree(&pChildRoot);
}

TEST(mytreetest, mirror) {
    EXPECT_EQ(NULL, mirror(NULL));

    BinaryTreeNode* pRoot = construct(preOrder1, inOrder1,
            ARRAY_LEN(preOrder1));
    BinaryTreeNode* pMirror = mirror(pRoot);
    EXPECT_EQ(0, pRoot->mValue);
    EXPECT_EQ(NULL, pRoot->mLeft);
    EXPECT_EQ(NULL, pRoot->mRight);
    destoryTree(&pMirror);

    pRoot = construct(preOrder2, inOrder2, ARRAY_LEN(preOrder2));
    pMirror = mirror(pRoot);
    EXPECT_EQ(1, pRoot->mValue);
    EXPECT_EQ(NULL, pRoot->mLeft);
    EXPECT_EQ(2, pRoot->mRight->mValue);
    EXPECT_EQ(NULL, pRoot->mRight->mLeft);
    EXPECT_EQ(3, pRoot->mRight->mRight->mValue);
    EXPECT_EQ(NULL, pRoot->mRight->mRight->mLeft);
    EXPECT_EQ(4, pRoot->mRight->mRight->mRight->mValue);
    EXPECT_EQ(NULL, pRoot->mRight->mRight->mRight->mRight);
    EXPECT_EQ(NULL, pRoot->mRight->mRight->mRight->mLeft);
    destoryTree(&pMirror);

    pRoot = construct(preOrder3, inOrder3, ARRAY_LEN(preOrder3));
    pMirror = mirror(pRoot);
    EXPECT_EQ(1, pMirror->mValue);
    EXPECT_EQ(2, pMirror->mRight->mValue);
    EXPECT_EQ(NULL, pMirror->mRight->mLeft);
    EXPECT_EQ(4, pMirror->mRight->mRight->mValue);
    EXPECT_EQ(NULL, pMirror->mRight->mRight->mRight);
    EXPECT_EQ(7, pMirror->mRight->mRight->mLeft->mValue);
    EXPECT_EQ(NULL, pMirror->mRight->mRight->mLeft->mRight);
    EXPECT_EQ(NULL, pMirror->mRight->mRight->mLeft->mLeft);
    EXPECT_EQ(3, pMirror->mLeft->mValue);
    EXPECT_EQ(5, pMirror->mLeft->mRight->mValue);
    EXPECT_EQ(NULL, pMirror->mLeft->mRight->mRight);
    EXPECT_EQ(NULL, pMirror->mLeft->mRight->mLeft);
    EXPECT_EQ(6, pMirror->mLeft->mLeft->mValue);
    EXPECT_EQ(NULL, pMirror->mLeft->mLeft->mLeft);
    EXPECT_EQ(8, pMirror->mLeft->mLeft->mRight->mValue);
    EXPECT_EQ(NULL, pMirror->mLeft->mLeft->mRight->mRight);
    EXPECT_EQ(NULL, pMirror->mLeft->mLeft->mRight->mLeft);
    destoryTree(&pMirror);

    //NonRecursive
    EXPECT_EQ(NULL, mirror(NULL, false));

    pRoot = construct(preOrder1, inOrder1, ARRAY_LEN(preOrder1));
    pMirror = mirror(pRoot, false);
    EXPECT_EQ(0, pRoot->mValue);
    EXPECT_EQ(NULL, pRoot->mLeft);
    EXPECT_EQ(NULL, pRoot->mRight);
    destoryTree(&pMirror);

    pRoot = construct(preOrder2, inOrder2, ARRAY_LEN(preOrder2));
    pMirror = mirror(pRoot, false);
    EXPECT_EQ(1, pRoot->mValue);
    EXPECT_EQ(NULL, pRoot->mLeft);
    EXPECT_EQ(2, pRoot->mRight->mValue);
    EXPECT_EQ(NULL, pRoot->mRight->mLeft);
    EXPECT_EQ(3, pRoot->mRight->mRight->mValue);
    EXPECT_EQ(NULL, pRoot->mRight->mRight->mLeft);
    EXPECT_EQ(4, pRoot->mRight->mRight->mRight->mValue);
    EXPECT_EQ(NULL, pRoot->mRight->mRight->mRight->mRight);
    EXPECT_EQ(NULL, pRoot->mRight->mRight->mRight->mLeft);
    destoryTree(&pMirror);

    pRoot = construct(preOrder3, inOrder3, ARRAY_LEN(preOrder3));
    pMirror = mirror(pRoot, false);
    EXPECT_EQ(1, pMirror->mValue);
    EXPECT_EQ(2, pMirror->mRight->mValue);
    EXPECT_EQ(NULL, pMirror->mRight->mLeft);
    EXPECT_EQ(4, pMirror->mRight->mRight->mValue);
    EXPECT_EQ(NULL, pMirror->mRight->mRight->mRight);
    EXPECT_EQ(7, pMirror->mRight->mRight->mLeft->mValue);
    EXPECT_EQ(NULL, pMirror->mRight->mRight->mLeft->mRight);
    EXPECT_EQ(NULL, pMirror->mRight->mRight->mLeft->mLeft);
    EXPECT_EQ(3, pMirror->mLeft->mValue);
    EXPECT_EQ(5, pMirror->mLeft->mRight->mValue);
    EXPECT_EQ(NULL, pMirror->mLeft->mRight->mRight);
    EXPECT_EQ(NULL, pMirror->mLeft->mRight->mLeft);
    EXPECT_EQ(6, pMirror->mLeft->mLeft->mValue);
    EXPECT_EQ(NULL, pMirror->mLeft->mLeft->mLeft);
    EXPECT_EQ(8, pMirror->mLeft->mLeft->mRight->mValue);
    EXPECT_EQ(NULL, pMirror->mLeft->mLeft->mRight->mRight);
    EXPECT_EQ(NULL, pMirror->mLeft->mLeft->mRight->mLeft);
    destoryTree(&pMirror);
}

TEST(mytreetest, isPostOrderOfBST) {
    EXPECT_FALSE(isPostOrderOfBST(NULL, 0));

    int postOrder51[] = { 1 };
    EXPECT_TRUE(isPostOrderOfBST(postOrder51, ARRAY_LEN(postOrder51)));

    int postOrder52[] = { 1, 2 };
    EXPECT_TRUE(isPostOrderOfBST(postOrder52, ARRAY_LEN(postOrder52)));

    int postOrder53[] = { 1, 2, 3 };
    EXPECT_TRUE(isPostOrderOfBST(postOrder53, ARRAY_LEN(postOrder53)));

    int postOrder54[] = { 5, 7, 6, 9, 11, 10, 8 };
    EXPECT_TRUE(isPostOrderOfBST(postOrder54, ARRAY_LEN(postOrder54)));

    int postOrder55[] = { 7, 4, 6, 5 };
    EXPECT_FALSE(isPostOrderOfBST(postOrder55, ARRAY_LEN(postOrder55)));
}

TEST(mytreetest, findPath) {
    std::vector<int> pOut;
    findPath(NULL, 0, &pOut);

    BinaryTreeNode* pRoot = construct(preOrder1, inOrder1,
            ARRAY_LEN(preOrder1));
    findPath(pRoot, 0, &pOut);
    EXPECT_EQ(0, pOut.at(0));
    pOut.clear();
    findPath(pRoot, 1, &pOut);
    EXPECT_EQ(0, pOut.size());
    pOut.clear();
    destoryTree(&pRoot);

    pRoot = construct(preOrder2, inOrder2, ARRAY_LEN(preOrder2));
    findPath(pRoot, 10, &pOut);
    EXPECT_EQ(4, pOut.size());
    EXPECT_EQ(1, pOut.at(0));
    EXPECT_EQ(4, pOut.at(3));
    pOut.clear();
    destoryTree(&pRoot);

    pRoot = construct(preOrder3, inOrder3, ARRAY_LEN(preOrder3));
    findPath(pRoot, 9, &pOut);
    EXPECT_EQ(3, pOut.size());
    EXPECT_EQ(1, pOut.at(0));
    EXPECT_EQ(5, pOut.at(2));
    pOut.clear();
    destoryTree(&pRoot);

    int preOrder41[] = { 1, 2, 4, 7, 3, 5, 9, 6, 8 };
    int inOrder42[] = { 4, 7, 2, 1, 9, 5, 3, 8, 6 };
    pRoot = construct(preOrder41, inOrder42, ARRAY_LEN(preOrder41));
    findPath(pRoot, 18, &pOut);
    EXPECT_EQ(8, pOut.size());
    EXPECT_EQ(1, pOut.at(0));
    EXPECT_EQ(9, pOut.at(3));
    EXPECT_EQ(1, pOut.at(4));
    EXPECT_EQ(8, pOut.at(7));
    pOut.clear();
    destoryTree(&pRoot);
}

TEST(mytreetest, convert) {
    EXPECT_EQ(NULL, convert(NULL));
    int preOrder51[] = { 1 };
    int inOrder52[] = { 1 };
    BinaryTreeNode* pRoot = construct(preOrder51, inOrder52,
            ARRAY_LEN(preOrder51));
    BinaryTreeNode* pList = convert(pRoot);
    EXPECT_EQ(NULL, pList->mLeft);
    EXPECT_EQ(NULL, pList->mRight);
    EXPECT_EQ(1, pList->mValue);
    delete pList;

    int preOrder53[] = { 4, 3, 2, 1 };
    int inOrder54[] = { 1, 2, 3, 4 };
    pRoot = construct(preOrder53, inOrder54, ARRAY_LEN(preOrder53));
    pList = convert(pRoot);
    EXPECT_EQ(NULL, pList->mLeft);
    EXPECT_EQ(1, pList->mValue);
    EXPECT_EQ(2, pList->mRight->mValue);
    EXPECT_EQ(3, pList->mRight->mRight->mValue);
    EXPECT_EQ(4, pList->mRight->mRight->mRight->mValue);
    EXPECT_EQ(NULL, pList->mRight->mRight->mRight->mRight);
    for (BinaryTreeNode* pCur = pList; pCur != NULL;) {
        BinaryTreeNode* pTemp = pCur->mRight;
        delete pCur;
        pCur = pTemp;
    }

    int preOrder55[] = { 1, 2, 3, 4 };
    int inOrder56[] = { 1, 2, 3, 4 };
    pRoot = construct(preOrder55, inOrder56, ARRAY_LEN(preOrder55));
    pList = convert(pRoot);
    EXPECT_EQ(NULL, pList->mLeft);
    EXPECT_EQ(1, pList->mValue);
    EXPECT_EQ(2, pList->mRight->mValue);
    EXPECT_EQ(3, pList->mRight->mRight->mValue);
    EXPECT_EQ(4, pList->mRight->mRight->mRight->mValue);
    EXPECT_EQ(NULL, pList->mRight->mRight->mRight->mRight);
    for (BinaryTreeNode* pCur = pList; pCur != NULL;) {
        BinaryTreeNode* pTemp = pCur->mRight;
        delete pCur;
        pCur = pTemp;
    }

    int preOrder57[] = { 10, 6, 4, 8, 14, 12, 16 };
    int inOrder58[] = { 4, 6, 8, 10, 12, 14, 16 };
    pRoot = construct(preOrder57, inOrder58, ARRAY_LEN(preOrder57));
    pList = convert(pRoot);
    BinaryTreeNode* pCur = pList;
    EXPECT_EQ(NULL, pCur->mLeft);
    for (int i = 0; i < ARRAY_LEN(inOrder58); ++i) {
        EXPECT_EQ(inOrder58[i], pCur->mValue);
        pCur = pCur->mRight;
    }
    EXPECT_EQ(NULL, pCur);
    for (pCur = pList; pCur != NULL;) {
        BinaryTreeNode* pTemp = pCur->mRight;
        delete pCur;
        pCur = pTemp;
    }
}

TEST(mytreetest, depth) {
    BinaryTreeNode* pRoot = construct(preOrder1, inOrder1,
            ARRAY_LEN(preOrder1));
    EXPECT_EQ(1, depth(pRoot));
    destoryTree(&pRoot);

    pRoot = construct(preOrder2, inOrder2, ARRAY_LEN(preOrder2));
    EXPECT_EQ(4, depth(pRoot));
    destoryTree(&pRoot);

    pRoot = construct(preOrder3, inOrder3, ARRAY_LEN(preOrder3));
    EXPECT_EQ(4, depth(pRoot));
    destoryTree(&pRoot);
}

TEST(mytreetest, isBalanced) {
    BinaryTreeNode* pRoot = construct(preOrder1, inOrder1,
            ARRAY_LEN(preOrder1));
    EXPECT_TRUE(isBalanced(pRoot));
    destoryTree(&pRoot);

    pRoot = construct(preOrder2, inOrder2, ARRAY_LEN(preOrder2));
    EXPECT_FALSE(isBalanced(pRoot));
    destoryTree(&pRoot);

    pRoot = construct(preOrder3, inOrder3, ARRAY_LEN(preOrder3));
    EXPECT_FALSE(isBalanced(pRoot));
    destoryTree(&pRoot);

    int preOrder5[] = { 1, 2, 4, 7, 9, 3, 5, 6, 8 };
    int inOrder5[] = { 4, 7, 2, 9, 1, 5, 3, 8, 6 };
    pRoot = construct(preOrder5, inOrder5, ARRAY_LEN(preOrder5));
    EXPECT_TRUE(isBalanced(pRoot));
    destoryTree(&pRoot);
}

TEST(mytreetest, getCommonParentOfBST) {
    EXPECT_EQ(NULL, getCommonParentOfBST(NULL, NULL, NULL));

    BinaryTreeNode* pRoot = construct(preOrder1, inOrder1,
            ARRAY_LEN(preOrder1));
    EXPECT_EQ(pRoot, getCommonParentOfBST(pRoot, pRoot, pRoot));
    destoryTree(&pRoot);

    int preOrder21[] = { 10, 6, 4, 8, 14, 12, 16 };
    int inOrder22[] = { 4, 6, 8, 10, 12, 14, 16 };
    pRoot = construct(preOrder21, inOrder22, ARRAY_LEN(preOrder21));
    EXPECT_EQ(pRoot->mLeft,
            getCommonParentOfBST(pRoot, pRoot->mLeft->mLeft,
                    pRoot->mLeft->mRight));
    destoryTree(&pRoot);

    int preOrder31[] = { 10, 6, 4, 5, 8, 7, 9, 14, 12, 11, 16 };
    int inOrder32[] = { 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16 };
    pRoot = construct(preOrder31, inOrder32, ARRAY_LEN(preOrder31));
    EXPECT_EQ(pRoot,
            getCommonParentOfBST(pRoot, pRoot->mLeft->mLeft,
                    pRoot->mRight->mRight));
    EXPECT_EQ(pRoot->mLeft,
            getCommonParentOfBST(pRoot, pRoot->mLeft->mLeft->mRight,
                    pRoot->mLeft->mRight->mLeft));
    destoryTree(&pRoot);
}

TEST(mytreetest, getCommonParentOfBT) {
    EXPECT_EQ(NULL, getCommonParentOfBT(NULL, NULL, NULL));

    BinaryTreeNode* pRoot = construct(preOrder1, inOrder1,
            ARRAY_LEN(preOrder1));
    EXPECT_EQ(pRoot, getCommonParentOfBT(pRoot, pRoot, pRoot));
    destoryTree(&pRoot);

    pRoot = construct(preOrder2, inOrder2, ARRAY_LEN(preOrder2));
    EXPECT_EQ(pRoot->mLeft,
            getCommonParentOfBT(pRoot, pRoot->mLeft,
                    pRoot->mLeft->mLeft->mLeft));
    destoryTree(&pRoot);

    pRoot = construct(preOrder3, inOrder3, ARRAY_LEN(preOrder3));
    EXPECT_EQ(pRoot,
            getCommonParentOfBT(pRoot, pRoot->mLeft->mLeft,
                    pRoot->mRight->mRight));
    EXPECT_EQ(pRoot->mRight,
            getCommonParentOfBT(pRoot, pRoot->mRight->mLeft,
                    pRoot->mRight->mRight->mLeft));
    destoryTree(&pRoot);
}

TreeNode* getTreeNode(int value) {
    TreeNode* pNew = new TreeNode();
    pNew->mValue = value;
    return pNew;
}

void destoryTree(TreeNode* pNode) {
    for (std::vector<TreeNode*>::iterator iter = pNode->mChild.begin();
            iter != pNode->mChild.end(); ++iter) {
        destoryTree(*iter);
    }
    free(pNode);
}

TEST(mytreetest, getCommonParentOfT) {
    EXPECT_EQ(NULL, getCommonParentOfT(NULL, NULL, NULL));

    TreeNode* pRoot = getTreeNode(1);
    TreeNode* pNode2 = getTreeNode(2);
    TreeNode* pNode3 = getTreeNode(3);
    TreeNode* pNode4 = getTreeNode(4);
    TreeNode* pNode5 = getTreeNode(5);
    TreeNode* pNode6 = getTreeNode(6);
    TreeNode* pNode7 = getTreeNode(7);
    TreeNode* pNode8 = getTreeNode(8);
    TreeNode* pNode9 = getTreeNode(9);
    TreeNode* pNode10 = getTreeNode(10);
    TreeNode* pNode11 = getTreeNode(11);
    TreeNode* pNode12 = getTreeNode(12);
    TreeNode* pNode13 = getTreeNode(13);
    TreeNode* pNode14 = getTreeNode(14);
    TreeNode* pNode15 = getTreeNode(15);
    TreeNode* pNode16 = getTreeNode(16);
    TreeNode* pNode17 = getTreeNode(17);
    TreeNode* pNode18 = getTreeNode(18);
    TreeNode* pNode19 = getTreeNode(19);
    TreeNode* pNode20 = getTreeNode(20);
    EXPECT_EQ(pRoot, getCommonParentOfT(pRoot, pRoot, pRoot));
    pRoot->mChild.push_back(pNode2);
    pRoot->mChild.push_back(pNode3);
    pRoot->mChild.push_back(pNode4);
    pNode2->mChild.push_back(pNode5);
    pNode2->mChild.push_back(pNode6);
    pNode2->mChild.push_back(pNode7);
    pNode2->mChild.push_back(pNode8);
    pNode6->mChild.push_back(pNode16);
    pNode6->mChild.push_back(pNode17);
    pNode7->mChild.push_back(pNode18);
    pNode18->mChild.push_back(pNode19);
    pNode19->mChild.push_back(pNode20);
    pNode3->mChild.push_back(pNode9);
    pNode3->mChild.push_back(pNode10);
    pNode3->mChild.push_back(pNode11);
    pNode9->mChild.push_back(pNode12);
    pNode12->mChild.push_back(pNode13);
    pNode12->mChild.push_back(pNode14);
    pNode12->mChild.push_back(pNode15);
    destoryTree(pRoot);
    std::vector<int> a;
    a.push_back(1
            );
}
