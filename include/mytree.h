/*
 * mytree.h
 *
 *  Created on: Jan 6, 2019
 *      Author: lsx
 */

#ifndef MYTREE_H_
#define MYTREE_H_

#include <stdio.h>
#include <vector>

struct BinaryTreeNode {
    int mValue;
    BinaryTreeNode* mLeft;
    BinaryTreeNode* mRight;
};

/**
 * 使用前序遍历数组和中序遍历数组构建二叉树
 */
BinaryTreeNode* construct(const int* const preOrder, const int* const inOrder,
        const int length);

/**
 * 销毁二叉树
 */
void destoryTree(BinaryTreeNode** pRoot);

/**
 * 前序遍历二叉树
 */
void preOrder(BinaryTreeNode* pRoot, bool recursive = true,
        std::vector<int>* pOut = NULL);

/**
 * 中序遍历二叉树
 */
void inOrder(BinaryTreeNode* pRoot, bool recursive = true,
        std::vector<int>* pOut = NULL);

/**
 * 后序遍历二叉树
 */
void postOrder(BinaryTreeNode* pRoot, bool recursive = true,
        std::vector<int>* pOut = NULL);

/**
 * 广度优先遍历
 */
void levelOrder(BinaryTreeNode* pRoot, std::vector<int>* pOut = NULL);

/**
 * 判断一颗二叉树是不是另外一颗二叉树的子结构
 */
bool hasChildTree(BinaryTreeNode* pRoot, BinaryTreeNode* pChildRoot);

/**
 * 输出一个二叉树的镜像
 */
BinaryTreeNode* mirror(BinaryTreeNode* pRoot, bool recursive = true);

#endif /* MYTREE_H_ */

