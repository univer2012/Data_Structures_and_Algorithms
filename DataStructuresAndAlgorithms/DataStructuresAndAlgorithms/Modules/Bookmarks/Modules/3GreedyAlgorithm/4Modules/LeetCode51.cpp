//
//  LeetCode51.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/27.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode51.hpp"
#include <string>

//第x行，y列放置皇后，mark[行][列]表示一张棋盘
void Prepare51::put_down_the_queen(int x, int y, std::vector<std::vector<int>> &mark) {
    //方向数组
    static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
    
    mark[x][y] = 1; //(x, y)放置皇后，进行标记
    
    for (int i = 1; i < mark.size(); i++) {
        for (int j = 0; j < 8; j++) {       //8个方向，每个方向向外延伸1至N-1
            int new_x = x + i * dx[j];      //新的位置向8个方向延伸，每个方向最多延伸N-1
            int new_y = y + i * dy[j];
            
            //检查新位置是否还在棋盘内
            if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size()) {
                mark[new_x][new_y] = 1;
            }
        }
    }
}


// ============== =================== ================== =================


std::vector<std::vector<std::string>> Solution51::solveNQueue(int n) {
    
    std::vector<std::vector<std::string>> result;   //存储最终结果的数组
    std::vector<std::vector<int>> mark;             //标记棋盘是否可以放置皇后的二维数组
    std::vector<std::string> location;              //存储某个摆放结果，当完成一次递归找到结果后，将location push进入result
    
    /*
     如 n = 4,                                       某4皇后中间结果：
     location 初始化：      mark初始化：               location：       mark：
     . . . .                0 0 0 0                 . Q . .         1 1 1 1
     . . . .                0 0 0 0         ===>    . . . Q         1 1 1 1
     . . . .                0 0 0 0                 . . . .         0 1 1 1
     . . . .                0 0 0 0                 . . . .         0 1 0 1
     */
    //初始化mark 和 location
    for (int i = 0; i < n; i++) {
        mark.push_back(std::vector<int>());
        for (int j = 0; j < n; j++) {
            mark[i].push_back(0);
        }
        location.push_back("");
        location[i].append(n, '.');
    }
    
    generate(0, n, location, result, mark);
    return result;
}

//第x行，y列放置皇后，mark[行][列]表示一张棋盘
void Solution51::put_down_the_queen(int x, int y, std::vector<std::vector<int>> &mark) {
    //方向数组
    static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
    
    mark[x][y] = 1; //(x, y)放置皇后，进行标记
    
    for (int i = 1; i < mark.size(); i++) {
        for (int j = 0; j < 8; j++) {       //8个方向，每个方向向外延伸1至N-1
            int new_x = x + i * dx[j];      //新的位置向8个方向延伸，每个方向最多延伸N-1
            int new_y = y + i * dy[j];
            
            //检查新位置是否还在棋盘内
            if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size()) {
                mark[new_x][new_y] = 1;
            }
        }
    }
}

//k代表完成了几个皇后的放置（正在放置第k行皇后）
//location: 某次结果存储在location中
//result:   最终结果存储在result
//mark:     表示棋盘的标记数组
void Solution51::generate(int x, int n,
              std::vector<std::string> &location,
              std::vector<std::vector<std::string>> &result,
              std::vector<std::vector<int>> &mark) {
    
    //当 x == n时，代表完成了第0至n-1行 皇后的放置，所有皇后完成放置后，
    //将记录皇后位置的location数组push进入result
    if (x == n) {
        result.push_back(location);
        return;
    }
    
    //按顺序尝试第0至第n-1列
    for (int y = 0; y < n; y++) {
        if (mark[x][y] == 0) {              //如果mark[x][y] == 0，即可以放置皇后
            
            std::vector<std::vector<int>> tmp_mark = mark;  //记录回溯前的mark镜像
            
            location[x][y] = 'Q';           //记录当前皇后的位置
            
            //第x行，y列放置皇后，mark[行][列]表示一张棋盘
            put_down_the_queen(x, y, mark); //放置皇后
            
            generate(x + 1, n, location, result, mark);     //递归下一行皇后放置
            
            mark = tmp_mark;                //将mark重新赋值为回溯前状态
            
            location[x][y] = '.';           //将当前尝试的皇后位置重新置`.`
        }
    }
}
