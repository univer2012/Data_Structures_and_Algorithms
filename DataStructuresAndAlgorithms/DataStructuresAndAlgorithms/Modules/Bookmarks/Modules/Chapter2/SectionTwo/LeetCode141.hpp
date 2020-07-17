//
//  LeetCode141.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/17.
//  Copyright © 2020 blue. All rights reserved.
//
/*
 LeetCode 141 Linked List Cycle
 142 Linked List Cycle II
 链表求环
 
 已知链表中可能存在环，若有环返回环起始节点，否则返回NULL。
 */
#ifndef LeetCode141_hpp
#define LeetCode141_hpp

#include <stdio.h>
#import "ListNode.h"


//思路2，快慢指针赛跑
class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;  //快指针
        ListNode *slow = head;  //慢指针
        ListNode *meet = head;  //相遇的节点
        while (fast) {
            slow = slow->next;  //slow与fast先各走一步
            fast = fast->next;
            if (!fast) {
                return NULL;    ///如果fast遇到链表尾，则返回NULL
            }
            fast = fast->next;  //fast再走1步
            if (fast == slow) {
                meet = fast;    //fast与slow相遇，记录相遇位置
                break;
            }
        }
        
        if (meet == NULL) {
            return NULL;        //如果没有相遇，则证明无环
        }
        while (head && meet) {
            if (head == meet) { //当head与meet相遇，说明遇到环的起始位置
                return head;
            }
            //head与meet每次走1次
            head = head->next;
            meet = meet->next;
        }
        return NULL;
    }
};

#endif /* LeetCode141_hpp */
