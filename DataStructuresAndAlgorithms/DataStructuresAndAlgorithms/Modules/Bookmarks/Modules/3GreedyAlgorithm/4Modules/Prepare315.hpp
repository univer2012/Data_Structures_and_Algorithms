//
//  Prepare315.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/27.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef Prepare315_hpp
#define Prepare315_hpp

#include <stdio.h>
#include <vector>
/*
预备知识：归并两个已排序数组

已知两个已排序数组，将这两个数组合并为一个排序数组。

*/
class Prepare315 {
public:
    void sec2demo9();
    
private:
    void merge_sort_two_vec(std::vector<int> &sub_vec1, std::vector<int> &sub_vec2, std::vector<int> &vec);
};




/*
 预备知识：分治算法之归并排序
 分治算法：
 将一个规模为N的问题分解为K个规模较小的子问题，这些子问题相互独立且与原问题性质相同。求出子问题的解后进行合并，就可得到原问题的解。
 
 一般步骤：
 1.分解，将要解决的问题划分成若干规模较小的同类问题；
 2.求解，当子问题划分得足够小时，用较简单的方法解决；
 3.合并，按原问题的要求，将子问题的解逐层合并构成原问题的解。
 
 
 ========  ========  ========  ========  ========  ========  ========
 */

#endif /* Prepare315_hpp */

