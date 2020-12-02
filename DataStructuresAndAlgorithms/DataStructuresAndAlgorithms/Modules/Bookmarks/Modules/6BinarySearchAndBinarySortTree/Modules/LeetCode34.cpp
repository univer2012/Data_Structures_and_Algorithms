//
//  LeetCode34.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/12/2.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode34.hpp"

std::vector<int> Solution34::searchRange(std::vector<int> &nums, int target) {
    std::vector<int> result;
    result.push_back(left_bound(nums, target));
    result.push_back(right_bound(nums, target));
    return result;
}

//区间左端点
int Solution34::left_bound(std::vector<int> &nums, int target) {
    int begin = 0;
    int end = (int)nums.size() - 1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (target == nums[mid]) {
            if (mid == 0 || nums[mid - 1] < target) {
                return mid;
            }
            end = mid - 1;
        }
        else if (target < nums[mid]) {
            end = mid - 1;
        }
        else if (target > nums[mid]) {
            begin = mid + 1;
        }
    }
    return  -1;
}

int Solution34::right_bound(std::vector<int> &nums, int target) {
    int begin = 0;
    int end = (int)nums.size() - 1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (target == nums[mid]) {
            if (mid == nums.size() - 1 || nums[mid + 1] > target) {
                return mid;
            }
            begin = mid + 1;
        }
        else if (target < nums[mid]) {
            end = mid - 1;
        }
        else if (target > nums[mid]) {
            begin = mid + 1;
        }
    }
    return  -1;
}
