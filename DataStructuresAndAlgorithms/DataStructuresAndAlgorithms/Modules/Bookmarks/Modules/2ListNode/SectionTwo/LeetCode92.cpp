//
//  LeetCode92.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/20.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode92.hpp"


ListNode *Solution92::reverseBetween(ListNode *head, int m,int n) {
    int change_len = n - m + 1;     //计算需要逆置的节点个数
    ListNode *pre_head = NULL;      //初始化开始逆置的节点的前驱
    ListNode *result = head;        //最终转换后的链表头节点，非特殊情况即为head
    while (head && --m) {           //将head向前移动 m-1 个位置
        pre_head = head;            //记录head的前驱
        head = head->next;
    }
    ListNode * modify_list_tail = head; //将 modify_list_tail 指向当前的head，即逆置后的链表尾
    ListNode *new_head = NULL;
    while (head && change_len) {    //逆置 change_len 个节点
        ListNode *next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
        change_len --;              //每完成一个节点逆置，change_len-- ；
    }
    
    modify_list_tail->next = head;  //连接逆置后的链表尾与逆置段的后一个节点
    if (pre_head) {                 //如果 pre_head 不空，说明不是从第一个节点开始逆置的，m>1
        pre_head->next = new_head;  //将逆置链表开始的节点前驱与逆置后的头节点连接
    } else {
        result = new_head;          //如果pre_head为空，说明 m==1，从第一个节点开始逆置，结果即为逆置后的头节点
    }
    
    return result;
}
