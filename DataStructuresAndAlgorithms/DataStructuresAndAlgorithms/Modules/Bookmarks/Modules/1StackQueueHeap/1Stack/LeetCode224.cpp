//
//  LeetCode224.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/21.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode224.hpp"

//i退格，实际上只有3个地方要i退格：
//1、STATE_BEGIN 转为 NUMBER_STATE 或者 OPERATION_STATE，要 i退格；
//2、NUMBER_STATE 转为 OPERATION_STATE，要 i退格；
//3、OPERATION_STATE 转为 NUMBER_STATE，要 i退格；
int Solution224::calculate(std::string s) {
    static const int STATE_BEGIN = 0;
    static const int NUMBER_STATE = 1;
    static const int OPERATION_STATE = 2;
    
    std::stack<int> number_stack;
    std::stack<char> operation_stack;
    
    int number = 0;
    int STATE = STATE_BEGIN;
    
    //使用一个变量compuate_flag记录是否可以计算。
    //当遇到「+ -」就可以计算，compuate_flag = 1；
    //当遇到「( 」就不可以计算，compuate_flag = 0
    int compuate_flag = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {      //忽略空格
            continue;
        }
        switch (STATE) {
            case STATE_BEGIN:
                if (s[i] >= '0' && s[i] <= '9') {
                    STATE = NUMBER_STATE;
                } else {
                    STATE = OPERATION_STATE;
                }
                i--;        //注意：字符指针退格！
                break;
                
            case NUMBER_STATE:
                if (s[i] >= '0' && s[i] <= '9') {
                    number = number * 10 + s[i] - '0';
                } else {
                    number_stack.push(number);
                    if (compuate_flag == 1) {
                        compute(number_stack, operation_stack);
                    }
                    number = 0;
                    i--;    //注意：字符指针退格！
                    STATE = OPERATION_STATE;
                }
                break;
                
            case OPERATION_STATE:
                if (s[i] == '+' || s[i] == '-') {
                    operation_stack.push(s[i]);
                    compuate_flag = 1;
                } else if (s[i] == '(') {
                    STATE = NUMBER_STATE;
                    compuate_flag = 0;
                } else if (s[i] >= '0' && s[i] <= '9') {
                    STATE = NUMBER_STATE;
                    i--;    //注意：字符指针退格！
                } else if (s[i] == ')') {
                    compute(number_stack, operation_stack);
                }
                break;
        }
    }
    
    if (number != 0) {
        number_stack.push(number);
        compute(number_stack, operation_stack);
    }
    if (number == 0 && number_stack.empty()) {
        return 0;
    }
    return number_stack.top();
}

//例5的 计算函数
void Solution224::compute(std::stack<int> &number_stack, std::stack<char> &operation_stack) {
    
    if (number_stack.size() < 2) {
        return; //处理特殊数据，如"(1235)"
    }
    
    int num2 = number_stack.top();
    number_stack.pop();
    int num1 = number_stack.top();
    number_stack.pop();
    
    
    if (operation_stack.top() == '+') {
        number_stack.push(num1 + num2);
    }
    else if (operation_stack.top() == '-') {
        number_stack.push(num1 - num2);
    }
    operation_stack.pop();
}


#include <stdio.h>
#include <queue>

/*
 big_heap.empty()   //判断堆是否为空
 big_heap.pop()     //弹出堆顶元素（最大值）
 big_heap.push(x)   //将元素x添加至二叉堆
 big_heap.top()     //返回堆顶元素（最大值）
 big_heap.size()    //返回堆中元素个数
 */
void BinaryHeapDemo::sec1demo9() {
    std::priority_queue<int> big_heap;  //默认构造是最大堆
    std::priority_queue<int, std::vector<int>, std::greater<int> > small_heap; //最小堆构造方法
    
    std::priority_queue<int, std::vector<int>, std::less<int> > big_heap2;  //最大堆构造方法
    if (big_heap.empty()) {
        printf("big_heap is empty!\n");
    }
    int test[] = {6, 10, 1, 7, 99, 4, 33};
    for (int i = 0; i < 7; i++) {
        big_heap.push(test[i]);
    }
    /*
                99
                / \
              10   33
              / \  / \
             6   7 1  4
     */
    printf("big_heap.top = %d\n", big_heap.top());
    big_heap.push(1000);
    /*
            1000
            /   \
          99    33
         /  \   /  \
        10   7  1   4
        /
       6
     */
    printf("big_heap.top = %d\n", big_heap.top());
    for (int i = 0; i < 3; i++) {
        big_heap.pop();
    }
    /*
            10
           /  \
          7    4
         /  \
        6    1
     */
    printf("big_heap.top = %d\n", big_heap.top());
    printf("big_heap.size = %lu\n", big_heap.size());
    
}
