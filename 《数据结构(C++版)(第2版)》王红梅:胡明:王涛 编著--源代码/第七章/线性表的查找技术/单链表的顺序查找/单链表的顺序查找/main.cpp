//
//  main.cpp
//  单链表的顺序查找
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

//LinkSearchMain.cpp
#include "LinkSearch.cpp"
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int r[9]={10,15,24,6,12,35,40,98,55};   //初始化数组
    LinkSearch b;
    b.LinkList(r,9);        //输出单链表中的元素
    b.PrintList();
    cout<<"\n"<<"查找40:"<<endl; //查找
    int location=b.SeqSearch2(b.GetFirst(),40);
    cout<<"所在位置为:"<<location<<endl;
    
    return 0;
}
