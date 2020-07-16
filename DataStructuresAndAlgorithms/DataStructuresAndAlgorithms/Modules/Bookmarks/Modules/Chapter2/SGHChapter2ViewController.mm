//
//  SGHChapter2ViewController.m
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/16.
//  Copyright © 2020 blue. All rights reserved.
//

#import "SGHChapter2ViewController.h"

#import "SGHLinkList.hpp"
//#import "SGHLinkList.cpp"
//#include <iostream>
//using namespace std;



@interface SGHChapter2ViewController ()

@end

@implementation SGHChapter2ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.type = SHBaseTableTypeMethod;
    
    //MARK: section 1
    NSArray *tempTitleArray = @[
        @"1链表",
    ];
    NSArray *tempClassNameArray = @[
        @"demo1",
    ];
    [self addSectionDataWithClassNameArray:tempClassNameArray titleArray:tempTitleArray title:@"第二章"];
    
    //MARK: section 1
    NSArray *tempTitleArray2 = @[
        @"1.预备知识：链表基础",
        @"1-a:测试",
        @"1-b:测试",
    ];
    NSArray *tempClassNameArray2 = @[
        @"sec2demo1",
        @"sec2demo2",
        @"sec2demo3",
    ];
    [self addSectionDataWithClassNameArray:tempClassNameArray2 titleArray:tempTitleArray2 title:@"其他"];
}
//
- (void)sec2demo3 {
    #include "LeeCode92Reverse_Linked_List2.h"
    
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    
    
    Solution solve;
    ListNode *head = solve.reverseBetween(&a, 2, 4);
    while (head) {
        printf("%d\n",head->val);
        head = head->next;
    }
    
}

- (void)sec2demo2 {
    #include "LeetCode206ReverseLinkedList.h"
    
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    
    
    Solution solve;
    ListNode *head = &a;
    printf("before reverse:\n");
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
    head = solve.reverseList(&a);
    printf("After reverse:\n");
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
}

//MARK: 1.链表基础
- (void)sec2demo1 {
    struct ListNode {
        int val;        //存储原生的数据域
        ListNode *next; //存储下一个节点地址的指针域
    };
    ListNode a;
    ListNode b;
    ListNode c;
    ListNode d;
    ListNode e;
    a.val = 10;
    b.val = 20;
    c.val = 30;
    d.val = 40;
    e.val = 50;
    
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;
    
    ListNode *head = &a;
    while (head) {
        printf("%d\n",head->val);
        head = head->next;
    }
}

//MARK: 1.链表
- (void)demo1 {
    
//    LinkList <int> a;
//    printf("执行插入操作:");
//    @try {
//        a.Insert(1,4);
//        a.Insert(2,5);
//        a.Insert(3,6);
//    } @catch (NSException *exception) {
//        printf("exception");
//    } @finally {
//        printf("none");
//    }
//    printf("已经插入“4，5，6”");
//    printf("单链表a的长度为:%d",a.Length()); //返回单链表长度
//    printf("单链表a的元素为:"); //显示链表中所有元素
//    a.PrintList();
//    printf("\n");
//
//    printf("按位查找第二个元素:");
//    printf("第二个元素为:%d \n", a.Get(2)); //查找链表中第二个元素
//
//    printf("按值查找5");
//    printf("值为5的元素位置为:%d \n",a.Locate(5)); //查找元素5，并返回在单链表中位置
//
//
//    printf("执行删除4的操作");
//    a.Delete(1);                    //删除元素4
//    printf("已删除成功，单链表a的长度为:%d \n",a.Length());
//
//    printf("链表a中的元素为:");
//    a.PrintList();
//
//
//    int r[ ]={1,2,3,4,5};
//    LinkList <int> b(r,5);     //根据数组创建单链表
//    printf("执行插入操作前单链表b为:");
//    b.PrintList();            //输出单链表所有元素
//    printf("插入前单链表b的长度为:%d \n", b.Length());
//
//
//    @try {
//        b.Insert(3,8);
//    } @catch (NSException *exception) {
//        printf("exception"); //如失败提示失败信息
//    } @finally {
//        printf("finally");
//    }
//
//    printf("执行插入操作后单链表b为:");
//    b.PrintList();            //输出单链表b所有元素
//    printf("插入后单链表b的长度为:%d \n", b.Length());
//
//
//    @try {
//        if(a.Length()){
//            printf("执行删除第一个元素操作:");
//            b.Delete(1);                //删除b中第一个元素
//            printf("已删除成功，单链表b的长度为:%d", b.Length());
//        } else{
//            printf("顺序表b长度为0");
//        }
//    } @catch (NSException *exception) {
//        printf("exception"); //如失败提示失败信息
//    }
//
//    printf("执行插入操作后单链表b为:");
//    b.PrintList();            //输出单链表所有元素
}

@end
