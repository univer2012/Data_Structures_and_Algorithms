//
//  tree.cpp
//  tree
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

//定义类中的成员函数，文件名为tree.cpp
#include<iostream>
#include<string>
#include"tree.h"
using namespace std;

/*
 *前置条件：树不存在
 *输    入：无
 *功    能：构造一棵树
 *输    出：无
 *后置条件：产生一棵树
 */
template<class T>
Tree<T>::Tree( )
{
    const int MaxSize = 100;
    int end = 0;
    int front = 0;
    int rear  = 0;  //采用顺序队列，并假定不会发生上溢
    int j = 0;
    TNode<T>* queue[MaxSize]; //声明一个队列
    TNode<T>* tempNode;              //声明指向结点类型的指针
    TNode<T>* brotherNode;   //工作指针
    TNode<T>* q;
    T ch;
    cout<<"请输入创建一棵树的根结点数据"<<endl;
    cin>>ch;
    root = new TNode<T>;
    root->data = ch;
    root->firstchild = NULL;
    root->rightsib = NULL;
    queue[rear++] = root;
    while (!end)    //若继续创建树
    {
        T ch1,ch2;
        cout<<"请输入创建一棵树的父结点数据和孩子结点数据"<<endl;
        cin>>ch1>>ch2;
        TNode<T>* p = new TNode<T>;       //生成一个结点
        p->data = ch2;
        p->firstchild = NULL;
        p->rightsib = NULL;
        queue[rear++] = p;
        tempNode = queue[front];//头结点出队，同时对头元素的标识符后移
        while(ch1 != tempNode->data)
            tempNode = queue[front++];
        if(tempNode->firstchild == NULL)	tempNode->firstchild = p;
        else{
            brotherNode = tempNode->firstchild;  //工作指针指向结点的第一个孩子
            while (brotherNode != NULL)          //若第一个孩子有兄弟结点
            {
                q = brotherNode;
                brotherNode = brotherNode->rightsib;//工作指针指向第一个孩子的右兄弟
            }
            q->rightsib = p;
        }
        cout<<"创建结束? 如果结束请按1否则请按0 "<<endl;
        cin>>end;
    }
}
/*
 *前置条件：树已存在
 *输    入：无
 *功    能：释放树中各结点的存储空间
 *输    出：无
 *后置条件：树不存在
 */
template<class T>
Tree<T>::~Tree(void)
{
    Release(root);
}
/*
 *前置条件：树已存在
 *输    入：无
 *功    能：获取指向树根结点的指针
 *输    出：指向树根结点的指针
 *后置条件：树不变
 */
template<class T>
TNode<T>* Tree<T>::Getroot( )
{
    return root;
}
/*
 *前置条件：树已存在
 *输    入：无
 *功    能：前序遍历树
 *输    出：树中结点的一个线性排列
 *后置条件：树不变
 */
template<class T>
void Tree<T>::PreOrder(TNode<T> *root)      //前序遍历树
{
    if (root == NULL)  return;     //递归调用的结束条件
    else{
        cout<<root->data;          //打印根节点
        PreOrder(root->firstchild);    //前序递归遍历root的第一个孩子
        PreOrder(root->rightsib);    //前序递归遍历root的右兄弟
    }
}
/*
 *前置条件：树已存在
 *输    入：无
 *功    能：后序遍历树
 *输    出：树中结点的一个线性排列
 *后置条件：树不变
 */
template<class T>
void Tree<T>::PostOrder(TNode<T> *root)
{
    if (root == NULL)  return;     //递归调用的结束条件
    else{
        PostOrder(root->firstchild);    //后序递归遍历root的第一个孩子
        cout<<root->data;               //打印出root结点
        PostOrder(root->rightsib);      //后序递归遍历root的右兄弟
    }
}
/*
 *前置条件：树已存在
 *输    入：无
 *功    能：层序遍历树
 *输    出：树中结点的一个线性排列
 *后置条件：树不变
 */
template<class T>
void Tree<T>::LeverOrder(TNode<T> *root)
{
    const int MAX_QUEUE_SIZE = 100;
    int front = 0;
    int rear  = 0;  //采用顺序队列，并假定不会发生上溢
    TNode<T>* queue[MAX_QUEUE_SIZE]; //声明一个队列
    TNode<T>* tempNode;      //声明指向结点类型的指针
    TNode<T>* brotherNode;   //工作指针
    
    if (root == NULL) return;//循环结束条件
    queue[rear++] = root;    //否则结点入队
    while (front != rear)    //若队列中有结点
    {
        tempNode = queue[front++];//头结点出队，同时对头元素的标识符后移
        cout<<tempNode->data;     //打印出头结点
        brotherNode = tempNode->firstchild;  //工作指针指向结点的第一个孩子
        while (brotherNode != NULL)          //若第一个孩子有兄弟结点
        {
            queue[rear++] = brotherNode;     //第一个孩子结点入队
            brotherNode = brotherNode->rightsib;//工作指针指向第一个孩子的右兄弟
        }
    }
}
/*
 *前置条件：树已经存在
 *输    入：无
 *功    能：释放树的存储空间，析构函数调用
 *输    出：无
 *后置条件：树不存在
 */
template <class T>
void Tree<T>::Release(TNode<T>* root)
{
    if (root != NULL){ 	
        Release (root->firstchild);   //释放第一个孩子
        Release (root->rightsib);   //释放右兄弟
        delete root;
    }
}








