//
//  LeetCode295.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/21.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode295.hpp"


void MedianFinder295::addNum(int num) {
    if (big_queue.empty()) {
        big_queue.push(num);
        return;
    }
    if (big_queue.size() == small_queue.size()) {
        if (num < big_queue.top()) {
            big_queue.push(num);
        } else {
            small_queue.push(num);
        }
    }
    else if (big_queue.size() > small_queue.size()) {
        if (num > big_queue.top()) {
            small_queue.push(num);
        } else {
            small_queue.push(big_queue.top());
            big_queue.pop();
            big_queue.push(num);
        }
    }
    else if (big_queue.size() < small_queue.size()) {
        if (num < small_queue.top()) {
            big_queue.push(num);
        } else {
            big_queue.push(small_queue.top());
            small_queue.pop();
            small_queue.push(num);
        }
    }
}

double MedianFinder295::findMedian() {
    if (big_queue.size() == small_queue.size()) {
        return (big_queue.top() + small_queue.top()) / 2.0;
    }
    else if (big_queue.size() > small_queue.size()) {
        return big_queue.top();
    }
    return small_queue.top();
}
