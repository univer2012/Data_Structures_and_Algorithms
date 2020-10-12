//
//  LeetCode113.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/10/12.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode113.hpp"

std::vector<std::vector<int>> Solution113::pathSum(TreeNode * root, int sum) {
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    int path_value = 0;
    preorder(root, path_value, sum, path, result);
    return result;
}


void Solution113::preorder(TreeNode *node, int &path_value, int sum,
                           std::vector<int> &path,
                           std::vector<std::vector<int>> &result) {
    
    if (!node) {
        return;
    }
    //遍历一个节点即更新一次路径值
    path_value += node->val;
    path.push_back(node->val);
    
    //满足条件时，将path添加至结果数组
    if (!node->left && !node->right && path_value == sum) {
        result.push_back(path);
    }
    preorder(node->left, path_value, sum, path, result);
    preorder(node->right, path_value, sum, path, result);
    
    //遍历完成后，将该节点送路径栈中弹出
    path_value -= node->val;
    path.pop_back();
}
