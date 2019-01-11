/*
 * array.cpp
 *
 *  Created on: Jan 4, 2019
 *      Author: lsx
 */

#include <stdio.h>
#include <string.h>
#include <vector>

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

static void printMatrixInCircle(const int* const array, const int start,
        const int rows, const int columns, std::vector<int>* pOut = NULL) {
    int endRow = rows - 1 - start, endColumn = columns - 1 - start;

    for (int i = start; i <= endRow; ++i) {
        printf("%d\n", array[start * rows + i]);
        if (pOut != NULL) {
            pOut->push_back(array[start * rows + i]);
        }
    }
    if (start < endColumn) {
        for (int j = start + 1; j <= endColumn; ++j) {
            printf("%d\n", array[j * rows + endRow]);
            if (pOut != NULL) {
                pOut->push_back(array[j * rows + endRow]);
            }
        }
    }
    if (start < endRow && start < endColumn) {
        for (int i = endRow - 1; i >= start; --i) {
            printf("%d\n", array[endColumn * rows + i]);
            if (pOut != NULL) {
                pOut->push_back(array[endColumn * rows + i]);
            }
        }
    }
    if (start < endRow && start < endColumn - 1) {
        for (int j = endColumn - 1; j > start; --j) {
            printf("%d\n", array[j * rows + start]);
            if (pOut != NULL) {
                pOut->push_back(array[j * rows + start]);
            }
        }
    }
}

void printMatrixClockwisly(const int* const array, const int rows,
        const int columns, std::vector<int>* pOut/*= NULL*/) {
    if (array == NULL || rows < 1 || columns < 1) {
        return;
    }

    for (int start = 0; start + start < rows && start + start < columns;
            ++start) {
        printMatrixInCircle(array, start, rows, columns, pOut);
    }
}






