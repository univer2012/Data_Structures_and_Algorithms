//
//  LinkList.h
//  HelloWorld
//
//  Created by huangaengoln on 15/10/5.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef HelloWorld_LinkList_h
#define HelloWorld_LinkList_h
template <class T>
struct Node {
    T data;
    Node<T> *next;
};
template <class T>

class LinkList {
public:
    LinkList( );  //建立只有头结点的空链表
    LinkList(T a[ ], int n);  //建立有n个元素的单链表
    ~LinkList();             //析构函数
    int Length();          //求单链表的长度
    T Get(int i);           //取单链表中第i个结点的元素值
    int Locate(T x);       //求单链表中值为x的元素序号
    void Insert(int i, T x);   //在单链表中第i个位置插入元素值为x的结点
    T Delete(int i);        //在单链表中删除第i个结点
    void PrintList( );           //遍历单链表，按序号依次输出各元素
private:
    Node<T> *first;  //单链表的头指针
    
};

#endif
