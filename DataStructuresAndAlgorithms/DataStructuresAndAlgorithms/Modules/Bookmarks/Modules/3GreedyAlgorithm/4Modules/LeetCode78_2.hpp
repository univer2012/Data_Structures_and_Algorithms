//
//  LeetCode78_2.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/27.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef LeetCode78_2_hpp
#define LeetCode78_2_hpp

#include <stdio.h>
#include <vector>

class Solution78_2 {
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums);
};

#endif /* LeetCode78_2_hpp */
/*
 例1-a（方法2位运算法）：预备知识
 
 位运算是 C语言（各编程语言）的基础运算符之一
 
 
 ========  ========  ========  ========  ========  ========  ========
 例1-a（方法2位运算法）：算法思路
 若一个集合有三个元素A，B，C，则3个元素有2^3 = 8种组成集合的方式，用0-7表示这些集合。
 
 ========  ========  ========  ========  ========  ========  ========
 例1-a（方法2位运算法）：算法思路
 A元素为100 = ；B元素为010 = 2；C元素为001 = 1
 如构造某一集合，即使用A，B，C对一个的三个整数与该集合对应的整数做 & 运算，当为真时，将该元素push进入集合。
 */
