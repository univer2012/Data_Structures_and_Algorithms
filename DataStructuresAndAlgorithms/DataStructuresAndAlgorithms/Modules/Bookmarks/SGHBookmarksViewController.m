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
        @"第二章",
    ];
    NSArray *tempClassNameArray = @[
        @"SGHCallCppClassViewController",
        @"SGHChapter2ViewController",
    ];
    [self addSectionDataWithClassNameArray:tempClassNameArray titleArray:tempTitleArray title:@"《数据结构(C++版)(第2版)》王红梅/胡明/王涛 编著--源代码"];
}

//- (void)chap2demo1 {
//
//}

@end
