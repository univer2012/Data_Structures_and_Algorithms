//
//  LeetCode35.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/12/2.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode35.hpp"

int Solution35::searchInsert(std::vector<int> &nums, int target) {
    int index = -1;                 //最终返回的下标，若找到则为该元素下标，否则为需要插入的位置
    int begin = 0;                  //搜索区间左端点
    int end = (int)nums.size() - 1; //搜索区间右端点
    while (index == -1) {           //若index == -1，则说明还未找到正确位置，持续二分搜索
        int mid = (begin + end) / 2;//计算中心位置
        if (target == nums[mid]) {  //若找到target
            index = mid;
        }
        else if (target < nums[mid]) {
            if (mid == 0 || target > nums[mid - 1]) {
                index = mid;
            }
            end = mid - 1;          //如果target小于中点，更新区间右端点
        }
        else if (target > nums[mid]) {
            if (mid == nums.size() - 1 || target < nums[mid + 1]) {
                index = mid + 1;
            }
            begin = mid + 1;        //如果target大于中点，更新区间左端点
        }
    }
    return index;
}
