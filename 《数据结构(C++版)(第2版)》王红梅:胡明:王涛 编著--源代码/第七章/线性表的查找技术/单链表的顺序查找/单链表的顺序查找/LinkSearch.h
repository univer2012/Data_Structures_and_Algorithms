//
//  LinkSearch.h
//  单链表的顺序查找
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef ____________LinkSearch__
#define ____________LinkSearch__

#include <stdio.h>
struct Node
{
    int data;
    Node *next;
};

class LinkSearch
{
public:
    void LinkList(int a[ ], int n);    //建立有n个元素的单链表
    void PrintList( );            //遍历单链表，按序号依次输出各元素
    int SeqSearch2(Node *first, int k);//查找单链表中是否存在元素k
    Node *GetFirst( );
private:
    Node *first;              //单链表的头指针
};
#endif /* defined(____________LinkSearch__) */
