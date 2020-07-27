//
//  LeetCode90.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/27.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode90.hpp"

std::vector<std::vector<int>> Solution90:: subsetsWithDup(std::vector<int> &nums) {
    
    std::vector<std::vector<int>> result;
    std::vector<int> item;
    std::set<std::vector<int>> res_set;         //去重使用的集合set
    
    std::sort_heap(nums.begin(), nums.end());   //对nums数组进行排序
    result.push_back(item);
    generate(0, nums, result, item, res_set);
    return result;
}


void Solution90::generate(int i, std::vector<int> &nums,
              std::vector<std::vector<int>> &result,
              std::vector<int> &item,
              std::set<std::vector<int>> &res_set) {
    
    if (i >= nums.size()) {
        return;
    }
    item.push_back(nums[i]);
    
    if (res_set.find(item) == res_set.end()) {  //如果res_set集合中，无法找到item
        result.push_back(item);                 //将item放入result数组中
        res_set.insert(item);                   //将item放入去重集合res_set中
    }
    
    generate(i + 1, nums, result, item, res_set);
    item.pop_back();
    generate(i + 1, nums, result, item, res_set);
}
