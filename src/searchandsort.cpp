/*
 * searchandsort.cpp
 *
 *  Created on: Jan 7, 2019
 *      Author: lsx
 */

#include <stdio.h>
#include <algorithm>
#include <exception>
#include <stdexcept>

bool binarySearch(const int* const array, const int length, const int value) {
    if (array == NULL || length < 1) {
        return false;
    }

    int begin = 0, end = length - 1;

    while (begin <= end) {
        int middle = begin + ((end - begin) >> 1);
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

static int partition(int* array, int begin, int end, bool increasing = true) {
    int smallIndex = begin - 1;
    for (int index = begin; index < end; ++index) {
        if ((*(array + index) < *(array + end)) == increasing) {
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

static void quickSort(int* array, const int length, int begin, int end,
        bool increasing = true) {
    int position = partition(array, begin, end, increasing);
    if (position > begin) {
        quickSort(array, length, begin, position - 1, increasing);
    }
    if (position < end) {
        quickSort(array, length, position + 1, end, increasing);
    }
}

void quickSort(int* array, const int length, bool increasing/*=true*/) {
    if (array == NULL || length < 1) {
        return;
    }

    quickSort(array, length, 0, length - 1, increasing);
}

static int findMinInOrder(const int* const rotateArray, const int begin,
        const int end) {
    int min = *(rotateArray + begin);
    for (int i = begin; i < end; ++i) {
        if (*(rotateArray + i) < min) {
            min = *(rotateArray + i);
        }
    }
    return min;
}

int findMin(const int* const rotateArray, const int length) {
    if (rotateArray == NULL || length < 1) {
        throw std::runtime_error("invalid input");
    }

    int begin = 0, end = length - 1, middle = begin;
    while (*(rotateArray + begin) >= *(rotateArray + end)) {
        if (end - begin == 1) {
            middle = end;
            break;
        }
        middle = begin + ((end - begin) >> 1);
        if (*(rotateArray + begin) == *(rotateArray + middle)
                && *(rotateArray + middle) == *(rotateArray + end)) {
            return findMinInOrder(rotateArray, begin, end);
        }

        if (*(rotateArray + middle) > *(rotateArray + begin)) {
            begin = middle;
        } else {
            end = middle;
        }
    }

    return *(rotateArray + middle);
}
