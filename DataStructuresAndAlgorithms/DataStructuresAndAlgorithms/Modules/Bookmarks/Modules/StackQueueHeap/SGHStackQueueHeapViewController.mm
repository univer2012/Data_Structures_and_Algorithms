//
//  SGHStackQueueHeapViewController.m
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/20.
//  Copyright © 2020 blue. All rights reserved.
//

#import "SGHStackQueueHeapViewController.h"

#include "SGHPrepareStack.hpp"
#include "LeetCode225.hpp"
#include "LeetCode232.hpp"
#include "LeetCode155.hpp"

#include "POJ1363Rails.hpp"


@interface SGHStackQueueHeapViewController ()

@end

@implementation SGHStackQueueHeapViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.type = SHBaseTableTypeMethod;
    
    //MARK: section 1
    NSArray *tempTitleArray = @[
        @"1.预备知识：STL stack（栈）",
        @"2.预备知识：STL queue（队列）",
        @"3.LeetCode225:测试",
        @"4.LeetCode232:测试",
        @"5.LeetCode155:测试",
        @"6.POJ1363Rails:合法的出栈序列",
        @"7.字符串转换数字",
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
    [self addSectionDataWithClassNameArray:tempClassNameArray titleArray:tempTitleArray title:@"栈"];
    
    //MARK: section 1
    NSArray *tempTitleArray2 = @[
    ];
    NSArray *tempClassNameArray2 = @[
    ];
    [self addSectionDataWithClassNameArray:tempClassNameArray2 titleArray:tempTitleArray2 title:@"队列"];
    
    NSArray *tempTitleArray3 = @[
    ];
    NSArray *tempClassNameArray3 = @[
    ];
    [self addSectionDataWithClassNameArray:tempClassNameArray3 titleArray:tempTitleArray3 title:@"堆"];
}

//MARK:7.字符串转换数字
- (void)sec1demo7 {
    stringToInt();
}

//MARK: 6.POJ1363Rails: 测试
- (void)sec1demo6 {
    int arr[6] = {6,5,4,3,2,1};
//    int arr[5] = {5,4,1,2,3};
//    int arr[5] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::queue<int> order;
    for (int i = 0; i < n; i++) {
        order.push(arr[i]);
    }
    if (check_is_valid_order(order)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

//MARK: 5.LeetCode155:测试
- (void)sec1demo5 {
    MinStack155 minStack;
    minStack.push(-2);
    printf("top = [%d]\n", minStack.top());
    printf("min = [%d]\n\n", minStack.getMin());
    minStack.push(0);
    printf("top = [%d]\n", minStack.top());
    printf("min = [%d]\n\n", minStack.getMin());
    minStack.push(-5);
    printf("top = [%d]\n", minStack.top());
    printf("min = [%d]\n\n", minStack.getMin());
    minStack.pop();
    printf("top = [%d]\n", minStack.top());
    printf("min = [%d]\n\n", minStack.getMin());
}

//MARK: 4.LeetCode232:测试
- (void)sec1demo4 {
    MyQueue232 Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    printf("%d\n", Q.peek());
    Q.pop();
    printf("%d\n", Q.peek());
}

//MARK: 3.LeetCode225:测试
- (void)sec1demo3 {
    MyStack225 S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    printf("%d\n", S.top());
    S.pop();
    printf("%d\n", S.top());
    S.push(5);
    printf("%d\n", S.top());
}

//MARK: 2.预备知识：STL queue（队列）
- (void)sec1demo2 {
    SGHPrepareStack::sec1demo2();
}

//MARK: 1.预备知识：STL stack（栈）
- (void)sec1demo1 {
    SGHPrepareStack::sec1demo1();
}


@end
