//
//  LeetCode206ReverseLinkedList.h
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/16.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef LeetCode206ReverseLinkedList_h
#define LeetCode206ReverseLinkedList_h

#include <stdio.h>
#import "ListNode.h"


class Solution {
public:
    ListNode* reverseList(ListNode *head) {
        ListNode * new_head = NULL;
        while (head) {
            ListNode *next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
        }
        return new_head;
    };
};

#endif /* LeetCode206ReverseLinkedList_h */
