/*
 * mynumber.cpp
 *
 *  Created on: Jan 8, 2019
 *      Author: lsx
 */

#include <stdio.h>
#include <vector>
#include <string>
#include <exception>
#include <stdexcept>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    int prev = 0, cur = 1;
    int index = 1;
    int temp = prev + cur;
    while (index < n) {
        temp = prev + cur;
        prev = cur;
        cur = temp;
        ++index;
    }
    return cur;
}

static bool myFloatEqual(double left, double right) {
    return left - right < 0.0000001f && left - right > -0.0000001f;
}

static double powerWithUnsignedPower(double base, unsigned int power) {
    if (power == 0) {
        return 1;
    }
    if (power == 1) {
        return base;
    }

    double result = powerWithUnsignedPower(base, power >> 1);
    result *= result;

    if (power & 0x01) {
        result *= base;
    }
    return result;
}

double myPower(double base, int power) {
    if (myFloatEqual(base, 0.0f) && power <= 0) {
        return 0.0f;
    }

    unsigned int absPower = (unsigned int) (power < 0 ? -power : power);

    double result = powerWithUnsignedPower(base, absPower);

    if (power < 0) {
        result = 1.0f / result;
    }
    return result;
}

static void printNumber(const char* const number, const int n,
        std::vector<std::string>* pOut = NULL) {
    int index = 0;
    while (index < n) {
        if (*(number + index) != '0') {
            printf("%s\n", number + index);
            if (pOut != NULL) {
                pOut->push_back(number + index);
            }
            break;
        }
        ++index;
    }
}

static void print1ToMaxOfNDigitsRecursive(char* number, const int n, int index,
        std::vector<std::string>* pOut =
        NULL) {
    if (index >= n) {
        printNumber(number, n, pOut);
        return;
    }

    for (int i = 0; i < 10; ++i) {
        *(number + index) = i + '0';
        print1ToMaxOfNDigitsRecursive(number, n, index + 1, pOut);
    }
}

static void print1ToMaxOfNDigitsRecursive(const int n,
        std::vector<std::string>* pOut =
        NULL) {
    char number[n + 1];
    memset(number, '0', n);
    number[n] = '\0';
    for (int i = 0; i < 10; ++i) {
        *number = i + '0';
        print1ToMaxOfNDigitsRecursive(number, n, 1, pOut);
    }
}

static bool increaseNumber(char* number, const int n) {
    bool isOverFlow = false;
    int nTakeOver = 0;

    for (int i = n - 1; i >= 0; --i) {
        int nSum = *(number + i) - '0' + nTakeOver;
        if (i == n - 1) {
            ++nSum;
        }
        if (nSum >= 10) {
            if (i == 0) {
                isOverFlow = true;
            } else {
                nSum -= 10;
                nTakeOver = 1;
                *(number + i) = nSum + '0';
            }
        } else {
            *(number + i) = nSum + '0';
            break;
        }
    }
    return isOverFlow;
}

static void print1ToMaxOfNDigitsNonRecursive(const int n,
        std::vector<std::string>* pOut = NULL) {
    char number[n + 1];
    memset(number, '0', n);
    number[n] = '\0';

    while (!increaseNumber(number, n)) {
        printNumber(number, n, pOut);
    }
}

void print1ToMaxOfNDigits(const int n, bool recursive/*=true*/,
        std::vector<std::string> *pOut/*=NULL*/) {
    if (n < 1) {
        return;
    }

    recursive ?
            print1ToMaxOfNDigitsRecursive(n, pOut) :
            print1ToMaxOfNDigitsNonRecursive(n, pOut);
}

static int stringcompare(const char* left, const char* right) {
    int leftLength = strlen(left);
    int rightLength = strlen(right);

    if (leftLength < rightLength) {
        return -1;
    } else if (leftLength > rightLength) {
        return 1;
    } else {
        int result = strcmp(left, right);
        if (result > 0) {
            return 1;
        } else if (result < 0) {
            return -1;
        } else {
            return 0;
        }
    }
    return 0;
}

const char* add(const char* left, const char* right) {
    if (left == NULL || right == NULL || strlen(left) == 0
            || strlen(right) == 0) {
        return NULL;
    }

    bool leftIsPositive = true;
    if (*left == '+') {
        ++left;
    } else if (*left == '-') {
        ++left;
        leftIsPositive = false;
    }
    bool rightIsPositive = true;
    if (*right == '+') {
        ++right;
    } else if (*right == '-') {
        ++right;
        rightIsPositive = false;
    }
    int isAdd = 1;
    bool resultIsPositive = true;
    if (!leftIsPositive && rightIsPositive) {
        if (stringcompare(left, right) > 0) {
            resultIsPositive = false;
        } else {
            std::swap(left, right);
        }
        isAdd = -1;
    } else if (leftIsPositive && !rightIsPositive) {
        if (stringcompare(left, right) < 0) {
            resultIsPositive = false;
            std::swap(left, right);
        }
        isAdd = -1;
    } else if (!leftIsPositive && !rightIsPositive) {
        resultIsPositive = false;
    }

    int leftLen = strlen(left), rightLen = strlen(right);
    if (leftLen == 0 || rightLen == 0) {
        return NULL;
    }
    char* newStr = (char*) calloc(leftLen + 2 + 1, sizeof(char));

    int nSum = 0, nTakeOver = 0;
    int leftIndex = leftLen - 1, rightIndex = rightLen - 1;
    char* newStrIndex = newStr;
    while (leftIndex >= 0 && rightIndex >= 0) {
        int leftDigit = *(left + leftIndex) - '0';
        int rightDigit = *(right + rightIndex) - '0';
        if (leftDigit < 0 || leftDigit > 9 || rightDigit < 0
                || rightDigit > 9) {
            free(newStr);
            throw std::invalid_argument("invalid input");
            return NULL;
        }
        nSum = leftDigit + isAdd * rightDigit + nTakeOver;
        if (nSum >= 10) {
            nTakeOver = 1;
            nSum -= 10;
        } else if (nSum < 0) {
            nTakeOver = -1;
            nSum += 10;
        } else {
            nTakeOver = 0;
        }
        *newStrIndex++ = nSum + '0';
        --leftIndex, --rightIndex;
    }
    while (leftIndex >= 0) {
        int leftDigit = *(left + leftIndex) - '0';
        if (leftDigit < 0 || leftDigit > 9) {
            free(newStr);
            throw std::invalid_argument("invalid input");
            return NULL;
        }
        nSum = leftDigit + nTakeOver;
        if (nSum >= 10) {
            nTakeOver = 1;
            nSum -= 10;
        } else if (nSum < 0) {
            nTakeOver = -1;
            nSum += 10;
        } else {
            nTakeOver = 0;
        }
        *newStrIndex++ = nSum + '0';
        --leftIndex;
    }
    while (rightIndex >= 0) {
        int rightDigit = *(right + rightIndex) - '0';
        if (rightDigit < 0 || rightDigit > 9) {
            free(newStr);
            throw std::invalid_argument("invalid input");
            return NULL;
        }
        nSum = rightDigit + nTakeOver;
        if (nSum >= 10) {
            nTakeOver = 1;
            nSum -= 10;
        } else if (nSum < 0) {
            nTakeOver = -1;
            nSum += 10;
        } else {
            nTakeOver = 0;
        }
        *newStrIndex++ = nSum + '0';
        --rightIndex;
    }

    if (nTakeOver) {
        *newStrIndex++ = nTakeOver + '0';
    }
    --newStrIndex;
    while (newStrIndex > newStr) {
        if (*newStrIndex == '0' || *newStrIndex == '\0') {
            --newStrIndex;
        } else {
            break;
        }
    }
    if (!resultIsPositive) {
        *++newStrIndex = '-';
    }
    *++newStrIndex = '\0';
    std::reverse(newStr, newStrIndex);
    return newStr;
}

static int powerBase10(unsigned int n) {
    int result = 1;
    for (unsigned int i = 0; i < n; ++i) {
        result *= 10;
    }
    return result;
}

static int countOf1Between1ToN(const char* number) {
    if (number == NULL) {
        return 0;
    }
    int first = *number - '0';
    int length = strlen(number);
    if (first == 0 && length == 1) {
        return 0;
    }
    if (first > 0 && length == 1) {
        return 1;
    }

    int countFirstDigit = 0;
    if (first > 1) {
        countFirstDigit = powerBase10(length - 1);
    } else if (first == 1) {
        countFirstDigit = atoi(number + 1) + 1;
    }
    int countOtherDigits = first * (length - 1) * powerBase10(length - 2);

    int countRecursive = countOf1Between1ToN(number + 1);
    return countFirstDigit + countOtherDigits + countRecursive;
}

int countOf1Between1ToN(unsigned int n) {
    if (n == 0) {
        return 0;
    }

    std::string numberStr;

    unsigned int number = n;
    while (number != 0) {
        numberStr.push_back('0' + number % 10);
        number /= 10;
    }
    std::reverse(numberStr.begin(), numberStr.end());

    return countOf1Between1ToN(numberStr.c_str());
}

static int minUgly(int value1, int value2, int value3) {
    int result = value1 < value2 ? value1 : value2;
    return result < value3 ? result : value3;
}

int getUglyNumber(unsigned int n) {
    if (n == 0) {
        return 0;
    }
    int* uglyNumbers = (int*) malloc(n * sizeof(int));
    uglyNumbers[0] = 1;
    unsigned int index = 1;
    unsigned int index2 = 0, index3 = 0, index5 = 0;
    while (index < n) {
        int min = minUgly(uglyNumbers[index2] * 2, uglyNumbers[index3] * 3,
                uglyNumbers[index5] * 5);
        uglyNumbers[index] = min;
        if (uglyNumbers[index2] * 2 <= min) {
            ++index2;
        }
        if (uglyNumbers[index3] * 3 <= min) {
            ++index3;
        }
        if (uglyNumbers[index5] * 5 <= min) {
            ++index5;
        }
        ++index;
    }

    int result = uglyNumbers[n - 1];
    free(uglyNumbers);
    return result;
}

static unsigned int getFirstBitOf1(int number) {
    unsigned int indexBit = 0;
    while ((number & 0x01) == 0 && indexBit < 8 * sizeof(int)) {
        number >>= 1;
        ++indexBit;
    }
    return indexBit;
}

static bool isBit1(int number, unsigned int indexBit) {
    return (number >> indexBit) & 0x01;
}

void findNumberAppearOnce(const int* const array, const unsigned int length,
        int* number1, int* number2) {
    if (array == NULL || length < 1) {
        return;
    }
    int number = 0;
    for (unsigned int i = 0; i < length; ++i) {
        number ^= array[i];
    }
    unsigned int indexOf1 = getFirstBitOf1(number);
    *number1 = *number2 = 0;
    for (unsigned int i = 0; i < length; ++i) {
        if (isBit1(array[i], indexOf1)) {
            *number1 ^= array[i];
        } else {
            *number2 ^= array[i];
        }
    }
}

bool findNumbersWithSum(const int* const array, const unsigned int length,
        const int sum, int* number1, int* number2) {
    if (array == NULL || length < 1) {
        return false;
    }
    bool found = false;
    int begin = 0, end = length - 1;
    while (begin < end) {
        int curSum = array[begin] + array[end];
        if (curSum == sum) {
            *number1 = array[begin];
            *number2 = array[end];
            found = true;
            break;
        } else if (curSum < sum) {
            ++begin;
        } else {
            --end;
        }
    }
    return found;
}

static void printSequeces(const int small, const int big,
        std::vector<int>* pOut = NULL) {
    for (int index = small; index <= big; ++index) {
        printf("%d\n", index);
        if (pOut != NULL) {
            pOut->push_back(index);
        }
    }
}

bool findSequencesWithSum(const int sum, std::vector<int>* pOut) {
    bool found = false;
    int small = 1, big = 2;
    int curSum = small + big;
    int middle = (sum + 1) >> 1;
    while (small < middle) {
        if (curSum == sum) {
            printSequeces(small, big, pOut);
            found = true;
            break;
        } else if (curSum < sum) {
            ++big;
            curSum += big;
        } else {
            curSum -= small;
            ++small;
        }
    }
    return found;
}

