//
//  inthrbitree_book.cpp
//  InThrBiTree
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include "inthrbitree_book.h"
#include <string>
using namespace std;
#include <iostream>


template <class T>
ThrNode<T> * InThrBiTree<T>::Creat(ThrNode<T> *bt) {
    T ch;
    cin>>ch;
    if (ch == '#') bt=NULL;
    else {
        bt=new ThrNode<T>;bt->data=ch;
        bt->ltag=0;bt->rtag=0;
        bt->lchild=Creat(bt->lchild);
        bt->rchild=Creat(bt->rchild);
    }
    return bt;
}
//中序线索化链表算法
template <class T>
void InThrBiTree<T>::ThrBiTree(ThrNode<T> *bt,ThrNode<T> *pre)
{
    if (bt==NULL) return;         //递归结束条件
    ThrBiTree(bt->lchild,pre);
    if (!bt->lchild){             //对root的左指针进行处理
        bt->ltag = Thread;
        bt->lchild = pre;        //设置pre的前驱线索
    }
    if (!bt->rchild) bt->rtag = Thread;          //对root的右指针进行处理
    if(pre != NULL){
        if (pre->rtag==Thread)  pre->rchild = bt;    //设置pre的后继线索
    }
    pre = bt;
    ThrBiTree(bt->rchild,pre);
}

template <class T>
InThrBiTree<T>::InThrBiTree() {
    root=Creat(root);
    ThrNode<T> *pre;
    pre=NULL;
    ThrBiTree(root, pre);
}

template <class T>
ThrNode<T>* InThrBiTree<T>::Next(ThrNode<T>* p)
{
    ThrNode<T>* q;
    if (p->rtag==1)   q = p->rchild;  //右标志为1，可直接得到后继结点
    else{
        q = p->rchild;            //工作指针初始化
        while (q->ltag==0)    //查找最左下结点
        {
            q = q->lchild;
        }
    }
    return q;
}

template <class T>
void InThrBiTree<T>::InOrder()
{
    ThrNode<T>* p = root;
    if (root==NULL)  return;     //如果线索链表为空，则空操作返回
    p=root;
    while (p->ltag==0) {
        p=p->lchild;
    }
    cout<<p->data;
    while (p->rchild != NULL) {
        p=Next(p);
        cout<<p->data;
    }
}


