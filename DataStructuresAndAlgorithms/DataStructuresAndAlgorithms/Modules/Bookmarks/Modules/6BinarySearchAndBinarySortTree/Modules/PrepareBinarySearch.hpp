//
//  PrepareBinarySearch.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/12/2.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef PrepareBinarySearch_hpp
#define PrepareBinarySearch_hpp

#include <stdio.h>
#include <vector>

/// 预备知识：二分查找基础知识
class PrepareBinarySearch {
public:
    std::vector<int> search_array(std::vector<int> &sort_array, std::vector<int> &random_array);
    
private:
    //递归
    bool binary_search(std::vector<int> &sort_arry, int begin, int end, int target);
    //循环
    bool binary_search(std::vector<int> &sort_arry, int target);
    
};

#endif /* PrepareBinarySearch_hpp */
