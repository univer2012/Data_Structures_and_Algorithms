//
//  main.cpp
//  Dijkstra算法
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include <iostream>
//#include "MGraph.cpp"
//#include "MGraph_wenKu.cpp"


using namespace std;

typedef string VertexType;
typedef int EdgeType;
#define MAXVEX 100             //最大定点数
#define INF 32767       /*INF表示∞*/

struct MGraph {
    VertexType vertex[MAXVEX];//顶点表
    EdgeType arc[MAXVEX][MAXVEX];//有向邻接矩阵  NXN
    int vertexNum;//图中当前的顶点数
    int numEdges;//图中当前的边数
};

int dist[MAXVEX];
string path[MAXVEX];

void dijkstra(MGraph G,int v/*每行*/) { //不可以写Dijstra,不然会报错.可能跟系统有冲突

    int i;
    int s[MAXVEX];

    for (i=0; i<G.vertexNum/*5*/; i++) {  //初始化数组 dist[]、path[]
        dist[i]=G.arc[v][i];
        string str;
        if (dist[i] != INF) {
            path[i]=G.vertex[v]+G.vertex[i];   //vertex : 顶点表
        }
        else
            path[i]=*(char *)"-"; //无穷大时 显示  "-"
    }

    s[0]=v;     //初始化集合 S
//    dist[v]=0;  //标记顶点 v 为源点
    int num=1;
    while (num<G.vertexNum/*顶点数*/) {//当顶点数 num 小于图的顶点数
        int k;
        for (k=0,i=0; i<G.vertexNum; i++)
            if ((dist[i]!=0) && (dist[i]<dist[k])) k=i;
        cout<<dist[k]<<"  "<<path[k]<<endl;
        s[num++]=k;     //将新生成的终点加入集合 S
        for (i=0; i<G.vertexNum; i++)
            if (dist[i]>dist[k]+G.arc[k][i]) {  //修改数组 dist 和 path
                dist[i]=dist[k]+G.arc[k][i];
                path[i]=path[k]+G.vertex[i];
            }
        dist[k]=0;      //置顶点 k 为已生成终点标记
        
        cout<<"当num="<<num-1<<"时的dist为 :\n";
        for (int j=0; j<G.vertexNum; j++){
            if (dist[i] == INF) cout<<"∞  ";
            else cout<<dist[j]<<"  ";
        }
        cout<<endl;
        
        cout<<"当num="<<num-1<<"时的path为 :\n";
        for (int j=0; j<G.vertexNum; j++)
            cout<<path[j]<<"  ";
        cout<<"\n"<<endl;
        
    }
}

int main(int argc, const char * argv[]) {
    // insert code here..
    MGraph eg;
    cout<<"-----------"<<endl;
    cout<<"* *请输入图的顶点数，和边数:   "<<endl;
    cout<<"--> ";
    cin>>eg.vertexNum/*顶点数*/>>eg.numEdges/*边数*/;
    
    cout<<"请输入各顶点的值:  "<<endl;
    cout<<"--->";
    for (int j=0; j<eg.vertexNum/*顶点数*/; j++)
        cin>>eg.vertex[j];  //顶点表
    
    //初始化邻接矩阵的元素 为 INF
    for (int i=0; i<eg.vertexNum; i++) {
        for (int j=0; j<eg.vertexNum; j++) {
            eg.arc[i][j]=INF;
        }
    }
    
    string x,y;
    cout<<"请分别输入"<<eg.numEdges/*边数*/<<"条边各边的起点，终点，及其权值：  "<<endl;
    for (int i=0; i<eg.numEdges/*边数*/; i++) {
        int j=0,k=0,weight;
        cout<<"--> ";
        cin>>x>>y>>weight;
        for (int m=0; m<eg.vertexNum; m++) {
            if (eg.vertex[m]==x) j=m;   //from
            else if (eg.vertex[m]==y) k=m;  //to
        }
        eg.arc[j][k]=weight;
    }
#pragma mark - 这里填 哪个点为源点
    dijkstra(eg, 1);    //0 表示以下标为0的点  作为源点

    
    return 0;
}
