//
//  LeetCode55.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/24.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode55.hpp"


bool Solution55::canJump(std::vector<int> &nums) {
    
    std::vector<int> index;             //最远可跳至的位置
    for (int i = 0; i < nums.size(); i++) {
        index.push_back(i + nums[i]);   //计算index数组
    }
    
    //初始化jump与max_index
    int jump = 0;
    int max_index = index[0];
    
    //直到jump跳至数组尾部  或  jump超越了当前可以跳的最远位置
    while (jump < index.size() && jump <= max_index) {
        if (max_index < index[jump]) {
            max_index = index[jump];    //如果当前可以跳的更远，则更新max_index
        }
        jump++;                         //扫描jump
    }
    if (jump == index.size()) {         //若jump达到数组尾部，则返回真
        return true;
    }
    return false;                       //否则返回假
}
