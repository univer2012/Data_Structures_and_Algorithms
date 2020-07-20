//
//  LeetCode160_Intersection_of_Two_Linked_lists.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/17.
//  Copyright © 2020 blue. All rights reserved.
//
/*
 LeetCode 160 Inersection of Two Linked Lists
 求两个链表的交点
 
 已知链表A的头节点指针headA，链表B的头节点指针headB，两个链表相交，求两链表对应的节点。
 难度：Easy
 */
#ifndef LeetCode160_hpp
#define LeetCode160_hpp

#include <stdio.h>

#import "ListNode.h"

class Solution160_1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
};


class Solution160_2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
    
private:
    int get_list_length(ListNode *head) {
        int len = 0;
        while (head) {  //遍历链表，计算链表
            len++;
            head = head->next;
        }
        return len;
    }
    
    ListNode *forward_long_list(int long_len, int short_len, ListNode *head) {
        int delta = long_len - short_len;
        while (head && delta) { //将指针向前移动至多出节点个数后面的位置
            head = head->next;
            delta--;
        }
        return head;
    }
};

#endif /* LeetCode160_hpp */
