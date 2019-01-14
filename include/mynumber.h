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

#endif /* MYNUMBER_H_ */
