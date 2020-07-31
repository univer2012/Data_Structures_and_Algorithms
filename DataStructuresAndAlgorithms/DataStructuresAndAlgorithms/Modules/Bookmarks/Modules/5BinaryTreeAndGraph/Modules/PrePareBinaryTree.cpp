//
//  PrePareBinaryTree.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/31.
//  Copyright © 2020 blue. All rights reserved.
//

#include "PrePareBinaryTree.hpp"


void PrePareBinaryTree::preorder_print(TreeNode *node, int layer) {
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

void PrePareBinaryTree::sec1demo1() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    
    preorder_print(&a, 0);
}
