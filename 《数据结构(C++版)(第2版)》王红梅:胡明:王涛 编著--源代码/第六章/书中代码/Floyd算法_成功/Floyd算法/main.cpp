//
//  main.cpp
//  Floyd算法
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>

typedef string VertexType;
typedef int EdgeType;
#define MAXVEX 100             //最大定点数
#define INF 32767       /*INF表示 ∞  */


struct MGraph {
    VertexType vertex[MAXVEX];//顶点表
    EdgeType arc[MAXVEX][MAXVEX];//有向邻接矩阵  NXN
    int vertexNum;//图中当前的顶点数
    int numEdges;//图中当前的边数
};

int dist[MAXVEX][MAXVEX];
string path[MAXVEX][MAXVEX];

//书本上的 代码
void floyd(MGraph G) {
    int i,j,k;
    
    for (i=0; i<G.vertexNum; i++)   //初始化矩阵 dist 和 path
        for (j=0; j<G.vertexNum; j++) {
            dist[i][j]=G.arc[i][j];
            if (dist[i][j] != INF) {
                path[i][j]=G.vertex[i]+G.vertex[j];
                if (dist[i][j]==0)
                    path[i][j]="--";//对角线元素 显示为这个
            } else
                path[i][j]=*(char *)"---";  //无穷大时 显示  "-"
        }
    
    for (k=0; k<G.vertexNum; k++) {   //进行 n 次迭代
        for (i=0; i<G.vertexNum; i++) {   //顶点 i 和 j 之间是否经过顶点 k
            for (j=0; j<G.vertexNum; j++)
                if (dist[i][k]+dist[k][j]<dist[i][j]) {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    string tempPrePath=path[i][k];
                    tempPrePath.resize(tempPrePath.length()-1);//把两字符串重复的字符  在合并前  去除一个
                    path[i][j]=tempPrePath+path[k][j];
//                    path[i][j]=path[i][k]+path[k][j];
                }
        }
#if 0   //打开后可以打印每一步的具体执行结果
        cout<<"k="<<k<<"时的dist :\n";
        for (int i=0; i<G.vertexNum; i++) {
            for (int j=0; j<G.vertexNum; j++){
                
                if (dist[i][j]==INF)
                    cout<<"∞  ";
                else
                    cout<<dist[i][j]<<"  ";
            }
            cout<<endl;
        }
        
        cout<<"k="<<k<<"时的path :\n";
        for (int i=0; i<G.vertexNum; i++) {
            for (int j=0; j<G.vertexNum; j++)
                cout<<path[i][j]<<"  ";
            cout<<endl;
        }
#endif
        
    }
    
}


void Floyd(int *edge,int *path,const int order,const int maxNum) {
    int length;
    if (path !=NULL)
        for (int i=0; i<order; i++)
            for (int j=0; j<order; j++) {
                if (i != j &&(*(edge +order*i+j)<maxNum))
                    *(path+order*i+j)=i;
                else
                    *(path+order*i+j)=0;
            }
                
    
    for (int k=0; k<order; k++)
        for (int i=0; i<order; i++)
            for (int j=0; j<order; j++) {
                length=(*(edge+i*order+k)+*(edge+k*order+j));
                if (length<*(edge+i*order+j)) {
                    *(edge+i*order+j)=length;
                    if (path !=NULL)
                        *(path+i*order+j)=*(path+k*order+j);
                }
            }
            
}

int main(int argc, const char * argv[]) {
    // insert code here...
#if 0
    const int MaxNum=INF;
    int a[4][4]={{0,1,MaxNum,4},
        {MaxNum,0,9,2},
        {3,5,0,8},
        {MaxNum,MaxNum,6,0}
    };

    int b[4][4];
    Floyd((int *)a, (int *)b, 4, MaxNum);
    cout<<"结果是：\n";
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cout<<b[i][j]<<" ";
        }
        cout<<"\n";
    }
#endif
    MGraph eg;
    cout<<"-----------"<<endl;
    cout<<"* *请输入图的顶点树，和边数:   "<<endl;
    cout<<"--> ";
    cin>>eg.vertexNum>>eg.numEdges;
    
    cout<<"请输入各顶点的值:  "<<endl;
    cout<<"--->";
    for (int j=0; j<eg.vertexNum; j++)
        cin>>eg.vertex[j];
    
    //初始化邻接矩阵的元素 为 INF
    for (int i=0; i<eg.vertexNum; i++) {
        for (int j=0; j<eg.vertexNum; j++) {
            if (i==j) eg.arc[i][j]=0;
            else      eg.arc[i][j]=INF;
        }
    }
    string x,y;
    cout<<"请分别输入"<<eg.numEdges<<"条边各边的起点，终点的下标，及其权值：  "<<endl;
    for (int i=0; i<eg.numEdges/*边数*/; i++) {
        int j=0,k=0,weight;
        cout<<"--> ";
        
        cin>>x>>y>>weight;
        
        //m是节点的下标
        for (int m=0; m<eg.vertexNum/*图的顶点数*/; m++) {
            if (eg.vertex[m]==x) j=m;    //from
            else if (eg.vertex[m]==y) k=m;    //to
        }
        eg.arc[j][k]=weight;
    }
    floyd(eg);
    cout<<"用Floyd算法得到的dist为 :\n";
    for (int i=0; i<eg.vertexNum; i++) {
        for (int j=0; j<eg.vertexNum; j++){
            if (dist[i][j]==INF)
                cout<<"∞  ";
            else
                cout<<dist[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    cout<<"用Floyd算法得到的path为 :\n";
    for (int i=0; i<eg.vertexNum; i++) {
        for (int j=0; j<eg.vertexNum; j++)
            cout<<path[i][j]<<"  ";
        cout<<endl;
    }
    
    return 0;
}
