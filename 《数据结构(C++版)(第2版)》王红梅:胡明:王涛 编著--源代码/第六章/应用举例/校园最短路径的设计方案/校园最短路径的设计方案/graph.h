//
//  graph.h
//  校园最短路径的设计方案
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef _______________graph__
#define _______________graph__

#include <stdio.h>

#include<string>                                          //引入标准库中的头文件
using namespace std;

const int MaxSize=12;                                     //图中最多顶点个数
template <class T>
class Graph
{
public:
    Graph(int* a, T* v,int n );                            //构造函数，初始化具有n个顶点的图
    ~Graph( ) { }                                          //析构函数
    void Dijkstra( int v,int endv);                       //最小距离
    void PutOutVexInfo();                                 //取顶点信息
    void PutOutArcInfo();                                 //输出路径
    void SetArc(int v1,int v2,int arclength);             //修改路径
    void DeleteVex(int pos);                              //删除顶点pos的信息
    void InsertVex(int num,T name);                       //在num的位置上插入一顶点，值为name
    void DeleteArc(int i, int j);                         //在图中删除一条边，其依附的两个顶点的编号为i和j
    void InsertArc(int i, int j,int n);                   //在图中插入一条边，其依附的两个顶点的编号为i和j
private:
    T  vertex[MaxSize];                                   //存放图中顶点的数组
    int arc[MaxSize][MaxSize];                            //存放图中边的数组
    int vertexNum;                                        //图的顶点数和边数
};

#endif /* defined(_______________graph__) */
