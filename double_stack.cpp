//
// Created by Acer on 2022/9/27.
//
#include <iostream>
#include <string>
#include <windows.h>

#include "double_stack.h"

using namespace std;

double_stack::double_stack() {
    stack = nullptr;
    left_top = -1;
    right_top = -1;
    length = -1;
}

double_stack::double_stack(int n) {
    length = n;
    stack = (int * )malloc(n * sizeof(int));
    if (stack == nullptr) {
        cout << "错误: 请求空间失败" << endl;
        exit(1);
    }
//    stack = new int[length]();
    left_top = -1;
    right_top = length;
}

bool double_stack::empty_left() const {
    return left_top < 0;
}

bool double_stack::empty_right() const {
    return right_top >= length;
}

bool double_stack::empty() const {
    return empty_left() && empty_right();
}

bool double_stack::full() const {
    return size() >= length;
}

bool double_stack::peek_left(int & val) {
    if (left_top < 0) {
        return false;
    }
    val = stack[left_top];
    return true;
}

bool double_stack::peek_right(int & val) {
    if (right_top >= length) {
        return false;
    }
    val = stack[right_top];
    return true;
}

bool double_stack::pop_left() {
    if (left_top < 0) {
        return false;
    }
    -- left_top;
    return true;
}

bool double_stack::pop_right() {
    if (right_top >= length) {
        return false;
    }
    ++ right_top;
    return true;
}

void double_stack::print_values() {
    if (stack == nullptr) {
        cout << "null" << endl;
        return;
    }
    if (length <= 0) {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    if (left_top >= 0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LEFT_STACK);	//字体变色
        cout << stack[0];
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT);	//字体变色
        cout << "null";
    }

    int i = 1;
    while (i <= left_top) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT);	//字体变色
        cout << ", ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LEFT_STACK);	//字体变色
        cout << stack[i];
        ++ i;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT);	//字体变色
    while (i < right_top) {
        cout << ", null";
        ++ i;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RIGHT_STACK);	//字体变色
    while (i < length) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT);	//字体变色
        cout << ", ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RIGHT_STACK);	//字体变色
        cout << stack[i];
        ++ i;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT);	//字体变色
    cout << "]" << endl;
}

bool double_stack::push_left(int val) {
    if (full()) {
        return false;
    }
    ++ left_top;
    stack[left_top] = val;
    return true;
}

bool double_stack::push_right(int val) {
    if (full()) {
        return false;
    }
    -- right_top;
    stack[right_top] = val;
    return true;
}

int double_stack::size_left() const {
    return left_top + 1;
}

int double_stack::size_right() const {
    return length - right_top;
}

int double_stack::size() const {
    return size_left() + size_right();
}

double_stack::~double_stack() {
    free(stack);
//    delete [] stack;
}