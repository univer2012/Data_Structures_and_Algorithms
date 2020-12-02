//
//  LeetCode35.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/12/2.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef LeetCode35_hpp
#define LeetCode35_hpp

#include <stdio.h>
#include <vector>

/* 例1：插入位置
 给定一个排序数组nums（无重复元素）与目标值target，如果target在nums里出现，则返回target所在下标，如果target在nums里未出现，则返回target应该插入位置的数组下标，使得将target插入数组nums后，数组仍有序。
 
 选自 LeetCode 35. Search Insert Position
 https://leetcode.com/problems/search-insert-position/description/
 难度：Easy
 */
class Solution35 {
public:
    int searchInsert(std::vector<int> &nums, int target);
};

#endif /* LeetCode35_hpp */
