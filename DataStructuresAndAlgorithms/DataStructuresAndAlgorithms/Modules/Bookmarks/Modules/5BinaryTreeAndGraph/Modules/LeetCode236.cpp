//
//  LeetCode236.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/10/12.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode236.hpp"

TreeNode * Solution236::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode * q) {
    std::vector<TreeNode *> path;       //声明遍历用的临时栈
    std::vector<TreeNode *> node_p_path;    //存储p节点路径
    std::vector<TreeNode *> node_q_path;    //存储q节点路径
    int finish = 0;     //记录是否完成搜索的变量finish
    preorder(root, p, path, node_p_path, finish);
    
    //清空path、finish，计算q节点路径
    path.clear();
    finish = 0;
    preorder(root, q, path, node_q_path, finish);
    
    int path_len = 0;   //较短路径的长度
    if (node_p_path.size() < node_q_path.size()) {
        path_len = (int)node_p_path.size();
    } else {
        path_len = (int)node_q_path.size();
    }
    
    //同时遍历根到p，q两个节点的路径上的节点
    TreeNode *result = 0;
    for (int i = 0; i < path_len; i++) {
        if (node_p_path[i] == node_q_path[i]) {
            result = node_p_path[i];    //找到了最近公共祖先
        }
    }
    return result;
    
}

void Solution236::preorder(TreeNode *node,      //正在遍历的节点
              TreeNode *search,                 //待搜索节点
              std::vector<TreeNode *> &path,    //遍历时的节点路径栈
              std::vector<TreeNode *> &result,  //最终搜索到节点search的路径结果
              int &finish) {                    //记录是否找到节点search的变量，未找到时是0，找到为1
    
    if (!node || finish) {  //当node为空或已找到search节点直接返回，结束搜索
        return;
    }
    path.push_back(node);   //先序遍历时，将节点压入path栈
    if (node == search) {
        finish = 1;         //当找到search节点后，标记finish变量
        result = path;      //将当前的path存储到result中
    }
    
    preorder(node->left, search, path, result, finish);     //深度遍历node左孩子
    preorder(node->right, search, path, result, finish);    //深度遍历node右孩子
    path.pop_back();        //结束遍历node时，将node节点弹出path栈
}
