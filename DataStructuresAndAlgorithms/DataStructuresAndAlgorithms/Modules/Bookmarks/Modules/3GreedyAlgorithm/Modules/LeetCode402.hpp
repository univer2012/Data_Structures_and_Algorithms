//
//  LeetCode402.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/21.
//  Copyright © 2020 blue. All rights reserved.
//
/*
 例3：移除K个数字
 已知一个使用字符串表示的非负整数num，将num中的k个数字移除，求移除k个数字后，可以获得的最小的可能的新数字。（num不会以0开头，num长度小于10002）
 
 输入：num = "1432219" ，k = 3
 在去掉3个数字后得到的很多很多可能里，入1432、4322、2219、1219、1229...；去掉数字4、3、2、得到的1219最小！
 
 选自： LeetCode 402 Remove K Digits
 难度：Medium
 */
#ifndef LeetCode402_hpp
#define LeetCode402_hpp

#include <stdio.h>
#include <string>
/*
 例3：思考
 一个长度为n的数字，去掉k个数字可以有多少种可能？
 
 C(k,n) = n!/((n-m)! * m!) 种可能。
 
 n最大可达到10002，k <= n，
 故这个数字可能会非常大，天文数字！
 故枚举是不可能的。
 
 思考：
 假设数字1432219，k=1，我们只去掉一个个数字，应该去掉哪个呢？
 如果k > 1，我们应该按照什么顺序与策略进行删除数字，得到的结果最优？
 
 
 
 
 例3：贪心规律
 从高位向低位遍历，如果对应的数字大于下一位数字，则把该位数字去掉，得到的数字最小！
 
 最暴力的方法：
 去掉k个数字，即从最高位遍历k次。
 
 
 
 例3：算法思路
 使用栈存储最终结果或删除工作，从高位向低位遍历num，
 如果遍历的数字 大于 栈顶元素，则将该数字push入栈，
 如果小于栈顶元素，则进行pop弹栈，知道栈为空 或 不能再删除数字(k==0)或栈顶小于当前元素为止。
 
 
 
 例3：思考如下问题：
 1. 当所有数字都扫描完成后，k仍然 > 0，应该做怎样的处理？例如：num = 12345，k = 3时。
 
 2. 当数字中有0出现时，应该又怎样的特殊处理？例如:num = 100200， k = 1时。
 
 3. 如何将最后结果存储为字符串并返回？
 
 */

class Solution402 {
public:
    std::string removeKdigits(std::string num, int k);
};

#endif /* LeetCode402_hpp */
