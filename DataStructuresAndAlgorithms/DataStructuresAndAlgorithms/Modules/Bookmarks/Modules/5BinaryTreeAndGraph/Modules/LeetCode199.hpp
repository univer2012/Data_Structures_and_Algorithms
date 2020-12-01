//
//  LeetCode199.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/12/1.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef LeetCode199_hpp
#define LeetCode199_hpp

#include <stdio.h>
#include "TreeNode.h"
#include <queue>

#include <vector>
//MARK: 预备知识：二叉树层次遍历
class Solution_BFS_print {
public:
    // 宽度优先搜索二叉树
    void BFS_print(TreeNode *root);
};


class Solution199 {
public:
    std::vector<int> rightSideView(TreeNode *root);
};





#endif /* LeetCode199_hpp */
