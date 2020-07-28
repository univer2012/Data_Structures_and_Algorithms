//
//  LeetCode22.cpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/27.
//  Copyright © 2020 blue. All rights reserved.
//

#include "LeetCode22.hpp"

void Prepare22::sec2demo6() {
    std::vector<std::string> result;
    generate("", 2, result);
    for (int i = 0; i < result.size(); i++) {
        printf("'%s'\n",result[i].c_str());
    }
}

//item为用来生成的括号字符串，n为组数，result为最终结果
void Prepare22::generate(std::string item, int n, std::vector<std::string> &result) {
    if (item.size() == 2 * n) {     //当字符串长度是括号组数2倍时，结束递归
        result.push_back(item);
        return;
    }
    
    generate(item + '(', n, result);//添加'('字符，继续递归
    generate(item + ')', n, result);//添加')'字符，继续递归
}


//========= ========
std::vector<std::string> Solution22::generateParenthesis(int n) {
    std::vector<std::string> result;
    generate("", n, n, result);
    return result;
}

//生成字符串item
//当前还可以放置左括号的数量left
//当前可以放置的右括号数量right
void Solution22::generate(std::string item, int left, int right, std::vector<std::string> &result) {
    if (left == 0 && right == 0) {
        result.push_back(item);
        return;
    }
    if (left > 0) {
        generate(item + '(', left - 1, right, result);
    }
    
    if (left < right) {
        generate(item + ')', left, right - 1, result);
    }
}
