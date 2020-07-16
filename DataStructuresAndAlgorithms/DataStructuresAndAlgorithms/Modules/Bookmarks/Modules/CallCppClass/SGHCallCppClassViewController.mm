//
//  SGHCallCppClassViewController.m
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/16.
//  Copyright © 2020 blue. All rights reserved.
//

#import "SGHCallCppClassViewController.h"
#import "SGHTextCppClass.hpp"

@interface SGHCallCppClassViewController ()

@end

@implementation SGHCallCppClassViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.type = SHBaseTableTypeMethod;
    
    //MARK: section 1
    NSArray *tempTitleArray = @[
        @"测试OC调用cpp代码",
    ];
    NSArray *tempClassNameArray = @[
        @"demo1",
    ];
    [self addSectionDataWithClassNameArray:tempClassNameArray titleArray:tempTitleArray title:@"第二章"];
    
    
    
}

- (void)demo1 {
    const char *pathChar = "a";
    MyCppClass::ShowMsg(pathChar);
    float * array = GetDotClass::GetDot();
}


@end
