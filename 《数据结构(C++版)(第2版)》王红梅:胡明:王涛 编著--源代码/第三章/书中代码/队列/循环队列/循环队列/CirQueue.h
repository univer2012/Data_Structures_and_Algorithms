//
//  CirQueue.h
//  循环队列
//
//  Created by huangaengoln on 15/10/5.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef ________CirQueue__
#define ________CirQueue__

#include <stdio.h>

const int QueueSize=100;  //定义存储队列元素的数组的最大长度

template <class T>        //定义模板类CirQueue
class CirQueue
{
public:
    CirQueue( );        //构造函数，置空队
    ~ CirQueue( );               //析构函数
    void EnQueue(T x);           //将元素x入队
    T DeQueue( );                //将队头元素出队
    T GetQueue( );               //取队头元素（并不删除）
    bool Empty( );               //判断队列是否为空
private:
    T data[QueueSize];           //存放队列元素的数组
    int front, rear;    //队头和队尾指针，分别指向队头元素的前一个位置和队尾元素的位置
    
};

#endif /* defined(________CirQueue__) */
