//
//  LeetCode138.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/20.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode138.hpp"
#include <map>
#include <vector>
//`.`说的是对象，`*` 说的是指针。
RandomListNode *Solution138::copyRandomList(RandomListNode *head) {
    std::map<RandomListNode *, int> node_map;   //地址到节点位置的map
    std::vector<RandomListNode *> node_vec;     //使用vector根据存储节点位置访问地址
    RandomListNode *ptr = head;
    int i = 0;
    while (ptr) {
        //将新链表节点push入 node_vec ，生成了新链表节点位置到地址的map
        node_vec.push_back(new RandomListNode(ptr->label));
        node_map[ptr] = i;  //记录原始链表地址至节点位置的node_map
        ptr = ptr->next;    //遍历原始列表
        i++;                //i记录节点位置
    }
    node_vec.push_back(0);  //目的至为了下面的`node_vec[i]->next = node_vec[i+1];`操作时一致的
    ptr = head;
    i = 0;
    
    //再次遍历原始列表，连接新链表的next指针，random指针
    while (ptr) {
        node_vec[i]->next = node_vec[i+1];      //连接新链表next指针
        if (ptr->random) {                      //当random指针不空时
            int id = node_map[ptr->random];     //根据node_map确认原链表random指针指向的位置即id
            node_vec[i]->random = node_vec[id]; //连接新链表random指针
        }
        ptr = ptr->next;
        i++;
    }
    return node_vec[0];
}
