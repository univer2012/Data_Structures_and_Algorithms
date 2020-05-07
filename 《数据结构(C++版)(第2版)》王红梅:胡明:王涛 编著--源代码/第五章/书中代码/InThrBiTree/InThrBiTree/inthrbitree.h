//
//  inthrbitree.h
//  InThrBiTree
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//
//声明类InThrBiTree及定义结构ThrNode，文件名为inthrbitree.h
#ifndef __InThrBiTree__inthrbitree__
#define __InThrBiTree__inthrbitree__

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
class InThrBiTree
{
public:
    InThrBiTree( );      //构造函数，建立中序线索链表
    ~InThrBiTree( );     //析构函数，释放线索链表中各结点的存储空间
    ThrNode<T>* Getroot( );            //获取根结点
    ThrNode<T>* Next(ThrNode<T>* p);   //查找结点p的后继
    void InOrder(ThrNode<T>* root);    //中序遍历线索链表
private:
    ThrNode<T>* root;        //指向线索链表的头指针
    ThrNode<T>* Creat( );    //构造函数调用
    void ThrBiTree(ThrNode<T>* root,ThrNode<T> *pre);    //构造函数调用
    void Release(ThrNode<T>* root);       //析构函数调用
};

#endif /* defined(__InThrBiTree__inthrbitree__) */
