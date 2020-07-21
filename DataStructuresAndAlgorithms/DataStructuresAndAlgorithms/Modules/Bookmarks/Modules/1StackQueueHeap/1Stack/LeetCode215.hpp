//
//  LeetCode215.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/21.
//  Copyright © 2020 blue. All rights reserved.
//
/*
 例6：数组中第K大的数
 已知一个未排序的数组，求这个数组中第K大的数字。
 
 选自：LeetCode 215 Kth Largest Element in an Array
 难度：Easy
 */
#ifndef LeetCode215_hpp
#define LeetCode215_hpp

#include <stdio.h>

#include <vector>
#include <queue>

/*
 例6：思路
 维护一个K大小的最小堆，堆中元素个数小于K时，新元素直接进入堆；否则，当堆顶小于新元素时，弹出堆顶，将新元素加入堆。
 
 解释：
 由于堆是最小堆，堆顶是堆中最小元素，新元素都会保证比堆顶小（否则新元素替换堆顶），故堆中K个元素时已扫描的元素里最大的K个；堆顶即为第K大的数。
 
 设数组长度为N，求第K大的数，时间复杂度：N * logK
 */
class Solution215 {
public:
    int findKthLargest(std::vector<int> &nums, int k);
};


#endif /* LeetCode215_hpp */
