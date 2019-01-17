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

struct TreeNode {
    int mValue;
    std::vector<TreeNode*> mChild;
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

/**
 * 判断某个数组是不是二叉搜索树的后序遍历序列
 */
bool isPostOrderOfBST(const int* const array, const int length);

/**
 * 打印出二叉树中所有和为某值的路径
 */
void findPath(BinaryTreeNode* pRoot, const int sum, std::vector<int>* pOut =
NULL);

/**
 * 将二叉搜索树转换成双向链表
 */
BinaryTreeNode* convert(BinaryTreeNode* pRoot);

/**
 * 获取二叉树的深度
 */
int depth(BinaryTreeNode* pRoot);

/**
 * 判断二叉树是否是平衡二叉树
 */
bool isBalanced(BinaryTreeNode* pRoot);

/**
 * 获取树中节点的共同祖先
 */
BinaryTreeNode* getCommonParentOfBST(BinaryTreeNode* pRoot,
        BinaryTreeNode* pNode1, BinaryTreeNode* pNode2);

BinaryTreeNode* getCommonParentOfBT(BinaryTreeNode* pRoot,
        BinaryTreeNode* pNode1, BinaryTreeNode* pNode2);

TreeNode* getCommonParentOfT(TreeNode* pRoot, TreeNode* pNode1,
        TreeNode* pNode2);

#endif /* MYTREE_H_ */

