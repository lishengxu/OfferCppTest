/*
 * array.h
 *
 *  Created on: Jan 4, 2019
 *      Author: lsx
 */

#ifndef ARRAY_H_
#define ARRAY_H_

/**
 * 在一个沿右下方向递增的二维数组中查找数组中是否存在某个值
 */
bool contain(const int* array, int rowBegin, int rowEnd, int columnBegin,
        int columnEnd, const int rows, const int columns, int number,
        bool isRecursive = true);

/**
 * 合并两个递增的数组，返回合并后的数组指针；maxLen表示desc最大的容量，超过则返回NULL
 */
char* merge(const char* const src, char* const desc, int maxLen);

#endif /* ARRAY_H_ */
