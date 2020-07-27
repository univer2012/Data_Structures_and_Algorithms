//
//  LeetCode78_2.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/27.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode78_2.hpp"

std::vector<std::vector<int>> Solution78_2::subsets(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    int all_set = 1 << nums.size();     //设置全部集合的最大值+1， 1 << n 即为2^n
    
    //整数i代表从0至2^n-1这2^n个集合
    //(1 << j)即为构造nums数组的第j个元素
    //若i & (1 << j) 为真，则nums[j] 放入item
    for (int i = 0; i < all_set; i++) { //遍历所有集合
        std::vector<int> item;
        for (int j = 0; j < nums.size(); j++) {
            if (i & (1 << j)) {
                item.push_back(nums[j]); //构造数字i代表的集合，各元素存储至item
            }
        }
        result.push_back(item);
    }
    return result;
}
