//
//  LeetCode40.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/27.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef LeetCode40_hpp
#define LeetCode40_hpp

#include <stdio.h>
#include <vector>
#include <set>

///不是最优解，复杂度是O(2^n)
class Solution40 {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target);
    
private:
    void generate(int i, std::vector<int> &nums,
                  std::vector<std::vector<int>> &result,
                  std::vector<int> &item,
                  std::set<std::vector<int>> &res_set);
};



//在搜索回溯过程中进行剪枝操作
class Solution40_2 {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target);
    
private:
    void generate(int i, std::vector<int> &nums,
                  std::vector<std::vector<int>> &result,
                  std::vector<int> &item,
                  std::set<std::vector<int>> &res_set,
                  int sum, int target);
};


#endif /* LeetCode40_hpp */
/*
 例1-c：组合数之和2
 已知一组数（其中有重复元素），求这组数可以组成的所有子集中，自己中的各个元素和为整数target的子集，结果中无重复的子集。
 
 例如： nums[] = [10,1,2,7,6,1,5] ，target = 8
 结果为： [[1,7],[1,2,5],[2,6],[1,1,6]]
 
 选自：LeetCode 40 Combination Sum II
 难度：Medium
 
 
 ========  ========  ========  ========  ========  ========  ========
 例1-c：思考
 如下算法是否可行？
 按照例1-b的有重复元素的集合生成方法，将所有子集构造出来后，再找出元素和为target的子集。
 
 时间复杂度是？
 是否偶更好的优化方案？            思考半分钟。
 
 
 ========  ========  ========  ========  ========  ========  ========
 例1-c：分析
 无论是回溯法或位运算法，整体时间复杂度O(2^n)。
 
 例如：
 nums[] = [10,1,2,7,6,1,5]，target = 8;
 [10] > target，则所有包含[10]的子集[10,...]，一定不满足目标。
 [1,2,7] > target，则所有包含[1,2,7]的子集[1,2,7,...]，一定不满足目标。
 [7,6] > target，则所有包含[7,6]的子集[7,6,...]，一定不满足目标。
 ...
 过多的错误尝试，浪费了大量时间。
 
 
 ========  ========  ========  ========  ========  ========  ========
 例1-c：算法思路
 在搜索回溯过程中进行剪枝操作：
 
 递归调用时，计算已选择元素的和sum，若sum > target，不再进行更深的搜索，直接返回。
 
 例如：
 nums[] = [10,1,2,7,6,1,5]
 target = 8
 */
