//
//  LeetCode78.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/27.
//  Copyright © 2020 blue. All rights reserved.
//
//回溯法其实就是暴力枚举法，或者暴力破解法，复杂度：O(2^n)
#ifndef LeetCode78_hpp
#define LeetCode78_hpp

#include <stdio.h>
#include <vector>

class Prepare78 {
public:
    //MARK: nums[] = [1,2,3]，将子集[[1],[1,2],[1,2,3]]打印出来
    //例1-a（方法1回溯法）：预备知识（循环）
    void sec2demo1();
    
    //例1-a（方法1回溯法）：预备知识（递归）
    void sec2demo1_2();
private:
    void generate(int i, std::vector<int> &nums, std::vector<int> &item, std::vector<std::vector<int>> &result);
};

class Solution78 {
public:
    //方法1回溯法
    std::vector<std::vector<int>> subsets(std::vector<int> &nums);
private:
    void generate(int i, std::vector<int> &nums, std::vector<int> &item, std::vector<std::vector<int>> &result);
};

#endif /* LeetCode78_hpp */
/*
 例1-a：求子集
 已知一组数（其中无重复元素），求这组数可以组成的所有子集。结果中不可有无重复的子集。
 
 例如：nums[] = [1,2,3]
 结果为：[[], [1], [1,2],[1,2,3],[1,3],[2], [2,3], [3]]
 
 选自：LeetCode78 Subsets
 难度：Medium
 
 
 ========  ========  ========  ========  ========  ========  ========
 例1-a：思考
 在所有子集，生成各个子集，[[], [1], [1,2],[1,2,3],[1,3],[2], [2,3], [3]]，即是否选[1]，是否选[2]， 是否选[3]的问题。
 
 如果只是用循环，困难的地方在哪里？
 使用循环程序难以直接模拟是否选某一元素的过程。
 
 如果只是生成[1],[1,2],[1,2,3]三个子集，如何做？           思考半分钟。
 
 
 ========  ========  ========  ========  ========  ========  ========
 例1-a（方法1回溯法）：算法思路
 利用回溯方法生成子集，即对于每个元素，都有试探放入或不放入集合的两个选择：
 选择放入该元素，递归的进行后续元素的选择，完成放入该元素后续所有元素的试探；之后将其拿出，即再进行一次选择不放入该元素，递归的进行后续元素的选择，完成不放入该元素后续所有元素的试探。
 
 本来选择放入，再选择一次不放入的这个过程，称为回溯试探法。
 
 例如：
 元素数组：nums = [1,2,3,4,5,...]，子集生成数组 item[] = []
 对于元素1，
 选择放入item，item = [1]，继续递归处理后续[2,3,4,5,...]元素；item = [1,...]
 选择不放入item，item = []，继续递归处理后续[2,3,4,5,...]元素；item = [...]
 */
