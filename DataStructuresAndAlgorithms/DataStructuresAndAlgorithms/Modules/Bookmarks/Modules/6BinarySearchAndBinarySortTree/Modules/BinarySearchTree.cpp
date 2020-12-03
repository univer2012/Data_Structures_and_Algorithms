//
//  BinarySearchTree.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/12/3.
//  Copyright © 2020 blue. All rights reserved.
//

#include "BinarySearchTree.hpp"

void PrepareBinarySearchTree::test_insert() {
    //////     构建二叉查找（排序）树
    
    //将test中的节点，按顺序插入到root中
    TreeNode root(8);               //以8位根的二叉树
    std::vector<TreeNode *> node_vec;
    int test[] = {3, 10, 1, 6, 15};
    for (int i = 0; i < 5; i++) {
        node_vec.push_back(new TreeNode(test[i]));
    }
    for (int i = 0; i < node_vec.size(); i++) {
        BST_insert(&root, node_vec[i]);
    }
    //打印
    preorder_print(&root, 0);
    //删除
    for (int i = 0; i < node_vec.size(); i++) {
        delete node_vec[i];
    }
}

void PrepareBinarySearchTree::BST_insert(TreeNode *node, TreeNode *insert_node) {
    if (insert_node->val < node->val) {
        if (node->left) {   //当左子树不空的时候，递归地将insert_node插入左子树
            BST_insert(node->left, insert_node);
        }
        else {              //当左子树为空时，将node的左指针与待插入节点相连接
            node->left = insert_node;
        }
    } else {
        if (node->right) {  //当右子树不空的时候，递归地将insert_node插入右子树
            BST_insert(node->right, insert_node);
        }
        else {              //当右子树为空时，将node的右指针与待插入节点相连接
            node->right = insert_node;
        }
    }
}

//二叉树前序遍历
void PrepareBinarySearchTree::preorder_print(TreeNode *node, int layer) {
    if (!node) {
        return;
    }
    for (int i = 0; i < layer; i++) {
        printf("-----");
    }
    printf("[%d]\n", node->val);
    preorder_print(node->left, layer + 1);
    preorder_print(node->right, layer + 1);
}

// =================== =================== =================== =================== ===================

/// 预备知识：二叉查找树查找数值
void PrepareBinarySearchTree::test_search() {
    //构建 二叉查找树
    TreeNode a(8);
    TreeNode b(3);
    TreeNode c(10);
    TreeNode d(1);
    TreeNode e(6);
    TreeNode f(15);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    
    for (int i = 0; i < 20; i++) {
        if (BST_search(&a, i)) {
            printf("%d is in the BST.\n", i);
        } else {
            printf("%d is not in the BST.\n", i);
        }
    }
}


bool PrepareBinarySearchTree::BST_search(TreeNode *node, int value) {
    if (node->val == value) {
        return true;
    }
    if (value < node->val) {
        if (node->left) {
            return BST_search(node->left, value);
        }
        else {
            return false;
        }
    }
    else {
        if (node->right) {
            return BST_search(node->right, value);
        }
        else {
            return false;
        }
    }
}
