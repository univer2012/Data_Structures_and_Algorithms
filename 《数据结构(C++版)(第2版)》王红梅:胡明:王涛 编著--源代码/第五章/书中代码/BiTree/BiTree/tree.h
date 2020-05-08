//
//  tree.h
//  BiTree
//
//  Created by 远平 on 2020/5/7.
//  Copyright © 2020 huangaengoln. All rights reserved.
//

#ifndef tree_h
#define tree_h
#include "node.h"
#include <map>
using namespace std;

class BinaryTree
{
private:
    Node *root;
    
private:
    Node *create(map<int, int> &tree, int index);
    
public:
    BinaryTree();
    BinaryTree(map<int, int> &tree);
    ~BinaryTree();
    
public:
    int depth() const;
    int count() const;
    
public:
    void preOrder(Visit visit) const;//前序遍历二叉树
    void midOrder(Visit visit) const;//中序遍历二叉树
    void postOrder(Visit visit) const;//后序遍历二叉树
};

#endif
