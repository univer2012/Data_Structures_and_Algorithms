//
//  LeetCode232.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/20.
//  Copyright © 2020 blue. All rights reserved.
//
/*例2：使用栈实现队列
 设计一个队列，支持基本的队列操作，这个队列的内部存储数据的结构为栈，栈的方法智能包括push、top、pop、size、empty等标准的栈方法。
 
 选自：LeetCode 232 Implement Queue using Stacks
 难度：Easy
 */
#ifndef LeetCode232_hpp
#define LeetCode232_hpp

#include <stdio.h>
#include <stack>

/*思路：
 方案：
 1.在队列push元素时，利用临时栈 调换元素次序
 2.将元数据栈内容push进入临时栈temp_stack
 3.将新数据push进入临时栈temp_stack
 4.将临时栈temp_stack中的元素进入数据栈data_stack
 */
class MyQueue232 {
public:
    MyQueue232() {}
    void push(int x) {
        std::stack<int> temp_stack;         //设置临时栈，用来调换数据栈data_stack中元素的次序
        while (!_data.empty()) {
            temp_stack.push(_data.top());   //将元数据栈内容push进入临时栈temp_stack
            _data.pop();
        }
        temp_stack.push(x);                 //将新数据push进入临时栈temp_stack
        
        while (!temp_stack.empty()) {
            _data.push(temp_stack.top());   //将临时栈temp_stack中的元素进入数据栈data_stack
            temp_stack.pop();
        }
    }
    
    //弹出队列头部元素并返回
    int pop() {
        int x = _data.top();    //将栈顶存储至x
        _data.pop();            //弹出栈顶，返回x
        return x;
    }
    int peek() {        //front
        return _data.top();
    }
    
    bool empty() {
        return _data.empty();
    }
    
private:
    std::stack<int> _data;
    
};

#endif /* LeetCode232_hpp */
