//
//  LeetCode452.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/24.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef LeetCode452_hpp
#define LeetCode452_hpp

#include <stdio.h>
#include <vector>

class Solution452 {
public:
    int findMinArrowShots(std::vector<std::pair<int, int>> & points);
};

#endif /* LeetCode452_hpp */
/*
 例5：射击气球
 已知在一个平面上有一定数量的气球，平面可以看作一个坐标系，在平面的x轴的不同位置安排弓箭手向y轴方向射箭，弓箭可以向y轴走无穷远；给定气球的宽度xstart <= x <= xend，问至少需要多少弓箭手，将全部气球打爆？
 
 例如：四个气球：[[10,16], [2,8], [1,6], [7,12]]，至少需要2个弓箭手。
 
 选自 LeetCode 452 Minimum Number of Arrows to Burst Ballons.
 难度： Medium
 
 
 ========  ========  ========  ========  ========  ========  ========
 例5：贪心规律
 1.对于某个气球，至少需要使用1个弓箭将它击穿。
 2.在这只气球将其击穿的同事，尽可能击穿其他更多的气球！（贪心）
 
 
 ========  ========  ========  ========  ========  ========  ========
 例5：算法思路
 1.对各个气球进行排序，按照气球的左端点从小到大排序。
 
 2.遍历气球数组，同时维护一个射击区间，在满足可以将当前气球射穿的情况下，尽可能击穿更多的气球， 每击穿一个新的气球，更新一次射击区间（保证射击区间可以将新气球也击穿）。
 
 3.如果新的气球没办法击穿了，则需要增加一名弓箭手，即维护一个新的射击区间（将该气球击穿），随后继续遍历气球数组。
 */
