//
//  SGHBinaryTreeGraphViewController.m
//  DataStructuresAndAlgorithms
//
//  Created by blue on 2020/7/31.
//  Copyright © 2020 blue. All rights reserved.
//

#import "SGHBinaryTreeGraphViewController.h"

#include "PrePareBinaryTree.hpp"
#include "LeetCode113.hpp"
#include "LeetCode236.hpp"

@interface SGHBinaryTreeGraphViewController ()

@end

@implementation SGHBinaryTreeGraphViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.type = SHBaseTableTypeMethod;
    
    //MARK: section 1
    NSArray *tempTitleArray = @[
        @"1.预备知识：二叉树 前序遍历二叉树",
        @"例1：路径之和2",
        @"例2：最近的公共祖先",
    ];
    NSArray *tempClassNameArray = @[
        @"sec1demo1",
        @"sec1demo2",
        @"sec1demo3",
    ];
    [self addSectionDataWithClassNameArray:tempClassNameArray titleArray:tempTitleArray title:@"二叉树与图"];
}

//MARK: 例2：最近的公共祖先
- (void)sec1demo3 {
    //构造样例中的树
    TreeNode a(3);
    TreeNode b(5);
    TreeNode c(1);
    TreeNode d(6);
    TreeNode e(2);
    TreeNode f(0);
    TreeNode x(8);
    TreeNode y(7);
    TreeNode z(4);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &x;
    e.left = &y;
    e.right = &z;
    
    Solution236 solve;
    TreeNode *result = solve.lowestCommonAncestor(&a, &b, &f);
    printf("lowestCommonAncestor = %d\n",result->val);
    
    result = solve.lowestCommonAncestor(&a, &d, &z);
    printf("lowestCommonAncestor = %d\n",result->val);
    
    result = solve.lowestCommonAncestor(&a, &b, &y);
    printf("lowestCommonAncestor = %d\n",result->val);
}

//MARK: 例1：路径之和2
- (void)sec1demo2 {
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    TreeNode d(11);
    TreeNode e(13);
    TreeNode f(4);
    TreeNode g(7);
    TreeNode h(2);
    TreeNode x(5);
    TreeNode y(1);
    
    a.left = &b;
    a.right = &c;
    b.left = &d;
    c.left = &e;
    c.right = &f;
    d.left = &g;
    d.right = &h;
    f.left = &x;
    f.right = &y;
    
    Solution113 solve;
    std::vector<std::vector<int>> result = solve.pathSum(&a, 22);
    for (int i = 0; i < result.size(); i++) {
        for (int j  = 0; j < result[i].size(); j++) {
            printf("[%d]", result[i][j]);
        }
        printf("\n");
    }
}

//MARK: 1.预备知识：二叉树 前序遍历二叉树
- (void)sec1demo1 {
    PrePareBinaryTree solve;
    solve.sec1demo1();
}

@end
