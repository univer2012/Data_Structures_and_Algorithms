//
//  node.h
//  学生会组织机构的设计方案
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef _____________node_h
#define _____________node_h

template <class T>
class Node
{
public:
    Node(T* data) {	_data = data; _firstChild = NULL; _brother = NULL;}//有参构造函数
    ~Node() {}//无参析构函数
    Node<T>* getFirstChild() { return _firstChild; } //访问结点第一个孩子
    Node<T>* getBrother() { return _brother; }       //访问结点的右兄弟
    T* getData() { return _data; }                   //取结点数据域的值
    
    void setFirstChild(Node<T>* node) { _firstChild = node; } //为结点的第一个孩子赋值
    void setBrother(Node<T>* node) { _brother = node; }//为结点的右兄弟赋值
    void setData(T* data) { _data = data; }              //为结点的数据域赋值
private:
    T* _data;                 //结点的数据域
    Node<T>* _firstChild;     //结点的头孩子指针
    Node<T>* _brother;        //结点的右兄弟指针
};

#endif
