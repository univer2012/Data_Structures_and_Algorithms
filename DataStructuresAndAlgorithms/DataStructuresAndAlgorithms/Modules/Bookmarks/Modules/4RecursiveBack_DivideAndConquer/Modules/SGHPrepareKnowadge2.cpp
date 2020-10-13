//
//  SGHPrepareKnowadge2.cpp
//  DataStructuresAndAlgorithms
//
//  Created by 远平 on 2020/7/26.
//  Copyright © 2020 blue. All rights reserved.
//

#include "SGHPrepareKnowadge2.hpp"

void add_to_vector(ListNode *head, std::vector<int> &vec) {
    if (!head) {
        return;
    }
    vec.push_back(head->val);
    add_to_vector(head->next, vec);
    
}


void PrepareKnowadge2::prepareKnowadge2() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    
    std::vector<int> vec;
    add_to_vector(&a, vec);
    for (int i = 0; i < vec.size(); i++) {
        printf("[%d]", vec[i]);
    }
    printf("\n");
}
