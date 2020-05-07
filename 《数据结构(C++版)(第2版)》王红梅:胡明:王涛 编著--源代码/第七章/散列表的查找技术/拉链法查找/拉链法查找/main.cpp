//
//  main.cpp
//  拉链法查找
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//
#include"Chaining.cpp"    //引入成员函数文件
#include<iostream>        //引入输入输出流
using namespace std;



int main(int argc, const char * argv[]) {
    // insert code here...
    Node *h[11]={0,0,0,0,0,0,0,0,0,0,0};
    LinkList a;
    int b[]={11,22,3,47};
    for (int i=0;i<4;i++)
    {
        a.Build(h,b[i],11);
    }
    try
    {
        cout<<HashSearch2(h,11,3)<<endl;
    }
    catch(char* wrong)
    {
        cout << wrong;     //如失败提示失败信息
    }
    
    return 0;
}
