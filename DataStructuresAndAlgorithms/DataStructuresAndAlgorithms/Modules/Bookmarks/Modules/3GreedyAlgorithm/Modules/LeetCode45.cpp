//
//  LeetCode45.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/24.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode45.hpp"


int Solution45::jump(std::vector<int> &nums) {
    if (nums.size() < 2) {
        return 0;                   //如果数组长度小于2，则说明不用跳跃，返回0
    }
    int current_max_index = nums[0];//当前可达到的最远位置
    int pre_max_max_index = nums[0];//遍历各个位置过程中，可达到的最远位置
    int jump_min = 1;
    
    for (int i = 1; i < nums.size(); i++) {
        if (i > current_max_index) {//若无法再向前移动了，才进行跳跃
            jump_min++;
            current_max_index = pre_max_max_index;  //更新当前可达到的最远位置
        }
        if (pre_max_max_index < nums[i] + i) {
            pre_max_max_index = nums[i] + i;        //更新pre_max_max_index
        }
    }
    return jump_min;
}
