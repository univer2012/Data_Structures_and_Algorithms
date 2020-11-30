//
//  LeetCode114.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/11/27.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode114.hpp"

void Solution114_1::flatten(TreeNode *root) {
    std::vector<TreeNode *> node_vec;
    preorder(root, node_vec);
    for (int i = 1; i < node_vec.size(); i++) {
        node_vec[i - 1]->left = NULL;
        node_vec[i - 1]->right = node_vec[i];
    }
}

void Solution114_1::preorder(TreeNode *node, std::vector<TreeNode *> &node_vec) {
    if (!node) {
        return;
    }
    preorder(node->left, node_vec);
    preorder(node->right, node_vec);
}

// ====

void Solution114_2::flatten(TreeNode *root) {
    TreeNode *last = NULL;
    preorder(root, last);
}
/*
 @param last:当前子树的先序遍历的最后一个节点，传引用会传出
 @param node:当前的节点
 */
void Solution114_2::preorder(TreeNode *node, TreeNode *& last) {
    if (!node) {
        return;
    }
    if (!node->left && !node->right) {
        last = node;
        return;
    }
    TreeNode *left = node->left;    //备份左右指针
    TreeNode *right = node->right;
    TreeNode *left_last = NULL;     //左右子树最后一个节点
    TreeNode *right_last = NULL;
    
    //若有左子树，递归将左子树转换单链表
    if (left) {
        preorder(left, left_last);
        node->left = NULL;          //左指针赋空
        node->right = left;
        last = left_last;           //将该节点的last保存为左子树的last
    }
    
    //若有右子树，递归将右子树转换单链表
    if (right) {
        preorder(right, right_last);
        if (left_last) {            //若node找到左子树最后一个节点（有左子树）
            left_last-> right = right;
        }
        last = right_last;
    }
}
