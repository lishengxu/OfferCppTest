/*
 * mystackandqueue.h
 *
 *  Created on: Jan 7, 2019
 *      Author: lsx
 */

#ifndef MYSTACKANDQUEUE_H_
#define MYSTACKANDQUEUE_H_
#include <stack>
#include <queue>
#include <exception>
#include <stdexcept>

template<typename T>
class MyQueueWithStack {
public:
    MyQueueWithStack(void);
    ~MyQueueWithStack(void);

    void appendTail(const T& node);
    T deleteHead(void);
private:
    std::stack<T> stack1;
    std::stack<T> stack2;
};

template<typename T>
MyQueueWithStack<T>::MyQueueWithStack() {
}

template<typename T>
MyQueueWithStack<T>::~MyQueueWithStack() {
}

template<typename T>
void MyQueueWithStack<T>::appendTail(const T& node) {
    stack1.push(node);
}

template<typename T>
T MyQueueWithStack<T>::deleteHead() {
    if (stack2.empty()) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    if (stack2.empty()) {
        throw std::runtime_error("queue is empty");
    }
    T result = stack2.top();
    stack2.pop();
    return result;
}

template<typename T>
class MyStackWithQueue {
public:
    MyStackWithQueue(void);
    ~MyStackWithQueue(void);

    void push(const T& node);
    void pop(void);
    T top(void);
    bool empty(void);
private:
    std::queue<T> queue1;
    std::queue<T> queue2;
};

template<typename T>
MyStackWithQueue<T>::MyStackWithQueue() {
}

template<typename T>
MyStackWithQueue<T>::~MyStackWithQueue() {
}

template<typename T>
void MyStackWithQueue<T>::push(const T& node) {
    if (queue1.empty()) {
        queue2.push(node);
    } else {
        queue1.push(node);
    }
}

template<typename T>
void MyStackWithQueue<T>::pop() {
    if (queue1.empty() && queue2.empty()) {
        throw std::runtime_error("stack is empty");
    }
    if (queue1.empty()) {
        while (queue2.size() > 1) {
            queue1.push(queue2.front());
            queue2.pop();
        }
        queue2.pop();
    } else {
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        queue1.pop();
    }
}

template<typename T>
T MyStackWithQueue<T>::top() {
    if (queue1.empty()) {
        if (queue2.empty()) {
            throw std::runtime_error("stack is empty");
        }
    }

    if (queue1.empty()) {
        return queue2.back();
    } else {
        return queue1.back();
    }
}

template<typename T>
bool MyStackWithQueue<T>::empty() {
    return queue1.empty() && queue2.empty();
}

template<typename T>
class MyStackWithMin {
public:
    MyStackWithMin(void);
    ~MyStackWithMin(void);

    void push(const T& data);
    void pop(void);
    const T& min(void) const;

private:
    std::stack<T> mData;
    std::stack<T> mMin;
};

template<typename T>
MyStackWithMin<T>::MyStackWithMin() {
}

template<typename T>
MyStackWithMin<T>::~MyStackWithMin() {
}

template<typename T>
void MyStackWithMin<T>::push(const T& data) {
    mData.push(data);
    if (mMin.empty() || mMin.top() > data) {
        mMin.push(data);
    } else {
        mMin.push(mMin.top());
    }
}

template<typename T>
void MyStackWithMin<T>::pop() {
    if (mData.empty() || mMin.empty()) {
        throw std::runtime_error("stack is empty");
    }
    mData.pop();
    mMin.pop();
}

template<typename T>
const T& MyStackWithMin<T>::min() const {
    if (mMin.empty()) {
        throw std::runtime_error("stack is empty");
    }
    return mMin.top();
}

#endif /* MYSTACKANDQUEUE_H_ */

