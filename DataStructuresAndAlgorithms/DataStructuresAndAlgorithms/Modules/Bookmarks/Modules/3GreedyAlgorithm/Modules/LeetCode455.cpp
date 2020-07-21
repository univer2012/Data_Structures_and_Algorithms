//
//  LeetCode455.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/21.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode455.hpp"
#include <algorithm>

int Solution455::findContentChildren(std::vector<int> &g, std::vector<int> &s) {
    //对孩子的需求因子g 与糖果大小s 两数组排序
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    
    //child代表已满足了几个孩子，cookie代表尝试了几个糖果
    int child = 0;
    int cookie = 0;
    while (child < g.size() && cookie < s.size()) { //当孩子或糖果同时均未尝试完时
        if (g[child] <= s[cookie]) { //当满足孩子的需求因子 小于或等于 糖果大小时
            child ++;   //该糖果满足了孩子，孩子指针child向后移动
        }
        cookie++;       //无论成功或失败，每个糖果只尝试一次，cookie向后移动
    }
    return child;
}
