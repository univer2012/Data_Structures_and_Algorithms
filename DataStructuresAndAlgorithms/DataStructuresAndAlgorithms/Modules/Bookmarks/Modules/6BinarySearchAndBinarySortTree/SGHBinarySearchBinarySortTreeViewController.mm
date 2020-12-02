//
//  SGHBinarySearchBinarySortTreeViewController.m
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/12/2.
//  Copyright © 2020 blue. All rights reserved.
//

#import "SGHBinarySearchBinarySortTreeViewController.h"

#include "PrepareBinarySearch.hpp"
#include <vector>
#include "LeetCode35.hpp"
#include "LeetCode34.hpp"

@interface SGHBinarySearchBinarySortTreeViewController ()

@end

@implementation SGHBinarySearchBinarySortTreeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.type = SHBaseTableTypeMethod;
    
    //MARK: section 1
    NSArray *tempTitleArray = @[
        @"1.预备知识：二分查找基础知识",
        @"例1：插入位置",
        @"例2：区间查找",
    ];
    NSArray *tempClassNameArray = @[
        @"sec1demo1",
        @"sec1demo2",
        @"sec1demo3",
    ];
    [self addSectionDataWithClassNameArray:tempClassNameArray titleArray:tempTitleArray title:@"二分查找与二叉查找树"];
}

//MARK: 例2：区间查找
- (void)sec1demo3 {
    int test[] = {5, 7, 7, 8, 8, 8, 8, 10};
    std::vector<int> nums;
    Solution34 solve;
    for (int i = 0; i < 8; i++) {
        nums.push_back(test[i]);
    }
    for (int i = 0; i < 12; i++) {
        std::vector<int> result = solve.searchRange(nums, i);
        printf("%d : [%d, %d]\n", i, result[0], result[1]);
    }
}

//MARK: 例1：插入位置
- (void)sec1demo2 {
    int test[] = {1, 3, 5, 6};
    std::vector<int> nums;
    Solution35 solve;
    for (int i = 0; i < 4; i++) {
        nums.push_back(test[i]);
    }
    for (int i = 0; i < 8; i++) {
        printf("i = %d index = %d\n", i, solve.searchInsert(nums, i));
    }
}

//MARK: 1.预备知识：二分查找基础知识
- (void)sec1demo1 {
    int A[] = {-1, 2, 5, 20, 90, 100, 207, 800};
    int B[] = {50, 90, 3, -1, 207, 80};
    std::vector<int> sort_array;
    std::vector<int> random_array;
    std::vector<int> C;
    
    for (int i = 0; i < 8 ; i++) {
        sort_array.push_back(A[i]);
    }
    for (int i = 0; i < 6; i++) {
        random_array.push_back(B[i]);
    }
    PrepareBinarySearch solve;
    C = solve.search_array(sort_array, random_array);
    for (int i = 0; i < C.size(); i++) {
        printf("%d\n", C[i]);
    }
}


@end
