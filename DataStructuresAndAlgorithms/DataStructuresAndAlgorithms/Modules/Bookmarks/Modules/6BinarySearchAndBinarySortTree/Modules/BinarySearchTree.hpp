//
//  BinarySearchTree.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/12/3.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>

#include "TreeNode.h"

#include <vector>


class PrepareBinarySearchTree {
public:
    /// 预备知识：二叉查找树插入节点
    void test_insert();
    /// 预备知识：二叉查找树查找数值
    void test_search();
    
private:
    //插入
    void BST_insert(TreeNode *node, TreeNode *insert_node);
    //二叉树前序遍历
    void preorder_print(TreeNode *node, int layer);
    
    bool BST_search(TreeNode *node, int value);
};

#endif /* BinarySearchTree_hpp */
