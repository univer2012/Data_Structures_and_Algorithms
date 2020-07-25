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
#include "LeetCode402.hpp"
#include "LeetCode55.hpp"
#include "LeetCode45.hpp"
#include "Poj2431Expedition.hpp"

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
        @"4.LeetCode402:移除K个数字",
        @"5.LeetCode55:例4-a:跳跃游戏",
        @"6.LeetCode45:例4-b:跳跃游戏",
        @"7.Poj2431Expedition:最优加油方法",
    ];
    NSArray *tempClassNameArray = @[
        @"sec1demo1",
        @"sec1demo2",
        @"sec1demo3",
        @"sec1demo4",
        @"sec1demo5",
        @"sec1demo6",
        @"sec1demo7",
    ];
    [self addSectionDataWithClassNameArray:tempClassNameArray titleArray:tempTitleArray title:@"贪心"];
}

//MARK: 7.Poj2431Expedition:最优加油方法
///这个代码需要在c++的工程中才能运行
- (void)sec1demo7 {
    std::vector<std::pair<int, int>> stop;
    int N;
    int L;
    int P;
    int distance;
    int fuel;
    printf("请输入加油站的个数：N=");
    scanf("%d",&N);
    printf("请输入加油站数组：pair<加油站至终点的距离, 加油站汽油量>");
    for (int i = 0; i < N; i++) {
        scanf("%d %d",&distance, &fuel);
        stop.push_back(std::make_pair(distance, fuel));
    }
    printf("请输入 起点到终点的距离L 和 起点初始的汽油量P：");
    scanf("%d %d", &L, &P);
    printf("输出结果为：");
    SolutionPoj2431 solve;
    printf("%d\n",solve.get_minimum_stop(L, P, stop));
}

//MARK: 6.LeetCode45:例4-b:跳跃游戏
- (void)sec1demo6 {
    std::vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    Solution45 solve;
    printf("%d\n", solve.jump(nums));
}

//MARK: 5.LeetCode55:例4-a:跳跃游戏
- (void)sec1demo5 {
    std::vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    Solution55 solve;
    printf("%d\n", solve.canJump(nums));
    
}

//MARK: 4.LeetCode402:移除K个数字
- (void)sec1demo4 {
    //101,k=1
    Solution402 solve;
    std::string result = solve.removeKdigits("1432219", 3);
    printf("%s\n",result.c_str());

    std::string result2 = solve.removeKdigits("100200", 1);
    printf("%s\n",result2.c_str());
    
    std::string result3 = solve.removeKdigits("101", 1);
    printf("%s\n",result3.c_str());
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
