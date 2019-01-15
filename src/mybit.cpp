/*
 * mybit.cpp
 *
 *  Created on: Jan 8, 2019
 *      Author: lsx
 */

static int countOf1InNumber1(int n) {
    int count = 0;
    unsigned int index = 1;
    while (index) {
        if (n & index) {
            ++count;
        }
        index <<= 1;
    }
    return count;

}

static int countOf1InNumber2(int n) {
    int count = 0;
    while (n) {
        ++count;
        n &= n - 1;
    }
    return count;
}

int countOf1InNumber(int n, bool flag/*= true*/) {
    return flag ? countOf1InNumber1(n) : countOf1InNumber2(n);
}
