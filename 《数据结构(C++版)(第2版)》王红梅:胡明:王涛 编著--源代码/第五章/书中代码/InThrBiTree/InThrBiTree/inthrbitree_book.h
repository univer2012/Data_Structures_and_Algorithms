//
//  inthrbitree_book.h
//  InThrBiTree
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef __InThrBiTree__inthrbitree_book__
#define __InThrBiTree__inthrbitree_book__

#include <stdio.h>
enum flag {Child, Thread};   //枚举类型，枚举常量Child=0，Thread=1
template <class T>
struct ThrNode               //二叉线索树的结点结构
{
    T data;
    ThrNode<T> *lchild, *rchild;
    flag ltag, rtag;
};

template <class T>
class InThrBiTree {
public:
    InThrBiTree();
    ~InThrBiTree();
    ThrNode<T> *Next(ThrNode<T> *p);
    void InOrder();
private:
    ThrNode<T> *root;
    ThrNode<T> *Creat(ThrNode<T> *bt);
    void ThrBiTree(ThrNode<T> *bt,ThrNode<T> *pre);
};


#endif /* defined(__InThrBiTree__inthrbitree_book__) */
