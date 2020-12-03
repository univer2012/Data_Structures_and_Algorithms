//
//  LeetCode33.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/12/3.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode33.hpp"

int Solution33::search(std::vector<int> &nums, int target) {
    int begin = 0;
    int end = (int)nums.size() - 1;
    
    while (begin <= end) {
        int mid = (begin + end) / 2;
        
        if (target == nums[mid]) {
            return mid;
        }
        else if (target < nums[mid]) {              //target
            if (nums[begin] < nums[mid]) {          //说明递增区间[begin, mid - 1]，旋转区间为[mid + 1, end]
                if (target >= nums[begin]) {        //target在旋转区间
                    end = mid - 1;
                }
                else {
                    begin = mid + 1;                //target在递增区间
                }
            }
            else if (nums[begin] > nums[mid]) {     //旋转区间[begin, mid - 1]，递增区间为[mid + 1, end]
                end = mid - 1;                      //target在旋转区间
            }
            else if (nums[begin] == nums[mid]) {    //说明目标只可能在[mid + 1, end]间，如target = 1，数组[6, 1]
                begin = mid + 1;
            }
        }
        else if (target > nums[mid]) {              //target
            if (nums[begin] < nums[mid]) {          //说明递增区间[begin, mid - 1]，旋转区间为[mid + 1, end]
                begin = mid + 1;                    //target在旋转区间
            }
            else if (nums[begin] > nums[mid]) {     //说明旋转区间[begin, mid - 1]，递增区间为[mid + 1, end]
                if (target >= nums[begin]) {
                    end = mid - 1;                  //target在旋转区间
                }
                else {
                    begin = mid + 1;                //target在递增区间
                }
            }
            else if (nums[begin] == nums[mid]) {    //说明目标只可能在[mid + 1, end]间，如target = 7，数组[6, 7]
                begin = mid + 1;
            }
        }
    }
    return -1;
}
