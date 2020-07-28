//
//  LeetCode51.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/27.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef LeetCode51_hpp
#define LeetCode51_hpp

#include <stdio.h>
#include <vector>

class Prepare51 {
public:
    void put_down_the_queen(int x, int y, std::vector<std::vector<int>> &mark);
};



class Solution51 {
public:
    std::vector<std::vector<std::string>> solveNQueue(int n);
    
private:
    void put_down_the_queen(int x, int y, std::vector<std::vector<int>> &mark);
    
    void generate(int x, int n,
                  std::vector<std::string> &location,
                  std::vector<std::vector<std::string>> &result,
                  std::vector<std::vector<int>> &mark);
};


#endif /* LeetCode51_hpp */
/*
 例3：N皇后
 
 N皇后问题是计算机科学中最为经典的问题之一，该问题可追溯到1848年，由国际西洋棋棋手马克斯·贝瑟尔于提出了8皇后问题。
 将N各个皇后摆放在N*N的棋盘中，互相不可攻击，有多少种摆放方式，每种摆放方式具体是怎样的？
 
 选自： LeetCode 51 N-Queens
 难度：Hard
 
 
 ========  ========  ========  ========  ========  ========  ========
 例3：皇后的攻击范围
 若再期盼上已放置一个皇后，它实际上占据了哪些位置？
 以这个皇后为中心，上、下、左、右、左上、左下、右上、右下，8个方向的位置全部被占据。
 
 思考：
 若在棋盘上放置一个皇后，如右图，标记为红色位置即不可再放其他皇后了，如何设计算法与数据存储，实现这一过程？
 
 
 ========  ========  ========  ========  ========  ========  ========
 例3：棋盘与皇后表示
 使用二维数组mark[][]表示一张空棋盘
 
 假设在(x,y)位置放置一个皇后，即数组的第x行，第y列放置皇后：如x = 4,y = 3；第4行，第3列
 
 设置方向数组：
 
 
 按照方向数组的8个方向分别延伸N个距离，只要不超过边界，mark[][] = 1
 
 */
