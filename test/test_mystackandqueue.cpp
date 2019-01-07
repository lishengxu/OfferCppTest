/*
 * test_mystackandqueue.cpp
 *
 *  Created on: Jan 7, 2019
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include "mystackandqueue.h"

TEST(mystackandqueuetest, myqueuewithstack) {
    MyQueueWithStack<int> myqueue;
    myqueue.appendTail(1);
    myqueue.appendTail(2);
    EXPECT_EQ(1, myqueue.deleteHead());
    myqueue.appendTail(3);
    myqueue.appendTail(4);
    EXPECT_EQ(2, myqueue.deleteHead());
    EXPECT_EQ(3, myqueue.deleteHead());
    EXPECT_EQ(4, myqueue.deleteHead());
    try {
        myqueue.deleteHead();
        ADD_FAILURE();
    } catch (std::exception &ex) {
        EXPECT_STREQ("queue is empty", ex.what());
    }
}

TEST(mystackandqueuetest, mystackwithqueue) {
    MyStackWithQueue<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.pop();
    EXPECT_EQ(1, myStack.top());
    myStack.push(3);
    myStack.push(4);
    myStack.pop();
    EXPECT_EQ(3, myStack.top());

    myStack.pop();
    EXPECT_EQ(1, myStack.top());

    myStack.pop();
    EXPECT_TRUE(myStack.empty());

    try {
        myStack.pop();
        ADD_FAILURE();
    } catch (std::exception &ex) {
        EXPECT_STREQ("stack is empty", ex.what());
    }
}

