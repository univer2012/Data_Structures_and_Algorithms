//
//  BothStack.h
//  两栈共享空间
//
//  Created by huangaengoln on 15/10/5.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef __________BothStack__
#define __________BothStack__

#include <stdio.h>

const int StackSize=100;  //100只是示例数据，需根据具体问题定义

template <class T>
class BothStack
{
public:
    BothStack( );                  //构造函数，将两个栈分别初始化
    ~BothStack( );                            //析构函数为空
    void Push(int i, T x);                    //入栈操作，将元素x压入栈i
    T Pop(int i);                             //出栈操作，对栈i执行出栈操作
    T GetTop(int i);                          //取栈i的栈顶元素
    bool Empty(int i);                        //判断栈i是否为空栈
private:
    T data[StackSize];                        //存放两个栈的数组
    int top1, top2;                //两个栈的栈顶指针，分别为各自栈顶元素在数组中的下标
};

#endif /* defined(__________BothStack__) */
