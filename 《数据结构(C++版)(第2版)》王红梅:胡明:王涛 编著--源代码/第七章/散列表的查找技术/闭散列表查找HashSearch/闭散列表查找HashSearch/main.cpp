//
//  main.cpp
//  闭散列表查找HashSearch
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include<iostream>         //引入输入输出流
using namespace std;

int  HashSearch1(int ht[ ], int m, int k)
{
    int j=k%m;
    if (ht[j]==k)
        return j;     //没有发生冲突，比较一次查找成功
    int i=(j+1) % m;
    while (i!=j)
    {
        if (ht[i]==k)
            return i;  //发生冲突，比较若干次查找成功
        i=(i+1) % m;    //向后探测一个位置
    }
    if (i==j)
        throw "溢出";
    else 
        ht[i]=k;   //查找不成功时插入
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int s[11]={11,0,0,47,0,0,0,7,29,8,0};
    cout<<"散列表中的元素有:\n";
    for(int i=0;i<11;i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<"\n"<<"执行查找操作,结果为:\n";   //查找操作
    cout<<HashSearch1(s,11,8)<<endl;
    
    return 0;
}
