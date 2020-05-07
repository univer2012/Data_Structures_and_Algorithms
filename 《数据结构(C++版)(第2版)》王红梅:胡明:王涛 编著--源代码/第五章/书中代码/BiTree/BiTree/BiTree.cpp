//
//  BiTree.cpp
//  BiTree
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//
//定义类中的成员函数，文件名为bitree.cpp
#include<iostream>
#include<string>

#include"bitree.h"

using namespace std;

///构造一棵二叉树
template<class T>
BiTree<T>::BiTree( )
{
    this->root = Creat( );
}

///释放二叉链表中各结点的存储空间
template<class T>
BiTree<T>::~BiTree(void)
{
    Release(root);
}

///获取指向二叉树根结点的指针
template<class T>
BiNode<T>* BiTree<T>::Getroot( )
{
    return root;
}

///前序遍历二叉树
template<class T>
void BiTree<T>::PreOrder(BiNode<T> *root)
{
    if(root==NULL)  return;
    else{
        cout<<root->data<<" ";
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

///中序遍历二叉树
template <class T>
void BiTree<T>::InOrder (BiNode<T> *root)
{
    if (root==NULL)  return;      //递归调用的结束条件
    else{
        InOrder(root->lchild);    //中序递归遍历root的左子树
        cout<<root->data<<" ";    //访问根结点的数据域
        InOrder(root->rchild);    //中序递归遍历root的右子树
    }
}

///后序遍历二叉树
template <class T>
void BiTree<T>::PostOrder(BiNode<T> *root)
{
    if (root==NULL)   return;       //递归调用的结束条件
    else{
        PostOrder(root->lchild);    //后序递归遍历root的左子树
        PostOrder(root->rchild);    //后序递归遍历root的右子树
        cout<<root->data<<" ";      //访问根结点的数据域
    }
}

///层序遍历二叉树
template <class T>
void BiTree<T>::LeverOrder(BiNode<T> *root)
{
    const int MaxSize = 100;
    
    int front = 0;
    int rear = 0;  //采用顺序队列，并假定不会发生上溢
    
    BiNode<T>* Q[MaxSize];
    BiNode<T>* q;
    
    if (root==NULL) return;
    else{
        Q[rear++] = root;
        while (front != rear)
        {
            q = Q[front++];
            cout<<q->data<<" ";
            if (q->lchild != NULL)    Q[rear++] = q->lchild;
            if (q->rchild != NULL)    Q[rear++] = q->rchild;
        }
    }
}

///初始化一棵二叉树,构造函数调用
template <class T>
BiNode<T>* BiTree<T>::Creat( )
{
    BiNode<T>* root;
    T ch;
    cout<<"请输入创建一棵二叉树的结点数据"<<endl;
    cin>>ch;
    if (ch=="#") root = NULL;
    else{
        root = new BiNode<T>;       //生成一个结点
        root->data=ch;
        root->lchild = Creat( );    //递归建立左子树
        root->rchild = Creat( );    //递归建立右子树
    }
    return root;
}

///释放二叉树的存储空间，析构函数调用
template<class T>
void BiTree<T>::Release(BiNode<T>* root)
{
    if (root != NULL){
        Release(root->lchild);   //释放左子树
        Release(root->rchild);   //释放右子树
        delete root;
    }  
}











