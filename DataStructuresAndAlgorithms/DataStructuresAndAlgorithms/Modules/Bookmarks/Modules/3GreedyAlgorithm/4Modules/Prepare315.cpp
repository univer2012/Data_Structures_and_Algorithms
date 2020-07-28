//
//  Prepare315.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/27.
//  Copyright © 2020 blue. All rights reserved.
//

#include "Prepare315.hpp"

#include <algorithm>
#include <assert.h>

void Prepare315::merge_sort_two_vec(std::vector<int> &sub_vec1, //数组1
                                    std::vector<int> &sub_vec2, //数组2
                                    std::vector<int> &vec)      //合并后的数组
{
    
    int i = 0;
    int j = 0;
    while (i < sub_vec1.size() && j < sub_vec2.size()) {
        if (sub_vec1[i] <= sub_vec2[j]) {
            vec.push_back(sub_vec1[i]);
            i++;
        } else {
            vec.push_back(sub_vec2[j]);
            j++;
        }
    }
    //将sub_vec1 或sub_vec2中剩余元素push进入vec
    for (; i < sub_vec1.size(); i++) {
        vec.push_back(sub_vec1[i]);
    }
    for (; j < sub_vec2.size(); j++) {
        vec.push_back(sub_vec2[j]);
    }
}

void Prepare315::sec2demo9() {
    int test1[] = {2,5,8,20};
    int test2[] = {1,3,5,7,30,50};
    std::vector<int> sub_vec1;
    std::vector<int> sub_vec2;
    std::vector<int> vec;
    
    for (int i = 0; i < 4; i++) {
        sub_vec1.push_back(test1[i]);
    }
    for (int i = 0; i < 6; i++) {
        sub_vec2.push_back(test2[i]);
    }
    
    merge_sort_two_vec(sub_vec1, sub_vec2, vec);
    for (int i = 0; i < vec.size(); i++) {
        printf("[%d]", vec[i]);
    }
    printf("\n");
    
}

//预备知识：归并排序实现
void Prepare315::merge_sort(std::vector<int> &vec) {
    if (vec.size() < 2) {
        return;         //求解：子问题足够小时，直接求解
    }
    
    //对原问题进行分解，即对原数组拆分为两个规模相同的数组，再对它们分别求解（排序）
    int mid = (int)vec.size() / 2;
    std::vector<int> sub_vec1;
    std::vector<int> sub_vec2;
    for (int i = 0; i < mid; i++) {
        sub_vec1.push_back(vec[i]);
    }
    for (int i = mid; i < vec.size(); i++) {
        sub_vec2.push_back(vec[i]);
    }
    
    //对拆解后的两个子问题进行求解
    merge_sort(sub_vec1);
    merge_sort(sub_vec2);
    
    vec.clear();
    
    //合并，将子问题的解进行合并
    merge_sort_two_vec(sub_vec1, sub_vec2, vec);
}

void Prepare315::sec2demo10() {
    std::vector<int> vec;
    int test[] = {5, -7, 9, 8, 1, 4, -3, 10, 2, 0};
    for (int i = 0; i < 10; i++) {
        vec.push_back(test[i]);
    }
    
    merge_sort(vec);
    for (int i = 0; i < vec.size(); i++) {
        printf("[%d]", vec[i]);
    }
    
    printf("\n\n");
}

void Prepare315::sec2demo10_2() {
    //生成随机数组，利用 std::sort测试归并排序
    std::vector<int> vec1;
    std::vector<int> vec2;
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        int num = (rand() * rand()) % 100003;
        vec1.push_back(num);
        vec2.push_back(num);
    }
    
    merge_sort(vec1);
    std::sort(vec2.begin(), vec2.end());
    assert(vec1.size() == vec2.size());
    for (int i = 0; i < vec1.size(); i++) {
        assert(vec1[i] == vec2[i]);
    }
}
