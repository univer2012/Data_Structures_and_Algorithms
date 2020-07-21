//
//  LeetCode141.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/17.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode141.hpp"
#include<set>


//思路1，使用set求环起始节点
ListNode *Solution141_1::detectCycle(ListNode *head) {
    std::set<ListNode *> node_set;  //设置node_set
    while (head) {                  //遍历链表
        if (node_set.find(head) != node_set.end()) {    //如果在node_set已经出现了
            return head;            //返回环的第一个节点
        }
        node_set.insert(head);      //将节点插入node_set
        head = head->next;
    }
    
    return NULL;                    //没有遇到环，则返回NULL
}


//思路2，快慢指针赛跑
ListNode *Solution141_2::detectCycle(ListNode *head) {
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




