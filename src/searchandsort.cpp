/*
 * searchandsort.cpp
 *
 *  Created on: Jan 7, 2019
 *      Author: lsx
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <vector>
#include <set>

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

static void reOrder(int* const array, const int length, bool (*rule)(int)) {
    int *pBegin = array;
    int *pEnd = array + length - 1;
    while (pBegin < pEnd) {
        while (pBegin < pEnd && rule(*pBegin)) {
            ++pBegin;
        }
        while (pBegin < pEnd && !rule(*pEnd)) {
            --pEnd;
        }
        if (pBegin < pEnd) {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
            ++pBegin, --pEnd;
        }
    }
}

static bool isOdd(int value) {
    return value & 0x01;
}

static bool isEven(int value) {
    return !(value & 0x01);
}

void reOrderOddEven(int* const array, const int length, bool flag) {
    if (array == NULL || length < 1) {
        return;
    }
    reOrder(array, length, flag ? isOdd : isEven);
}

static int moreThanHalfNumChange(int* array, const int length) {
    if (array == NULL || length < 1) {
        throw std::invalid_argument("invalid input");
    }

    int middle = length >> 1;
    int begin = 0, end = length - 1;
    int index = partition(array, begin, end, true);
    while (index != middle) {
        if (index < middle) {
            begin = index + 1;
            index = partition(array, begin, end, true);
        } else {
            end = index - 1;
            index = partition(array, begin, end, true);
        }
    }
    int result = array[middle];
    int count = 0;
    for (int i = 0; i < length; ++i) {
        if (array[i] == result) {
            ++count;
        }
    }
    if (count * 2 <= length) {
        throw std::invalid_argument("invalid input");
    }
    return result;
}

static int moreThanHalfNumNonChange(const int* array, const int length) {
    if (array == NULL || length < 1) {
        throw std::invalid_argument("invalid input");
    }

    int number = array[0], times = 1;
    for (int i = 1; i < length; ++i) {
        if (times == 0) {
            number = array[i];
        }
        if (array[i] == number) {
            ++times;
        } else {
            --times;
        }
    }
    int count = 0;
    for (int i = 0; i < length; ++i) {
        if (array[i] == number) {
            ++count;
        }
    }
    if (count * 2 <= length) {
        throw std::invalid_argument("invalid input");
    }
    return number;
}

int moreThanHalfNum(int* array, const int length, bool change) {
    return change ?
            moreThanHalfNumChange(array, length) :
            moreThanHalfNumNonChange(array, length);
}

static void findLeastNumbersChange(int* array, const int length, const int k,
        std::vector<int>* pOut = NULL) {
    if (array == NULL || length < k) {
        return;
    }
    int begin = 0, end = length - 1;
    int index = partition(array, begin, end);
    while (index != k - 1) {
        if (index < k - 1) {
            begin = index + 1;
            index = partition(array, begin, end);
        } else {
            end = index - 1;
            index = partition(array, begin, end);
        }
    }

    for (int i = 0; i < k; ++i) {
        pOut->push_back(array[i]);
    }
}

static void findLeastNumbersNonChange(const int* array, const int length,
        const int k, std::vector<int>* pOut = NULL) {
    if (array == NULL || length < k) {
        return;
    }

    std::multiset<int, std::greater<int> > set;
    for (int i = 0; i < length; ++i) {
        if (set.size() < (unsigned int) k) {
            set.insert(array[i]);
        } else if (*set.begin() > array[i]) {
            set.erase(set.begin());
            set.insert(array[i]);
        }
    }
    for (std::multiset<int, std::greater<int> >::iterator iter = set.begin();
            iter != set.end(); ++iter) {
        pOut->push_back(*iter);
    }
}

void findLeastNumbers(int* array, const int length, const int k, bool change,
        std::vector<int>* pOut) {
    return change ?
            findLeastNumbersChange(array, length, k, pOut) :
            findLeastNumbersNonChange(array, length, k, pOut);
}

int findMaxSumOfSubArray(const int* array, const int length) {
    if (array == NULL || length < 1) {
        throw std::invalid_argument("invalid input");
    }

    int maxSum = 0, curMaxSum = 0;
    for (int i = 0; i < length; ++i) {
        curMaxSum += array[i];
        if (curMaxSum > maxSum) {
            maxSum = curMaxSum;
        }
        if (curMaxSum < 0) {
            curMaxSum = 0;
        }
    }
    return maxSum;
}

static const int sMaxIntLength = 10;
static char sCompare1[sMaxIntLength * 2 + 1];
static char sCompare2[sMaxIntLength * 2 + 1];

static int compare(const void* left, const void* right) {
    strcpy(sCompare1, *(const char**) left);
    strcat(sCompare1, *(const char**) right);
    strcpy(sCompare2, *(const char**) right);
    strcat(sCompare2, *(const char**) left);

    return strcmp(sCompare1, sCompare2);
}

void printMinNumber(const int* array, const unsigned int length,
        std::string& out) {
    if (array == NULL || length < 1) {
        return;
    }

    char** strNumbers = (char**) calloc(length, sizeof(char*));
    for (unsigned int i = 0; i < length; ++i) {
        strNumbers[i] = (char*) calloc(sMaxIntLength + 1, sizeof(char));
        snprintf(strNumbers[i], sMaxIntLength, "%d", array[i]);
    }

    qsort(strNumbers, length, sizeof(char*), compare);

    for (unsigned int i = 0; i < length; ++i) {
        printf("%s", strNumbers[i]);
        out += strNumbers[i];
        free(strNumbers[i]);
    }
    printf("\n");
    free(strNumbers);
}

static int getInversePairs(int* array, int* copy, int begin, int end) {
    if (begin == end) {
        copy[begin] = array[begin];
        return 0;
    }
    int middle = begin + ((end - begin) >> 1);
    int leftCount = getInversePairs(copy, array, begin, middle);
    int rightCount = getInversePairs(copy, array, middle + 1, end);

    int leftIndex = middle, rightIndex = end, copyIndex = end;
    int count = 0;
    while (leftIndex >= begin && rightIndex >= middle + 1) {
        if (array[leftIndex] > array[rightIndex]) {
            copy[copyIndex--] = array[leftIndex--];
            count += rightIndex - middle;
        } else {
            copy[copyIndex--] = array[rightIndex--];
        }
    }

    while (leftIndex >= begin) {
        copy[copyIndex--] = array[leftIndex--];
    }
    while (rightIndex >= middle + 1) {
        copy[copyIndex--] = array[rightIndex--];
    }

    return leftCount + rightCount + count;
}

int getInversePairs(int* array, const unsigned int length) {
    if (array == NULL || length < 1) {
        return 0;
    }

    int copy[length];
    for (unsigned int i = 0; i < length; ++i) {
        copy[i] = array[i];
    }

    return getInversePairs(array, copy, 0, length - 1);
}

static int firstIndexOfK(const int* const array, int begin, int end,
        const int k) {
    if (array == NULL || begin > end) {
        return -1;
    }
    int index = -1;
    while (begin <= end) {
        int middle = begin + ((end - begin) >> 1);
        if (array[middle] == k) {
            if ((middle > 0 && array[middle - 1] != k) || middle == 0) {
                index = middle;
                break;
            } else {
                end = middle - 1;
            }
        } else if (array[middle] < k) {
            begin = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    return index;
}

static int lastIndexOfK(const int* const array, int begin, int end,
        const int k) {
    if (array == NULL || begin > end) {
        return -1;
    }
    int index = -1;
    while (begin <= end) {
        int middle = begin + ((end - begin) >> 1);
        if (array[middle] == k) {
            if ((middle < end && array[middle + 1] != k) || middle == end) {
                index = middle;
                break;
            } else {
                begin = middle + 1;
            }
        } else if (array[middle] < k) {
            begin = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    return index;
}

int countOfK(const int* const array, const int length, const int k) {
    if (array == NULL || length < 1) {
        return 0;
    }

    int first = firstIndexOfK(array, 0, length - 1, k);
    int last = lastIndexOfK(array, 0, length - 1, k);
    if (first != -1 && last != -1) {
        return last - first + 1;
    }
    return 0;
}

