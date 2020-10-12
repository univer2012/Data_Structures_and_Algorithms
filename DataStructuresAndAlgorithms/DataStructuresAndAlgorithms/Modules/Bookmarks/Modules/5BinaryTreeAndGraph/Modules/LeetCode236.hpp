//
//  LeetCode236.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/10/12.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef LeetCode236_hpp
#define LeetCode236_hpp

#include <stdio.h>
#include "TreeNode.h"
#include <vector>
/*
 例2：最近的公共祖先
 
 已知二叉树，求二叉树中给定的两个节点的最近公共祖先。
 最近公共祖先：两节点v与w的最近公共祖先u，满足在树上最低（离根最远），且v，w两个节点都是u的子孙。
 
 选自 LeetCode 236. Lowest Common Ancestor of a Binary Tree
 难度：Medium
 
         3
        /  \
      5     1
     /  \  /  \
    6   2  0   8
       / \
      7   4
 p = [3,5,6]
 q = [3,5,2,4]
 ------------ ------------ ------------ ------------ ------------ ------------ ------------
 例2：思考与分析
 1.两个节点的公共祖先一定在从根节点，至这两个节点的路径上。
 2.由于求公共祖先中的最近公共祖先，那么即同时出现在这两条路径上的离根节点最远的节点（或离两个最近）。
 3.最终算法即：求p节点路径，q节点路径，两路径上最后一个相同的节点。
 
 ------------ ------------ ------------ ------------ ------------ ------------ ------------
 例2：求根节点至某节点路径（深度搜索）
 1.从根节点遍历（搜索）至该节点，找到该节点后就结束搜索。
 2.将遍历过程中遇到的节点按照顺序存储起来，这些节点即路径节点。
 
 ------------ ------------ ------------ ------------ ------------ ------------ ------------
 例2：求两路径上租后一个相同的节点
 1.求出较短路径的长度n。
 2.同时遍历p节点的路径与q节点的路径，遍历n个节点，最后一个发现的相同节点，即最近公共祖先。
 */


class Solution236 {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode * q);
private:
    //求根节点至某节点路径（实现）
    void preorder(TreeNode *node,
                  TreeNode *search,
                  std::vector<TreeNode *> &path,
                  std::vector<TreeNode *> &result,
                  int &finish);
};

#endif /* LeetCode236_hpp */
