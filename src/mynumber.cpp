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
#include <algorithm>
#include <list>

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

void printAllProbality(const int n, std::vector<float> *pOut/* = NULL*/,
        const int maxValue/* = 6*/) {
    if (n < 1) {
        return;
    }
    int* pBuffer = (int*) calloc(n * maxValue + 1, sizeof(int));
    for (int i = 1; i <= maxValue; ++i) {
        pBuffer[i] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = i * maxValue; j >= i; --j) {
            int sum = 0;
            for (int k = j - 1; k > 0 && k > j - 7; --k) {
                sum += pBuffer[k];
            }
            pBuffer[j] = sum;
        }
        for (int j = i - 1; j > 0; --j) {
            pBuffer[j] = 0;
        }
    }

    double total = pow(maxValue, n);
    for (int i = n; i <= n * maxValue; ++i) {
        printf("%f\n", pBuffer[i] / total);
        if (pOut != NULL) {
            pOut->push_back(pBuffer[i] / total);
        }
    }
    free(pBuffer);
}

static int compare(const void* left, const void* right) {
    return *(int*) left - *(int*) right;
}

bool isContinuous(int* numbers, const int length) {
    if (numbers == NULL || length < 1) {
        return false;
    }
    qsort(numbers, length, sizeof(int), compare);

    int countOfZero = 0;
    int index = 0;
    while (index < length && numbers[index] == 0) {
        ++countOfZero;
        ++index;
    }
    int small = index, big = index + 1;
    int countOfGap = 0;
    while (big < length) {
        if (numbers[small] == numbers[big]) {
            return false;
        }
        countOfGap += numbers[big] - numbers[small] - 1;
        small = big;
        ++big;
    }
    return countOfZero >= countOfGap;
}

static int lastRemaining1(unsigned int n, unsigned int m) {
    std::list<int> numbers;
    for (unsigned int i = 0; i < n; ++i) {
        numbers.push_back(i);
    }
    std::list<int>::iterator cur = numbers.begin();
    while (numbers.size() > 1) {
        for (unsigned int i = 1; i < m; ++i) {
            ++cur;
            if (cur == numbers.end()) {
                cur = numbers.begin();
            }
        }
        std::list<int>::iterator next = ++cur;
        if (next == numbers.end()) {
            next = numbers.begin();
        }
        --cur;
        numbers.erase(cur);
        cur = next;
    }
    return *cur;
}

static int lastRemaining2(unsigned int n, unsigned int m) {
    unsigned int last = 0;
    for (unsigned int i = 2; i <= n; ++i) {
        last = (last + m) % i;
    }
    return last;
}

int lastRemaining(unsigned int n, unsigned int m, bool function1) {
    if (n < 1 || m < 1) {
        return -1;
    }
    return function1 ? lastRemaining1(n, m) : lastRemaining2(n, m);
}

class Temp {
public:
    Temp(void) {
        ++n;
        sum += n;
    }

    static void reset(void) {
        n = 0;
        sum = 0;
    }

    static unsigned int getSum() {
        return sum;
    }
private:
    static unsigned int n;
    static unsigned int sum;
};

unsigned int Temp::n = 0;
unsigned int Temp::sum = 0;

static unsigned int sum1(unsigned int n) {
    Temp::reset();
    Temp temp[n];
    return Temp::getSum();
}

class A {
public:
    virtual unsigned int sum(unsigned int n) {
        return 0;
    }
    virtual ~A() {
    }
};

A* array[2];
class B: public A {
public:
    virtual unsigned int sum(unsigned int n) {
        return array[!!n]->sum(n - 1) + n;
    }
};

static unsigned int sum2(unsigned int n) {
    A a;
    B b;
    array[0] = &a;
    array[1] = &b;
    return array[!!n]->sum(n);
}

typedef unsigned int (*func)(unsigned int n);
unsigned int func1(unsigned int n) {
    return 0;
}
unsigned int func2(unsigned int n) {
    static func f[2] = { func1, func2 };
    return f[!!n](n - 1) + n;
}

static unsigned int sum3(unsigned int n) {
    return func2(n);
}

unsigned int sum(unsigned int n, int function) {
    unsigned int result = 0;
    switch (function) {
    case 1:
        result = sum1(n);
        break;
    case 2:
        result = sum2(n);
        break;
    case 3:
        result = sum3(n);
        break;
    default:
        break;
    }
    return result;
}

int add2(int left, int right) {
    do {
        int sum = left ^ right;
        int carry = (left & right) << 1;
        left = sum;
        right = carry;
    } while (right != 0);
    return left;
}

enum status {
    kValid = 0, kInvalid
};

int strToInt(const char* const pStr) {
    if (pStr == NULL) {
        throw std::invalid_argument("invalid input");
        return 0;
    }

    const char* pIndex = pStr;
    bool positiveFlag = true;
    if (*pIndex == '+') {
        ++pIndex;
    } else if (*pIndex == '-') {
        ++pIndex;
        positiveFlag = false;
    }
    if (*pIndex == '\0') {
        throw std::invalid_argument("invalid input");
        return 0;
    }
    long long result = 0;
    while (*pIndex != '\0') {
        int number = *pIndex++ - '0';
        if (number <= 9 && number >= 0) {
            result = result * 10 + number;
        } else {
            result = 0;
            throw std::invalid_argument("invalid input");
        }
        if ((positiveFlag && result > 0x7FFFFFFF)
                || (!positiveFlag && result > 0x80000000)) {
            result = 0;
            throw std::invalid_argument("invalid input");
        }
    }
    return (int) result * (positiveFlag ? 1 : -1);
}
