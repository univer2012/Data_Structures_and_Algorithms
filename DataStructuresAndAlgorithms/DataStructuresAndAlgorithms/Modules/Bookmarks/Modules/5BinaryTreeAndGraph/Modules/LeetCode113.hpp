//
//  LeetCode113.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/10/12.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef LeetCode113_hpp
#define LeetCode113_hpp

#include <stdio.h>
#include <vector>
#include "TreeNode.h"

/*
 例1：路径之和2
 给定一个二叉树与整数sum，找出所有从根节点到叶节点的路径，这些路径上的节点值累加和为sum。
 
 选自 LeetCode 113. Path Sum II
 难度：Medium
 
 例如，sum=22，输出 [[5,4,11,2], [5,8,4,5]]
      5
    /   \
   4     8
  /    /  \
 11   13   4
 / \       / \
 7  2     5   1
 
 */

/*
 例1：思考
 深度所搜所有从根节点到叶节点的路径，检查各路径上的所有节点的值的和是否为sum。
 
 思考：
 1.使用何种数据结构存储遍历路径上的节点？
 2.在树的前序遍历时做什么？后续遍历时做什么？
 3.如何判断一个节点为叶节点？当遍历到叶节点时应该做什么？
 
 */

/*
 例1：算法思路
 1.从根节点深度办理二叉树，先序遍历时，将该节点值存储至path栈中（vector实现），使用path_value累加节点值。
 2.当遍历至叶节点时，检查path_value值是否为sum，若为sum，则将path push进入result结果中。
 3.在后续遍历时，将该节点值从path栈中弹出，path_value减去节点值。
 */

class Solution113 {
public:
    std::vector<std::vector<int>> pathSum(TreeNode * root, int sum);
    
private:
    void preorder(TreeNode *node, int &path_value, int sum, std::vector<int> &path, std::vector<std::vector<int>> &result);
};

#endif /* LeetCode113_hpp */
