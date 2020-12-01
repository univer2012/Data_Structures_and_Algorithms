//
//  LeetCode204.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/12/1.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode204.hpp"
#include <queue>

//pair<课程1, 课程2>，代表课程1依赖课程2
bool Solution204::canFinish(int numCourses, std::vector< std::pair<int, int> > &prerequisites) {
    std::vector< GraphNode * > graph;       //邻接表
    std::vector<int> visit;                 //节点访问状态，-1没有访问过，0代表正在访问，1代表已完成访问
    for (int i = 0; i < numCourses; i++) {
        graph.push_back(new GraphNode(i));  //创建图的节点，并赋访问状态为空
        visit.push_back(-1);
    }
    
    //创建图，连接图的顶点
    for (int i = 0; i < prerequisites.size(); i++) {
        GraphNode *begin = graph[prerequisites[i].second];
        GraphNode *end = graph[prerequisites[i].first];
        begin->neighbors.push_back(end);    //课程2指向课程1
    }
    
    for (int i = 0; i < graph.size(); i++) {
        //如果节点没访问过，进行DFS；如果DFS遇到环，返回无法完成
        if (visit[i] == -1 && !DFS_graph(graph[i], visit)) {
            return  false;
        }
    }
    
    for (int i = 0; i < numCourses; i++) {
        delete graph[i];
    }
    return true; //返回可以完成
}

//节点访问状态，-1没有访问过，0代表正在访问，1代表已完成访问
//返回bool值，false = 0代表遇到环；true = 1代表没有环
bool Solution204::DFS_graph(GraphNode *node, std::vector<int> &visit) {
    visit[node->label] = 0;
    for (int i = 0; i < node->neighbors.size(); i++) {
        if (visit[node->neighbors[i]->label] == -1) {
            if (DFS_graph(node->neighbors[i], visit) == 0) {
                return false;
            }
        } else if (visit[node->neighbors[i]->label] == 0) {
            return false;
        }
    }
    visit[node->label] = 1;
    return true;
}



bool Solution204_2::canFinish(int numCourses, std::vector< std::pair<int, int> > &prerequisites) {
    std::vector<GraphNode *> graph;
    std::vector<int> degree;            //入度数组
    for (int i = 0; i < prerequisites.size(); i++) {
        degree.push_back(0);
        graph.push_back(new GraphNode(i));
    }
    
    for (int i = 0; i < prerequisites.size(); i++) {
        GraphNode *begin = graph[prerequisites[i].second];
        GraphNode *end = graph[prerequisites[i].first];
        begin->neighbors.push_back(end);
        degree[prerequisites[i].first]++;   //入度++，即pair<课程1, 课程2>，课程1的入度++
    }
    
    std::queue<GraphNode *> Q;
    for (int i = 0; i < numCourses; i++) {
        if (degree[i] == 0) {
            Q.push(graph[i]);
        }
    }
    //宽度搜索
    while (!Q.empty()) {
        GraphNode *node = Q.front();
        Q.pop();
        for (int i = 0; i < node->neighbors.size(); i++) {
            degree[node->neighbors[i]->label] --;
            if (degree[node->neighbors[i]->label] == 0) {
                Q.push(node->neighbors[i]);
            }
        }
    }
    for (int i = 0; i < graph.size(); i++) {
        delete graph[i];
    }
    for (int i = 0; i < degree.size(); i++) {
        if (degree[i]) {
            return false;
        }
    }
    return true;
}
