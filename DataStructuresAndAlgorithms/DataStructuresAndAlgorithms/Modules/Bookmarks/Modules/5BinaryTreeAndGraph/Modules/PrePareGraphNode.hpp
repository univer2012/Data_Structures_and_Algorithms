//
//  PrePareGraphNode.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/12/1.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef PrePareGraphNode_hpp
#define PrePareGraphNode_hpp

#include <stdio.h>
#include "GraphNode.h"


//预备知识：图的深度优先遍历
class PrePareGraphNode_DFS {
public:
    void DFS_graph(GraphNode *node, int visit[]);
    void test();
};

//预备知识：图的宽度优先遍历
class PrePareGraphNode_BFS {
public:
    void BFS_graph(GraphNode *node, int visit[]);
    void test();
};

#endif /* PrePareGraphNode_hpp */
