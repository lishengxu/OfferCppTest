/*
 * string.h
 *
 *  Created on: Jan 4, 2019
 *      Author: lsx
 */

#ifndef STRING_H_
#define STRING_H_

#include <vector>
#include <string>

/**
 * 将字符串operation中包含的src字符串替换成desc字符串，如果src字符串为空，则不做替换
 */
char* replaceString(const char* const operation, const char* const src,
        const char* const desc, bool fromFirst = true);

/**
 *  打印一个字符串的所有排列
 */
void permutation(char* pStr, std::vector<std::string>* pOut = NULL);

/**
 * 打印一个字符串的所有组合
 */
void combination(char* pStr, std::vector<std::string>* pOut = NULL);

/**
 * 第一个只出现一次的字符
 */
char firstNotRespondingChar(const char* pStr);

#endif /* STRING_H_ */
