//
//  LeetCode114.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/11/27.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef LeetCode114_hpp
#define LeetCode114_hpp

#include <stdio.h>
/*
 例3：二叉树转链表
 给定一个二叉树，将该二叉树就地（in-place）转换为单链表。单链表中节点顺序为二叉树前序遍历顺序。
 
 选自 LeetCode114. Flatten Binary Tree to Linked List
 难度：Medium
 ------------ ------------ ------------ ------------ ------------ ------------ ------------
 例3：思考
 前序遍历二叉树，将节点指针push进入vector，顺序遍历
 
 
 */

#include "TreeNode.h"
#include <vector>

/// 方法1
class Solution114_1 {
public:
    void flatten(TreeNode *root);
    
private:
    void preorder(TreeNode *node, std::vector<TreeNode *> &node_vec);
};


/// 方法2
class Solution114_2 {
public:
    void flatten(TreeNode *root);
    
private:
    void preorder(TreeNode *node, TreeNode *& last);
};

#endif /* LeetCode114_hpp */
