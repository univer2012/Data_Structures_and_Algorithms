//
//  LeetCode22.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/27.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef LeetCode22_hpp
#define LeetCode22_hpp

#include <stdio.h>
#include <vector>
#include <string>

//例2：预备知识：递归生成所有可能

class Prepare22 {
public:
    void sec2demo6();
    
private:
    void generate(std::string item, int n, std::vector<std::string> &result);
};




class Solution22 {
public:
    std::vector<std::string> generateParenthesis(int n);
    
private:
    void generate(std::string item, int left, int right, std::vector<std::string> &result);
};


#endif /* LeetCode22_hpp */
/*
 例2：生成括号
 
 已知n组括号，开发一个程序，生成这n组括号所有的合法的组合可能。
 
 例如：n = 3
 结果为： ["((()))", "(()())", "(())()", "()(())", "()()()"]
 
 选自 LeetCode22 Generate Parentheses
 难度：Medium
 
 
 ========  ========  ========  ========  ========  ========  ========
 例2：思考
 n组括号，有多少种组合可能？
 
 n组括号，括号字符串长度为2 * n，字符串中的每个字符有两种选择可能，“(”或“)”，故有2^(2n)种可能。
 
 例如2组括号，所有的组合可能：
 ['((((', '((()', '(()(', '(())', '()((', '()()', '())(', '()))', ')(((', ')(()', ')()(', ')())', '))((', '))()', ')))(', '))))']
 
 在这16种可能中，满足哪些是合法的？有多少种合法可能？如何生成它们？             思考半分钟
 
 
 ========  ========  ========  ========  ========  ========  ========
 例2：算法思路
 在组成的所有可能中，哪些是合法的？
 1.左括号与右括号的数量不可超过n。
 2.每放一个左括号，才可放一个右括号，即右括号不可先于左括号放置。
 
 故递归需要限制条件：
 1.左括号与右括号的数量，最多放置n个。
 2.若左括号的数量<= 右括号数量，不可进行放置右括号的递归。
 */
