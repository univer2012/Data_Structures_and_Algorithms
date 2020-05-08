//
//  node.h
//  BiTree
//
//  Created by 远平 on 2020/5/7.
//  Copyright © 2020 huangaengoln. All rights reserved.
//

#ifndef node_h
#define node_h
#include<iostream>
#include<cmath>
using namespace std;

class Node;
typedef void (*Visit)(const Node *node);
class Node
{
public:
    int nodeValue;
    Node *l_child;
    Node *r_child;
    
public:
    Node(int value = 0);
    ~Node();
    
public:
    int degree() const;
    int depth() const;
    int count() const;
    
public:
    void preOrder(Visit visit) const;
    void midOrder(Visit visit) const;
    void postOrder(Visit visit) const;
};

#endif /* node_h */
