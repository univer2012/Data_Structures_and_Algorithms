//
//  LeetCode21.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/20.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode21.hpp"

ListNode *Solution21::mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode temp_head(0);          //设置临时头节点temp_head
    ListNode *pre = &temp_head;     //使用pre指针指向temp_head
    while (l1 && l2) {              //l1与l2同时不空时，对他们进行比较
        if (l1->val < l2->val) {    //如果l1对应的节点 小于 l2对应的节点
            pre->next = l1;         //将pre与较小的节点进行连接
            l1 = l1->next;
        } else {
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;            //pre指向新连接的节点
    }
    
    if (l1) {               //如果l1有剩余
        pre->next = l1;     //将l1接到pre后
    }
    if (l2) {
        pre->next = l2;     //如果l2有剩余
    }
    return temp_head.next;  //将l2接到pre后
}
