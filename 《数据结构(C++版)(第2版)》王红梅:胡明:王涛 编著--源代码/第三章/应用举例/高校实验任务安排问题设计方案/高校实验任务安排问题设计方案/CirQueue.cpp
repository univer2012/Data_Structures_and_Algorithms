//
//  CirQueue.cpp
//  高校实验任务安排问题设计方案
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include "CirQueue.h"      //引入头文件
//#include <string>
#include <iostream>
using namespace std;

/*
 * 前置条件：队列已存在
 * 输    入：元素值x
 * 功    能：在队尾插入一个元素
 * 输    出：如果插入不成功，抛出异常
 * 后置条件：如果插入成功，队尾增加了一个元素
 */

template <class T>
void CirQueue<T>::EnQueue(T x)
{
    if ((rear+1)%QueueSize ==front) throw "上溢";
    rear=(rear+1)%QueueSize;   //队尾指针在循环意义下加1
    data[rear]=x;             //在队尾处插入元素
}

/*
 * 前置条件：队列已存在
 * 输    入：无
 * 功    能：删除队头元素
 * 输    出：如果删除成功，返回被删元素值，否则，抛出删除异常
 * 后置条件：如果删除成功，队头减少了一个元素
 */

template <class T>
T CirQueue<T>::DeQueue()
{
    if (rear==front) throw "下溢";
    front=(front+1)%QueueSize;       //队头指针在循环意义下加1
    return data[front];             //读取并返回出队前的队头元素，注意队头指针
}                               //指向队头元素的前一个位置

/*
 * 前置条件：队列已存在
 * 输    入：无
 * 功    能：读取队头元素
 * 输    出：若队列不空，返回队头元素
 * 后置条件：队列不变
 */

template <class T>
T CirQueue<T>::GetQueue()
{
    int i;
    if (rear==front) throw "下溢";
    i=(front+1)%QueueSize;  //注意不要给队头指针赋值
    return data[i];
}

/*
 * 前置条件：队列已存在
 * 输    入：无
 * 功    能：读取队列长度
 * 输    出：若队列不空，返回队列长度
 * 后置条件：队列不变
 */

template <class T >
int CirQueue<T>::Length()
{
    int length =(rear-front+QueueSize) % QueueSize;
    return length;
}

/*
 *前置条件：队列已存在
 *输    入：无
 *功    能：遍历队列元素
 *输    出：若队列不空，返回队列元素
 *后置条件：队列不变
 */

template <class T>
void CirQueue<T>::PrintQueue()
{
    int i=front;
    while (i!=rear)
    {
        cout << "学号：" << data[i+1].num << "\n";
        cout << "姓名：" << data[i+1].name << "\n";
        cout << "班级: " << data[i+1].grade <<"\n";
        i=(i+1)%QueueSize;
    }
}

/*
 *前置条件：队列已存在
 *输    入：某一元素
 *功    能：查询队列中是否存在某元素
 *输    出：若存在，返回该元素所在位置，否则返回零
 *后置条件：队列不变
 */

template <class T>
int CirQueue<T>::Enquire(string num)
{
    int i;
    for(i=front+1; i<=(rear-front+QueueSize)%QueueSize; i++)
    {
        if(data[i].num==num)
            return i;
    }
    return 0;
}

/*
 *前置条件：队列已存在
 *输    入：位置
 *功    能：删除队列中该位置的元素
 *输    出：无
 *后置条件：队列不变
 */

template <class T >
void CirQueue<T>::Delete(int i)
{
    if (i<1 || i>(rear-front+QueueSize)%QueueSize) throw "位置";
    int t;
    t=i;
    while(t!=rear)
    {
        data[t]=data[(t+1)%QueueSize];
        t=(t+1)%QueueSize;
    }
    rear= (rear-1)%QueueSize;
}






