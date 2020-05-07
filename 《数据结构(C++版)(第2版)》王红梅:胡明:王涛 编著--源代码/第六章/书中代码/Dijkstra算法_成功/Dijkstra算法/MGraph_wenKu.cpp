//
//  MGraph_wenKu.cpp
//  Dijkstra算法
//
//  Created by huangaengoln on 15/10/7.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include "MGraph_wenKu.h"

#if 1
MGraph::MGraph(string a[],int n,int e) {
    vertexNum=n;
    arcNum=e;
    int i,j,k,w;
    for (i=0; i<vertexNum; i++)
        for (j=0; j<vertexNum; j++)
            arc[i][j]=100000;
    for (i=0; j<vertexNum; j++)
        arc[i][i]=0;
    
}
#endif
#if 1
void MGraph::insertArc(int i, int j, int w) {
    if (i>MaxSize || j>MaxSize) throw "位置";
    arc[i][j]=w;
    cout<<"("<<vertex[i]<<", "<<vertex[j]<<"):"<<arc[i][j]<<endl;
}
#endif
#if 1
void Dijkstra(MGraph G,int v) {
    int dist[MaxSize];
    string path[MaxSize],s[MaxSize];
    int i,j,k,num,min;
    for (i=0; i<G.vertexNum; i++) {
        dist[i]=G.arc[v][i];
        if (dist[i] != 100000 && i != v) path[i]=G.vertex[v]+" "+G.vertex[i];
        else path[i]="";
    }
    cout<<endl;s[0]=G.vertex[v];
    dist[v]=0;num=1;
    while (num<G.vertexNum) {
        k=0;
        for (i=0; i<G.vertexNum; i++) {
            if (dist[i] != 0) {
                min=dist[i];k=i;break;
            }
        }
        for (i=0; i<G.vertexNum; i++) {
            if (dist[i] != 0 && dist[i]<min) k=i;
        }
        cout<<dist[k]<<"  "<<path[k]<<endl;
        s[num++]=G.vertex[k];
        for (i=0; i<G.vertexNum; i++) {
            if (dist[i]>dist[k]+G.arc[k][i]) {
                dist[i]=dist[k]+G.arc[k][i];
                path[i]=path[k]+" "+G.vertex[i];
            }
            dist[k]=0;
        }
    }
}
#endif








