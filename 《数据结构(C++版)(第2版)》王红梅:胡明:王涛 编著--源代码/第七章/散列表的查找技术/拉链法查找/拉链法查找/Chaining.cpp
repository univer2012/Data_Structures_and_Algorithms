//
//  Chaining.cpp
//  拉链法查找
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include "LinkList.h"
/*
 * 前置条件：链表已存在
 * 输    入：插入位置i；待插节点x
 * 功    能：在链表的第i个位置处插入一个新节点
 * 输    出：若插入不成功，抛出异常
 * 后置条件：若插入成功，表中增加了一个新节点
 */
void LinkList::Insert(Node *p, int k)
{
    while (p->next != 0)
    {
        p=p->next;     //工作指针p后移
    }
    if (!p)
        throw "位置";
    else
    {
        Node *s;
        s=new Node;
        s->data=k;             //向内存申请一个结点s，其数据域为x
        s->next=0;       //将结点s插入到结点p之后
        p->next=s;
    }
}
/*
 *开散列表的建立
 */

void LinkList::Build(Node *T[], int k, int m)
{
    int j=k%m;
    if (T[j]==0){
        Node *s;
        s=new Node;
        s->data=k;             //向内存申请一个结点s，其数据域为x
        s->next=0;
        T[j]=s;
    }
    else{
        Insert(T[j],k);
    }
}
/*
 *开散列表的查找
 */

Node *HashSearch2(Node *ht[], int m, int k)
{
    Node *p;
    int j=k%m;
    p=ht[j];
    while ( p->data!=k)
        p=p->next;
    if (p->data==k)
        return p;
    else
    {
        throw"fail";
    }
}


