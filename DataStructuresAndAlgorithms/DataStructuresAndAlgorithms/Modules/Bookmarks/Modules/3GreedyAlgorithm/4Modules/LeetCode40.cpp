//
//  LeetCode40.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/27.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode40.hpp"
std::vector<std::vector<int>> Solution40:: combinationSum2(std::vector<int> &candidates, int target) {
    
    std::vector<std::vector<int>> result;
    std::vector<int> item;
    std::set<std::vector<int>> res_set;         //去重使用的集合set
    
    std::sort_heap(candidates.begin(), candidates.end());   //对nums数组进行排序
    result.push_back(item);
    generate(0, candidates, result, item, res_set);
    
    std::vector<std::vector<int>> target_result;
    for (int i = 0; i < result.size(); i++) {
        int sum = 0;
        for (int j = 0; j < result[i].size(); j++) {
            sum += result[i][j];
        }
        if (sum == target) {
            target_result.push_back(result[i]);
        }
    }
    
    return target_result;
}


void Solution40::generate(int i, std::vector<int> &nums,
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


//================ ================== =============== ===============
std::vector<std::vector<int>> Solution40_2:: combinationSum2(std::vector<int> &candidates, int target) {
    
    std::vector<std::vector<int>> result;
    std::vector<int> item;
    std::set<std::vector<int>> res_set;         //去重使用的集合set
    
    std::sort_heap(candidates.begin(), candidates.end());   //对nums数组进行排序
    
    generate(0, candidates, result, item, res_set, 0, target);
    
    return result;
}


void Solution40_2::generate(int i, std::vector<int> &nums,
              std::vector<std::vector<int>> &result,
              std::vector<int> &item,
              std::set<std::vector<int>> &res_set,
              int sum, int target) {
    
    if (i >= nums.size() || sum > target) {
        return;
    }
    sum += nums[i];
    item.push_back(nums[i]);
    if (target == sum && res_set.find(item) == res_set.end()) {
        result.push_back(item);
        res_set.insert(item);
    }
    
    generate(i + 1, nums, result, item, res_set, sum, target);
    
    sum -= nums[i];
    item.pop_back();
    generate(i + 1, nums, result, item, res_set, sum, target);
}
