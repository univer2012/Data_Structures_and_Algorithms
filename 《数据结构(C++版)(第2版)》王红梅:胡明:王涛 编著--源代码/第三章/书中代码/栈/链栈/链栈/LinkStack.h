//
//  LinkStack.h
//  链栈
//
//  Created by huangaengoln on 15/10/5.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef ______LinkStack__
#define ______LinkStack__

#include <stdio.h>

template <class T>
struct Node
{
    T data;
    Node<T> *next;  //此处<T>也可以省略
};

template <class T>
class LinkStack
{
public:
    LinkStack();              //构造函数，初始化一个空链栈
    ~LinkStack();             //析构函数，释放链栈中各结点的存储空间
    void Push(T x);           //入栈操作，将元素x入栈
    T Pop();                  //出栈操作，将栈顶元素出栈
    T GetTop();               //取栈顶元素（并不删除）
    bool Empty(){return top == NULL ?  1 : 0;}             //判空操作，判断链栈是否为空栈
private:
    Node<T> *top;             //栈顶指针即链栈的头指针
};

#endif /* defined(______LinkStack__) */
