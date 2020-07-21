//
//  LeetCode206.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/20.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode206.hpp"


ListNode *Solution206::reverseList(ListNode *head) {
    ListNode * new_head = NULL;
    while (head) {
        ListNode *next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
    }
    return new_head;
}
