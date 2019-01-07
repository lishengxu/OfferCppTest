/*
 * searchandsort.h
 *
 *  Created on: Jan 7, 2019
 *      Author: lsx
 */

#ifndef SEARCHANDSORT_H_
#define SEARCHANDSORT_H_

/**
 * 递增数组二分查找
 */
bool binarySearch(const int* const array, const int length, const int value);

/**
 * 快速排序
 */
void quickSort(int* array, const int length);

#endif /* SEARCHANDSORT_H_ */
