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

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
};


class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //求A、B两个链表长度
        int list_A_len = get_list_length(headA);
        int list_B_len = get_list_length(headB);
        if (list_A_len > list_B_len) {  //如果链表A长，移动headA到对应位置
            headA = forward_long_list(list_A_len, list_B_len, headA);
        } else {        //如果链表B长，移动headB到对应位置
            headB = forward_long_list(list_B_len, list_A_len, headB);
        }
        
        while (headA && headB) {
            if (headA == headB) {   //当两指针指向了同一个节点时，说明找到了！
                return headA;;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
    
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
