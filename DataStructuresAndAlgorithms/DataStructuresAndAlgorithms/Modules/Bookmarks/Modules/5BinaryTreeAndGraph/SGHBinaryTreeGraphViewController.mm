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
#include "LeetCode114.hpp"
#include "LeetCode199.hpp"

#include "PrePareGraphNode.hpp"
#include "LeetCode204.hpp"

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
        @"例3：二叉树转链表",
        @"2.预备知识：二叉树层次遍历",
        @"例4：侧面观察二叉树",
        @"预备知识：图的构造与表示（邻接矩阵）",
        @"预备知识：图的构造与表示（邻接表）",
        @"预备知识：图的深度优先遍历",
        @"预备知识：图的宽度优先遍历",
        @"例5：课程安排-方法1：深度搜索",
        @"例5：课程安排-方法2：拓扑排序（宽度优先搜索）",
    ];
    NSArray *tempClassNameArray = @[
        @"sec1demo1",
        @"sec1demo2",
        @"sec1demo3",
        @"sec1demo4",
        @"sec1demo5",
        @"sec1demo6",
        @"sec1demo7",
        @"sec1demo8",
        @"sec1demo9",
        @"sec1demo10",
        @"sec1demo11",
        @"sec1demo12",
    ];
    [self addSectionDataWithClassNameArray:tempClassNameArray titleArray:tempTitleArray title:@"二叉树与图"];
}

//MARK: 例5：课程安排-方法2：拓扑排序（宽度优先搜索）
- (void)sec1demo12 {
    std::vector<std::pair<int, int> > prerequisites;
    prerequisites.push_back(std::make_pair(1, 0));
    prerequisites.push_back(std::make_pair(2, 0));
    prerequisites.push_back(std::make_pair(3, 1));
    prerequisites.push_back(std::make_pair(3, 2));
    Solution204_2 solve;
    printf("是否可以完成课程：%d\n", solve.canFinish(4, prerequisites));
    
}

//MARK: 例5：课程安排-方法1：深度搜索
- (void)sec1demo11 {
    const int MAX_N = 5;        //5个顶点
    std::vector<std::pair<int, int>> prerequisites;
    prerequisites.push_back(std::make_pair(4, 0));
    prerequisites.push_back(std::make_pair(3, 4));
    prerequisites.push_back(std::make_pair(3, 2));
    prerequisites.push_back(std::make_pair(2, 0));
    prerequisites.push_back(std::make_pair(2, 1));
    prerequisites.push_back(std::make_pair(0, 1));
    
    Solution204 solve;
    printf("是否可以完成课程：%d\n", solve.canFinish(MAX_N, prerequisites));

}

//MARK: 预备知识：图的宽度优先遍历
- (void)sec1demo10 {
    PrePareGraphNode_BFS solve;
    solve.test();
}

//MARK: 预备知识：图的深度优先遍历
- (void)sec1demo9 {
    PrePareGraphNode_DFS solve;
    solve.test();
}

//MARK: 预备知识：图的构造与表示（邻接表）
- (void)sec1demo8 {
    const int MAX_N = 5;        //5个顶点
    GraphNode * Graph[MAX_N];
    
    for (int i = 0; i < MAX_N; i++) {
        Graph[i] = new GraphNode(i);
    }
    //添加边 --- 有向图
    Graph[0]->neighbors.push_back(Graph[2]);
    Graph[0]->neighbors.push_back(Graph[4]);
    Graph[1]->neighbors.push_back(Graph[0]);
    Graph[1]->neighbors.push_back(Graph[2]);
    Graph[2]->neighbors.push_back(Graph[3]);
    Graph[3]->neighbors.push_back(Graph[4]);
    Graph[4]->neighbors.push_back(Graph[3]);
    
    printf("Graph:\n");
    for (int i = 0; i < MAX_N; i++) {
        printf("Label(%d) : ", i);
        for (int j = 0; j < Graph[i]->neighbors.size(); j++) {
            printf("%d ", Graph[i]->neighbors[j]->label);
        }
        printf("\n");
    }
    
    for (int i = 0; i < MAX_N; i++) {
        delete Graph[i];
    }
}

//MARK: 预备知识：图的构造与表示（邻接矩阵）
- (void)sec1demo7 {
    const int MAX_N = 5;            //一共有5个顶点
    int Graph[MAX_N][MAX_N] = {0};  //使用邻接矩阵表示
    
    //将图连通，且不带权
    //一般用邻接矩阵表示稠密图
    Graph[0][2] = 1;
    Graph[0][4] = 1;
    Graph[1][0] = 1;
    Graph[1][2] = 1;
    Graph[2][3] = 1;
    Graph[3][4] = 1;
    Graph[4][3] = 1;
    printf("Graph: \n");
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            printf("%d ", Graph[i][j]);
        }
        printf("\n");
    }
}

//MARK: 例4：侧面观察二叉树
- (void)sec1demo6 {
    /*
       a1
       / \
     b2   c5
    /  \    \
  d3   e4   f6
     */
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    
    Solution199 solve;
    std::vector<int> result = solve.rightSideView(&a);
    for (int i = 0; i < result.size(); i++) {
        printf("[%d]\n", result[i]);
    }
}

//MARK: 2.预备知识：二叉树层次遍历
- (void)sec1demo5 {
    /*
       a1
       / \
     b2   c5
    /  \    \
  d3   e4   f6
     */
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    
    Solution_BFS_print solve;
    solve.BFS_print(&a);
}

//MARK: 例3：二叉树转链表
- (void)sec1demo4 {
    /*
       a1
       / \
     b2   c5
    /  \    \
  d3   e4   f6
     */
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    
    Solution114_2 solve;
    solve.flatten(&a);
    
    TreeNode *head = &a;
    while (head) {
        if (head->left) {
            printf("ERROR \n");
        }
        printf("[%d]", head->val);
        head = head->right;
    }
}

//MARK: 例2：最近的公共祖先
- (void)sec1demo3 {
    //构造样例中的树
    /*
         a3
        /  \
      b5     c1
     /  \  /  \
    d6   e2  f0   x8
       / \
      y7   z4
     */
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
