/*
 * mylist.cpp
 *
 *  Created on: Jan 5, 2019
 *      Author: lsx
 */

#include <stdio.h>
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
        pDel = NULL;
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



