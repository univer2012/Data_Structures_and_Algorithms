//
//  LeetCode315.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/27.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef LeetCode315_hpp
#define LeetCode315_hpp

#include <stdio.h>
#include <vector>
class Solution315 {
    
public:
    std::vector<int> countSmaller(std::vector<int> &nums);
    
private:
    void merge_sort_two_vec(std::vector<std::pair<int, int>> &sub_vec1,
                            std::vector<std::pair<int, int>> &sub_vec2,
                            std::vector<std::pair<int, int>> &vec,
                            std::vector<int> &count);
    
    //预备知识：归并排序实现
    void merge_sort(std::vector<std::pair<int, int>> &vec, std::vector<int> &count);
};

#endif /* LeetCode315_hpp */

/*
 例4：逆序数
 已知数组nums，求新数组count，count[i]代表了在nums[i]右侧且比nums[i]小的元素个数。
 
 例如：
 nums = [5,2,6,1], count = [2,1,1,0];
 nums = [6,6,6,1,1,1], count = [3,3,3,0,0,0];
 nums = [5,-7,9,1,3,5,-2,1], count = [5,0,5,1,2,2,0,0];
 
 选自：LeetCode 315 Count of Smaller Numbers After Self
 难度：Hard
 
 
 ========  ========  ========  ========  ========  ========  ========
 例4：思考
 最暴力的方法，即对每个元素扫描其右侧比它小的数，累加个数。假设数组元素个数为N，算法复杂度O(N^2)。
 
 观察如下数组，该数组前4个元素有序，后4个元素有序，是否有更好的方法计算count数组？
 count:     0  1 3 4     0 0 0 0
 nums :     -7 1 5 9    -2 1 3 5
            i            j
 
 
 ========  ========  ========  ========  ========  ========  ========
 例4：算法思路
 在归并两排序数组时，当需要将前一个数组元素的指针i指向的元素插入时，对应的count[i]，即为指向后一个数组的指针j的值。
 count:     0  1 3 4     0 0 0 0
 nums :     -7 1 5 9    -2 1 3 5
            i            j
 
 count:     0  1 3 4     0 0 0 0
 nums :     -7 1 5 9    -2 1 3 5
                 i             j=3
 
 count:      0  0 1 0 0 3
 nums :     -7 -2 1 1 3 5
 
 
 ========  ========  ========  ========  ========  ========  ========
 例4：算法思路
 期望的count结果，与排序前原数组元素可对应上：
 
 count:      0 1 3 4     0 0 0 0
 nums :     -7 1 5 9    -2 1 3 5
 
 排序的结果：
 count:      0  0 1 0 0 3 0 4
 nums :     -7 -2 1 1 3 5 5 9                   如何解决？
 
 
 ========  ========  ========  ========  ========  ========  ========
 例4：算法思路
 
 将元素nums[i]与元素的位置i绑定为pair       如：<nums[i], i>
 排序是，按照nums[i]大小排序pair对，利用pair对<nums[i], i>中的i
 更新count数组
 
 
 */
