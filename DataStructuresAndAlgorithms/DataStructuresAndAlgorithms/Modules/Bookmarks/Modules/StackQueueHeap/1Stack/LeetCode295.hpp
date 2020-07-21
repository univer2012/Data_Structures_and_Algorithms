//
//  LeetCode295.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/21.
//  Copyright © 2020 blue. All rights reserved.
//
/*
 例7：寻找中位数
 设计一个数据结构，该数据结构动态维护一组数据，且支持如下操作：
 1. 添加元素：void addNum(int num)，将整型num添加至数据结构中。
 2. 返回数据的中位数：double findMedian()，返回其维护的数据的中位数。
 
 中位数定义：
 1. 若数据个数为奇数，中位数是该组数排序后中间的数。 [1,2,3]  --> 2
 2. 若数据个数为偶数，中位数是该组数排序后中间的两个数字的平均值。  [1,2,3,4] ---> 2.5
 
 选中： LeetCode 295 Find Median from Data Stream
 难度：Hard
 */
#ifndef LeetCode295_hpp
#define LeetCode295_hpp

#include <stdio.h>
#include <vector>
#include <queue>

/*例7：思考：如何获取中位数
 最直观的方法：
 存储结构使用数组，每次添加元素或查找中位数时对数组排序，再计算结果。
 
 时间复杂度：
 1. 若添加元素时排序，addNum复杂度O(n)，findMedian复杂度O(1)
 2. 若查询中位数时排序，addNum复杂度O(1)，findMedian复杂度O(nlogn)
 
 若添加元素或查询中位数是随机的操作，共n次操作，按上述思想，整体复杂度最佳为O(n^2)
 
 是否还有更好的方法？
 */


/*
 例7：思路：巧用堆的性质
 动态维护一个最大堆和一个最小堆，最大堆存储一半数据，最小堆存储另一半数据，维持最大堆的堆顶比最小堆的堆顶小。
 
 添加元素时堆调整1
 情况1：最大堆与最小堆元素个数相同时：
 
 添加元素时堆调整2
 情况2：最大堆比最小堆多一个元素：
 a. 如果新元素小于最大堆堆顶；
 b. 如果新元素大于最大堆堆顶；
 
 添加元素时堆调整3
 情况3：最大堆比最小堆少一个元素：
 a. 如果新元素小于最小堆堆顶；
 b. 如果新元素大于最小堆堆顶；
 
 获取中位数：
 a. 最大堆最小堆中的元素个数相同时：最大堆堆顶与最小堆堆顶的平均值：
 
 b. 最大堆比最小堆多一个元素：取最大堆堆顶
 
 c. 最大堆比最小堆少一个元素：取最小堆堆顶
 */

class MedianFinder295 {
public:
    MedianFinder295() {}
    void addNum(int num);   //向数据结构中添加一个整数
    double findMedian();    //返回该数据结构中维护的数据的中位数
    
private:
    std::priority_queue<int, std::vector<int>, std::less<int> > big_queue;      //最大堆
    std::priority_queue<int, std::vector<int>, std::greater<int> > small_queue; //最小堆
};

#endif /* LeetCode295_hpp */
