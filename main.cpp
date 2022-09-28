#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>

#include "double_stack.h"

using namespace std;

//����������ɫ
void set_color(int cl) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cl);
}
//�ı�������ɫ�����
void print_color(const string & s, int cl) {
    set_color(cl);
    cout << s << endl;
    set_color(DEFAULT);
}
//����˵�
void print_menu(int val) {
    if (val == 0) {
        system("pause");
        system("cls");
    }
    if (val == 0 || val == '1')
        print_color("[1] �½�˫ջ", CREATE);

    if (val == 0 || val == '2')
        print_color("[2] ��ջѹ��", LEFT_STACK);


    if (val == 0 || val == '3')
        print_color("[3] ��ջѹ��", RIGHT_STACK);


    if (val == 0 || val == '4')
        print_color("[4] ��ջ����", LEFT_STACK);


    if (val == 0 || val == '5')
        print_color("[5] ��ջ����", RIGHT_STACK);


    if (val == 0 || val == '6')
        print_color("[6] ��ջջ��", LEFT_STACK);

    if (val == 0 || val == '7')
        print_color("[7] ��ջջ��", RIGHT_STACK);

    if (val == 0 || val == '8')
        print_color("[8] ��ջΪ��", LEFT_STACK);

    if (val == 0 || val == '9')
        print_color("[9] ��ջΪ��", RIGHT_STACK);

    if (val == 0 || val == 'A' || val == 'a')
        cout << "[A] ȫջΪ��" << endl;

    if (val == 0 || val == 'B' || val == 'b')
        cout << "[B] ȫջΪ��" << endl;

    if (val == 0 || val == 'C' || val == 'c')
        print_color("[C] ��ջ�ռ�", LEFT_STACK);

    if (val == 0 || val == 'D' || val == 'd')
        print_color("[D] ��ջ�ռ�", RIGHT_STACK);

    if (val == 0 || val == 'E' || val == 'e')
        cout << "[E] ȫջ�ռ�" << endl;

    if (val == 0 || val == '0')
        print_color("[0] �˳�ϵͳ", EXIT);

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
                cout << "������ջ�����ռ�: ";
                set_color(CREATE);
                cin >> temp;
                set_color(DEFAULT);
                delete d_stack;
                d_stack = new double_stack(temp);
                print_color("�½�˫ջ�ɹ�", SUCCESS);
                break;
            case '2':
                cout << "��������Ҫѹ��ջ��ֵ: ";	//ѹ����ջ
                set_color(LEFT_STACK);
                cin >> temp;
                set_color(DEFAULT);
                if (d_stack == nullptr) {
                    print_color("����: δ�½�˫ջ", ERROR_OPERATION);
                }
                else if (d_stack->push_left(temp)) {
                    print_color("ѹ��ɹ�", SUCCESS);
                }
                else {
                    print_color("����: ջ��", ERROR_OPERATION);
                }
                break;
            case '3':
                cout << "��������Ҫѹ��ջ��ֵ: ";	//ѹ����ջ
                set_color(RIGHT_STACK);
                cin >> temp;
                set_color(DEFAULT);
                if (d_stack == nullptr) {
                    print_color("����: δ�½�˫ջ", ERROR_OPERATION);
                }
                else if (d_stack->push_right(temp)) {
                    print_color("ѹ��ɹ�", SUCCESS);
                }
                else {
                    print_color("����: ջ��", ERROR_OPERATION);
                }
                break;
            case '4':
                if (d_stack == nullptr) {
                    print_color("����: δ�½�˫ջ", ERROR_OPERATION);
                }
                else if (d_stack->pop_left()) {	//������ջ
                    print_color("�����ɹ�", SUCCESS);
                }
                else {
                    print_color("����: ջ��", ERROR_OPERATION);
                }
                break;
            case '5':
                if (d_stack == nullptr) {
                    print_color("����: δ�½�˫ջ", ERROR_OPERATION);
                }
                else if (d_stack->pop_right()) {	//������ջ
                    print_color("�����ɹ�", SUCCESS);
                }
                else {
                    print_color("����: ջ��", ERROR_OPERATION);
                }
                break;
            case '6':
                if (d_stack == nullptr) {
                    print_color("����: δ�½�˫ջ", ERROR_OPERATION);
                }
                else if (d_stack->peek_left(temp)) {	//��ջջ��Ԫ��
                    set_color(LEFT_STACK);
                    cout << temp << endl;
                    set_color(DEFAULT);
                }
                else {
                    print_color("����: ջ��", ERROR_OPERATION);
                }
                break;
            case '7':
                if (d_stack == nullptr) {
                    print_color("����: δ�½�˫ջ", ERROR_OPERATION);
                }
                else if (d_stack->peek_right(temp)) {	//��ջջ��Ԫ��
                    set_color(RIGHT_STACK);
                    cout << temp << endl;
                    set_color(DEFAULT);
                }
                else {
                    print_color("����: ջ��", ERROR_OPERATION);
                }
                break;
            case '8':
                if (d_stack == nullptr) {
                    print_color("����: δ�½�˫ջ", ERROR_OPERATION);
                }
                else {
                    set_color(LEFT_STACK);
                    cout << ((d_stack->empty_left()) ? "true" : "false") << endl;    //��ջΪ��?
                    set_color(DEFAULT);
                }
                break;
            case '9':
                if (d_stack == nullptr) {
                    print_color("����: δ�½�˫ջ", ERROR_OPERATION);
                }
                else {
                    set_color(RIGHT_STACK);
                    cout << ((d_stack->empty_right()) ? "true" : "false") << endl;    //��ջΪ��?
                    set_color(DEFAULT);
                }
                break;
            case 'A':
            case 'a':
                if (d_stack == nullptr) {
                    print_color("����: δ�½�˫ջ", ERROR_OPERATION);
                }
                else {
                    cout << ((d_stack->empty()) ? "true" : "false") << endl;    //ȫջΪ��?
                }
                break;
            case 'B':
            case 'b':
                if (d_stack == nullptr) {
                    print_color("����: δ�½�˫ջ", ERROR_OPERATION);
                }
                else {
                    cout << ((d_stack->full()) ? "true" : "false") << endl;    //ȫջ���?
                }
                break;
            case 'C':
            case 'c':
                if (d_stack == nullptr) {
                    print_color("����: δ�½�˫ջ", ERROR_OPERATION);
                }
                else {
                    set_color(LEFT_STACK);
                    cout << d_stack->size_left() << endl;    //��ջԪ�ظ���
                    set_color(DEFAULT);
                }
                break;
            case 'D':
            case 'd':
                if (d_stack == nullptr) {
                    print_color("����: δ�½�˫ջ", ERROR_OPERATION);
                }
                else {
                    set_color(RIGHT_STACK);
                    cout << d_stack->size_right() << endl;    //��ջԪ�ظ���
                    set_color(DEFAULT);
                }
                break;
            case 'E':
            case 'e':
                if (d_stack == nullptr) {
                    print_color("����: δ�½�˫ջ", ERROR_OPERATION);
                }
                else {
                    cout << d_stack->size() << endl;    //ȫջԪ�ظ���
                }
                break;
            default:;
        }
    }
    delete d_stack;
    cout << "�ͷſռ�ɹ�" << endl;
    system("pause");
    return 0;
}