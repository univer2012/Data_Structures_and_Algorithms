//
//  PrePareGraphNode.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/12/1.
//  Copyright © 2020 blue. All rights reserved.
//

#include "PrePareGraphNode.hpp"
#include <queue>

void PrePareGraphNode_DFS::DFS_graph(GraphNode *node, int visit[]) {
    visit[node->label] = 1;
    printf("%d ", node->label);
    for (int i = 0; i < node->neighbors.size(); i++) {
        if (visit[node->neighbors[i]->label] == 0) {
            DFS_graph(node->neighbors[i], visit);
        }
    }
}

void PrePareGraphNode_DFS::test() {
    const int MAX_N = 5;        //5个顶点
    GraphNode * Graph[MAX_N];
    
    for (int i = 0; i < MAX_N; i++) {
        Graph[i] = new GraphNode(i);
    }
    //添加边 --- 有向图
    Graph[0]->neighbors.push_back(Graph[2]);
    Graph[0]->neighbors.push_back(Graph[4]);
    Graph[1]->neighbors.push_back(Graph[0]);
    Graph[1]->neighbors.push_back(Graph[2]);
    Graph[2]->neighbors.push_back(Graph[3]);
    Graph[3]->neighbors.push_back(Graph[4]);
    Graph[4]->neighbors.push_back(Graph[3]);
    
    int visit[MAX_N] = {0};
    for (int i = 0; i < MAX_N; i++) {
        if (visit[i] == 0) {
            printf("From label(%d) : ", Graph[i]->label);
            DFS_graph(Graph[i], visit);
            printf("\n");
        }
    }
    
    for (int i = 0; i < MAX_N; i++) {
        delete Graph[i];
    }
    
}

/// ================= ================= ================= ================= =================
void PrePareGraphNode_BFS::BFS_graph(GraphNode *node, int visit[]) {
    std::queue<GraphNode *> Q;      //宽度优先搜索使用队列，
    Q.push(node);
    visit[node->label] = 1;
    while (!Q.empty()) {            //队列不空即一直循环
        GraphNode * node = Q.front();
        Q.pop();
        printf("%d ", node->label);
        for (int i = 0; i < node->neighbors.size(); i++) {
            if (visit[node->neighbors[i]->label] == 0) {
                Q.push(node->neighbors[i]);
                visit[node->neighbors[i]->label] = 1;
            }
        }
    }
}
void PrePareGraphNode_BFS::test() {
    const int MAX_N = 5;        //5个顶点
    GraphNode * Graph[MAX_N];
    
    //创建图的顶点
    for (int i = 0; i < MAX_N; i++) {
        Graph[i] = new GraphNode(i);
    }
    //添加图的边，注意添加边的顺序
    Graph[0]->neighbors.push_back(Graph[2]);
    Graph[0]->neighbors.push_back(Graph[4]);
    Graph[1]->neighbors.push_back(Graph[0]);
    Graph[1]->neighbors.push_back(Graph[2]);
    Graph[2]->neighbors.push_back(Graph[3]);
    Graph[3]->neighbors.push_back(Graph[4]);
    Graph[4]->neighbors.push_back(Graph[3]);
    
    int visit[MAX_N] = {0};         //标记已访问的顶点
    for (int i = 0; i < MAX_N; i++) {
        if (visit[i] == 0) {
            printf("From label(%d) : ", Graph[i]->label);
            BFS_graph(Graph[i], visit);
            printf("\n");
        }
    }
    
    for (int i = 0; i < MAX_N; i++) {
        delete Graph[i];
    }
    
}
