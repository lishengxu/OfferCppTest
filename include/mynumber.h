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

#endif /* MYNUMBER_H_ */
