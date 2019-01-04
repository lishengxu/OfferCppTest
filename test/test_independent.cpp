/*
 * test_temp.cpp
 *
 *  Created on: Jan 3, 2019
 *      Author: lsx
 */

#include "gtest/gtest.h"
#include <string.h>

/**
 * 空类型实例占有的内存大小为1
 * 构造函数和析构函数只需要通过类型指向指针，本身在实例中不占有内存
 * 存在虚拟函数，编译器会为每个实例添加一个指向虚函数表的指针，占用指针长度的内存
 */
TEST(nullclasssizeoftest, positive) {
    class a {

    };
    EXPECT_EQ(1, sizeof(a));

    class b {
    public:
        b();
        ~b();
    };

    EXPECT_EQ(1, sizeof(b));

    class c {
    public:
        c();
        virtual ~c();
    };

    EXPECT_EQ(8, sizeof(c));
}

TEST(operatorcopytest, positive) {
    class MyString {
    public:
        MyString(char* pData = NULL) {
            if (pData != NULL) {
                mPData = new char[strlen(pData) + 1];
                strcpy(mPData, pData);
            }
        }

        MyString(const MyString& str) {
            if (str.mPData != NULL) {
                mPData = new char[strlen(str.mPData) + 1];
                strcpy(mPData, str.mPData);
            }
        }

        MyString& operator =(const MyString& str) {
            if (this != &str) {
                MyString temp(str);
                char *tempString = temp.mPData;
                temp.mPData = mPData;
                mPData = tempString;
            }

            return *this;
        }

        ~MyString() {
            if (mPData != NULL) {
                delete[] mPData;
            }
        }

        char* getData() {
            return mPData;
        }
    private:
        char* mPData;
    };

    char a[] = "abcdefg";
    char b[] = "hijklmn";
    MyString temp1(a);
    EXPECT_STREQ(a, temp1.getData());

    MyString temp2(b);
    EXPECT_STREQ(b, temp2.getData());

    MyString temp3(temp1);
    EXPECT_STREQ(a, temp3.getData());

    MyString temp4 = temp2;
    EXPECT_STREQ(b, temp4.getData());

    MyString temp5 = temp4 = temp1;
    EXPECT_STREQ(a, temp4.getData());
    EXPECT_STREQ(a, temp5.getData());

    temp5 = temp4 = temp2;
    EXPECT_STREQ(b, temp4.getData());
    EXPECT_STREQ(b, temp5.getData());
}
class MySingleton {

public:
    static MySingleton* getInstance() {
        if (sInstance == NULL) {
            sInstance = new MySingleton();
        }
        return sInstance;
    }
    int getData() {
        return mData;
    }

    void setData(int data) {
        mData = data;
    }
private:
    MySingleton() :
            mData(0) {
    }
    static MySingleton* sInstance;
    int mData;
};

MySingleton* MySingleton::sInstance = NULL;

TEST(singletontest, positive) {
    MySingleton* a = MySingleton::getInstance();
    EXPECT_EQ(0, a->getData());

    MySingleton* b = MySingleton::getInstance();
    EXPECT_EQ(0, b->getData());

    a->setData(1);
    EXPECT_EQ(1, a->getData());

    b->setData(2);
    EXPECT_EQ(2, b->getData());

    a->setData(3);
    EXPECT_EQ(3, a->getData());
    EXPECT_EQ(3, b->getData());
}

int getSize(int data[]) {
    return sizeof(data);
}
TEST(arraysizeoftest, positive) {
    int data1[] = { 1, 2, 3, 4, 5 };
    int sizeof1 = sizeof(data1);
    EXPECT_EQ(20, sizeof1);

    int* data2 = data1;
    int sizeof2 = sizeof(data2);
    EXPECT_EQ(8, sizeof2);

    int sizeof3 = getSize(data1);
    EXPECT_EQ(8, sizeof3);
}

TEST(stringsizeoftest, positive) {
    const char* str = "12345";
    EXPECT_EQ(5, strlen(str));

    char str1[] = "hello world";
    char str2[] = "hello world";

    const char* str3 = "hello world";
    const char* str4 = "hello world";

    EXPECT_FALSE(str1 == str2);
    EXPECT_TRUE(str3 == str4);
}
