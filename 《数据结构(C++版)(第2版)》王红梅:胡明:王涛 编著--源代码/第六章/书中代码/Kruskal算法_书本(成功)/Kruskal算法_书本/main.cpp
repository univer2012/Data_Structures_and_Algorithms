//
//  main.cpp
//  Kruskal算法_书本
//
//  Created by huangaengoln on 15/10/7.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include <iostream>
using namespace std;

const int MaxVertex=20; //图中最大顶点数
const int MaxEdge=100;  //图中最大边数

int FindRoot(int parent[],int v);

struct EdgeType {
    int from;   //边的起点
    int to;     //边的终点
    int weight; //权值
};

struct EdgeGraph {
    char vertex[MaxVertex]; //顶点表，     顶点的数据类型为  ‘char’
    EdgeType edge[MaxEdge]; //存放边的数组
    int vertexNum;          //图的顶点数
    int edgeNum;            //图的边数
    int parent[MaxVertex];
};

void Sort(EdgeType ed[], int E) {   //权值排序
    int i,j;
    EdgeType p;
    for (i=0; i<E; i++)         //趟次
        for (j=0; j<E-i-1; j++) //每趟比较次数
            if (ed[j].weight>=ed[j+1].weight) {
                p=ed[j+1];
                ed[j+1]=ed[j];
                ed[j]=p;
            }
}

//最小生成树代码实现主体部分
void Kruskal(EdgeGraph G) {
    int parent[MaxVertex];
    int i;
    int num;
    int vex1;
    int vex2;
    
    for (i=0; i<G.vertexNum; i++)
        parent[i]=-1;
    
    for (num=0,i=0; i<G.edgeNum; i++) {
        vex1=FindRoot(parent, G.edge[i].from);
        vex2=FindRoot(parent, G.edge[i].to);
        if (vex1 != vex2) {
            cout<<"("<<G.vertex[G.edge[i].from]<<" "<<G.vertex[G.edge[i].to]<<")"<<endl;        //输出生成的边
            parent[vex2]=vex1;
            num++;
            if (num==G.vertexNum-1) return;
        }
    }
}
//求顶点的双亲一直到根
int FindRoot(int parent[],int v) {
    while (parent[v] != -1) {
        if (parent[v]>-1) {
            v=parent[v];
        }
    }
    return v;
}

//主函数
int main(int argc, const char * argv[]) {
    // insert code here...
    
    EdgeGraph eg;
    char x,y;
    cout<<"-----------"<<endl;
    cout<<"* *请输入图的顶点树，和边数:   "<<endl;
    cout<<"--> ";
    cin>>eg.vertexNum>>eg.edgeNum;
    
    cout<<"请输入各顶点的值:  "<<endl;
    cout<<"--->";
    for (int j=0; j<eg.vertexNum; j++) {
        cin>>eg.vertex[j];
    }
    
    cout<<"请分别输入"<<eg.edgeNum<<"条边各边的起点，终点，及其权值：  "<<endl;
    for (int i=0; i<eg.edgeNum; i++) {
        cout<<"--> ";
        cin>>x>>y>>eg.edge[i].weight;
        for (int m=0; m<eg.vertexNum/*图的顶点数*/; m++) {
            if (eg.vertex[m]==x) {  // vertex :顶点表
                eg.edge[i].from=m;  //edge :存放边的数组
            }
            if (eg.vertex[m]==y) {
                eg.edge[i].to=m;
            }
        }
    }
    Sort(eg.edge, eg.edgeNum);
    cout<<"最小生成树为："<<endl;
    Kruskal(eg);
    
    return 0;
}
