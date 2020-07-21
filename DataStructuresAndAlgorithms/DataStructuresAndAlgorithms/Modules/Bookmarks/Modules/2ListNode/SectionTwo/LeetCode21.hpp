//
//  LeetCode21.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/20.
//  Copyright © 2020 blue. All rights reserved.
//
/*
 
 例6-a：排序链表的合并（2个）
 一直两个已排序链表头节点贺子珍I1与I2，将这两个链表合并，合并后仍为有序的，返回合并后的头节点。
 
 LeetCode 21 Merge Two Sorted Lists
 难度：Easy
 */
#ifndef LeetCode21_hpp
#define LeetCode21_hpp

#include <stdio.h>
#import "ListNode.h"

/*例6-a:思路
 比较I1和I2指向的节点，将较小的节点插入到pre指针，并向前移动较小节点对应的指针。*/
class Solution21 {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);
};

#endif /* LeetCode21_hpp */
