//
//  inthrbitree.cpp
//  InThrBiTree
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

//定义类InThrBiTree中的成员函数，文件名为inthrbitree.cpp
#include<iostream>
#include<string>
#include"inthrbitree.h"
using namespace std;
/*
 *前置条件：中序线索二叉树不存在
 *输    入：无
 *功    能：构造一棵中序线索二叉树
 *输    出：无
 *后置条件：产生一棵中序线索二叉树
 */
template <class T>
InThrBiTree<T>::InThrBiTree( )
{
    ThrNode<T>* pre = NULL;
    this->root = Creat( );
    ThrBiTree(root,pre);
}
/*
 *前置条件：中序线索二叉树已存在
 *输    入：无
 *功    能：释放中序线索二叉链表中各结点的存储空间
 *输    出：无
 *后置条件：中序线索二叉树不存在
 */
template <class T>
InThrBiTree<T>::~InThrBiTree(void)
{
    Release(root);
}
/*
 *前置条件：中序线索二叉树已经存在
 *输    入：无
 *功    能：获取指向中序线索二叉树根结点的指针
 *输    出：指向中序线索二叉树根结点的指针
 *后置条件：中序线索二叉树不变
 */
template <class T>
ThrNode<T>* InThrBiTree<T>::Getroot( )
{
    return root;
}
/*
 *前置条件: 中序线索二叉树已经存在
 *输    入: 无
 *功    能: 查找结点p的后继结点
 *输    出：输出指向结点p的后继结点的指针
 *后置条件：中序线索二叉树不变
 */
template <class T>
ThrNode<T>* InThrBiTree<T>::Next(ThrNode<T>* p)
{
    ThrNode<T>* q;
    if (p->rtag==Thread)   q = p->rchild;  //右标志为1，可直接得到后继结点
    else{
        q = p->rchild;            //工作指针初始化
        while (q->ltag==Child)    //查找最左下结点
        {
            q = q->lchild;
        }
    }
    return q;
}

/*
 *前置条件：中序线索二叉树已经存在
 *输    入：无
 *功    能：中序遍历一棵线索二叉树
 *输    出：线索二叉树结点数据的一个线性排序
 *后置条件：中序线索二叉树不变
 */
template <class T>
void InThrBiTree<T>::InOrder(ThrNode<T> *root)
{
    ThrNode<T>* p = root;
    if (root==NULL)  return;     //如果线索链表为空，则空操作返回
    while (p->ltag==Child)       //查找中序遍历序列的第一个结点p并访问
    {
        p = p->lchild;
    }
    cout<<p->data<<" ";
    while (p->rchild!=NULL)      //当结点p存在后继，依次访问其后继结点
    {
        p = Next(p);
        cout<<p->data<<" ";
    }
    cout<<endl;
}
/*
 *前置条件：二叉树不存在
 *输    入：结点的数据值
 *功    能：构造一棵二叉树,构造函数调用
 *输    出：指向根结点的指针
 *后置条件：产生一棵二叉树
 */
template <class T>
ThrNode<T>* InThrBiTree<T>::Creat( )
{
    ThrNode<T> *root;
    T ch;
    cout<<"请输入创建一棵二叉树的结点数据"<<endl;
    cin>>ch;
    if (ch=="#") root = NULL;
    else{
        root=new ThrNode<T>;      //生成一个结点
        root->data = ch;
        root->ltag = Child;
        root->rtag = Child;
        root->lchild = Creat( );   //递归建立左子树
        root->rchild = Creat( );   //递归建立右子树
    }
    return root;
}
/*
 *前置条件：二叉树已经存在
 *输    入：无
 *功    能：给二叉树建立线索
 *输    出：无
 *后置条件：产生一棵中序线索二叉树
 */
template <class T>
void InThrBiTree<T>::ThrBiTree(ThrNode<T> *root,ThrNode<T> *pre)
{
    if (root==NULL) return;         //递归结束条件
    ThrBiTree(root->lchild,pre);
    if (!root->lchild){             //对root的左指针进行处理
        root->ltag = Thread;
        root->lchild = pre;        //设置pre的前驱线索
    }
    if (!root->rchild) root->rtag = Thread;          //对root的右指针进行处理
    if(pre != NULL){
        if (pre->rtag==Thread)  pre->rchild = root;    //设置pre的后继线索
    }
    pre = root;
    ThrBiTree(root->rchild,pre);
}
/*
 *前置条件：中序线索二叉树已经存在
 *输    入：无
 *功    能：释放中序线索二叉树的存储空间，析构函数调用
 *输    出：无
 *后置条件：中序线索二叉树不存在
 */
template<class T>
void InThrBiTree<T>::Release(ThrNode<T>* root)
{
    if (root!=NULL){
        Release(root->lchild);   //释放左子树
        Release(root->rchild);   //释放右子树
        delete root;
    }  
}
