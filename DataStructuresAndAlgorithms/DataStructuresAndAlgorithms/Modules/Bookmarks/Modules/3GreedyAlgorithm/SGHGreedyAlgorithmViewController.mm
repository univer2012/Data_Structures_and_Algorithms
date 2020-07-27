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

#include "LeetCode78.hpp"
#include "LeetCode78_2.hpp"
#include "LeetCode90.hpp"
#include "LeetCode40.hpp"
#include "LeetCode22.hpp"
#include "LeetCode51.hpp"

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
    
    //MARK: section 2
    NSArray *tempTitleArray2 = @[
        @"1.例1-a（方法1回溯法）：预备知识（循环/递归）",
        @"2.例1-a方法1回溯法 实现",
        @"3.例1-a方法2位运算法 实现",
        @"4.例1-b：求子集2",
        @"5.例1-c：组合数之和2",
        @"6.例2：预备知识：递归生成所有可能",
        @"7.例2：生成括号",
        @"8.例3：N皇后",
    ];
    NSArray *tempClassNameArray2 = @[
        @"sec2demo1",
        @"sec2demo2",
        @"sec2demo3",
        @"sec2demo4",
        @"sec2demo5",
        @"sec2demo6",
        @"sec2demo7",
        @"sec2demo8",
    ];
    [self addSectionDataWithClassNameArray:tempClassNameArray2 titleArray:tempTitleArray2 title:@"递归、回溯与分治"];
}

//MARK: 8.例3：N皇后
- (void)sec2demo8 {
    std::vector<std::vector<std::string>> result;
    Solution51 solve;
    result = solve.solveNQueue(4);
    for (int i = 0; i < result.size(); i++) {
        printf("i = %d\n", i);
        for (int j = 0; j < result[i].size(); j++) {
            printf("%s\n", result[i][j].c_str());
        }
        printf("\n");
    }
}

//MARK: 7.例2：生成括号
- (void)sec2demo7 {
    Solution22 solve;
    std::vector<std::string> result = solve.generateParenthesis(3);
    for (int i = 0; i < result.size(); i++) {
        printf("%s\n",result[i].c_str());
    }
}

//MARK: 6.例2：预备知识：递归生成所有可能
- (void)sec2demo6 {
    Prepare22 solve;
    solve.sec2demo6();
}

//MARK: 5.例1-c：组合数之和2
- (void)sec2demo5 {
    
    std::vector<int> nums;
    nums.push_back(10);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(1);
    nums.push_back(5);
    
    std::vector<std::vector<int>> result;
    Solution40_2 solve;
    result = solve.combinationSum2(nums, 8);
    
    for (int i = 0; i < result.size(); i++) {
        printf("[");
        for (int j = 0; j < result[i].size(); j++) {
            if (j == result[i].size() - 1) {
                printf("%d", result[i][j]);
            } else {
                printf("%d,", result[i][j]);
            }
            
        }
        printf("]\n");
    }
}

//MARK: 4.例1-b：求子集2
- (void)sec2demo4 {
    std::vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    
    std::vector<std::vector<int>> result;
    Solution90 solve;
    result = solve.subsetsWithDup(nums);
    for (int i = 0; i < result.size(); i++) {
        printf("[");
        for (int j = 0; j < result[i].size(); j++) {
            if (j == result[i].size() - 1) {
                printf("%d", result[i][j]);
            } else {
                printf("%d,", result[i][j]);
            }
            
        }
        printf("]\n");
    }
}

//MARK: 3.例1-a方法2位运算法 实现
- (void)sec2demo3 {
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    
    std::vector<std::vector<int>> result;
    Solution78_2 solve;
    result = solve.subsets(nums);
    
    //打印result
    for (int i = 0; i < result.size(); i++) {
        printf("[");
        for (int j = 0; j < result[i].size(); j++) {
            if (j == result[i].size() - 1) {
                printf("%d", result[i][j]);
            } else {
                printf("%d,", result[i][j]);
            }
            
        }
        printf("]\n");
    }
}

//MARK: 2.例1-a方法1回溯法 实现
- (void)sec2demo2 {
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    
    Solution78 solve;
    std::vector<std::vector<int>> result = solve.subsets(nums);
    
    //打印result
    for (int i = 0; i < result.size(); i++) {
        printf("[");
        for (int j = 0; j < result[i].size(); j++) {
            if (j == result[i].size() - 1) {
                printf("%d", result[i][j]);
            } else {
                printf("%d,", result[i][j]);
            }
            
        }
        printf("]\n");
    }
}


//MARK: 1.例1-a（方法1回溯法）：预备知识（循环/递归）
/*
 预备知识：回溯法
 回溯法又称为试探法，但当探索到某一步时，发现原先选择达不到目标，就退回一步重新选择，这种走不通就退回再走的技术为回溯法。
 
 */
- (void)sec2demo1 {
    Prepare78 solve;
    solve.sec2demo1();
    
    solve.sec2demo1_2();
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
