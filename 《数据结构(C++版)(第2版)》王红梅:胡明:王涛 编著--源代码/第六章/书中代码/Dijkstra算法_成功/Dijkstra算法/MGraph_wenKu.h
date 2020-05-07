//
//  MGraph_wenKu.h
//  Dijkstra算法
//
//  Created by huangaengoln on 15/10/7.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef __Dijkstra____MGraph_wenKu__
#define __Dijkstra____MGraph_wenKu__

#include <stdio.h>
#include <iostream>
using namespace std;

const int MaxSize=12;

class MGraph {
public:
    MGraph(string a[],int n,int e);
    void insertArc(int i,int j,int w);
    friend void Dijkstra(MGraph G,int v);
private:
    string vertex[MaxSize];
    int arc[MaxSize][MaxSize];
    int vertexNum,arcNum;
};


#endif /* defined(__Dijkstra____MGraph_wenKu__) */
