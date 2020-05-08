//
//  tree.cpp
//  BiTree
//
//  Created by 远平 on 2020/5/7.
//  Copyright © 2020 huangaengoln. All rights reserved.
//

#include <stdio.h>
#include "tree.h"

BinaryTree::BinaryTree()
{
    root = NULL;
}

Node* BinaryTree::create(map<int, int> &tree, int index)
{
    if(tree.find(index) == tree.end())
    {
        return NULL;
    }
    Node *node = new Node();
    node->nodeValue = tree[index];
    node->l_child = create(tree, index * 2);
    node->r_child = create(tree, index * 2 + 1);
    return node;
}

BinaryTree::BinaryTree(map<int, int> &tree)
{
    root = create(tree, 1);
}

BinaryTree::~BinaryTree()
{
    if(root != NULL)
    {
        delete root;
    }
}

int BinaryTree::depth() const
{
    return root->depth();
}

int BinaryTree::count() const
{
    return root->count();
}

void BinaryTree::preOrder(Visit visit) const
{
    root->preOrder(visit);
    cout << endl;
}

void BinaryTree::midOrder(Visit visit) const
{
    root->midOrder(visit);
    cout << endl;
}

void BinaryTree::postOrder(Visit visit) const
{
    root->postOrder(visit);
    cout << endl;
}
