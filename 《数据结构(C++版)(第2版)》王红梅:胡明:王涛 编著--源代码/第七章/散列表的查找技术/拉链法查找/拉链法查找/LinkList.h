//
//  LinkList.h
//  拉链法查找
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef ______LinkList_h
#define ______LinkList_h

struct Node
{
    int data;
    Node *next;
};

class LinkList
{
public:
    //LinkList( ){first=new Node; first->next=NULL;}  //建立只有头结点的空链表
    //~LinkList(){}             //析构函数
    void Insert(Node *p, int k);//在单链表中第i个位置插入元素值为x的结点
    Node* GetFirst(){return first;}
    void Build(Node *T[], int k, int m);
private:
    Node *first;  //单链表的头指针
};

#endif
