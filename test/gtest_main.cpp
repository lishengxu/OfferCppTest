/*
 * gtest_main.cpp
 *
 *  Created on: Jan 4, 2019
 *      Author: lsx
 */

#include <stdio.h>
#include "gtest/gtest.h"

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



