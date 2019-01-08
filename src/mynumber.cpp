/*
 * mynumber.cpp
 *
 *  Created on: Jan 8, 2019
 *      Author: lsx
 */

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

    if (power % 2) {
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
