/*
 * mylist.cpp
 *
 *  Created on: Jan 5, 2019
 *      Author: lsx
 */

#include <stdio.h>
#include <stack>
#include <exception>
#include <stdexcept>
#include "mylist.h"

void deleteList(ListNode** pHead) {
    if (pHead == NULL) {
        return;
    }
    ListNode* pCur = *pHead;
    while (pCur != NULL) {
        *pHead = pCur->mNext;
        delete pCur;
        pCur = *pHead;
    }
}

ListNode* addToTail(ListNode** pHead, int value) {
    if (pHead == NULL) {
        return NULL;
    }

    ListNode* pNode = new ListNode();
    pNode->mValue = value;
    pNode->mNext = NULL;

    if (*pHead == NULL) {
        *pHead = pNode;
    } else {
        ListNode* pCur = *pHead;
        while (pCur->mNext != NULL) {
            pCur = pCur->mNext;
        }
        pCur->mNext = pNode;
    }

    return pNode;
}

void removeNode(ListNode** pHead, int value) {
    if (pHead == NULL) {
        return;
    }

    while (*pHead != NULL && (*pHead)->mValue == value) {
        ListNode* pDel = *pHead;
        *pHead = (*pHead)->mNext;
        delete pDel;
    }

    if (*pHead != NULL) {
        ListNode* pPre = *pHead;
        ListNode* pCur = (*pHead)->mNext;
        while (pCur != NULL) {
            if (pCur->mValue == value) {
                pPre->mNext = pCur->mNext;
                delete pCur;
                pCur = pPre->mNext;
            } else {
                pPre = pCur;
                pCur = pCur->mNext;
            }
        }
    }
}

static void printListReverseRecursive(ListNode* node, std::vector<int>* pOut) {
    if (node != NULL) {
        printListReverseRecursive(node->mNext, pOut);
        printf("%d\n", node->mValue);
        if (pOut != NULL) {
            pOut->push_back(node->mValue);
        }
    }
}

static void printListReverseNonRecursive(ListNode* node,
        std::vector<int>* pOut) {
    ListNode* pCur = node;
    std::stack<ListNode*> nodes;
    while (pCur != NULL) {
        nodes.push(pCur);
        pCur = pCur->mNext;
    }

    while (!nodes.empty()) {
        pCur = nodes.top();
        nodes.pop();
        printf("%d\n", pCur->mValue);
        if (pOut != NULL) {
            pOut->push_back(pCur->mValue);
        }
    }
}

static void printListReverse(ListNode* node, std::vector<int>* pOut,
        bool recursive = true) {
    if (recursive) {
        printListReverseRecursive(node, pOut);
    } else {
        printListReverseNonRecursive(node, pOut);
    }
}

void printList(ListNode** pHead, bool forward/*=true*/,
        std::vector<int>* pOut/*=NULL*/) {
    if (pHead == NULL) {
        return;
    }

    if (forward) {
        ListNode* pCur = *pHead;
        while (pCur != NULL) {
            printf("%d\n", pCur->mValue);
            if (pOut != NULL) {
                pOut->push_back(pCur->mValue);
            }
            pCur = pCur->mNext;
        }
    } else {
        printListReverse(*pHead, pOut, false);
    }
}

void deleteNode(ListNode** pHead, ListNode* pToDel) {
    if (pHead == NULL || pToDel == NULL) {
        return;
    }

    if (*pHead == pToDel) {
        *pHead = pToDel->mNext;
        delete pToDel;
        pToDel = NULL;
    } else if (pToDel->mNext == NULL) {
        ListNode* pCur = *pHead;
        while (pCur->mNext != NULL && pCur->mNext != pToDel) {
            pCur = pCur->mNext;
        }

        if (pCur->mNext == NULL) {
            throw std::invalid_argument("toDel is not a node in list");
        } else {
            pCur->mNext = pToDel->mNext;
            delete pToDel;
            pToDel = NULL;
        }
    } else {
        ListNode* pTemp = pToDel->mNext;
        pToDel->mValue = pTemp->mValue;
        pToDel->mNext = pTemp->mNext;
        delete pTemp;
    }
}

ListNode* getKNodeToTail(ListNode** pHead, const int k) {
    if (pHead == NULL || k < 1) {
        return NULL;
    }

    int countOfNode = 0;
    ListNode* pNextK = *pHead;
    while (pNextK != NULL && countOfNode < k) {
        pNextK = pNextK->mNext;
        ++countOfNode;
    }
    if (countOfNode < k) {
        return NULL;
    }

    ListNode* pCur = *pHead;
    while (pNextK != NULL) {
        pNextK = pNextK->mNext;
        pCur = pCur->mNext;

    }

    return pCur;
}

ListNode* getMiddleNode(ListNode** pHead) {
    if (pHead == NULL) {
        return NULL;
    }

    ListNode* pCur = *pHead;
    ListNode* pMiddle = *pHead;

    while (pCur != NULL && pCur->mNext != NULL) {
        pCur = pCur->mNext->mNext;
        pMiddle = pMiddle->mNext;
    }

    return pMiddle;
}

bool isCircleList(ListNode** pHead) {
    if (pHead == NULL) {
        return false;
    }

    ListNode* pFirst = *pHead;
    ListNode* pSecond = *pHead;
    while (pFirst != NULL && pFirst->mNext != NULL) {
        pFirst = pFirst->mNext->mNext;
        pSecond = pSecond->mNext;
        if (pFirst == pSecond) {
            return true;
        }
    }

    return false;
}

ListNode* reverseList(ListNode** pHead) {
    if (pHead == NULL) {
        return NULL;
    }
    ListNode* pPrev = NULL;
    ListNode* pCur = *pHead;
    ListNode* pNext = NULL;
    while (pCur != NULL) {
        pNext = pCur->mNext;
        pCur->mNext = pPrev;
        pPrev = pCur;
        pCur = pNext;
    }
    *pHead = pPrev;
    return pPrev;
}

static ListNode* mergeSortedListsNonRecursive(ListNode* pLeftHead,
        ListNode* pRightHead) {
    ListNode* pLeft = pLeftHead;
    ListNode* pRight = pRightHead;
    ListNode* pNewHead = NULL;
    ListNode* pNew = pNewHead;
    while (pLeft != NULL && pRight != NULL) {
        if (pLeft->mValue < pRight->mValue) {
            if (pNewHead == NULL) {
                pNewHead = pLeft;
                pNew = pLeft;
            } else {
                pNew->mNext = pLeft;
                pNew = pLeft;
            }
            pLeft = pLeft->mNext;
        } else {
            if (pNewHead == NULL) {
                pNewHead = pRight;
                pNew = pRight;
            } else {
                pNew->mNext = pRight;
                pNew = pRight;
            }
            pRight = pRight->mNext;
        }
    }
    if (pLeft != NULL) {
        if (pNewHead == NULL) {
            pNewHead = pLeft;
        } else {
            pNew->mNext = pLeft;
        }
    }
    if (pRight != NULL) {
        if (pNewHead == NULL) {
            pNewHead = pRight;
        } else {
            pNew->mNext = pRight;
        }
    }
    return pNewHead;
}

static ListNode* mergeSortedListsRecursive(ListNode* pLeftHead,
        ListNode* pRightHead) {
    if (pLeftHead == NULL) {
        return pRightHead;
    } else if (pRightHead == NULL) {
        return pLeftHead;
    }

    ListNode* pNewHead = NULL;
    if (pLeftHead->mValue < pRightHead->mValue) {
        pNewHead = pLeftHead;
        pNewHead->mNext = mergeSortedListsRecursive(pLeftHead->mNext,
                pRightHead);
    } else {
        pNewHead = pRightHead;
        pNewHead->mNext = mergeSortedListsRecursive(pLeftHead,
                pRightHead->mNext);

    }
    return pNewHead;
}

ListNode* mergeSortedLists(ListNode** pLeftHead, ListNode** pRightHead,
        bool recursive) {
    if (pLeftHead == NULL || pRightHead == NULL) {
        return NULL;
    }
    return recursive ?
            mergeSortedListsRecursive(*pLeftHead, *pRightHead) :
            mergeSortedListsNonRecursive(*pLeftHead, *pRightHead);
}

static void cloneNodes(ComplexListNode* pHead) {
    ComplexListNode* pCur = pHead;
    while (pCur != NULL) {
        ComplexListNode* pNew = new ComplexListNode();
        pNew->mValue = pCur->mValue;
        pNew->mNext = pCur->mNext;
        pNew->mSibling = NULL;
        pCur->mNext = pNew;
        pCur = pCur->mNext->mNext;
    }
}

static void connectionSiblingNodes(ComplexListNode* pHead) {
    ComplexListNode* pCur = pHead;
    while (pCur != NULL) {
        ComplexListNode* pNew = pCur->mNext;
        if (pCur->mSibling != NULL) {
            pNew->mSibling = pCur->mSibling->mNext;
        }
        pCur = pCur->mNext->mNext;
    }
}

static ComplexListNode* reConnectionNodes(ComplexListNode* pHead) {
    ComplexListNode* pNewHead = NULL;
    ComplexListNode* pNew = NULL;
    ComplexListNode* pCur = pHead;
    if (pCur != NULL) {
        pNewHead = pCur->mNext;
        pNew = pCur->mNext;
        pCur->mNext = pNew->mNext;
        pCur = pCur->mNext;
    }

    while (pCur != NULL) {
        pNew->mNext = pCur->mNext;
        pNew = pCur->mNext;
        pCur->mNext = pNew->mNext;
        pCur = pCur->mNext;
    }
    return pNewHead;
}

ComplexListNode* clone(ComplexListNode* pHead) {
    cloneNodes(pHead);
    connectionSiblingNodes(pHead);
    return reConnectionNodes(pHead);
}

int getListLength(ListNode* pHead) {
    int length = 0;
    ListNode* pCur = pHead;
    while (pCur != NULL) {
        ++length;
        pCur = pCur->mNext;
    }
    return length;
}

ListNode* getFirstCommonNode(ListNode* pLeft, ListNode* pRight) {
    if (pLeft == NULL || pRight == NULL) {
        return NULL;
    }
    int leftLength = getListLength(pLeft);
    int rightLength = getListLength(pRight);
    int diffLength = leftLength - rightLength;
    ListNode* pLongList = pLeft;
    ListNode* pShortList = pRight;
    if (diffLength < 0) {
        pLongList = pRight;
        pShortList = pLeft;
        diffLength = -diffLength;
    }
    while (diffLength > 0) {
        --diffLength;
        pLongList = pLongList->mNext;
    }
    while (pLongList != NULL && pShortList != NULL && pLongList != pShortList) {
        pLongList = pLongList->mNext;
        pShortList = pShortList->mNext;
    }
    if (pLongList != NULL) {
        return pLongList;
    }
    return NULL;
}

