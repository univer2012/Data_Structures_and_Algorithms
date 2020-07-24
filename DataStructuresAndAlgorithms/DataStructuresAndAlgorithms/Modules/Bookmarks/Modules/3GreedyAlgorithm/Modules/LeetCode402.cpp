//
//  LeetCode402.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/21.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode402.hpp"
#include <vector>

std::string Solution402::removeKdigits(std::string num, int k) {
    std::vector<int> S;             //使用vector当作栈（因为vector可以遍历）
    std::string result = "";        //存储最终结果的字符串
    for (int i = 0; i < num.length(); i++) {    //从最高位循环扫描数字num
        int number = num[i] - '0';              //将字符型的num转化为整数使用
        
        //当栈不空，栈顶元素大于数number，仍然可以删除数字时，while循环继续
        while (S.size() != 0 && S[S.size() - 1] > number && k > 0) {
            S.pop_back();           //弹出栈顶元素
            k--;
        }
        if (number != 0 || S.size() != 0) {
            S.push_back(number);    //将数字number压入栈中
        }
    }
    
    while (S.size() != 0 && k > 0) {//如果栈不空，且仍然可以删除数字
        S.pop_back();
        k--;                        //删除数字后更新k
    }
    
    //将栈中的元素从头遍历，存储至result
    for (int i = 0; i < S.size(); i++) {
        result.append(1, '0' + S[i]);
    }
    
    if (result == "") {
        result = "0";   //如果result为空，result即为0
    }
    return result;
    
}
