//
//  Poj2431Expedition.cpp
//  DataStructuresAndAlgorithms
//
//  Created by 远平 on 2020/7/25.
//  Copyright © 2020 blue. All rights reserved.
//

#include "Poj2431Expedition.hpp"
#include <algorithm>

bool cmp2431(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return a.first > b.first;
}

//L为起点到终点的距离，P为起点初始的汽油量
//pair<加油站至终点的距离, 加油站汽油量>
int SolutionPoj2431::get_minimum_stop(int L, int P, std::vector<std::pair<int, int>> &stop) {
    
    std::priority_queue<int> Q; //存储油量的最大堆
    int result = 0;             //记录加过几次油的变量
    
    stop.push_back(std::make_pair(0, 0)); //将终点作为一个停靠点，添加至stop数组
    std::sort(stop.begin(), stop.end(), cmp2431);   //以停靠点至终点距离从大到小 进行排序
    
    //遍历各个停靠点
    for (int i = 0; i < stop.size(); i++) {
        int dis = L - stop[i].first; //当前要走的距离即为当前距终点距离L 减去 下一个停靠点至终点距离
        while (!Q.empty() && P < dis) {
            P += Q.top();
            Q.pop();
            result++;
        }
        if (Q.empty() && P < dis) {
            return -1;
        }
        P = P - dis;
        L = stop[i].first;      //更新L为当前停靠点至终点距离
        Q.push(stop[i].second); //将当前停靠点的汽油量添加至最大堆
    }
    return result;
}
