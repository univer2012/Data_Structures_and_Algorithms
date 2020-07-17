//
//  SGHCallCppClassViewController.m
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/16.
//  Copyright © 2020 blue. All rights reserved.
//

#import "SGHCallCppClassViewController.h"
#import "SGHTextCppClass.hpp"

#import "SGHCppStudent.hpp"


#import "SGHObjectiveCAdaptor.h"
#import "SGHCPlusPlusClass.hpp"

@interface SGHCallCppClassViewController ()

@end

@implementation SGHCallCppClassViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.type = SHBaseTableTypeMethod;
    
    //MARK: section 1
    NSArray *tempTitleArray = @[
        @"1.测试OC调用cpp代码",
        @"3.测试:如何在oc的类中调用c++对象",
    ];
    NSArray *tempClassNameArray = @[
        @"demo1",
        @"demo3",
    ];
    [self addSectionDataWithClassNameArray:tempClassNameArray titleArray:tempTitleArray title:@"第二章"];
    
    
    
}

//MARK: 3.测试:如何在oc的类中调用c++对象
//来自：[如何在oc的类中调用c++对象](https://blog.csdn.net/ztanap/article/details/25393395)
- (void)demo3 {
    //使用c++的适配器，调用c++代码
    SGHObjectiveCAdaptor * testObjectiveCObj = [[SGHObjectiveCAdaptor alloc] init];
    [testObjectiveCObj objectiveFunc];
    //[testObjectiveCObj release];
    
    //直接调用c++的类
    CPlusPlusClass * cppClass = new CPlusPlusClass();
    cppClass->setInt(8);
    cppClass->func();
}

- (void)demo2 {
    printf("调用C语言。");
//    Student *student = new Student();
//    student->getWeight();
//    delete student;
}

- (void)demo1 {
    const char *pathChar = "a";
    MyCppClass::ShowMsg(pathChar);
    float * array = GetDotClass::GetDot();
}


@end
