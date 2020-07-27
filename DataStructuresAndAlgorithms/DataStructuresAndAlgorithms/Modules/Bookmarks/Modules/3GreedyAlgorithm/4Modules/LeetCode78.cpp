//
//  LeetCode78.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/27.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode78.hpp"
#include <vector>

//nums[] = [1,2,3]，将子集[[1],[1,2],[1,2,3]]打印出来
//例1-a（方法1回溯法）：预备知识（循环）
void Prepare78::sec2demo1() {
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    
    std::vector<int> item;                  //item，生成各个子集的数组
    std::vector<std::vector<int>> result;   //result，最终结果数组
    //i=0时，item=[1]
    //i=1时，item=[1,2]
    //i=2时，item=[1,2,3]
    for (int i = 0; i < nums.size(); i++) {
        item.push_back(nums[i]);
        result.push_back(item);
    }
    
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            printf("[%d]", result[i][j]);   //打印result
        }
        printf("\n");
    }
}



/*
 nums[] = [1,2,3]，将子集[[1],[1,2],[1,2,3]]递归的加入result
 
 第一次递归调用：
 generate(0,nums,item,result);
 i = 0, item = [1], result = [[1]]
 
 第二次递归调用：
 generate(1,nums,item,result);
 i = 1, item = [1,2], result = [[1], [1,2]]
 
 第三次递归调用：
 generate(2,nums,item,result);
 i = 2, item = [1,2,3], result = [[1], [1,2], [1,2,3]]
 
 第四次递归调用：
 generate(3,nums,item,result);
 i == nums.size(), return
 */
//例1-a（方法1回溯法）：预备知识（递归）

void Prepare78::generate(int i, std::vector<int> &nums,
              std::vector<int> &item,
              std::vector<std::vector<int>> &result) {
    if (i >= nums.size()) {
        return;
    }
    item.push_back(nums[i]);
    result.push_back(item);
    generate(i + 1, nums, item, result);
}
void Prepare78::sec2demo1_2() {
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    std::vector<int> item;
    std::vector<std::vector<int>> result;
    generate(0, nums, item, result);
    
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            printf("[%d]", result[i][j]);
        }
        printf("\n");
    }
}


std::vector<std::vector<int>> Solution78::subsets(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;   //存储最终结果的result
    std::vector<int> item;              //回溯时，产生各个子集的数组
    result.push_back(item);             //将空集push进入result
    generate(0, nums, item, result);    //计算各个子集
    return result;
}

void Solution78::generate(int i, std::vector<int> &nums, std::vector<int> &item, std::vector<std::vector<int>> &result)
{
    if (i >= nums.size()) { //递归结束条件是？？
        return;
    }
    
    item.push_back(nums[i]);
    result.push_back(item);             //将当前生成的子集添加进入result
    generate(i + 1, nums, item, result);//第一次递归调用
    
    item.pop_back();
    generate(i + 1, nums, item, result);//第二次递归调用
}
