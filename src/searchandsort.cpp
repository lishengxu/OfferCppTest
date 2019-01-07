/*
 * searchandsort.cpp
 *
 *  Created on: Jan 7, 2019
 *      Author: lsx
 */

#include <stdio.h>
#include <algorithm>

bool binarySearch(const int* const array, const int length, const int value) {
    if (array == NULL || length < 1) {
        return false;
    }

    int begin = 0, end = length - 1;

    while (begin <= end) {
        int middle = begin + (end - begin) / 2;
        if (*(array + middle) > value) {
            end = middle - 1;
        } else if (*(array + middle) < value) {
            begin = middle + 1;
        } else {
            return true;
        }
    }
    return false;
}

static int partition(int* array, int begin, int end) {
    int smallIndex = begin - 1;
    for (int index = begin; index < end; ++index) {
        if (*(array + index) < *(array + end)) {
            ++smallIndex;
            if (smallIndex != index) {
                std::swap(*(array + smallIndex), *(array + index));
            }
        }
    }
    ++smallIndex;
    std::swap(*(array + smallIndex), *(array + end));
    return smallIndex;
}

static void quickSort(int* array, const int length, int begin, int end) {
    int position = partition(array, begin, end);
    if (position > begin) {
        quickSort(array, length, begin, position - 1);
    }
    if (position < end) {
        quickSort(array, length, position + 1, end);
    }
}

void quickSort(int* array, const int length) {
    if (array == NULL || length < 1) {
        return;
    }

    quickSort(array, length, 0, length - 1);
}

