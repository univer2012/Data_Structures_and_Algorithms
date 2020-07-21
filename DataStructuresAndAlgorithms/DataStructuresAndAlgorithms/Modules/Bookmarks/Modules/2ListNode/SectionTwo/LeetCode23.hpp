//
//  LeetCode23.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/20.
//  Copyright © 2020 blue. All rights reserved.
//
/*
 例6-b：排序链表的合并（多个）
 已知k个已排序链表头节点指针，将这k个链表合并，合并后仍为有序的，返回合并后的头节点。
 
 LeetCode 23 Merge k Sorted Lists
 难度：Hard
 */
#ifndef LeetCode23_hpp
#define LeetCode23_hpp

#include <stdio.h>
#import "ListNode.h"
#include <algorithm>

/*方法1思考，暴力合并
 方案1：最普通的方法，k个链表按顺序合并k-1 次。
 设有k个链表，平均每个链表有n个节点，时间复杂度：
 (n+n)+(2n+n)+...+((k-1)n+n) = (1+2+...+k-1)n+(k-1)n = (1+2+...+k)n - n = (k^2+k-1)/2 * n
 = O(k^2*n)
 
 
 
 例6-b:方法2思考，排序后相连
 方案2：将k*n个节点放到vector中，再将vector排序，再将节点顺序相连。
 设有k个链表，平均每个链表有n个节点，时间复杂度：
 kN*logkN + kN = O(kN*logkN)（比如k=100，n=10000） logkN = 20，k=100
 */

class Solution23_2 {
public:
    static void test1();
};



/*
 例6-b:方法3思考，分治后相连
 方案3：对k个链表进行分治，两两进行合并。
 设有k个链表，平均每个链表有n个节点，时间复杂度：
 第1轮，进行k/2次，每次处理2n个数字；第2轮，进行k/4次，每次处理4n个数字；...；
 最后一次，进行k/(2^logk)次，每次处理2^logk*N个值。
 2N * k/2 + 4N * k/4 + 8N * k/8 + ... + 2^logk*N * k/(2^logk)
 = Nk + Nk + ...+ Nk = O(kNlogk)
 
 是最优的算法。
 */
class Solution23_3 {
public:
    ListNode *mergeKLists(std::vector<ListNode *> & lists);
};


//例6-b:实现（分治）
//子链表二路归并排序
class Solution23_4 {
public:
    ListNode *mergeKLists(std::vector<ListNode *> & lists);
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);
};


#endif /* LeetCode23_hpp */
