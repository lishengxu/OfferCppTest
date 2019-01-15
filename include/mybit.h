/*
 * mybit.h
 *
 *  Created on: Jan 8, 2019
 *      Author: lsx
 */

#ifndef MYBIT_H_
#define MYBIT_H_

inline bool powerOf2(int n) {
    if (n <= 0) {
        return false;
    }
    return (n & (n - 1)) == 0;
}

/**
 * 获取一个整数的二进制表示中1的个数
 */
int countOf1InNumber(int n, bool flag = true);

#endif /* MYBIT_H_ */
