//
//  SGHBookmarksViewController.m
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/16.
//  Copyright © 2020 blue. All rights reserved.
//

#import "SGHBookmarksViewController.h"

@interface SGHBookmarksViewController ()

@end

@implementation SGHBookmarksViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.type = SHBaseTableTypeNewVC;
    
    //MARK: section 1
    NSArray *tempTitleArray = @[
        @"测试OC调用cpp代码",
        @"第二章 链表",
        @"1.栈、队列、堆",
        @"2.链表",
        @"3.贪心",
        @"4.递归、回溯与分治",
    ];
    NSArray *tempClassNameArray = @[
        @"SGHCallCppClassViewController",
        @"SGHChapter2ViewController",
        @"SGHStackQueueHeapViewController",
        @"SGH2ListNodeViewController",
        @"SGHGreedyAlgorithmViewController",
        @"SGHRecursiveBackViewController",
    ];
    [self addSectionDataWithClassNameArray:tempClassNameArray titleArray:tempTitleArray title:@"《数据结构(C++版)(第2版)》王红梅/胡明/王涛 编著--源代码"];
}

//- (void)chap2demo1 {
//
//}

@end
