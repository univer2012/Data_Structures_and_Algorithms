//
//  tree.h
//  学生会组织机构的设计方案
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef ________________tree__
#define ________________tree__

#include <stdio.h>
#include "node.h"
#include<string>
typedef void (*Function)(void* node);  //声明函数指针

template <class T>
class Tree
{
    Node<T>* _root;					//指向根结点的头指针
    T* _tempData;                   //结点数据域中的数据
public:
    Tree(T* data) {_root = new Node<T>(data);}  //有参构造函数，初始化一棵树的根结点
    ~Tree(void)  {Release(_root);}            //析构函数，释放树中各结点的存储空间
    void Insert(T* oldData, T* newData);    //插入函数
    void Delete(T* data);			  //删除树中某结点及其孩子结点
    void Update(T* oldData, T* newData);        //修改函数
    Node<T>* FindNode(std::string position,Function function); //查询函数
    void LeverOrder(Function function);   //层序遍历树
    
private:
    void Release(Node<T>* node);   //析构函数调用
    Node<T>* FindNode(T* data);    //插入函数调用
    void InsertBrother(Node<T>* node,T* data);     //插入兄弟结点点
    void InsertChild(Node<T>* node, T* data);      //插入第一个孩子结点
    
};

#endif /* defined(________________tree__) */
