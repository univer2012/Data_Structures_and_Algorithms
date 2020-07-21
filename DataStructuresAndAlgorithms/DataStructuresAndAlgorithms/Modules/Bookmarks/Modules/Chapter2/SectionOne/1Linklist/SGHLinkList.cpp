//
//  SGHLinkList.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/20.
//  Copyright © 2020 blue. All rights reserved.
//

#include "SGHLinkList.hpp"

#include <iostream>
using namespace std;


/*
 *前置条件：单链表不存在
 *输    入：无
 *功    能：构建一个单链表
 *输    出：无
 *后置条件：构建一个单链表
 */
template <class T>
LinkList<T>::LinkList()
{
    first=new Node<T>;      //生成头结点
    first->next = NULL ;    //头结点的指针域置为空
}

/*
 *前置条件：单链表不存在
 *输    入：顺序表信息的数组形式a[],单链表长度n
 *功    能：将数组a[]中元素建为长度为n的单链表
 *输    出：无
 *后置条件：构建一个单链表
 */
template <class T>
LinkList<T>::LinkList(T a[],int n) {
#if 0   /* 尾插法建立单链表 */
    first=new Node<T>;   //生成头结点
    Node<T> *r,*s;
    r=first;          //尾指针初始化
    for (int i=0; i<n; i++) {
        s=new Node<T>;s->data=a[i];  //为每个数组元素建立一个结点
        r->next=s;r=s;      //插入到终端结点之后
    }
    r->next=NULL;    //单链表建立完毕，将终端结点的指针域置空
    
#elif 1 /* 头插法建立单链表 */
    first=new Node<T>; first->next=NULL;    //初始化一个空链表
    Node<T> *s;
    for (int i=0; i<n; i++) {
        s=new Node<T>; s->data=a[i];            //为每个数组元素建立一个结点
        s->next=first->next;    first->next = s ;  //将结点 s 插入到头结点之后
    }
#endif
}

/*
 *前置条件：无
 *输    入：无
 *功    能：无
 *输    出：无
 *后置条件：无
 */
template <class T>
LinkList<T>::~LinkList() {
    Node<T> *q;
    while (first != NULL) {
        q=first;
        first=first->next;
        delete q;
    }
}

/*
 *前置条件：单链表存在
 *输    入：查询元素位置i
 *功    能：按位查找位置为i的元素并输出值
 *输    出：查询元素的值
 *后置条件：单链表不变
 */
template <class T>
T LinkList<T>::Get(int i) {
    Node<T> *p;int j;
    p=first->next;  j=1;    //工作指针p 和 累加器 i 初始化
    while (p && j<i) {
        p=p->next;      //各种指针 p 后移
        j++;
    }
    if (!p) throw "p为空";
    else return p->data;
}

/*
 *前置条件：单链表存在
 *输    入：查询元素值x
 *功    能：按值查找值的元素并输出位置
 *输    出：查询元素的位置
 *后置条件：单链表不变
 */
template <class T>
int LinkList<T>::Locate(T x) {
    Node<T> *p;int j;
    p=first->next;j=1;      //工作指针p 和 累加器 i 初始化
#if 0
    if (p && p->next) {
        while (p->data != x) {
            p=p->next;
            j++;
        }
        return j;
    } else throw "p为空";
#endif
    while (p != NULL) {
        if (p->data == x) return j; //查找成功，结束函数并返回序号
        p=p->next;
        j++;
    }
    return 0;   //退出循环表明查找失败
}

/*
 *前置条件：单链表存在
 *输    入：插入元素x,插入位置i
 *功    能：将元素x插入到单链表中位置i处
 *输    出：无
 *后置条件：单链表插入新元素
 */
template <class T>
void LinkList<T>::Insert(int i, T x) {
    Node<T> *p;int j;
    p=first;j=0;        //工作指针 p 硬纸箱头结点
    while (p && j<i-1) {    //查找第 i-1个节点
        p=p->next;          //各种指针 p 后移
        j++;
    }
    if (!p) throw "位置";     //没有找到第 i-1 个结点
    else {
        Node<T> *s;
        s=new Node<T>;
        s->data=x;           //申请一个结点s，其数据域为x
        s->next=p->next;
        p->next=s;           //将结点s插入到结点 p 之后
    }
}

/*
 *前置条件：单链表存在
 *输    入：无
 *功    能：输出单链表长度
 *输    出：单链表长度
 *后置条件：单链表不变
 */
template <class T>
int LinkList<T>::Length() {
    Node<T> *p=first->next; int i=0;    //工作指针p和累加器 i 初始化
    while (p) {
        p=p->next;
        i++;
    }
    return i;       //注意 i 的初始化和返回值之间的关系
}

/*
 *前置条件：单链表存在
 *输    入：要删除元素位置i
 *功    能：删除单链表中位置为i的元素
 *输    出：无
 *后置条件：单链表删除元素
 */
template <class T>
T LinkList<T>::Delete(int i) {
    Node<T> *p; int j;
    p=first;j=0;        //注意工作指针 p 要指向头结点
    while (p && j<i-1) {    //查找第 i-1 个结点
        p=p->next;
        j++;
    }
    if (!p || !p->next) throw "位置"; //结点 p 不存在或 p 的后继结点不存在
    else {
        Node<T> *q;int x;
        q=p->next;x=q->data;        //暂存被删结点
        p->next=q->next;            //摘链
        delete q;
        return x;
    }
}

/*
 *前置条件：单链表存在
 *输    入：无
 *功    能：单链表遍历
 *输    出：输出所有元素
 *后置条件：单链表不变
 */
/* 单链表遍历算法 */
template <class T>
void LinkList<T>::PrintList() {
    Node<T> *p;
    p=first->next;          //工作指针p初始化
    while (p != NULL) {
        cout <<p->data<<endl;
        p=p->next;          //工作指针p后移，注意不能写作p++
    }
}
