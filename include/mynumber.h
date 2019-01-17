/*
 * mynumber.h
 *
 *  Created on: Jan 8, 2019
 *      Author: lsx
 */

#ifndef MYNUMBER_H_
#define MYNUMBER_H_

/**
 * 斐波那契数列
 */
int fibonacci(int n);

/**
 * 获取一个浮点数的power次方
 */
double myPower(double base, int power);

/**
 * 打印1到最大的n位数字
 */
void print1ToMaxOfNDigits(const int n, bool recursive = true,
        std::vector<std::string> *pOut = NULL);

/**
 * 大数加法
 */
const char* add(const char* left, const char* right);

/**
 * 从1到n整数中1出现的次数
 */
int countOf1Between1ToN(unsigned int n);

/**
 * 获取丑数
 */
int getUglyNumber(unsigned int n);

/**
 * 获取数组中只出现一次的两个数字，其他数字出现两次
 */
void findNumberAppearOnce(const int* const array, const unsigned int length,
        int* number1, int* number2);

/**
 * 获取排序的数组中和为s的两个数字
 */
bool findNumbersWithSum(const int* const array, const unsigned int length,
        const int sum, int* number1, int* number2);

/**
 * 获取和为s的正数序列
 */
bool findSequencesWithSum(const int sum, std::vector<int>* pOut = NULL);

/**
 * n个骰子的点数
 */
void printAllProbality(const int n, std::vector<float> *pOut = NULL,
        const int maxValue = 6);

/**
 * 判断扑克牌的顺子
 */
bool isContinuous(int* numbers, const int length);

/**
 * 圆圈中最后剩下的数字
 */
int lastRemaining(unsigned int n, unsigned int m, bool function1 = true);

/**
 * 计算0+1+...+n的和
 */
unsigned int sum(unsigned int n, int function = 1);

/**
 * 不用加减乘除做加法
 */
int add2(int left, int right);

/**
 * 字符串转换成整数
 */
int strToInt(const char* const pStr);
enum StrToIntStatus {
    VALID = 0, INVALID
};
StrToIntStatus gStrToIntStatus = VALID;
int strToInt2(const char* const pStr) {
    if (pStr == NULL) {
        gStrToIntStatus = INVALID;
        return 0;
    }
    gStrToIntStatus = VALID;
    const char* pIndex = pStr;
    bool positiveFlag = true;
    if (*pIndex == '+') {
        ++pIndex;
    } else if (*pIndex == '-') {
        ++pIndex;
        positiveFlag = false;
    }
    if (*pIndex == '\0') {
        gStrToIntStatus = INVALID;
        return 0;
    }
    long long result = 0;
    while (*pIndex != '\0') {
        int number = *pIndex++ - '0';
        if (number >= 0 && number <= 9) {
            result = result * 10 + number;
        } else {
            break;
        }
        if ((positiveFlag && result > 0x7FFFFFFF)
                || (!positiveFlag && result > 0x80000000)) {
            break;
        }
    }
    if (*pIndex != 0) {
        gStrToIntStatus = INVALID;
        result = 0;
    }
    return result * (positiveFlag ? 1 : -1);
}

#endif /* MYNUMBER_H_ */
