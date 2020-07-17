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
//class Solution {
//public:
//    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//        set<ListNode *> node_set;   //设置查找集合node_set
//        while (headA) {
//            node_set.insert(headA); //将链表A中的节点插入node_set
//            headA = headA->next;    //遍历链表A
//        }
//        while (headB) {
//            //当在headB中找到第一个出现在node_set中的节点时
//            if (node_set.find(headB) != node_set.end()) {
//                return headB;
//            }
//            headB = headB->next;    //遍历链表B
//        }
//        return NULL;
//    }
//};

//方法1实现
ListNode * Solution::getIntersectionNode(ListNode *headA, ListNode *headB) {
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




