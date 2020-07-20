//
//  LeetCode86.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/17.
//  Copyright © 2020 blue. All rights reserved.
//
/*
 LeetCode 86 Partition List
 链表划分
 
 已知链表头指针head与数值x，将所有小于x的节点放在大于或等于x的节点前，且保持这些节点的原来的相对位置。
 难度：Medium
 */
#ifndef LeetCode86_hpp
#define LeetCode86_hpp

#include <stdio.h>
#import "ListNode.h"

//思路，巧用临时头节点
class Solution86 {
public:
    ListNode *partition(ListNode *head, int x) {
        //设置两个临时的头节点
        ListNode less_head(0);
        ListNode more_head(0);
        //对应指针指向这两个头节点
        ListNode *lesss_ptr = &less_head;
        ListNode *more_ptr = &more_head;
        while (head) {
            if (head->val < x) {    //如果节点值小于x，则将该节点插入less_ptr后
                lesss_ptr->next = head;
                lesss_ptr = head;   //链接完成后，lesss_ptr向后移动，指向head
            } else {    //否则将该节点插入more_ptr后
                more_ptr->next = head;
                more_ptr = head;
            }
            head = head->next;      //遍历链接
        }
        lesss_ptr->next = more_head.next;   //将less链表尾，与more链表头相连
        more_ptr->next = NULL;      //将more_ptr即链表尾节点next置空
        return less_head.next;      //less_head的next节点即为新链表头节点，返回
    }
};

#endif /* LeetCode86_hpp */
