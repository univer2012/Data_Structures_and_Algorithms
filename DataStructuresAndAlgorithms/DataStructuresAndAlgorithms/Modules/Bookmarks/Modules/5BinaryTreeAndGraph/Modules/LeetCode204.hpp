//
//  LeetCode204.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/12/1.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef LeetCode204_hpp
#define LeetCode204_hpp

#include <stdio.h>
#include "GraphNode.h"

//方法1：深度搜索
class Solution204 {
public:
    //课程依赖关系<课程1, 课程2>，代表课程1依赖课程2
    bool canFinish(int numCourses, std::vector< std::pair<int, int> > &prerequisites);
    
private:
    bool DFS_graph(GraphNode *node, std::vector<int> &visit);
};

//方法2：拓扑排序（宽度优先搜索）
class Solution204_2 {
public:
    //课程依赖关系<课程1, 课程2>，代表课程1依赖课程2
    bool canFinish(int numCourses, std::vector< std::pair<int, int> > &prerequisites);
};


#endif /* LeetCode204_hpp */
