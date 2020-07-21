//
//  SGH2ListNodeViewController.m
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/21.
//  Copyright © 2020 blue. All rights reserved.
//

#import "SGH2ListNodeViewController.h"

#import "ListNode.h"
#include "LeetCode206.hpp"
#include "LeetCode92.hpp"
#include "LeetCode160.hpp"
#include "LeetCode141.hpp"
#include "LeetCode86.hpp"
#include "LeetCode138.hpp"
#include "LeetCode21.hpp"
#include "LeetCode23.hpp"

#include <map>  //STL map头文件
#include <vector>
#include <iostream>
using namespace std;

@interface SGH2ListNodeViewController ()

@end

@implementation SGH2ListNodeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.type = SHBaseTableTypeMethod;
    
    NSArray *tempTitleArray2 = @[
        @"1.预备知识：链表基础",
        @"1-a:测试",
        @"1-b:测试",
        @"LeetCode160:求两个链表的交点",
        @"LeetCode141:链表求环",
        @"LeetCode86:链表划分",
        @"例5：必备知识（STL Map的使用）",
        @"LeetCode138:深拷贝random链表",
        @"LeetCode21:例6-a：排序链表的合并（2个）",
        @"LeetCode23:例6-b:方法2思考，排序后相连",
        @"LeetCode23:例6-b:实现（分治）",
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
        @"sec2demo9",
        @"sec2demo10",
        @"sec2demo11",
    ];
    [self addSectionDataWithClassNameArray:tempClassNameArray2 titleArray:tempTitleArray2 title:@"链表"];
}

- (void)sec2demo11 {
    ListNode a(1);
    ListNode b(4);
    ListNode c(6);
    ListNode d(0);
    ListNode e(5);
    ListNode f(7);
    ListNode g(2);
    ListNode h(3);
    a.next = &b;
    b.next = &c;
    
    d.next = &e;
    e.next = &f;
    
    g.next = &h;
    Solution23_4 solve;
    std::vector<ListNode *>lists;
    lists.push_back(&a);
    lists.push_back(&d);
    lists.push_back(&g);
    ListNode *head = solve.mergeKLists(lists);
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
}

//MARK:
- (void)sec2demo10 {
    Solution23_2::test1();
}

//MARK: LeetCode21
- (void)sec2demo9 {
    ListNode a(1);
    ListNode b(4);
    ListNode c(6);
    ListNode d(0);
    ListNode e(5);
    ListNode f(7);
    a.next = &b;
    b.next = &c;
    
    d.next = &e;
    e.next = &f;
    Solution21 solve;
    ListNode *head = solve.mergeTwoLists(&a, &d);
    while (head) {
        printf("%d\n",head->val);
        head = head->next;
    }
}

//MARK: LeetCode138
- (void)sec2demo8 {
    
    RandomListNode a(1);
    RandomListNode b(2);
    RandomListNode c(3);
    RandomListNode d(4);
    RandomListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    a.random = &c;
    b.random = &d;
    c.random = &c;
    e.random = &d;
    
    Solution138 solve;
    RandomListNode *head = solve.copyRandomList(&a);
    while (head) {
        printf("label = %d", head->label);
        if (head->random) {
            printf("rand = %d\n",head->random->label);
        } else {
            printf("rand = NULL\n");
        }
        head = head->next;
    }
}

- (void)sec2demo7 {
    //必备知识（STL Map的使用）
    
    std::map<RandomListNode*, int> node_map;    //设置一个节点map，key为节点地址，value为整型
    RandomListNode a(5);
    RandomListNode b(3);
    RandomListNode c(6);
    a.next = &b;
    b.next = &c;
    a.random = &c;
    b.random = &a;
    c.random = &c;
    node_map[&a] = 1;
    node_map[&b] = 2;
    node_map[&c] = 3;
    printf("a.random id = %d\n",node_map[a.random]);
    printf("b.random id = %d\n",node_map[b.random]);
    printf("c.random id = %d\n",node_map[c.random]);
}

//
- (void)sec2demo6 {
    
    ListNode a(1);
    ListNode b(4);
    ListNode c(3);
    ListNode d(2);
    ListNode e(5);
    ListNode f(2);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    Solution86 solve;
    ListNode *head = solve.partition(&a, 3);
    while (head) {
        printf("%d\n",head->val);
        head = head->next;
    }
}
//
- (void)sec2demo5 {
    
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    ListNode g(7);
    
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &c;
    
    /*
     1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
               |                   |
               -----<-------<-------
     */
    Solution141_1 solve1;
    ListNode *node1 = solve1.detectCycle(&a);
    if (node1) {
        printf("%d\n",node1->val);
    } else {
        printf("NULL\n");
    }
    
    Solution141_2 solve;
    ListNode *node = solve.detectCycle(&a);
    if (node) {
        printf("%d\n",node->val);
    } else {
        printf("NULL\n");
    }
}

//MARK: LeetCode160
- (void)sec2demo4 {
    ListNode a1(1);
    ListNode a2(2);
    
    ListNode b1(3);
    ListNode b2(4);
    ListNode b3(5);
    
    ListNode c1(6);
    ListNode c2(7);
    ListNode c3(8);
    
    a1.next = &a2;
    a2.next = &c1;
    c1.next = &c2;
    c2.next = &c3;
    
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;
    
    ListNode headA = a1;    // 1 <- 2 <- 6 <- 7 <- 8
    ListNode headB = b1;    // 3 <- 4 <- 5 <- 6
    
    Solution160_1 solve;
    ListNode *result = solve.getIntersectionNode(&headA, &headB);
    printf("%d\n",result->val);
    
    Solution160_2 solve2;
    ListNode *result2 = solve2.getIntersectionNode(&headA, &headB);
    printf("%d\n",result2->val);
}

//MARK: LeeCode92
- (void)sec2demo3 {
    
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    
    
    Solution92 solve;
    ListNode *head = solve.reverseBetween(&a, 2, 4);
    while (head) {
        printf("%d\n",head->val);
        head = head->next;
    }
    
}

//MARK: LeetCode206
- (void)sec2demo2 {
    
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    
    
    Solution206 solve;
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

@end
