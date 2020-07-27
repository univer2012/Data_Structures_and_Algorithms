//
//  SGHRecursiveBackViewController.m
//  DataStructuresAndAlgorithms
//
//  Created by 远平 on 2020/7/26.
//  Copyright © 2020 blue. All rights reserved.
//

#import "SGHRecursiveBackViewController.h"

#include "SGHPrepareKnowadge1.hpp"
#include "SGHPrepareKnowadge2.hpp"

@interface SGHRecursiveBackViewController ()

@end

@implementation SGHRecursiveBackViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.type = SHBaseTableTypeMethod;
    
    //MARK: section 1
    NSArray *tempTitleArray = @[
        @"1.预备知识：递归函数基础",
        @"2.预备知识：课堂练习",
    ];
    NSArray *tempClassNameArray = @[
        @"sec1demo1",
        @"sec1demo2",
    ];
    [self addSectionDataWithClassNameArray:tempClassNameArray titleArray:tempTitleArray title:@"递归、回溯与分治"];
}

//MARK: 2.预备知识：课堂练习
- (void)sec1demo2 {
    PrepareKnowadge2 demo;
    demo.prepareKnowadge2();
}

//MARK: 1.预备知识：递归函数基础
- (void)sec1demo1 {
    PrepareKnowadge1 demo;
    demo.prepareKnowadge1();
    
    demo.prepareKnowadge1_2();
}


@end
