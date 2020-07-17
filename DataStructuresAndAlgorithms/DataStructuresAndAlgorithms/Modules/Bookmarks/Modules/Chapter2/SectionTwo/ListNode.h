//
//  ListNode.h
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/17.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef ListNode_h
#define ListNode_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(NULL) {}
};

#endif /* ListNode_h */
