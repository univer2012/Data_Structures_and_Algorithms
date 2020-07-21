//
//  LeetCode224.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/21.
//  Copyright © 2020 blue. All rights reserved.
//
/*
 例5：简单的计算器
 设计一个计算器，输入一个字符串存储的数学表达式，可以及时包括“(”、“)”、“+”、“-”四种付豪的数学表达式，输入的数学表达式字符串保证是合法的。输入端数学表达式中可能存在空格字符。
 
 选中：LeetCode 224 Basic Calculator
 难度：Hard
 */
#ifndef LeetCode224_hpp
#define LeetCode224_hpp

#include <stdio.h>
#include <string>
#include <stack>


//例5 的 难点：字符串转换数字
static void stringToInt() {
    //将字符串“12345”转换为整型12345
    int number = 0;
    std::string s = "12345";
    for (int i = 0; i < s.length(); i++) {
        number = number * 10 + s[i] - '0';
    }
    printf("number = %d\n", number);
}

/*
 NUMBER_STATE:
 
 1)如果为数字字符：
 number = number * 10 + s[i] - '0';
 2）否则：
 number进入数字栈  number_stack.push(number)
 根据compute_flag进行计算
 并切换至 OPERATION_STATE
 并将字符指针退格、number = 0;
 
 
 
 OPERATION_STATE:
 1）如果 + -
 operation_stack.push
 compute_flag = 1
 
 2）如果 (
 compute_flag = 0
 切换至NUMBER_STATE
 
 3）如果 )
 进行计算 compute
 
 4）如果 0 ~ 9
 切换至NUMBER_STATE
 注意字符指针退格！
 
 
 */
class Solution224 {
public:
    int calculate(std::string s);
    
private:
    //例5的 计算函数
    void compute(std::stack<int> &number_stack, std::stack<char> &operation_stack);
};


//


#endif /* LeetCode224_hpp */


/*
 预备知识：二叉堆属性
 最(大)小二叉堆，最(大)小值先出的完全二叉树。
 
 
 预备知识：STL优先级队列（二叉堆）
 二叉堆，最(大)小值先出的完全二叉树。
 */

class BinaryHeapDemo {
public:
    static void sec1demo9();
};
