//
//  main.cpp
//  tree
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

//有关树的实现的主函数，文件名为treemain.cpp
#include <iostream>
#include <string>
#include"tree.cpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    Tree<string> t; //创建一棵树
    TNode<string>* p = t.Getroot( );  //获取指向根结点的指针
    cout<<"------前序遍历------ "<<endl;
    t.PreOrder(p);
    cout<<endl;
    cout<<"------后序遍历------ "<<endl;
    t.PostOrder(p);
    cout<<endl;
    cout<<"------层序遍历------ "<<endl;
    t.LeverOrder(p);
    cout<<endl;
    
    return 0;
}
