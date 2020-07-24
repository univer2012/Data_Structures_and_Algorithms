//
//  LeetCode452.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/24.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode452.hpp"

bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return a.first < b.first;   //无需考虑左端点相同时的排序
}

int Solution452::findMinArrowShots(std::vector<std::pair<int, int>> & points) {
    if (points.size() == 0) {
        return 0;               //插入的数据可能为空，直接返回0
    }
    
    std::sort(points.begin(), points.end(), cmp);   //对气球按照左端点从小到大排序
    
    int shoot_num = 1;                  //初始化弓箭手数量为1
    int shoot_begin = points[0].first;  //初始化射击区间，即为第一个气球的两端点
    int shoot_end = points[0].second;
    
    for (int i = 0; i < points.size(); i++) {
        if (points[i].first <= shoot_end) {
            shoot_begin = points[i].first;
            if (shoot_end > points[i].second) {
                shoot_end = points[i].second;
            }
        } else {
            shoot_num ++;
            shoot_begin = points[i].first;  //再保证当前气球被射穿的条件下，射击区间不能再更新了，需要增加一个新的射击区间了。
            shoot_end = points[i].second;
        }
    }
    return shoot_num;
}
