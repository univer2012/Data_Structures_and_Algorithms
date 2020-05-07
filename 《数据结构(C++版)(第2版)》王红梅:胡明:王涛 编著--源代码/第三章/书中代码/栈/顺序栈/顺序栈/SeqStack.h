//
//  SeqStack.h
//  顺序栈
//
//  Created by huangaengoln on 15/10/5.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef _______SeqStack__
#define _______SeqStack__

#include <stdio.h>
const int StackSize=10;  //10只是示例性的数据，可以根据实际问题具体定义

template <class T>       //定义模板类SeqStack
class SeqStack
{
public:
    SeqStack( ) ;            //构造函数，初始化一个空栈
    ~SeqStack( );            //析构函数为空
    void Push(T x);          //入栈操作，将元素x入栈
    T Pop( );                //出栈操作，将栈顶元素弹出
    T GetTop( );	         //取栈顶元素(并不删除)
    bool Empty( );           //判断栈是否为空
private:
    T data[StackSize];      //存放栈元素的数组
    int top;                //栈顶指针，为栈顶元素在数组中的下标
};

#endif /* defined(_______SeqStack__) */
