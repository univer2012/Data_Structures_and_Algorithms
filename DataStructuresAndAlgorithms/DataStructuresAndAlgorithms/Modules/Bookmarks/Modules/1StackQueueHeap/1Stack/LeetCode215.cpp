//
//  LeetCode215.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/21.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode215.hpp"


int Solution215::findKthLargest(std::vector<int> &nums, int k) {
    
    std::priority_queue<int, std::vector<int>, std::greater<int> > Q;   //最小堆
    
    for (int i = 0; i < nums.size(); i++) { //遍历nums数组
        if (Q.size() < k) {          //如果堆中元素个数小于k，直接push进入堆
            Q.push(nums[i]);
        }
        else if (Q.top() < nums[i]) {//如果堆顶比新元素小，弹出堆顶，push进入新元素（即替换堆顶）
            Q.pop();
            Q.push(nums[i]);
        }
    }
    return Q.top(); //返回堆顶
}
