//
//  POJ1363Rails.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/20.
//  Copyright © 2020 blue. All rights reserved.
//
/*
 例4：合法的出栈序列
 已知从1至n的数字序列，按顺序入栈，每个数字入栈后即可出栈，也可在栈中停留，等待后面的数字入栈出栈后，该数字出栈，求该数字序列的出栈序列是否合法？
 
 选自 poj 1363 Rails
 难度：Medium
 */
#ifndef POJ1363Rails_hpp
#define POJ1363Rails_hpp

#include <stdio.h>
#include <stack>
#include <queue>
#include <array>


//整体算法复杂度O(n)
static bool check_is_valid_order(std::queue<int> & order) {
    std::stack<int> S;      //S为模拟栈
    
    unsigned long n = order.size(); //n为序列长度，将 1 ~ n 按顺序入栈
    
    for (int i = 1; i <= n; i++) {
        S.push(i);  //对元素i做入栈操作
        
        while (!S.empty() && order.front() == S.top()) {
            S.pop();
            order.pop();
        }
    }
    
    if (!S.empty()) {   //如果栈不空，就返回false即不是合法的序列
        return false;
    }
    return true;
}


#include <string>

static void stringToInt() {
    //将字符串“12345”转换为整型12345
    int number = 0;
    std::string s = "12345";
    for (int i = 0; i < s.length(); i++) {
        number = number * 10 + s[i] - '0';
    }
    printf("number = %d\n", number);
}





#endif /* POJ1363Rails_hpp */
