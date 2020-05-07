//
//  main.cpp
//  InThrBiTree
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

//线索二叉树的主函数，文件名为inthrbitreemain.cpp
#include<iostream>
#include<string>
#include"inthrbitree.cpp"
//#include "inthrbitree_book.cpp"
using namespace std;
ThrNode<string>* pre;

int main(int argc, const char * argv[]) {
    // insert code here...
    InThrBiTree<string> inbt;//构造一棵线索二叉树
    ThrNode<string>* p = inbt.Getroot( );  //获取指向根结点的指针
    cout<<"----中序遍历线索二叉树------"<<endl;
    inbt.InOrder(p);
    
    return 0;
}
