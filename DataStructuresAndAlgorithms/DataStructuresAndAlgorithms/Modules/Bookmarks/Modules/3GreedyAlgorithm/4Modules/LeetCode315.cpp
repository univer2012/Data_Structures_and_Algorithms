//
//  LeetCode315.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/27.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode315.hpp"

std::vector<int> Solution315::countSmaller(std::vector<int> &nums) {
    std::vector<std::pair<int, int>> vec;
    std::vector<int> count;
    for (int i = 0; i < nums.size(); i++) {
        vec.push_back(std::make_pair(nums[i], i));  //将nums[i]与i绑定为pair<nums[i], i>
        count.push_back(0);
    }
    merge_sort(vec, count);
    return count;
}

void Solution315::merge_sort_two_vec(std::vector<std::pair<int, int>> &sub_vec1,
                        std::vector<std::pair<int, int>> &sub_vec2,
                        std::vector<std::pair<int, int>> &vec,
                        std::vector<int> &count) {
    int i = 0;
    int j = 0;
    while (i < sub_vec1.size() && j < sub_vec2.size()) {
        if (sub_vec1[i].first <= sub_vec2[j].first) {
            count[sub_vec1[i].second] += j;
            vec.push_back(sub_vec1[i]);
            i++;
        } else {
            vec.push_back(sub_vec2[j]);
            j++;
        }
    }
    for (; i < sub_vec1.size(); i++) {
        count[sub_vec1[i].second] +=j;
        vec.push_back(sub_vec1[i]);
    }
    for (; j < sub_vec2.size(); j++) {
        vec.push_back(sub_vec2[j]);
    }
}



void Solution315::merge_sort(std::vector<std::pair<int, int>> &vec, std::vector<int> &count) {
    if (vec.size() < 2) {
        return;             //子问题足够小的时候，直接求解
    }
    int mid = (int)vec.size() / 2;
    std::vector<std::pair<int, int>> sub_vec1;
    std::vector<std::pair<int, int>> sub_vec2;
    
    //对原问题进行分解，即对原数组拆分为两个规模相同的数组，再对它们分别求解（排序）
    for (int i = 0; i < mid; i++) {
        sub_vec1.push_back(vec[i]);
    }
    for (int i = mid; i < vec.size(); i++) {
        sub_vec2.push_back(vec[i]);
    }
    
    //对拆解后的两个子问题进行求解
    merge_sort(sub_vec1, count);
    merge_sort(sub_vec2, count);
    vec.clear();
    merge_sort_two_vec(sub_vec1, sub_vec2, vec, count);
}
