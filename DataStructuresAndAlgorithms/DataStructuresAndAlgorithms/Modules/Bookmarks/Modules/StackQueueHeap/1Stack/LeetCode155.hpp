//
//  LeetCode155.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/20.
//  Copyright © 2020 blue. All rights reserved.
//
/*例3：包含min函数的栈
 
 设计一个栈，支持如下操作，这些操作的算法复杂度需要是常数级，O(1)
 1.push(x)  :将元素x压入栈中
 2.pop()    :弹出（移除）栈顶元素
 3.top()    :返回栈顶元素
 4.getMin() :返回栈内最小元素
 
 选自：LeetCode 155 Min Stack
 难度：Easy
 */
#ifndef LeetCode155_hpp
#define LeetCode155_hpp

//时间复杂度是O(1)，因为用了空间换取时间的算法
#include <stdio.h>
#include <stack>

class MinStack155 {
public:
    MinStack155() {}
    void push(int x) {
        _data.push(x);              //将数据压入数据栈
        if (_min.empty()) {         //栈为开孔，直接入栈
            _min.push(x);
        } else {
            if (x > _min.top()) {   //如果新数据大于最小值栈的栈顶，则改变x的值
                x = _min.top();
            }
            _min.push(x);           //将x push进入最小值栈
        }
    }
    
    void pop() {
        _data.pop();                //数据栈与最小值栈同时弹出
        _min.pop();
    }
    
    int top() {                     //top即返回数据栈栈顶
        return _data.top();
    }
    int getMin() {                  //getMin即返回最小值栈栈顶
        return _min.top();
    }
    
private:
    std::stack<int> _data;      //数据栈
    std::stack<int> _min;       //最小值栈
};


#endif /* LeetCode155_hpp */
