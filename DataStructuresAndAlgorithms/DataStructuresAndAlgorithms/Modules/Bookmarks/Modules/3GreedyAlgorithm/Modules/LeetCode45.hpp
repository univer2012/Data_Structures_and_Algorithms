//
//  LeetCode45.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/24.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef LeetCode45_hpp
#define LeetCode45_hpp

#include <stdio.h>
#include <vector>

class Solution45 {
public:
    //最少需要跳跃几次到达数组尾部
    int jump(std::vector<int> &nums);
};

#endif /* LeetCode45_hpp */
/*
例4-b：跳跃游戏2

一个数组存储了非负整型数据，数组中的第i个元素nums[i]，代表了可以从数组第i个位置最多向前跳跃nums[i]步；已知数组各元素的情况下，确认可以从第0位置跳跃到数组最后一个位置，求最少需要跳跃几次？

例如：
nums = [2,3,1,1,4]，从第0位置跳到第1位置，从第1位置跳至最后一个位置。

选自 LeetCode 45 Jump Game II
难度：Hard


 ========  ========  ========  ========  ========  ========  ========
例4-b：思考
从第0位子，最少需要跳几次达到最后一个位置？
如果希望最少跳跃达到终点，则需要明确何时进行跳跃式最合适的。

例如，在到达位置i前：

如果在位置i前都未跳跃，则可能无法到达位置i后的地方：



========  ========  ========  ========  ========  ========  ========
例4-b：贪心规律
在到达某点前，若一直不跳跃，发现从该点不能跳到更远的地方了，在这之前肯定有次必要的跳跃！

结论：在无法到达更远的地方时，在这之前应该跳到一个可以到达更远位置的位置！
index[i-2]是index[0,1,...,i]中最大的。


========  ========  ========  ========  ========  ========  ========
例4-b：算法思路
1.设置current_max_index为当前可达到的最远位置；
2.设置pre_max_max_index为在遍历各个位置的过程中，各个位置可达到的最远位置；
3.设置jump_min为最少跳跃的次数。
4.利用i遍历nums数组，若i超过current_max_index，jump_min加1，current_max_index = pre_max_max_index
5.遍历过程中，若nums[i]+i(index[i])更大，则更新 pre_max_max_index = nums[i] + i
*/
