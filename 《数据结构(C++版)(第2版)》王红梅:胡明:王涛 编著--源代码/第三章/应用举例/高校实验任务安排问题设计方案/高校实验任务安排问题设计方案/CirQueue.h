//
//  CirQueue.h
//  高校实验任务安排问题设计方案
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef __________________CirQueue__
#define __________________CirQueue__

#include <stdio.h>

#include <string>
using namespace std;

const int QueueSize=100;  //100只是示例性的数据，可以根据实际问题具体定义

struct student    //结构体
{
    string num;     //学生学号
    string name;    //学生姓名
    string grade;   //学生班级
};

template < class T >
class  CirQueue
{
public:
    CirQueue() {front=rear=0;}  //构造函数，置空队
    ~ CirQueue() {}           //析构函数，释放队列中各结点的存储空间
    void EnQueue(T x);        //将元素x入队
    T DeQueue();             //将队头元素出队
    T GetQueue();          //取队头元素（并不删除）
    bool Empty() {return front == rear ? 1:0;}//{front==rear? return 1: return 0;}  //判断队列是否为空
    int Length();
    void PrintQueue( );       //遍历队列，按序号依次输出各元素
    int  Enquire(string num); //查询队列中是否存在输入的学号
    void Delete(int i);        //删除队列的第i个元素
    
private:
    T data[QueueSize];   //存放队列元素的数组
    int front, rear;    //队头和队尾指针，分别指向队头元素的前一个位置和队尾元素的位置
};

#endif /* defined(__________________CirQueue__) */
