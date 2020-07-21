//
//  SGHPrepareGreedy.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/21.
//  Copyright © 2020 blue. All rights reserved.
//
/*
 有1元、5元、10元、20元、100元、200元的钞票无穷多张。现使用这些钞票支付X元，最少需要多少张？
 
 例如，X = 628
 最佳支付方法：
 3张200元的，1张20元的，1张5元的，3张1元的；
 共需要3+1+1+3=8张。
 
 直觉告诉我们：尽可能多的使用面值较大的钞票！
 贪心法：遵循某种规律，不断贪心的选取当前最优策略的算法设计方法。
 
 
 
 为何这么做一定是对的？
 面额为1元、5元、10元、20元、100元、200元，任意面额是比自己小的面额的倍数关系。
 所以当使用一张较大面额钞票时，若用较小面额钞票替换，一定需要更多的其他面额的钞票！
 
 例如：
 5 = 1 + 1 + 1 + 1 + 1
 10 = 5 + 5
 20 + 10 + 10
 100 = 20 + 20 + 20 + 20 + 20
 200 = 100 + 100
 故，当前最优解即为全局最优解，贪心成立！

 思考：如果增加7元面额，贪心还成立吗？   答：不成立。
 */

//
#ifndef SGHPrepareGreedy_hpp
#define SGHPrepareGreedy_hpp

#include <stdio.h>

class PrepareGreedyDemo {
public:
    static void sec1demo1();
};

#endif /* SGHPrepareGreedy_hpp */
