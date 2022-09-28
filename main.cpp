#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>

#include "double_stack.h"

using namespace std;

//设置字体颜色
void set_color(int cl) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cl);
}
//改变字体颜色并输出
void print_color(const string & s, int cl) {
    set_color(cl);
    cout << s << endl;
    set_color(DEFAULT);
}
//输出菜单
void print_menu(int val) {
    if (val == 0) {
        system("pause");
        system("cls");
    }
    if (val == 0 || val == '1')
        print_color("[1] 新建双栈", CREATE);

    if (val == 0 || val == '2')
        print_color("[2] 左栈压入", LEFT_STACK);


    if (val == 0 || val == '3')
        print_color("[3] 右栈压入", RIGHT_STACK);


    if (val == 0 || val == '4')
        print_color("[4] 左栈弹出", LEFT_STACK);


    if (val == 0 || val == '5')
        print_color("[5] 右栈弹出", RIGHT_STACK);


    if (val == 0 || val == '6')
        print_color("[6] 左栈栈顶", LEFT_STACK);

    if (val == 0 || val == '7')
        print_color("[7] 右栈栈顶", RIGHT_STACK);

    if (val == 0 || val == '8')
        print_color("[8] 左栈为空", LEFT_STACK);

    if (val == 0 || val == '9')
        print_color("[9] 右栈为空", RIGHT_STACK);

    if (val == 0 || val == 'A' || val == 'a')
        cout << "[A] 全栈为空" << endl;

    if (val == 0 || val == 'B' || val == 'b')
        cout << "[B] 全栈为满" << endl;

    if (val == 0 || val == 'C' || val == 'c')
        print_color("[C] 左栈空间", LEFT_STACK);

    if (val == 0 || val == 'D' || val == 'd')
        print_color("[D] 右栈空间", RIGHT_STACK);

    if (val == 0 || val == 'E' || val == 'e')
        cout << "[E] 全栈空间" << endl;

    if (val == 0 || val == '0')
        print_color("[0] 退出系统", EXIT);

}

int main() {
    double_stack * d_stack = nullptr;
    int c = 0;
    while (c != '0') {
        print_menu(0);

        cout << endl;
        if (d_stack == nullptr) {
            cout << "null" << endl;
        }
        else {
            d_stack->print_values();
        }
        cout << endl;

        c = getch();
        print_menu(c);
        int temp;
        switch (c) {
            case '1':
                cout << "请输入栈的最大空间: ";
                set_color(CREATE);
                cin >> temp;
                set_color(DEFAULT);
                delete d_stack;
                d_stack = new double_stack(temp);
                print_color("新建双栈成功", SUCCESS);
                break;
            case '2':
                cout << "请输入需要压入栈的值: ";	//压入左栈
                set_color(LEFT_STACK);
                cin >> temp;
                set_color(DEFAULT);
                if (d_stack == nullptr) {
                    print_color("错误: 未新建双栈", ERROR_OPERATION);
                }
                else if (d_stack->push_left(temp)) {
                    print_color("压入成功", SUCCESS);
                }
                else {
                    print_color("错误: 栈满", ERROR_OPERATION);
                }
                break;
            case '3':
                cout << "请输入需要压入栈的值: ";	//压入右栈
                set_color(RIGHT_STACK);
                cin >> temp;
                set_color(DEFAULT);
                if (d_stack == nullptr) {
                    print_color("错误: 未新建双栈", ERROR_OPERATION);
                }
                else if (d_stack->push_right(temp)) {
                    print_color("压入成功", SUCCESS);
                }
                else {
                    print_color("错误: 栈满", ERROR_OPERATION);
                }
                break;
            case '4':
                if (d_stack == nullptr) {
                    print_color("错误: 未新建双栈", ERROR_OPERATION);
                }
                else if (d_stack->pop_left()) {	//弹出左栈
                    print_color("弹出成功", SUCCESS);
                }
                else {
                    print_color("错误: 栈空", ERROR_OPERATION);
                }
                break;
            case '5':
                if (d_stack == nullptr) {
                    print_color("错误: 未新建双栈", ERROR_OPERATION);
                }
                else if (d_stack->pop_right()) {	//弹出右栈
                    print_color("弹出成功", SUCCESS);
                }
                else {
                    print_color("错误: 栈空", ERROR_OPERATION);
                }
                break;
            case '6':
                if (d_stack == nullptr) {
                    print_color("错误: 未新建双栈", ERROR_OPERATION);
                }
                else if (d_stack->peek_left(temp)) {	//左栈栈顶元素
                    set_color(LEFT_STACK);
                    cout << temp << endl;
                    set_color(DEFAULT);
                }
                else {
                    print_color("错误: 栈空", ERROR_OPERATION);
                }
                break;
            case '7':
                if (d_stack == nullptr) {
                    print_color("错误: 未新建双栈", ERROR_OPERATION);
                }
                else if (d_stack->peek_right(temp)) {	//右栈栈顶元素
                    set_color(RIGHT_STACK);
                    cout << temp << endl;
                    set_color(DEFAULT);
                }
                else {
                    print_color("错误: 栈空", ERROR_OPERATION);
                }
                break;
            case '8':
                if (d_stack == nullptr) {
                    print_color("错误: 未新建双栈", ERROR_OPERATION);
                }
                else {
                    set_color(LEFT_STACK);
                    cout << ((d_stack->empty_left()) ? "true" : "false") << endl;    //左栈为空?
                    set_color(DEFAULT);
                }
                break;
            case '9':
                if (d_stack == nullptr) {
                    print_color("错误: 未新建双栈", ERROR_OPERATION);
                }
                else {
                    set_color(RIGHT_STACK);
                    cout << ((d_stack->empty_right()) ? "true" : "false") << endl;    //右栈为空?
                    set_color(DEFAULT);
                }
                break;
            case 'A':
            case 'a':
                if (d_stack == nullptr) {
                    print_color("错误: 未新建双栈", ERROR_OPERATION);
                }
                else {
                    cout << ((d_stack->empty()) ? "true" : "false") << endl;    //全栈为空?
                }
                break;
            case 'B':
            case 'b':
                if (d_stack == nullptr) {
                    print_color("错误: 未新建双栈", ERROR_OPERATION);
                }
                else {
                    cout << ((d_stack->full()) ? "true" : "false") << endl;    //全栈溢出?
                }
                break;
            case 'C':
            case 'c':
                if (d_stack == nullptr) {
                    print_color("错误: 未新建双栈", ERROR_OPERATION);
                }
                else {
                    set_color(LEFT_STACK);
                    cout << d_stack->size_left() << endl;    //左栈元素个数
                    set_color(DEFAULT);
                }
                break;
            case 'D':
            case 'd':
                if (d_stack == nullptr) {
                    print_color("错误: 未新建双栈", ERROR_OPERATION);
                }
                else {
                    set_color(RIGHT_STACK);
                    cout << d_stack->size_right() << endl;    //右栈元素个数
                    set_color(DEFAULT);
                }
                break;
            case 'E':
            case 'e':
                if (d_stack == nullptr) {
                    print_color("错误: 未新建双栈", ERROR_OPERATION);
                }
                else {
                    cout << d_stack->size() << endl;    //全栈元素个数
                }
                break;
            default:;
        }
    }
    delete d_stack;
    cout << "释放空间成功" << endl;
    system("pause");
    return 0;
}