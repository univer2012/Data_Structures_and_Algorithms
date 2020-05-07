//
//  String.cpp
//  String
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include "String.h"
#include <iostream>
//using namespace std;
/*
 *前置条件：串不存在
 *输    入：无
 *功    能：构建一个串
 *输    出：无
 *后置条件：构建一个串
 */
template <class T>
String<T>:: String( )
{
    data[0]="0";
    length=0;
}
/*
 *前置条件：串不存在
 *输    入：串信息的数组形式a[],串长度n
 *功    能：将数组a[]中元素建为长度为n的串
 *输    出：无
 *后置条件：构建一个串
 */
template <class T>
String<T>:: String(T a[], int n)
{
    if (n>MaxSize) throw "参数非法";
    for (int i=0; i<n; i++)
        data[i+1]=a[i];
    data[0]=n;
    length=n;
}
/*
 *前置条件：无
 *输    入：无
 *功    能：无
 *输    出：无
 *后置条件：无
 */
template <class T>
String<T>:: ~String( )
{
}
/*
 *前置条件：顺序表存在
 *输    入：无
 *功    能：输出顺序表长度
 *输    出：顺序表长度
 *后置条件：顺序表不变
 */
template <class T>
int String<T>::Length()
{
    return length;
}
/*
 *前置条件：串存在
 *输    入：串x，位置i
 *功    能：将串x插入到串S 的第i个位置上
 *输    出：无
 *后置条件：串x不变
 */
template <class T>
void String<T>::StrInsert(int i, String x)
{
    int j;
    if (length>=MaxSize) throw "上溢";
    if (i<1 || i>length+1) throw "位置";
    for (int k=x.length;k>0;k--)
    {
        for (j=length; j>=i; j--)
            data[j+1]=data[j];
        data[i]=x.data[k];
        length++;
        data[0]=data[0]+1;
    }
}
/*
 *前置条件：串存在
 *输    入：位置i，长度len
 *功    能：删除串S中从第i个字符开始连续len个字符
 *输    出：无
 *后置条件：串删除元素
 */
template <class T>
void String<T>::StrDelete(int i,int len)
{
    int j,k;
    if (len==0) throw "下溢";
    if (i<1 || i>length) throw "位置";
    for (k=len; k>0; k--)
    {
        for (j=i; j<length; j++)
            data[j]=data[j+1];
        length--;
        data[0]=data[0]-1;
    }
}
/*
 *前置条件：无
 *输    入: 串T
 *功    能：串连接，将串T放在串S的后面连接成一个新串S
 *输    出：无
 *后置条件：串T不变
 */
template <class T>
void String<T>::StrConcat(String S)
{
    int k,j;
    for (k=1; k<=S.length; k++)
    {
        data[length+k]=S.data[k];
        length++;
        data[0]=data[0]-1;
    }
}
/*
 *前置条件：无
 *输    入: 串T
 *功    能：将T的串值赋值给串S
 *输    出：无
 *后置条件：串T不变
 */
template <class T>
void String<T>::StrAssign(String S)
{
    int k,j;
    for (k=1; k<S.length; k++)
        data[k]=S.data[k];
    length=S.length;
    data[0]=S.data[0];
}
/*
 *前置条件：串存在
 *输    入：无
 *功    能：串遍历输出
 *输    出：输出所有元素
 *后置条件：串不变
 */
template <class T>
void String<T>::PrintList()
{
    for(int i=1;i<=length;i++)
        std::cout<<data[i];
}