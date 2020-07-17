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
class Solution {
public:
    ListNode * detectCycle(ListNode *head) {
        std::set<ListNode *> node_set;  //设置node_set
        while (head) {  //遍历链表
            if (node_set.find(head) != node_set.end()) {    //如果在node_set已经出现了
                return head;    //返回环的第一个节点
            }
            node_set.insert(head);  //将节点插入node_set
        }
        return NULL;    //么偶遇到环，则返回NULL
    }
};





