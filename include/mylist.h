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

#endif /* MYLIST_H_ */
