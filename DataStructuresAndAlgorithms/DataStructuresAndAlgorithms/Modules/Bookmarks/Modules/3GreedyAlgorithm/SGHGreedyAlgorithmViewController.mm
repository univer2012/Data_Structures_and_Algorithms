//
//  SGHGreedyAlgorithmViewController.m
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/21.
//  Copyright © 2020 blue. All rights reserved.
//

#import "SGHGreedyAlgorithmViewController.h"

#include "SGHPrepareGreedy.hpp"
#include "LeetCode455.hpp"
#include "LeetCode376.hpp"

#include <iostream>

@interface SGHGreedyAlgorithmViewController ()

@end

@implementation SGHGreedyAlgorithmViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.type = SHBaseTableTypeMethod;
    
    //MARK: section 1
    NSArray *tempTitleArray = @[
        @"1.预备知识：贪心法找钱",
        @"2.LeetCode455:分糖果",
        @"3.LeetCode376:摇摆序列",
    ];
    NSArray *tempClassNameArray = @[
        @"sec1demo1",
        @"sec1demo2",
        @"sec1demo3",
    ];
    [self addSectionDataWithClassNameArray:tempClassNameArray titleArray:tempTitleArray title:@"贪心"];
}

//MARK: 3.LeetCode376:摇摆序列
- (void)sec1demo3 {
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(17);
    nums.push_back(5);
    nums.push_back(10);
    nums.push_back(13);
    nums.push_back(15);
    nums.push_back(10);
    nums.push_back(5);
    nums.push_back(16);
    nums.push_back(8);
    Solution376 solve;
    printf("%d\n", solve.wiggleMaxLength(nums));
    
}

//MARK: 2.LeetCode455:分糖果
- (void)sec1demo2 {
    Solution455 solve;
    std::vector<int> g;
    std::vector<int> s;
    g.push_back(5);
    g.push_back(10);
    g.push_back(2);
    g.push_back(9);
    g.push_back(15);
    g.push_back(9);
    
    s.push_back(6);
    s.push_back(1);
    s.push_back(20);
    s.push_back(3);
    s.push_back(8);
    
    printf("%d\n", solve.findContentChildren(g, s));
}

//MARK: 1.预备知识：贪心法找钱
- (void)sec1demo1 {
    PrepareGreedyDemo::sec1demo1();
}

@end
