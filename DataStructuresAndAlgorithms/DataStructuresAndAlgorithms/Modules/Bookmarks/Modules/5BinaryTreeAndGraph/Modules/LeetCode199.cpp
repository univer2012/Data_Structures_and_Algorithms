//
//  LeetCode199.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/12/1.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode199.hpp"

void Solution_BFS_print::BFS_print(TreeNode *root) {
    std::queue<TreeNode *> Q;
    Q.push(root);
    while (!Q.empty()) {
        TreeNode *node = Q.front();
        Q.pop();
        printf("[%d]\n",node->val);
        
        if (node->left) {
            Q.push(node->left);
        }
        if (node->right) {
            Q.push(node->right);
        }
    }
}


std::vector<int> Solution199::rightSideView(TreeNode *root) {
    std::vector<int> view;                      //按层遍历的最后一个节点
    std::queue< std::pair<TreeNode *, int> > Q; //宽度优先搜索队列<节点，层数>
    
    if (root) {
        Q.push(std::make_pair(root, 0));        //根节点非空时，将<root, 0> push进入队列
    }
    while (!Q.empty()) {
        TreeNode *node = Q.front().first;       //搜索节点
        int depth = Q.front().second;           //待搜索节点的层数
        Q.pop();
        
        if (view.size() == depth) {
            view.push_back(node->val);
        } else {
            view[depth] = node->val;
        }
        
        if (node->left) {
            Q.push(std::make_pair(node->left, depth + 1));
        }
        if (node->right) {
            Q.push(std::make_pair(node->right, depth + 1));
        }
    }
    return  view;
}
