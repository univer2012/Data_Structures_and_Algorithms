//
//  LeetCode90.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/27.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef LeetCode90_hpp
#define LeetCode90_hpp

#include <stdio.h>
#include <vector>
#include <set>

class Solution90 {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums);
    
private:
    void generate(int i, std::vector<int> &nums,
                  std::vector<std::vector<int>> &result,
                  std::vector<int> &item,
                  std::set<std::vector<int>> &res_set);
};

#endif /* LeetCode90_hpp */
/*
 例1-b：求子集2
 已知一组数（其中有重复元素），求这组数可以组成的所有子集。
 结果中无重复的子集。
 
 例如： nums[] = [2,1,2,2]
 结果为： [[],[1],[1,2],[1,2,2],[1,2,2,2],[2],[2,2],[2,2,2]]
 注意：[2,1,2]与 [1,2,2]是重复的集合！
 
 选自： LeetCode 90 Subsets II
 难度：Medium
 
 
 ========  ========  ========  ========  ========  ========  ========
 例1-b：思考
 有两种重复原因：
 1.不同位置的元素组成的集合是同一个子集，
 例如：[2,1,2,2]，
 选择第1，2，3个元素组成的子集：[2,1,2]；
 选择第1，2，4个元素组成的子集：[2,1,2]。
 
 2.不同位置的元素组成的集合是同一个子集，
 例如：[2,1,2,2]，
 选择第1，2，3个元素组成的子集：[2,1,2]；
 选择第2，3，4个元素组成的子集：[1,2,2]。          如何解决？思考半分钟。
 
 
 ========  ========  ========  ========  ========  ========  ========
 例1-b：算法思路
 不同位置的元素组成的集合是同一个个子集，子集的各个元素顺序相同，或顺序不同，解决方法。
 
 例如：[2,1,2,2]，
 选择第1，2，3个元素组成的子集：[2,1,2]；
 选择第1，2，4个元素组成的子集：[2,1,2]；
 选择第2，3，4个元素组成的子集：[1,2,2]。
 
 解决方案：
 先对原始nums数组进行排序，再使用set去重！
 
 例如：[2,1,2,2]排序后：[1,2,2,2]
 无论如何选择，对上述情况，均只出现[1,2,2]
 */
