//
//  MGraph.cpp
//  Dijkstra算法
//
//  Created by huangaengoln on 15/10/7.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include <iostream>
using namespace std;
#include "MGraph.h"

template<class DataType>
MGraph<DataType>::MGraph(DataType a[],int n,int e) {
    int i,j,k;
    vertexNum =n;arcNum=e;
    for (i=0; i<vertexNum; i++)
        vertex[i]=a[i];
    for (i=0; i<vertexNum; i++)
        for (j=0; j<vertexNum; j++) {
            if (i!=j) arc[i][j]=100000;
            else arc[i][j]=0;
        }
    for (k=0; k<arcNum; k++) {
        cout<<"请输入边的两个地点的序号以及两地点的距离:";
        cin>>i>>j;
        cin>>arc[i][j];
        arc[j][i]=arc[i][j];
    }
}
template<class DataType>
void MGraph<DataType>::InsertArc(int i, int j, int w) {
    if (i>MaxSize || j>MaxSize) throw "位置";
    arc[i][j]=w;
    cout<<"("<<vertex[i]<<", "<<vertex[j]<<"):"<<arc[i][j]<<endl;
}

template<class DataType>
void MGraph<DataType>::DFSTraverse(int v) {
    int visited[MaxSize];
    cout<<vertex[v];visited[v]=1;
    for (int j=0; j<vertexNum; j++)
        if (arc[v][j]!=100000 && arc[v][j]!=0 && visited[j]==0)
            DFSTraverse(j);
}




