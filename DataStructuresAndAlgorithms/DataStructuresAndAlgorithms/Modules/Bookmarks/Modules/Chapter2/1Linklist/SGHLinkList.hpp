//
//  SGHLinkList.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/16.
//  Copyright © 2020 blue. All rights reserved.
//
/*默认是不认`template <class T>`的，解决办法在：
 https://blog.csdn.net/opengl_es/article/details/17544937
 */
#ifndef SGHLinkList_hpp
#define SGHLinkList_hpp

#include <stdio.h>

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



#endif /* SGHLinkList_hpp */
