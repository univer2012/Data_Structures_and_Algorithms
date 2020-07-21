//
//  LeetCode92.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/20.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef LeetCode92_hpp
#define LeetCode92_hpp

#include <stdio.h>
#import "ListNode.h"

class Solution92 {
public:
    //1 <= m <= n <= 链表长度
    //head：链表头指针
    //从m逆序至到n
    ListNode *reverseBetween(ListNode *head, int m,int n);
    
};

#endif /* LeetCode92_hpp */
