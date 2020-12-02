//
//  PrepareBinarySearch.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/12/2.
//  Copyright © 2020 blue. All rights reserved.
//

#include "PrepareBinarySearch.hpp"

std::vector<int> PrepareBinarySearch::search_array(std::vector<int> &sort_array, std::vector<int> &random_array) {
    std::vector<int> result;
    for (int i = 0; i < random_array.size(); i++) {
        int res = binary_search(sort_array, 0, (int)sort_array.size() - 1, random_array[i]);
        result.push_back(res);
    }
    return result;
}


/*
 sort_arry  : 排序数组
 begin、end      : 待搜索的区间左端、右端
 target     : 搜索目标
 return bool值，搜索到返回true，否则返回false
 */
bool PrepareBinarySearch::binary_search(std::vector<int> &sort_arry, int begin, int end, int target) {
    if (begin > end) {
        return false;
    }
    int mid = (begin + end) / 2;
    if (target == sort_arry[mid]) {
        return true;
    } else if (target < sort_arry[mid]) {
        return  binary_search(sort_arry, begin, mid - 1, target);
    } else if (target > sort_arry[mid]) {
        return  binary_search(sort_arry, mid + 1, end, target);
    }
    return false;
}

/*
 sort_arry  : 排序数组
 target     : 搜索目标
 return bool值，搜索到返回true，否则返回false
 */
bool PrepareBinarySearch::binary_search(std::vector<int> &sort_arry, int target) {
    int begin = 0;
    int end = (int)sort_arry.size() - 1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (target == sort_arry[mid]) {
            return true;
        } else if (target < sort_arry[mid]) {
            end = mid - 1;
        } else if (target > sort_arry[mid]) {
            begin = mid + 1;
        }
    }
    return false;
}
