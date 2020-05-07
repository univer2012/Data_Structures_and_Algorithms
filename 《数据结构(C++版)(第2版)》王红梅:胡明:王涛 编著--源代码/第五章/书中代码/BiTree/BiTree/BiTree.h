//
//  BiTree.h
//  BiTree
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//
//声明类BiTree及定义结构BiNode,文件名为bitree.h
#ifndef __BiTree__BiTree__
#define __BiTree__BiTree__

#include <stdio.h>

//二叉树的结点结构
template <class T>
struct BiNode
{
    T data;
    BiNode<T> *lchild, *rchild;
};


template <class T>
class BiTree
{
public:
    BiTree( );             //构造函数，初始化一棵二叉树，其前序序列由键盘输入
    ~BiTree(void);         //析构函数，释放二叉链表中各结点的存储空间
    BiNode<T>* Getroot();  //获得指向根结点的指针
    void PreOrder(BiNode<T> *root);     //前序遍历二叉树
    void InOrder(BiNode<T> *root);      //中序遍历二叉树
    void PostOrder(BiNode<T> *root);    //后序遍历二叉树
    void LeverOrder(BiNode<T> *root);   //层序遍历二叉树
    
private:
    BiNode<T> *root;         //指向根结点的头指针
    BiNode<T> *Creat( );     //有参构造函数调用
    void Release(BiNode<T> *root);   //析构函数调用
};

#endif /* defined(__BiTree__BiTree__) */
