//
//  SGHPrepareGreedy.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/21.
//  Copyright © 2020 blue. All rights reserved.
//

#include "SGHPrepareGreedy.hpp"

void PrepareGreedyDemo::sec1demo1() {
    const int RMB[] = {200, 100, 20, 10, 5, 1}; //钞票金额
    const int NUM = 6;  //6种面值
    int X = 628;
    int count = 0;
    for (int i = 0; i < NUM; i++) {
        int use = X / RMB[i];       //需要面额为RMB[i] 的use张
        count += use;               //总计增加use张
        X = X - RMB[i] * use;       //将总额减去使用RMB[i]已组成的金额
        printf("需要面额为%d的%d张，",RMB[i], use);
        printf("剩余需要支付金额%d. \n", X);
    }
    
    printf("总共需要%d张 \n", count);
}
