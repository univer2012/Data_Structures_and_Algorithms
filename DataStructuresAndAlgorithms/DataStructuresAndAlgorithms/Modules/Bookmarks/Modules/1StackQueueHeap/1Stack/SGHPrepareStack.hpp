//
//  SGHPrepareStack.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/20.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef SGHPrepareStack_hpp
#define SGHPrepareStack_hpp

#include <stdio.h>
#include <stack>
#include <queue>

class  SGHPrepareStack {
public:
    static void sec1demo1() {
        /*
         S.top()        //取出栈顶
         S.empty()      //判断栈是否为空
         S.push(x)      //将x添加至栈
         S.pop()        //弹出栈顶
         S.size()       //栈的存储元素个数
         */
        std::stack<int> S;
        if (S.empty()) {
            printf("S is empty!");
        }
        S.push(5);
        S.push(6);
        S.push(10);
        
        printf("S.top = %d\n", S.top());
        S.pop();
        S.pop();
        printf("S.top = %d\n", S.top());
        printf("T.size = %lu\n", S.size());
    }
    
    static void sec1demo2() {
        /*
         Q.empty()      //判断队列是否为空
         Q.front()      //返回队列头部元素
         Q.back()       //返回队列尾部元素
         Q.pop()        //弹出队列头部元素
         Q.push(x)      //将x添加至队列
         Q.size()       //返回对垒的存储元素的个数
         */
        std::queue<int> Q;
        if (Q.empty()) {
            printf("Q is empty!\n");
        }
        Q.push(5);
        Q.push(6);
        Q.push(10);
        printf("Q.front = %d\n",Q.front());
        
        Q.pop();
        Q.pop();
        printf("Q.front = %d/n",Q.front());
        
        Q.push(1);
        printf("Q.back = %d\n",Q.back());
        printf("Q.size = %lu\n", Q.size());
        
    }
    
    
};


#endif /* SGHPrepareStack_hpp */
