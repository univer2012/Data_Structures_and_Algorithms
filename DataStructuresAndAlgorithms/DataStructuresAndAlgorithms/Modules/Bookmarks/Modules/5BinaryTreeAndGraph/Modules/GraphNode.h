//
//  GraphNode.h
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/12/1.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef GraphNode_h
#define GraphNode_h
#include <vector>

//图的邻接表数据结构
struct GraphNode {
    int label;                              //图的顶点的值
    std:: vector<GraphNode *> neighbors;    //相邻节点指针数组
    GraphNode(int x) : label(x) {};
};

#endif /* GraphNode_h */
