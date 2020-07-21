//
//  LeetCode160_Intersection_of_Two_Linked_lists.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/17.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode160.hpp"



#include <stdio.h>
#include <iostream>
//#include <algorithm>
#include<set>

using namespace std;


//方法1实现
ListNode * Solution160_1::getIntersectionNode(ListNode *headA, ListNode *headB) {
    set<ListNode *> node_set;   //设置查找集合node_set
    while (headA) {
        node_set.insert(headA); //将链表A中的节点插入node_set
        headA = headA->next;    //遍历链表A
    }
    while (headB) {
        //当在headB中找到第一个出现在node_set中的节点时
        if (node_set.find(headB) != node_set.end()) {
            return headB;
        }
        headB = headB->next;    //遍历链表B
    }
    return NULL;
}

ListNode *Solution160_2::getIntersectionNode(ListNode *headA, ListNode *headB) {
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




