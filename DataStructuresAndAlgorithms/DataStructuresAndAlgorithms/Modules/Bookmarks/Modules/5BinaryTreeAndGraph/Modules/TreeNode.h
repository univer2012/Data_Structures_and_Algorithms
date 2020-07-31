//
//  TreeNode.h
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/31.
//  Copyright © 2020 blue. All rights reserved.
//

#ifndef TreeNode_h
#define TreeNode_h

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

#endif /* TreeNode_h */
