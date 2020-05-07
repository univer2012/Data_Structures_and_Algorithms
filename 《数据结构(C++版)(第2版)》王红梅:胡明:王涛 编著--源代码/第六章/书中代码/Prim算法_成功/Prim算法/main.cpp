//
//  main.cpp
//  Prim算法
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

#define MAXV  100
#define INF 32767       /*INF表示∞*/
typedef int InfoType;

typedef struct
{   int no;                     /*顶点编号*/
    InfoType info;              /*顶点其他信息*/
} VertexType;                   /*顶点类型*/

typedef struct                  /*图的定义*/
{   int arc[MAXV][MAXV];      /*邻接矩阵*/
    int vertexNum,arcnum;          /*顶点数，弧数*/
    VertexType vexs[MAXV];      /*存放顶点信息*/
} MGraph;                       /*图的邻接矩阵类型*/

typedef struct {
    int adjvex;
    int lowcost;
} shortedge;

void DispMat(MGraph g) {  /*输出邻接矩阵g*/
    int i,j;
    for (i=0;i<g.vertexNum;i++)
    {
        for (j=0;j<g.vertexNum;j++)
            if (g.arc[i][j]==INF)
                printf("%3s" , "  ∞");
            else
                printf("%3d",g.arc[i][j]);
        printf("\n");
    }
}

//寻找最短边的邻接点k
int MinEdge(shortedge shortEdge[],int vertexNum) {  //,顶点数
    int k=0,min=INF;    //最短边
    for (int j=0; j<vertexNum; j++) {
        if (shortEdge[j].lowcost != 0 && shortEdge[j].lowcost<min) {
            min=shortEdge[j].lowcost;
            k=j;
        }
    }
    return k;
}

//从顶点V0出发，按普里姆算法构造联通网G的最小生成树
void Prim(MGraph G) {
    shortedge shortEdge[MAXV];
    int i, j, k;
    
    for(i=0;i<G.vertexNum;i++) {
        shortEdge[i].lowcost=G.arc[0][i];
        shortEdge[i].adjvex=0;
        
    }
    shortEdge[0].lowcost=0;
    
    for(i=1;i<G.vertexNum;i++) {
        k=MinEdge(shortEdge,G.vertexNum);   //寻找最短边的邻接点k
//        cout<<"结点<"<<shortEdge[k].adjvex<<"~~~~~"<<k<<")  边的权值为:   "<<shortEdge[k].lowcost;
        printf("结点<%d~~~~~~~%d)    边的权值为:   %d\n",shortEdge[k].adjvex,k,shortEdge[k].lowcost);
        shortEdge[k].lowcost=0;
        for (j=1; j<G.vertexNum; j++)
            if (G.arc[k][j]<shortEdge[j].lowcost) {
                shortEdge[j].lowcost=G.arc[k][j];
                shortEdge[j].adjvex=k;
            }
    }
}



//从顶点V0出发，按普里姆算法构造联通网G的最小生成树
void prim(MGraph G,int v)   //用的时候，v被赋值为0
{
    //输出最小生成树的每条边

    int Vlength[MAXV];
    int cloest[MAXV];
    int min;
    int i, j, k;
    
    for(i=0;i<G.vertexNum;i++) {
        Vlength[i]=G.arc[v][i];
        cloest[i]=v;
    }
    
    for(i=1;i<G.vertexNum;i++) {
        min=INF;   //min为其中最大的一条边=MAXV
        for(j=0;j<G.vertexNum;j++) //找n-1条边
        {
            if(Vlength[j]!=0&&Vlength[j]<min)
            {
                min=Vlength[j];
                k=j;
            }
        }
        printf("结点<%d~~~~~~~%d)    边的权值为:   %d\n",cloest[k],k,min);
        Vlength[k]=0;
        Vlength[cloest[k]]=0;
        for(j=0;j<G.vertexNum;j++)  //选择当前代价最小的边
        {
            if(G.arc[k][j]!=0&&G.arc[k][j]<Vlength[j])
            {
                Vlength[j]=G.arc[k][j];
                cloest[j]=k;
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int i,j;
    MGraph g;
    int A[MAXV][11];
    g.vertexNum=6;//顶点数
    g.arcnum=10;  //弧数
    
    for (i=0;i<g.vertexNum;i++)
        for (j=0;j<g.vertexNum;j++)
            A[i][j]=INF;
    A[0][1]=5;A[0][2]=8;A[0][3]=7;A[0][5]=3;
    A[1][2]=4;
    A[2][3]=5;A[2][5]=9;
    A[3][4]=5;
    A[4][5]=1;
    
    for (i=0;i<g.vertexNum;i++)
        for (j=0;j<g.vertexNum;j++)
            A[j][i]=A[i][j];
    
    for (i=0;i<g.vertexNum;i++)     /*建立图9.1的邻接矩阵*/
        for (j=0;j<g.vertexNum;j++)
            g.arc[i][j]=A[i][j];
    
    printf("\n");
    printf("图G的邻接矩阵表示出来:\n");
    DispMat(g);
    printf("\n");
    printf("Prim算法求解结果:\n");
//    prim(g,0);
    Prim(g);
    printf("\n");
    
    return 0;
}
