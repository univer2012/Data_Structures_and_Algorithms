//
//  SGHBinaryTreeGraphViewController.m
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/31.
//  Copyright © 2020 blue. All rights reserved.
//

#import "SGHBinaryTreeGraphViewController.h"

#include "PrePareBinaryTree.hpp"

@interface SGHBinaryTreeGraphViewController ()

@end

@implementation SGHBinaryTreeGraphViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.type = SHBaseTableTypeMethod;
    
    //MARK: section 1
    NSArray *tempTitleArray = @[
        @"1.预备知识：二叉树 前序遍历二叉树",
    ];
    NSArray *tempClassNameArray = @[
        @"sec1demo1",
    ];
    [self addSectionDataWithClassNameArray:tempClassNameArray titleArray:tempTitleArray title:@"二叉树与图"];
}

//MARK: 1.预备知识：二叉树 前序遍历二叉树
- (void)sec1demo1 {
    PrePareBinaryTree solve;
    solve.sec1demo1();
}

@end
