//
//  LeetCode376.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/21.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode376.hpp"

int Solution376::wiggleMaxLength(std::vector<int> &nums) {
    if (nums.size() < 2) {  //序列个数小于2时，直接为摇摆序列
        return (int)nums.size();
    }
    //扫描序列时的三种状态
    static const int BEGIN = 0;
    static const int UP = 1;
    static const int DOWN = 2;
    
    int STATE = BEGIN;
    int max_length = 1; //摇摆序列最大长度至少为1
    
    //从第二个元素开始扫描
    for (int i = 1; i < nums.size(); i++) {
        switch (STATE) {
            case BEGIN:
                if (nums[i - 1] < nums[i]) {
                    STATE = UP;
                    max_length ++;
                }
                else if (nums[i - 1] > nums[i]) {
                    STATE = DOWN;
                    max_length ++;
                }
                break;
                
            case UP:
                if (nums[i - 1] > nums[i]) {
                    STATE = DOWN;
                    max_length++;
                }
                break;
            case DOWN:
                if (nums[i - 1] < nums[i]) {
                    STATE = UP;
                    max_length++;
                }
                break;
        }
    }
    
    return max_length;
}
