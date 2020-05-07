//
//  bisorttree.h
//  二叉排序树查询
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef ___________bisorttree__
#define ___________bisorttree__

#include <stdio.h>

struct BiNode
{
    int data;
    BiNode *lchild, *rchild;
};

class BiSortTree    //假定记录中只有一个整型数据项
{
public:
    BiSortTree(int a[ ], int n);    //建立查找集合a[n]的二叉排序树
    ~BiSortTree(void);        //析构函数，释放二叉排序树中所有结点，同二叉链表的析构函数
    BiNode* Getroot( );       //获取指向根结点的指针
    BiNode* InsertBST(BiNode *root, BiNode *s);          //在二叉排序树中插入一个结点s
    void DeleteBST(BiNode *p, BiNode *f );               //删除结点f的左孩子结点p
    BiNode* SearchBST(BiNode *root, int k, int count);   //查找值为k的结点
private:
    BiNode *root;    //二叉排序树（即二叉链表）的根指针
    void Release(BiNode *root);   //析构函数调用
};

#endif /* defined(___________bisorttree__) */
