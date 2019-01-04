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

#endif /* ARRAY_H_ */
