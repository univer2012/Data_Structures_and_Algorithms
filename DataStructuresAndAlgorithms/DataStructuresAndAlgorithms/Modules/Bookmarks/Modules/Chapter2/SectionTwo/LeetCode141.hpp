//
//  LeetCode141.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/17.
//  Copyright © 2020 blue. All rights reserved.
//
/*
LeetCode 141 Linked List Cycle       142 Linked List Cycle II
 链表求环
 
 已知链表中可能存在环，若有环返回环起始节点，否则返回NULL。
 
 选自：LeetCode 141 Linked List Cycle       142 Linked List Cycle II
 
 难度：Medium
 */
#ifndef LeetCode141_hpp
#define LeetCode141_hpp

#include <stdio.h>
#import "ListNode.h"

/*思路1，使用set求环起始节点
 1. 遍历链表，将链表中节点对应的指针（地址），插入set
 2. 在遍历时插入节点前，需要在set中查找，第一个在set中发现的节点地址，即是链表环的起点。
 */
class Solution141_1 {
public:
    ListNode * detectCycle(ListNode *head);
};


//思路2，快慢指针赛跑
class Solution141_2 {
public:
    ListNode *detectCycle(ListNode *head);
};

#endif /* LeetCode141_hpp */
