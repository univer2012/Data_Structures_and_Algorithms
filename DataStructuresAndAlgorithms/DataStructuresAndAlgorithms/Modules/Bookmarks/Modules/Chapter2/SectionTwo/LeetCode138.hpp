//
//  LeetCode138.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/20.
//  Copyright © 2020 blue. All rights reserved.
//
/*
 LeetCode138 Copy List with Random Pointer
 
 已知一个复杂的链表，节点中有一个指向本链表任意某个节点的随机指针（也可以为空），求这个链表的深度拷贝。
 
 难度：Hard
 */
#ifndef LeetCode138_hpp
#define LeetCode138_hpp

#include <stdio.h>
#import "ListNode.h"

class Solution138 {
public:
    RandomListNode *copyRandomList(RandomListNode *head);
};

#endif /* LeetCode138_hpp */
