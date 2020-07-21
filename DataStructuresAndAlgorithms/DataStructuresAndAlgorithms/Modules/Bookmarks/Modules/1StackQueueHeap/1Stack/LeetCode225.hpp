//
//  LeetCode225.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/20.
//  Copyright © 2020 blue. All rights reserved.
//
/*
 例1：使用队列实现栈
 设计一个栈，支持基本的栈操作，这个栈的内部存储数据的结构物为队列，队列的方法智能包括push、peek(front)、pop、size、empty等标准的队列方法。
 
 选自：LeetCode 225 Implement Stack using Queues
 难度：Easy
 */
#ifndef LeetCode225_hpp
#define LeetCode225_hpp

#include <stdio.h>
#include <queue>

class MyStack225 {
public:
    MyStack225() {}
    void push(int x){
        std::queue<int> temp_queue;
        temp_queue.push(x);                 //将新元素push进入临时队列temp_queue
        while (!_data.empty()) {
            temp_queue.push(_data.front()); //将元队列内容push进入临时队列temp_queue
            _data.pop();
        }
        while (!temp_queue.empty()) {
            _data.push(temp_queue.front()); //将临时队列temp_queue元素push进入数据队列_data_queue
            temp_queue.pop();
        }
    }
    int pop() {
        int x = _data.front();  //去栈顶元素，即为队列头部元素
        _data.pop();            //弹出队列头部元素
        return x;               //返回取出的队列头部元素x，即为栈顶元素
    }
    int top() {
        return _data.front();   //返回栈顶即直接犯规队列头部元素
    }
    bool empty() {
        return _data.empty();
    }
private:
    std::queue<int> _data;      //_data数据队列存储元素的顺序，就是栈存储元素顺序
};

#endif /* LeetCode225_hpp */
