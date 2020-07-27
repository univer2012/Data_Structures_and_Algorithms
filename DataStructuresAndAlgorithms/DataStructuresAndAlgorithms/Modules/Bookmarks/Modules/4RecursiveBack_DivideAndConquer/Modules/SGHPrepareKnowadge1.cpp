//
//  SGHPrepareKnowadge1.cpp
//  DataStructuresAndAlgorithms
//
//  Created by 远平 on 2020/7/26.
//  Copyright © 2020 blue. All rights reserved.
//

#include "SGHPrepareKnowadge1.hpp"


void compute_sum_3(int i, int &sum) {
    sum += i;                   //i = 3,将sum加上3
}

void compute_sum_2(int i, int &sum) {
    sum += i;
    compute_sum_3(i + 1, sum);  //i = 2,将sum加上2，调用compute_sum_3(3,sum)
}

void compute_sum_1(int i, int &sum) {
    sum += i;
    compute_sum_2(i + 1, sum);  //i = 1,将sum加上1，调用compute_sum_2(2,sum)
}

void PrepareKnowadge1::prepareKnowadge1() {
    int sum = 0;
    compute_sum_1(1, sum);  //计算 1+2+3，将结果存储至sum，并打印sum
    printf("sum = %d\n",sum);
}



// ==================== ==================== ====================
void compute_sum(int i, int &sum) {
    if (i > 3) {
        return;
    }
    sum += i;
    compute_sum(i + 1, sum);
}

void PrepareKnowadge1::prepareKnowadge1_2() {
    int sum = 0;
    compute_sum(1, sum);
    printf("sum = %d\n", sum);
}
