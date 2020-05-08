//
//  main.cpp
//  BiTree
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#if 0
#include "node.h"
#include "tree.h"
using namespace std;

void visit(const Node *node)
{
    cout << node->nodeValue << " ";
}

void test01()
{
    map<int, int> tree;
    for(int i = 1; i < 10; ++i)
    {
        tree[i] = i * i;
    }
    
    /*
            1
           /  \
          4    9
         / \   /\
        16 25 36 49
        / \
       64 81
     */
    BinaryTree *binarytree = new BinaryTree(tree);
    cout << "the depth is " << binarytree->depth() << endl;
    cout << "the total number is " << binarytree->count() << endl;
    binarytree->preOrder(visit);
    binarytree->midOrder(visit);
    binarytree->postOrder(visit);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test01();
    return 0;
}
#endif
///=====================================================

#if 1
//二叉树的主函数，文件名为bitreemain.cpp
#include<iostream>
#include<string>
#include"BiTree.cpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    BiTree<string> bt; //创建一棵树
    BiNode<string>* root = bt.Getroot( );  //获取指向根结点的指针
    /*
     比如要输入如下二叉树：
        A
       /  \
       B   C
        \
         D
     则需要先写出这个二叉树的「扩展二叉树」：
            A
          /   \
          B    C
         / \  / \
        #   D #  #
           / \
           #  #
     所以要输入的字符串是： A B # D # # C # #
     
     再比如，要输入如下二叉树：
              A
             /  \
            B     C
           /     /  \
          D     E    F
           \
            G
     则需要先写出这个二叉树的「扩展二叉树」：
           A
          /  \
         B     C
        / \   /  \
       D   #  E    F
      / \    / \  / \
     #   G   #  # #  #
        / \
        #  #
     所以要输入的字符串是：A B D # G # # # C E # # F # #
     具体请看P119 的内容
     */
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
#endif
