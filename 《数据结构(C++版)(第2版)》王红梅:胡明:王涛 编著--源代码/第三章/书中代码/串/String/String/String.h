//
//  String.h
//  String
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef __String__String__
#define __String__String__

#include <stdio.h>

const int MaxSize=100;  //100只是示例性的数据，可以根据实际问题具体定义
template <class T>      //定义模板类SeqList
class String
{
public:
    String( );       //无参构造函数
    String(T a[], int n);       //有参构造函数
    ~String( );             //析构函数为空
    int  Length();          //返回串长度
    void StrConcat(String S);//将串T放在串S的后面连接成一个新串S
    void StrAssign(String S);         //将T的串值赋值给串S
    int  StrCmp(String x,String y);   //按值查找，求线性表中值为x的元素序号
    void StrInsert(int i, String x);  //将串T插入到串S 的第i个位置上
    void StrDelete(int i,int len);        //删除串S中从第i个字符开始连续len个字符
    void PrintList();       //遍历串，按序号依次输出各元素
private:
    T data[MaxSize];      //存放数据元素的数组
    int length;
};

#endif /* defined(__String__String__) */
