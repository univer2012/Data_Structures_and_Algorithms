//
//  LinkStack.cpp
//  链栈
//
//  Created by huangaengoln on 15/10/5.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include "LinkStack.h"

template <class T>
LinkStack<T>::LinkStack()
{
    top=NULL;
}

template <class T>
LinkStack<T>::~LinkStack()
{
    while (top)
    {
        Node<T> *p;
        p=top->next;
        delete top;
        top=p;
    }
}

template<class T>
void LinkStack<T>::Push(T x)
{
    Node<T> *s;
    s=new Node<T>;
    s->data = x;     //申请一个数据域为x的结点 s
    s->next = top;
    top=s;           //将结点 s 插在栈顶
}

template <class T>
T LinkStack<T>::Pop()
{
    Node<T> *p;
    int x;
    if (top==NULL) throw "下溢";
    x=top->data;            //暂存栈顶元素
    p=top;
    top=top->next;         //将栈顶结点摘链
    delete p;
    return x;
}

template <class T>
T LinkStack<T>::GetTop()
{
    if (top!=NULL)
        return top->data;
    return 0;
}

//template <class T>
//bool LinkStack<T>::Empty()
//{
//    return top == NULL ? 1 : 0;
//}





