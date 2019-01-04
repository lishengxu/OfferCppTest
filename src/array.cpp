/*
 * array.cpp
 *
 *  Created on: Jan 4, 2019
 *      Author: lsx
 */

#include <stdio.h>

int getNumber(int number) {
    return number;
}

bool containRecursive(const int *array, int rowBegin, int rowEnd,
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

bool containNonRecursive(const int *array, int rowBegin, int rowEnd,
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

bool contain(const int *array, int rowBegin, int rowEnd, int columnBegin,
        int columnEnd, const int rows, const int columns, int number,
        bool isRecursive) {
    return isRecursive ?
            containRecursive(array, rowBegin, rowEnd, columnBegin, columnEnd,
                    rows, columns, number) :
            containNonRecursive(array, rowBegin, rowEnd, columnBegin, columnEnd,
                    rows, columns, number);
}

