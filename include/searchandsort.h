/*
 * searchandsort.h
 *
 *  Created on: Jan 7, 2019
 *      Author: lsx
 */

#ifndef SEARCHANDSORT_H_
#define SEARCHANDSORT_H_

#include <string>

/**
 * 递增数组二分查找
 */
bool binarySearch(const int* const array, const int length, const int value);

/**
 * 快速排序
 */
void quickSort(int* array, const int length, bool increasing = true);

/**
 * 发现旋转数组中的最小值
 */
int findMin(const int* const rotateArray, const int length);

/**
 * 将数组中奇数放在前面，偶数放在后面
 */
void reOrderOddEven(int* const array, const int length, bool flag = true);

/**
 * 数组中出现次数超过一半的数字
 */
int moreThanHalfNum(int* array, const int length, bool change = false);

/**
 * 获取最小的k个数字
 */
void findLeastNumbers(int* array, const int length, const int k, bool change =
        false, std::vector<int>* pOut = NULL);

/**
 * 和做大公共子序列
 */
int findMaxSumOfSubArray(const int* array, const int length);

/**
 * 输出数组中数字能排列的最小的数字组合
 */
void printMinNumber(const int* array, const unsigned int length,
        std::string& out);

/**
 * 获取数组中逆序对数量
 */
int getInversePairs(int* array, const int length);

#endif /* SEARCHANDSORT_H_ */
