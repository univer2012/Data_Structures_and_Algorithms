//
//  LeetCode23.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/20.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode23.hpp"
#include <vector>
#include <algorithm>    //STL 排序算法  std::sort

// 比较函数，对节点进行从小到大的排序
bool cmp(const ListNode *a, const ListNode *b) {
    return a->val < b->val;
}

void Solution23_2::test1() {
    ListNode a(3);
    ListNode b(2);
    ListNode c(5);
    ListNode d(0);
    std::vector<ListNode *> node_vec;
    node_vec.push_back(&a);
    node_vec.push_back(&b);
    node_vec.push_back(&c);
    node_vec.push_back(&d);
    
    //调用排序函数
    std::sort(node_vec.begin(), node_vec.end(), cmp);
    for (int i = 0; i < node_vec.size(); i++) {
        printf("%d\n", node_vec[i]->val);
    }
    
}


ListNode *Solution23_3::mergeKLists(std::vector<ListNode *> & lists) {
    std::vector<ListNode *> node_vec;
    for (int i = 0; i < lists.size(); i++) {
        ListNode *head = lists[i];
        while (head) {
            node_vec.push_back(head);   //遍历k个链表，将节点全部添加至node_vec
            head = head->next;
        }
    }
    
    if (node_vec.size() == 0) {
        return NULL;
    }
    
    //根据节点数值进行排序
    std::sort(node_vec.begin(), node_vec.end(), cmp);
    for (int i = 1; i < node_vec.size(); i++) {
        node_vec[i - 1]->next = node_vec[i];    //连接新的链表
    }
    node_vec[node_vec.size() - 1]->next = NULL;
    return node_vec[0];
}


ListNode *Solution23_4::mergeKLists(std::vector<ListNode *> & lists) {
    if (lists.size() == 0) {
        return NULL;            //如果lists为空，返回NULL
    }
    if (lists.size() == 1) {
        return lists[0];        //如果只有一个lists，直接返回头指针
    }
    if (lists.size() == 2) {
        //如果只有两个list，调用两个list merge函数
        return mergeTwoLists(lists[0], lists[1]);
    }
    
    unsigned long mid = lists.size() / 2;
    
    //拆分lists为两个子lists
    std::vector<ListNode *> sub1_lists;
    std::vector<ListNode *> sub2_lists;
    for (int i = 0; i < mid; i++) {
        sub1_lists.push_back(lists[i]);
    }
    for (unsigned long i = mid; i < lists.size(); i++) {
        sub2_lists.push_back(lists[i]);
    }
    
    ListNode *l1 = mergeKLists(sub1_lists);
    ListNode *l2 = mergeKLists(sub2_lists);
    
    return mergeTwoLists(l1, l2);   //分治处理
}

ListNode *Solution23_4::mergeTwoLists(ListNode *l1, ListNode *l2) {
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
