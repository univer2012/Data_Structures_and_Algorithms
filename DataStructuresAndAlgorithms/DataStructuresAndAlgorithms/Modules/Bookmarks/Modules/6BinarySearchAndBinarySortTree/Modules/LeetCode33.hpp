//
//  LeetCode33.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/12/3.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef LeetCode33_hpp
#define LeetCode33_hpp

#include <stdio.h>
#include <vector>

/*
 例3：旋转数组查找
 给定一个排序数组nums(nums中有无重复元素)，且nums可能以某个未知下标旋转，给定目标值target，求target是否在nums中出现，若出现返回所在下标，未出现返回-1。
 
 选自 LeetCode 33.Search in Rotated Sorted Array

 https://leetcode.com/problems/search-in-rotated-sorted-array/description/

 难度：Medium
 */

class Solution33 {
public:
    int search(std::vector<int> &nums, int target);
};

#endif /* LeetCode33_hpp */
