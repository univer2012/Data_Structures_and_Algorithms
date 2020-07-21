//
//  LeetCode376.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/21.
//  Copyright © 2020 blue. All rights reserved.
//
/*
 例2：摇摆序列
 一个整数序列，如果两个相邻元素的差恰好正负（负正）交替出现，则该序列被称为摇摆序列。一个小于2个元素的序列直接为摇摆序列。
 
 例如：
 序列[1,7,4,9,2,5] 相邻元素的差(6,-3,5,-7,3)，该序列为摇摆序列。
 序列[1,4,7,2,5](3,3,-5,3)、 [1,7,4,5,5](6,-3,1,0)不是摇摆序列。
 
 给一个随机序列，求这个序列满足摇摆序列定义的最长子序列的长度。
 例如：
 输入[1,7,4,9,2,5]，结果为6；输入[1,17,5,10,13,15,10,5,16,8]，结果为7（[1,17,5,10,13,10,16,8]）;输入[1,2,3,4,5,6,7,8,9]，结果为2.
 
 选自： LeetCode 376 Wiggle Subsequence
 难度：Medium
 */
#ifndef LeetCode376_hpp
#define LeetCode376_hpp

#include <stdio.h>
#include <vector>

class Solution376 {
public:
    int wiggleMaxLength(std::vector<int> &nums);
};

#endif /* LeetCode376_hpp */
