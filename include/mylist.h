/*
 * mylist.h
 *
 *  Created on: Jan 5, 2019
 *      Author: lsx
 */

#ifndef MYLIST_H_
#define MYLIST_H_

#include <vector>

struct ListNode {
    int mValue;
    ListNode* mNext;
};

/**
 * 清理链表
 */
void deleteList(ListNode** pHead);

/**
 * 向链表中添加一个节点，返回添加的节点的指针，这样做的好处逻辑上是：
 * 添加一个节点，很大可能是想对这个节点进行操作，所以返回指向该节点的指针比较符合实用性要求
 */
ListNode* addToTail(ListNode** pHead, int value);

/**
 * 删除链表中所有值为value的节点
 */
void removeNode(ListNode** pHead, int value);

/**
 * 打印链表
 * forward=true表示从头向尾打印，false表示从尾向头打印
 * pOut表示支持输出打印的输出
 */
void printList(ListNode** pHead, bool forward = true, std::vector<int>* pOut =
        NULL);

/**
 * 在O(1)的时间复杂度上删除指针toDel指向的节点
 */
void deleteNode(ListNode** pHead, ListNode* toDel);

/**
 * 输出链表的倒数第k个节点
 */
ListNode* getKNodeToTail(ListNode** pHead, const int k);

/**
 * 获取链表中间的节点
 */
ListNode* getMiddleNode(ListNode** pHead);

/**
 * 是否是环形链表
 */
bool isCircleList(ListNode** pHead);

/**
 * 反转链表
 */
ListNode* reverseList(ListNode** pHead);

/**
 * 合并两个递增排序的链表
 */
ListNode* mergeSortedLists(ListNode** pLeft, ListNode** pRight, bool recursive =
        false);

#endif /* MYLIST_H_ */
