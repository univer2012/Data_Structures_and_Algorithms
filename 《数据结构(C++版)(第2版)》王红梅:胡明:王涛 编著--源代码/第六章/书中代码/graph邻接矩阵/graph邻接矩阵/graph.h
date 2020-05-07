//
//  graph.h
//  graph邻接矩阵
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef __graph______graph__
#define __graph______graph__

#include <stdio.h>

#include<string>                          //引入标准库中的头文件
using namespace std;

const int MaxSize=12;                     //图中最多顶点个数


template <class T>
class MGraph
{
public:
    MGraph(T a[],int n,int e);             //构造函数，初始化具有n个顶点的图
    void PutVex();                         //取顶点
    void GetVex(int i,T v[MaxSize] );      //取图中第i个顶点数据信息
    void DeleteVex(int i);                 //删除图中第i个顶点
    void InsertVex(int num,T value);       //在图中插入一个顶点，其编号为i，值为value
    void DeleteArc(int i, int j);          //在图中删除一条边，其依附的两个顶点的编号为i和j
    void InsertArc(int i, int j,int n);    //在图中插入一条边，其依附的两个顶点的编号为i和j
    void DFSTraverse(int v);               //深度优先遍历图
    void BFSTraverse(int v);               //广度优先遍历图
    
private:
    T  vertex[MaxSize];                    //存放图中顶点的数组
    int arc[MaxSize][MaxSize];             //存放图中边的数组
    int vertexNum,arcNum;                  //图的顶点数和边数
};

#endif /* defined(__graph______graph__) */
