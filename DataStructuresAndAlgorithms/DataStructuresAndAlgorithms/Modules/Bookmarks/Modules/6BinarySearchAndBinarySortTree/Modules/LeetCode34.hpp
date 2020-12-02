//
//  LeetCode34.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/12/2.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef LeetCode34_hpp
#define LeetCode34_hpp

#include <stdio.h>
#include <vector>


class Solution34 {
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target);
    
private:
    int left_bound(std::vector<int> &nums, int target);
    int right_bound(std::vector<int> &nums, int target);
};

#endif /* LeetCode34_hpp */
