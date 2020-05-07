//
//  MGraph.h
//  Dijkstra算法
//
//  Created by huangaengoln on 15/10/7.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef __Dijkstra____MGraph__
#define __Dijkstra____MGraph__

#include <stdio.h>
#include <iostream>
using namespace std;

const int MaxSize=10;
template<class DataType>
class MGraph {
public:
    MGraph(DataType a[],int n,int e);
    ~MGraph(){}
    void InsertArc(int i,int j,int w);
    void DFSTraverse(int v);
    template <class T>
    friend void dijkstra(MGraph G,int v) {
        int i,k;
        int s[MaxSize],dist[MaxSize];
        char path[MaxSize][MaxSize];
        for (i=0; i<G.vertexNum; i++) {
            dist[i]=G.arc[v][i];
            if (dist[i]<100000) {
                path[i][0]=G.vertex[v];
                path[i][1]=G.vertex[i];
                path[i][2]='\0';
            } else path[i][0]='\0';
        }
        s[0]=v;
        dist[v]=0;
        int num=1;
        while (num<G.vertexNum)
        {
            k=0;
            for (int j=0; (dist[j]==0 || dist[j]==100000) && j<G.vertexNum; j++)
                k++;
            for (i=0; i<G.vertexNum; i++)
                if ((dist[i]!=0) && (dist[i]<dist[k]))
                    k=i;
            cout<<G.vertex[v]<<"到"<<G.vertex[k]<<"最短路径是："<<path[k]<<"此时最短距离是："<<dist[k]<<endl;
            s[num++]=k;
            for (i=0; i<G.vertexNum; i++)
                if (dist[i]>dist[k]+G.arc[k][i]) {
                    dist[i]=dist[k]+G.arc[k][i];
                    strcpy(path[i],path[k ]);
                    int temp=strlen(path[i]);
                    path[i][temp++]=G.vertex[i];
                    path[i][temp]='\0';
                }
            dist[k]=0;
        }
    }
private:
    DataType vertex[MaxSize];
    int arc[MaxSize][MaxSize];
    int vertexNum,arcNum;
};

#endif /* defined(__Dijkstra____MGraph__) */
