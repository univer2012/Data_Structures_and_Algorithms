//
//  node.cpp
//  BiTree
//
//  Created by 远平 on 2020/5/7.
//  Copyright © 2020 huangaengoln. All rights reserved.
//

#include <stdio.h>

#include "node.h"

Node::Node(int value):nodeValue(value)
{
    l_child = NULL;
    r_child = NULL;
}

Node::~Node()
{
    if(l_child != NULL)
    {
        delete l_child;
    }
    if(r_child != NULL)
    {
        delete r_child;
    }
}

int Node::degree() const
{
    if(l_child == NULL && r_child == NULL)
    {
        return 0;
    }
    if(l_child != NULL && r_child != NULL)
    {
        return 2;
    }
    return 1;
}

int Node::depth() const
{
    int l_depth = 0;
    int r_depth = 0;
    if(l_child != NULL)
    {
        l_depth += l_child->depth();
    }
    if(r_child != NULL)
    {
        r_depth += r_child->depth();
    }
    return max(l_depth, r_depth) + 1;
}

int Node::count() const
{
    int l_count = 0;
    int r_count = 0;
    if(l_child != NULL)
    {
        l_count += l_child->count();
    }
    if(r_child != NULL)
    {
        r_count += r_child->count();
    }
    return l_count + r_count + 1;
}

void Node::preOrder(Visit visit) const
{
    (*visit)(this);
    if(this->l_child != NULL)
    {
        this->l_child->preOrder(visit);
    }
    if(this->r_child != NULL)
    {
        this->r_child->preOrder(visit);
    }
}

void Node::midOrder(Visit visit) const
{
    if(this->l_child != NULL)
    {
        this->l_child->preOrder(visit);
    }
    (*visit)(this);
    if(this->r_child != NULL)
    {
        this->r_child->preOrder(visit);
    }
}

void Node::postOrder(Visit visit) const
{
    if(this->l_child != NULL)
    {
        this->l_child->preOrder(visit);
    }
    if(this->r_child != NULL)
    {
        this->r_child->preOrder(visit);
    }
    (*visit)(this);
}
