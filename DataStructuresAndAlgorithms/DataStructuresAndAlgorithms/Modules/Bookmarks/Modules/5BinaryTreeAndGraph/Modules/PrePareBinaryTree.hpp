//
//  PrePareBinaryTree.hpp
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/31.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef PrePareBinaryTree_hpp
#define PrePareBinaryTree_hpp

#include <stdio.h>
#include "TreeNode.h"
/*
预备知识：二叉树定义
树是n（n>=0）个节点的有限集，且这些节点满足如下关系：
（1）有且仅有一个节点没有父节点，该节点称为树的根。
（2）除根外，其余的每个节点都有且仅有一个父节点。
（3）树中的每一个节点都构成一个以它为根的树。

二叉树在满足树的条件时，满足如下条件：
每个节点最大有两个孩子（子树），这两个子树有左右之分，次序不可颠倒。
*/
class PrePareBinaryTree {
public:
    void sec1demo1();
private:
    void preorder_print(TreeNode *node, int layer);
};



/*
 预备知识：二叉树的深度遍历
 
 */
class PrePareBinaryTree2 {
    void traversal(TreeNode *node) {
        if (!node) {
            return;
        }
        //此时访问node称为前序遍历
        traversal(node->left);
        //此时访问node称为中序遍历
        //此时访问node称为后序遍历
    }
};


#endif /* PrePareBinaryTree_hpp */

