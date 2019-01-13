/*
 * mytree.cpp
 *
 *  Created on: Jan 6, 2019
 *      Author: lsx
 */

#include <stdio.h>
#include <exception>
#include <stdexcept>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include "mytree.h"

BinaryTreeNode* construct(const int* const preOrder, const int* const inOrder,
        const int length) {
    if (preOrder == NULL || inOrder == NULL || length <= 0) {
        return NULL;
    }

    BinaryTreeNode* pNode = new BinaryTreeNode();
    int rootValue = preOrder[0];
    pNode->mValue = rootValue;

    int index = 0;
    while (index < length) {
        if (*(inOrder + index) == rootValue) {
            break;
        }
        ++index;
    }
    if (index >= length) {
        std::string error;
        error.append("Invalid input: the inOrder can not find ");
        std::stringstream ss;
        ss << rootValue;
        error.append(ss.str());
        throw std::logic_error(error.c_str());
    }

    pNode->mLeft = construct(preOrder + 1, inOrder, index);
    pNode->mRight = construct(preOrder + index + 1, inOrder + index + 1,
            length - index - 1);
    return pNode;
}

static void destoryTree(BinaryTreeNode* pNode) {
    if (pNode == NULL) {
        return;
    }
    BinaryTreeNode* pDel = pNode;
    destoryTree(pNode->mLeft);
    destoryTree(pNode->mRight);
    delete pDel;
    pDel = NULL;
}

void destoryTree(BinaryTreeNode** pRoot) {
    if (pRoot == NULL) {
        return;
    }
    destoryTree(*pRoot);
    *pRoot = NULL;
}

static void preOrderRecursive(BinaryTreeNode* pNode, std::vector<int>* pOut =
NULL) {
    if (pNode == NULL) {
        return;
    }
    printf("%d\n", pNode->mValue);
    if (pOut != NULL) {
        pOut->push_back(pNode->mValue);
    }
    preOrderRecursive(pNode->mLeft, pOut);
    preOrderRecursive(pNode->mRight, pOut);
}

static void preOrderNonRecursive(BinaryTreeNode* pNode, std::vector<int>* pOut =
NULL) {
    if (pNode == NULL) {
        return;
    }
    std::stack<BinaryTreeNode*> stack;
    stack.push(pNode);

    while (!stack.empty()) {
        BinaryTreeNode* pCur = stack.top();
        stack.pop();
        printf("%d\n", pCur->mValue);
        if (pOut != NULL) {
            pOut->push_back(pCur->mValue);
        }
        if (pCur->mRight != NULL) {
            stack.push(pCur->mRight);
        }
        if (pCur->mLeft != NULL) {
            stack.push(pCur->mLeft);
        }
    }
}

void preOrder(BinaryTreeNode* pRoot, bool recursive/*=true*/,
        std::vector<int>* pOut/*=NULL*/) {
    recursive ?
            preOrderRecursive(pRoot, pOut) : preOrderNonRecursive(pRoot, pOut);
}

void inOrderRecursive(BinaryTreeNode* pNode, std::vector<int>* pOut = NULL) {
    if (pNode == NULL) {
        return;
    }
    BinaryTreeNode* pCur = pNode;
    inOrderRecursive(pCur->mLeft, pOut);
    printf("%d\n", pCur->mValue);
    if (pOut != NULL) {
        pOut->push_back(pCur->mValue);
    }
    inOrderRecursive(pCur->mRight, pOut);
}

void inOrderNonRecursive(BinaryTreeNode* pNode, std::vector<int>* pOut = NULL) {
    if (pNode == NULL) {
        return;
    }
    std::stack<BinaryTreeNode*> stack;
    BinaryTreeNode* pCur = pNode;
    while (pCur != NULL || !stack.empty()) {
        if (pCur != NULL) {
            stack.push(pCur);
            pCur = pCur->mLeft;
        } else {
            pCur = stack.top();
            stack.pop();
            printf("%d\n", pCur->mValue);
            if (pOut != NULL) {
                pOut->push_back(pCur->mValue);
            }
            pCur = pCur->mRight;
        }
    }
}

void inOrder(BinaryTreeNode* pRoot, bool recursive/*=true*/,
        std::vector<int>* pOut/*=NULL*/) {
    recursive ?
            inOrderRecursive(pRoot, pOut) : inOrderNonRecursive(pRoot, pOut);
}

void postOrderRecursive(BinaryTreeNode* pNode, std::vector<int>* pOut = NULL) {
    if (pNode == NULL) {
        return;
    }
    BinaryTreeNode* pCur = pNode;
    postOrderRecursive(pCur->mLeft, pOut);
    postOrderRecursive(pCur->mRight, pOut);
    printf("%d\n", pCur->mValue);
    if (pOut != NULL) {
        pOut->push_back(pCur->mValue);
    }
}

void postOrderNonRecursive(BinaryTreeNode* pNode,
        std::vector<int>* pOut = NULL) {
    if (pNode == NULL) {
        return;
    }
    std::stack<BinaryTreeNode*> stack;
    BinaryTreeNode* pPre = pNode;
    BinaryTreeNode* pCur = pNode;
    stack.push(pNode);
    while (!stack.empty()) {
        pCur = stack.top();
        if ((pCur->mLeft == NULL && pCur->mRight == NULL)
                || (pCur->mRight == NULL && pCur->mLeft == pPre)
                || (pCur->mRight == pPre)) {
            printf("%d\n", pCur->mValue);
            if (pOut != NULL) {
                pOut->push_back(pCur->mValue);
            }
            pPre = pCur;
            stack.pop();
        } else {
            if (pCur->mRight != NULL) {
                stack.push(pCur->mRight);
            }
            if (pCur->mLeft != NULL) {
                stack.push(pCur->mLeft);
            }
        }
    }
}

void postOrder(BinaryTreeNode* pRoot, bool recursive/*=true*/,
        std::vector<int>* pOut/*=NULL*/) {
    recursive ?
            postOrderRecursive(pRoot, pOut) :
            postOrderNonRecursive(pRoot, pOut);
}

void levelOrder(BinaryTreeNode* pRoot, std::vector<int>* pOut/*=NULL*/) {
    if (pRoot == NULL) {
        return;
    }

    std::queue<BinaryTreeNode*> queue;
    queue.push(pRoot);

    while (!queue.empty()) {
        BinaryTreeNode* pCur = queue.front();
        queue.pop();
        printf("%d\n", pCur->mValue);
        if (pOut != NULL) {
            pOut->push_back(pCur->mValue);
        }
        if (pCur->mLeft != NULL) {
            queue.push(pCur->mLeft);
        }
        if (pCur->mRight != NULL) {
            queue.push(pCur->mRight);
        }
    }
}

bool isChildTree(BinaryTreeNode* pRoot, BinaryTreeNode* pChildRoot) {
    if (pChildRoot == NULL) {
        return true;
    }
    if (pRoot == NULL) {
        return false;
    }
    if (pRoot->mValue == pChildRoot->mValue) {
        return isChildTree(pRoot->mLeft, pChildRoot->mLeft)
                && isChildTree(pRoot->mRight, pChildRoot->mRight);
    }
    return false;
}

bool hasChildTree(BinaryTreeNode* pRoot, BinaryTreeNode* pChildRoot) {
    if (pRoot == NULL || pChildRoot == NULL) {
        return false;
    }

    if (pRoot->mValue == pChildRoot->mValue) {
        return isChildTree(pRoot->mLeft, pChildRoot->mLeft)
                && isChildTree(pRoot->mRight, pChildRoot->mRight);
    }
    return hasChildTree(pRoot->mLeft, pChildRoot)
            || hasChildTree(pRoot->mRight, pChildRoot);
}

BinaryTreeNode* mirrorRecursive(BinaryTreeNode* pRoot) {
    if (pRoot == NULL) {
        return NULL;
    }

    BinaryTreeNode* temp = pRoot->mLeft;
    pRoot->mLeft = mirror(pRoot->mRight);
    pRoot->mRight = mirror(temp);
    return pRoot;
}

BinaryTreeNode* mirrorNonRecursive(BinaryTreeNode* pRoot) {
    if (pRoot == NULL) {
        return NULL;
    }
    std::stack<BinaryTreeNode*> stack;
    stack.push(pRoot);
    while (!stack.empty()) {
        BinaryTreeNode* pCur = stack.top();
        stack.pop();
        BinaryTreeNode* pTemp = pCur->mLeft;
        pCur->mLeft = pCur->mRight;
        pCur->mRight = pTemp;
        if (pCur->mRight != NULL) {
            stack.push(pCur->mRight);
        }

        if (pCur->mLeft != NULL) {
            stack.push(pCur->mLeft);
        }
    }
    return pRoot;
}

BinaryTreeNode* mirror(BinaryTreeNode* pRoot, bool recursive) {
    return recursive ? mirrorRecursive(pRoot) : mirrorNonRecursive(pRoot);
}

static bool isPostOrderOfBSTRecursive(const int* begin, const int* end) {
    if (begin == end) {
        return true;
    }
    const int* index = begin;
    while (index < end) {
        if (*index > *end) {
            break;
        }
        ++index;
    }
    const int* rightBegin = index;
    while (index < end) {
        if (*index < *end) {
            break;
        }
        ++index;
    }
    if (index < end) {
        return false;
    }
    bool leftIsOk = true;
    if (begin < rightBegin) {
        leftIsOk = isPostOrderOfBSTRecursive(begin, rightBegin - 1);
    }
    bool rightIsOk = true;
    if (rightBegin < end) {
        rightIsOk = isPostOrderOfBSTRecursive(rightBegin, end - 1);
    }
    return leftIsOk && rightIsOk;
}

bool isPostOrderOfBST(const int* const array, const int length) {
    if (array == NULL || length < 1) {
        return false;
    }

    return isPostOrderOfBSTRecursive(array, array + length - 1);
}

static void findPathRecursive(BinaryTreeNode* pNote, const int sum,
        std::vector<int>* stackVector, int pathSum, std::vector<int>* pOut =
        NULL) {
    stackVector->push_back(pNote->mValue);
    pathSum += pNote->mValue;
    if (pNote->mLeft == NULL && pNote->mRight == NULL) {
        if (pathSum == sum) {
            for (unsigned int i = 0; i < stackVector->size(); ++i) {
                printf("%d\n", stackVector->at(i));
                if (pOut != NULL) {
                    pOut->push_back(stackVector->at(i));
                }
            }
        }
    } else {
        if (pNote->mLeft != NULL) {
            findPathRecursive(pNote->mLeft, sum, stackVector, pathSum, pOut);
        }
        if (pNote->mRight != NULL) {
            findPathRecursive(pNote->mRight, sum, stackVector, pathSum, pOut);
        }
    }
    stackVector->pop_back();
    pathSum -= pNote->mValue;
}

void findPath(BinaryTreeNode* pRoot, const int sum,
        std::vector<int>* pOut/*= NULL*/) {
    if (pRoot == NULL) {
        return;
    }
    std::vector<int> stackVector;
    int pathSum = 0;
    findPathRecursive(pRoot, sum, &stackVector, pathSum, pOut);
}

static void convertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLast) {
    if (pNode == NULL) {
        return;
    }
    if (pNode->mLeft != NULL) {
        convertNode(pNode->mLeft, pLast);
    }
    pNode->mLeft = *pLast;
    if (*pLast != NULL) {
        (*pLast)->mRight = pNode;
    }
    *pLast = pNode;
    if (pNode->mRight != NULL) {
        convertNode(pNode->mRight, pLast);
    }
}

BinaryTreeNode* convert(BinaryTreeNode* pRoot) {
    BinaryTreeNode* pLast = NULL;
    convertNode(pRoot, &pLast);
    BinaryTreeNode* pList = pRoot;
    while (pList != NULL && pList->mLeft != NULL) {
        pList = pList->mLeft;
    }
    return pList;
}

