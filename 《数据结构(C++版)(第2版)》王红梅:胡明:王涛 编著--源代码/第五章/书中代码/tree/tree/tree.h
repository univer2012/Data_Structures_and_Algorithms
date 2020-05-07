//
//  tree.h
//  tree
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef __tree__tree__
#define __tree__tree__

//声明树中的类以及结点结构，文件名为tree.h

#include <stdio.h>

//树中结点采用 「孩子兄弟表示法」
template <class T>
struct TNode
{
    T data;
    TNode<T> *firstchild, *rightsib;
};

template <class T>
class Tree
{
public:
    Tree( );               //构造函数，初始化一棵树，其前序序列由键盘输入
    ~Tree(void);           //析构函数，释放树中各结点的存储空间
    TNode<T>* Getroot( );  //获得指向根结点的指针
    void PreOrder(TNode<T> *root);     //前序遍历树
    void PostOrder(TNode<T> *root);    //后序遍历树
    void LeverOrder(TNode<T> *root);   //层序遍历树
private:
    TNode<T> *root;         //指向根结点的头指针
    void Release(TNode<T> *root);   //析构函数调用
};

#endif /* defined(__tree__tree__) */
