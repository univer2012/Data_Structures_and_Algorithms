//
//  graph.h
//  十字链表
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef ________graph__
#define ________graph__

#include <stdio.h>

#include <vector>
#include <iomanip>
#define  IN
#define OUT
#define INOUT
using namespace std;
namespace graphspace
{
    template <typename weight>
    struct Edge                      //弧
    {
        int tailvex;                 //弧尾顶点位置
        int headvex;                 //弧头顶点位置
        Edge<weight> *hlink;         //弧头相同的弧链表
        Edge<weight> *tlink;         //弧尾相同的弧链表
        weight edgeWeight;           //弧权重
        Edge(int a, int b, weight c, Edge<weight> *p = NULL, Edge<weight> *q = NULL)
        :tailvex(a), headvex(b), edgeWeight(c), hlink(p), tlink(q)
        {}
    };
    
    template <typename vertexNameType, typename weight>
    struct Vertex                    //顶点
    {
        vertexNameType vertexName;   //顶点名
        Edge<weight> *firstin;       //指向第一条入弧（即指向逆邻接表）
        Edge<weight> *firstout;      //指向第一条出弧（即指向邻接表）
        Vertex(vertexNameType x, Edge<weight> *p = NULL, Edge<weight> *q = NULL)
        :vertexName(x), firstin(p), firstout(q)
        {}
    };
    
    template <typename vertexNameType, typename weight>
    class OLGraph
    {
    public:
        explicit OLGraph();
        ~OLGraph();
    public:
        //插入结点
        bool insertAVertex(IN const vertexNameType vertexName);
        //插入边
        bool insertAEdge(IN const vertexNameType vertexName1, IN const vertexNameType vertexName2, IN const weight edgeWeight);
        //边是否存在
        bool edgeExist(IN const vertexNameType vertexName1, IN const vertexNameType vertexName2);
        //输出顶点的邻接表,即弧尾相同的链表
        void vertexAdjEdges(IN const vertexNameType vertexName);
        //输出单个节点入度信息,弧头相同的链表（逆邻接表）
        void vertexRAdjEdges(IN const vertexNameType vertexName);
        //删除边
        bool removeAEdge(IN const vertexNameType vertexName1, IN const vertexNameType vertexName2, IN const weight edgeWeight);
        //获取边权
        weight getEdgeWeight(IN const Edge<weight> *pEdge);
        //将顶点的所有邻接边的权值放入数组或者vector中
        void getVertexEdgeWeight(IN const int v1, OUT vector<weight> &DistanceArray);
        
        //获取最小权
        weight getMinWeight(IN const vertexNameType vertexName1, IN const vertexNameType vertexName2);
        //获取顶点索引
        int getVertexIndex(IN const vertexNameType vertexName);
        //获取顶点索引(2分搜索）
        int binarySearchIndex(IN const vertexNameType vertexName, int beginPosition, int size);
        //获取顶点名
        vertexNameType getData(IN int index);
        //获取顶点数
        int getVertexNumber();
        //迪科斯彻算法，最短路径
        int Dijkstra(IN const vertexNameType vertexName1);
        //输出迪科斯彻
        void DijkstraPrint(IN int index, IN int sourceIndex, IN vector<int> vecPreVertex);
        //结点合并拆分如何处理？
        friend ostream& operator<<(OUT ostream &out, IN const OLGraph<vertexNameType,weight> &graphInstance);
    public:
        vector< Vertex<vertexNameType, weight> > m_vertexArray;
        
    };
//#include "OLGraph_realize.h"
}

#endif /* defined(________graph__) */
