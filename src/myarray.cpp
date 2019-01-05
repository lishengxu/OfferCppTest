/*
 * array.cpp
 *
 *  Created on: Jan 4, 2019
 *      Author: lsx
 */

#include <stdio.h>
#include <string.h>

static bool containRecursive(const int* array, int rowBegin, int rowEnd,
        int columnBegin, int columnEnd, const int rows, const int columns,
        int number) {
    if (array == NULL || rowBegin < 0 || columnBegin < 0 || rows <= 0
            || columns <= 0 || rowBegin > rowEnd || columnBegin > columnEnd
            || rowEnd >= rows || columnEnd > columns
            || (rowEnd - rowBegin >= rows)
            || (columnEnd - columnBegin >= columns)) {
        return false;
    }

    int value = array[rowBegin * columns + columnEnd];
    if (value > number) {
        return containRecursive(array, rowBegin, rowEnd, columnBegin,
                columnEnd - 1, rows, columns, number);
    } else if (value < number) {
        return containRecursive(array, rowBegin + 1, rowEnd, columnBegin,
                columnEnd, rows, columns, number);
    }
    return true;
}

static bool containNonRecursive(const int* array, int rowBegin, int rowEnd,
        int columnBegin, int columnEnd, const int rows, const int columns,
        int number) {
    if (array == NULL || rowBegin < 0 || columnBegin < 0 || rows <= 0
            || columns <= 0 || rowBegin > rowEnd || columnBegin > columnEnd
            || rowEnd >= rows || columnEnd > columns
            || (rowEnd - rowBegin >= rows)
            || (columnEnd - columnBegin >= columns)) {
        return false;
    }
    int curRow = rowBegin, curColumn = columnEnd;
    while (curRow <= rowEnd && curColumn >= columnBegin) {
        int value = array[curRow * columns + curColumn];
        if (value == number) {
            return true;
        }
        value > number ? --curColumn : ++curRow;
    }

    return false;
}

bool contain(const int* array, int rowBegin, int rowEnd, int columnBegin,
        int columnEnd, const int rows, const int columns, int number,
        bool isRecursive) {
    return isRecursive ?
            containRecursive(array, rowBegin, rowEnd, columnBegin, columnEnd,
                    rows, columns, number) :
            containNonRecursive(array, rowBegin, rowEnd, columnBegin, columnEnd,
                    rows, columns, number);
}

char* merge(const char* const src, char* const desc, int maxLen) {
    if (src == NULL || desc == NULL) {
        return NULL;
    }

    int srcLen = strlen(src), descLen = strlen(desc);
    if (srcLen + descLen > maxLen) {
        return NULL;
    }

    int srcIndex = srcLen - 1, descIndex1 = descLen - 1, descIndex2 = srcLen
            + descLen - 1;
    while (descIndex1 < descIndex2) {
        if (*(desc + descIndex1) < *(src + srcIndex)) {
            *(desc + descIndex2) = *(src + srcIndex);
            --srcIndex;
        } else {
            *(desc + descIndex2) = *(desc + descIndex1);
            --descIndex1;
        }
        --descIndex2;
    }

    return desc;
}
