//
// Created by Acer on 2022/9/27.
//

#ifndef DOUBLESTACK_DOUBLE_STACK_H
#define DOUBLESTACK_DOUBLE_STACK_H

//--------字体颜色控制--------
#define BLUE 3
#define YELLOW 6
#define WHITE 7
#define GREEN 10
#define RED 12

//默认颜色
#define DEFAULT WHITE
//左栈颜色
#define LEFT_STACK BLUE
//右栈颜色
#define RIGHT_STACK YELLOW
//创建颜色
#define CREATE GREEN
//退出颜色
#define EXIT RED
//操作成功颜色
#define SUCCESS GREEN
//操作失败颜色
#define ERROR_OPERATION RED
//--------字体颜色控制--------

class double_stack {
private:
    int * stack;
    int left_top, right_top;
    int length;
public:
    explicit double_stack();
    explicit double_stack(int);

    bool empty_left() const;	//左栈为空?
    bool empty_right() const;	//右栈为空?
    bool empty() const;	//全栈为空?

    bool full() const;	//全栈溢出?

    bool peek_left(int &);	//左栈栈顶, 若为空返回 false
    bool peek_right(int &);	//右栈栈顶, 若为空返回 false

    bool pop_left();	//左栈弹出, 若为空返回 false
    bool pop_right();	//右栈弹出, 若为空返回 false

    void print_values();	//输出全栈元素

    bool push_left(int);	//左栈压入, 若为满返回 false
    bool push_right(int);	//右栈压入, 若为满返回 false

    int size_left() const;	//左栈元素个数
    int size_right() const;	//右栈元素个数
    int size() const;	//全栈元素个数

    ~double_stack();
};


#endif //DOUBLESTACK_DOUBLE_STACK_H