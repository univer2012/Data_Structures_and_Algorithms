//
//  main.cpp
//  BiTree
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

//二叉树的主函数，文件名为bitreemain.cpp
#include<iostream>
#include<string>
#include"bitree.cpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    BiTree<string> bt; //创建一棵树
    BiNode<string>* root = bt.Getroot( );  //获取指向根结点的指针
    
    cout<<"------前序遍历------ "<<endl;
    bt.PreOrder(root);
    cout<<endl;
    cout<<"------中序遍历------ "<<endl;
    bt.InOrder(root);
    cout<<endl;
    cout<<"------后序遍历------ "<<endl;
    bt.PostOrder(root);
    cout<<endl;
    cout<<"------层序遍历------ "<<endl;
    bt.LeverOrder(root);
    cout<<endl;
    
    return 0;
}
