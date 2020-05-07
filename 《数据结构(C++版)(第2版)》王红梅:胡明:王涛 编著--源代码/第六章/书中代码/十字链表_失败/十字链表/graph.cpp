//
//  graph.cpp
//  十字链表
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include "graph.h"
#include <iostream>
#include <ctime>
template<typename vertexNameType, typename weight>
graphspace::OLGraph<vertexNameType, weight>::OLGraph()
{
    if( !m_vertexArray.empty() )
        m_vertexArray.clear();
}

template<typename vertexNameType, typename weight>
graphspace::OLGraph<vertexNameType, weight>::~OLGraph()
{
//    vector< Vertex<vertexNameType, weight> > vertexArr;
//    vertexArr::iterator iter;
    vector<Vertex<vertexNameType, weight>> iter;//::iterator iter;
    for( iter = m_vertexArray.begin(); iter != m_vertexArray.end(); iter++ )
    {
        //Error：删除两次节点
        //邻接表跟逆邻接表指向的是同样节点，删除其中之一即可，但是另一个指针一定不要忘记置NULL
        Edge<weight> *p = iter->firstin;
        while( NULL != p )               //删除逆邻接表
        {
            iter->firstin = p->hlink;
            delete p;
            p = iter->firstin;
        }
        iter->firstout = NULL;
        
    }
    if( !m_vertexArray.empty())
        m_vertexArray.clear();
}

template<typename vertexNameType, typename weight>
bool graphspace::OLGraph<vertexNameType, weight>::insertAVertex(IN const vertexNameType vertexName)
{
    //任然不做节点重复处理，因为数据来自另一个系统，已经保证不重复
    Vertex<vertexNameType, weight> VertexInstance(vertexName, NULL);
    m_vertexArray.push_back(VertexInstance);
    return true;
}

template<typename vertexNameType, typename weight>
bool graphspace::OLGraph<vertexNameType, weight>::insertAEdge(IN const vertexNameType vertexName1,
                                                  IN const vertexNameType vertexName2, IN const weight edgeWeight)
{
    int v1 = -1;
    int v2 = -1;
    int size = m_vertexArray.size();
    //2分搜索定位V1，V2在容器中的位置
    v1 = binarySearchIndex(vertexName1, 0, size);
    v2 = binarySearchIndex(vertexName2, 0, size);
    
    if (-1 == v1)
    {
        cerr << "There is no vertex 1" << endl;
        return false;
    }
    if (-1 == v2)
    {
        cerr << "There is no vertex 2" << endl;
        return false;
    }
    Edge<weight> *p = m_vertexArray.at(v1).firstout;
    
    while( p != NULL && p->headvex != v2 )
    {
        p = p->tlink;
    }
    if( NULL == p )        //不存在边v1->v2，将新边插入到链表头
    {
        p = new Edge<weight>(v1, v2,  edgeWeight, m_vertexArray.at(v2).firstin, m_vertexArray.at(v1).firstout);
        m_vertexArray.at(v1).firstout = p;
        m_vertexArray.at(v2).firstin = p;
        return true;
    }
    if( v2 == p->headvex)   //已存在v1->v2的边
    {
        Edge<weight> *q = p;
        Edge<weight> *t = m_vertexArray.at(v2).firstin;
        while( t != NULL && t->tailvex != v1)   //找到边v1->v2在逆邻接表中的位置
        {
            t = t->hlink;
        }
        p = new Edge<weight>(v1, v2,  edgeWeight, t->hlink, q->tlink);   //将新边加在已存在的第一条v1->v2后面
        q->tlink = p;
        t->hlink = p;
        return true;
    }
    return false;
}
template<typename vertexNameType, typename weight>
int graphspace::OLGraph<vertexNameType, weight>::binarySearchIndex(IN const vertexNameType vertexName, int beginPosition, int size)
{
    
    int left = beginPosition;
    int right = size - 1;
    while(left <= right)
    {
        int middle = (left + right)/2;
        if (vertexName == m_vertexArray[middle].vertexName)
            return middle;
        if (vertexName > m_vertexArray[middle].vertexName)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}

template<typename vertexNameType, typename weight>
bool graphspace::OLGraph<vertexNameType, weight>::edgeExist(IN const vertexNameType vertexName1,
                                                IN const vertexNameType vertexName2)
{
    int v1 = getVertexIndex(vertexName1);
    if (-1 == v1)
    {
        cerr << "There is no vertex 1" << endl;
        return false;
    }
    int v2 = getVertexIndex(vertexName2);
    if (-1 == v2)
    {
        cerr << "There is no vertex 2" << endl;
        return false;
    }
    Edge<weight> *p = m_vertexArray.at(v1).firstout;
    while(p != NULL && p->headvex != v2)
    {
        p = p->tlink;
    }
    if(NULL == p)
    {
        cout<<"dont exist"<<endl;
        return false;
    }
    if(v2 == p->headvex)                 //存在，则输出所有的v1->v2边
    {
        cout<<"exist"<<endl;
        cout << vertexName1 << ":    ";
        while(p != NULL && p->headvex == v2)
        {
            cout << "(" << vertexName1 << "," << vertexName2 << "," << p->edgeWeight << ")  ";
            p = p->tlink;
        }
        cout << endl;
        return true;
    }
}

template<typename vertexNameType, typename weight>
void graphspace::OLGraph<vertexNameType, weight>::vertexAdjEdges(IN const vertexNameType vertexName)
{
    int v1 = getVertexIndex(vertexName);
    if( -1 == v1)
    {
        cerr<<"There is no vertex: "<<vertexName<<endl;
        return ;
    }
    Edge<weight> *p = m_vertexArray.at(v1).firstout;
    cout << vertexName << ":    ";
    while( p != NULL)            //顺着邻接表输出边信息
    {
        cout<<"(" << vertexName << "," << getData(p->headvex) <<"," << p->edgeWeight <<") ";
        p = p->tlink;
    }
    cout<<endl;
}
template<typename vertexNameType, typename weight>
void graphspace::OLGraph<vertexNameType, weight>::vertexRAdjEdges(IN const vertexNameType vertexName)
{
    int v1 = getVertexIndex(vertexName);
    if( -1 == v1)
    {
        cerr<<"There is no vertex: "<<vertexName<<endl;
        return ;
    }
    Edge<weight> *p = m_vertexArray.at(v1).firstin;
    cout << vertexName << ":    ";
    while( p != NULL)             //顺着逆邻接表输出信息
    {
        cout<<"(" << getData(p->tailvex) << "," << vertexName <<"," << p->edgeWeight <<") ";
        p = p->hlink;
    }
    cout<<endl;
}
template<typename vertexNameType, typename weight>
bool graphspace::OLGraph<vertexNameType, weight>::removeAEdge(IN const vertexNameType vertexName1,
                                                  IN const vertexNameType vertexName2, IN const weight edgeWeight)
{
    int v1 = getVertexIndex(vertexName1);
    if (-1 == v1)
    {
        cerr << "There is no vertex 1" << endl;
        return false;
    }
    int v2 = getVertexIndex(vertexName2);
    if (-1 == v2)
    {
        cerr << "There is no vertex 2" << endl;
        return false;
    }
    Edge<weight> *p = m_vertexArray.at(v1).firstout;
    Edge<weight> *q = NULL;
    while( p != NULL && p->headvex != v2 )
    {
        q = p;
        p = p->tlink;
    }
    if (NULL == p)
    {
        cerr << "Edge is not found" << endl;
        return false;
    }
    while( edgeWeight != p->edgeWeight && p->headvex == v2 )
    {
        q = p;
        p = p->tlink;
    }
    if (v2 != p->headvex)
    {
        cerr << "Edge is not found" << endl;
        return false;
    }
    
    Edge<weight> *t = m_vertexArray.at(v2).firstin;
    Edge<weight> *s = NULL;
    while ( t != p )   //边若存在，那么一定是p指向的边，所以t的搜索条件与p相比即可
    {
        s = t;
        t = t->hlink;
    }
    
    //修改v1的邻接表
    if( q == NULL )           //邻接表第一个即所要删除的边
        m_vertexArray.at(v1).firstout = p->tlink;
    else
        q->tlink = p->tlink;
    //修改v2的逆邻接表
    if( s == NULL )          //逆邻接表第一个即所要删除的边
        m_vertexArray.at(v2).firstin = t->hlink;
    else
        s->hlink = t->hlink;
    delete p;
    
    return true;
}
template<typename vertexNameType, typename weight>
weight graphspace::OLGraph<vertexNameType, weight>::getEdgeWeight(IN const Edge<weight> *pEdge)
{
    return pEdge->edgeWeight;
}

template<typename vertexNameType, typename weight>
void graphspace::OLGraph<vertexNameType, weight>::getVertexEdgeWeight(IN const int v1, OUT vector<weight> &DistanceArray)
{
    Edge<weight> *p = m_vertexArray.at(v1).firstout;
    int prevIndex = -1;
    weight tmp;
    while(NULL != p)
    {
        if (prevIndex == p->headvex)   //相同边找权值最小的一个
        {
            if (tmp > p->edgeWeight)
            {
                DistanceArray[prevIndex] = p->edgeWeight;
            }
        }
        else
        {
            DistanceArray[p->headvex] = p->edgeWeight;
            prevIndex = p->headvex;
            tmp = p->edgeWeight;
        }
        
        p = p->tlink;
    }
}

template<typename vertexNameType, typename weight>
weight graphspace::OLGraph<vertexNameType, weight>::getMinWeight(IN const vertexNameType vertexName1,
                                                     IN const vertexNameType vertexName2)
{
    Edge<weight> *pEdge = NULL;
    int v1 = getVertexIndex(vertexName1);
    if (-1 == v1)
    {
        cerr << "There is no vertex 1" << endl;
        return false;
    }
    int v2 = getVertexIndex(vertexName2);
    if (-1 == v2)
    {
        cerr << "There is no vertex 2" << endl;
        return false;
    }
    Edge<weight> *p = m_vertexArray.at(v1).firstout;
    while (p != NULL && p->headvex != v2)
    {
        p = p->tlink;
    }
    if (NULL == p)
    {
        pEdge = NULL;
        return weight(0);
    }
    weight tmp = getEdgeWeight(p);
    pEdge = p;
    while (NULL != p && v2 == p->headvex)
    {
        if (tmp > getEdgeWeight(p))
        {
            tmp = getEdgeWeight(p);
            pEdge = p;
        }
        p = p->tlink;
    }
    return tmp;
}

template<typename vertexNameType, typename weight>
int graphspace::OLGraph<vertexNameType, weight>::getVertexIndex(IN const vertexNameType vertexName)
{
    for( int i = 0; i < m_vertexArray.size(); i++ )
    {
        if( vertexName == getData(i) )
            return i;
    }
    return -1;
}

template<typename vertexNameType, typename weight>
vertexNameType graphspace::OLGraph<vertexNameType, weight>::getData(IN int index)
{
    return m_vertexArray.at(index).vertexName;
}

template<typename vertexNameType, typename weight>
int graphspace::OLGraph<vertexNameType, weight>::getVertexNumber()
{
    return m_vertexArray.size();
}
template<typename vertexNameType, typename weight>
int graphspace::OLGraph<vertexNameType, weight>::Dijkstra(IN const vertexNameType vertexName1)
{
    int sourceIndex = getVertexIndex(vertexName1);
    if (-1 == sourceIndex)
    {
        cerr << "There is no vertex " << endl;
        return false;
    }
    int nVertexNo = getVertexNumber();
    vector<bool> vecIncludeArray;
    vecIncludeArray.assign(nVertexNo, false);
    vecIncludeArray[sourceIndex] = true;
    vector<weight> vecDistanceArray;
    vecDistanceArray.assign(nVertexNo, weight(INT_MAX));
    vecDistanceArray[sourceIndex] = weight(0);
    vector<int> vecPrevVertex;
    vecPrevVertex.assign(nVertexNo, sourceIndex);
    getVertexEdgeWeight(sourceIndex, vecDistanceArray);
    int vFrom, vTo;
    while(1)
    {
        weight minWeight = weight(INT_MAX);
        vFrom = sourceIndex;
        vTo = -1;
        for (int i = 0; i < nVertexNo; i++)
        {
            if (!vecIncludeArray[i] && minWeight > vecDistanceArray[i])
            {
                minWeight = vecDistanceArray[i];
                vFrom = i;
            }
        }
        if (weight(INT_MAX) == minWeight)
        {
            break;
        }
        vecIncludeArray[vFrom] = true;
        Edge<weight> *p = m_vertexArray[vFrom].firstout;
        while (NULL != p)
        {
            weight wFT = p->edgeWeight;
            vTo = p->headvex;
            if (!vecIncludeArray[vTo] && vecDistanceArray[vTo] > wFT + vecDistanceArray[vFrom])
            {
                vecDistanceArray[vTo] = wFT + vecDistanceArray[vFrom];
                vecPrevVertex[vTo] = vFrom;
            }
            p = p->tlink;
        }
        
    }
    for (int i = 0; i < nVertexNo; i++)
    {
        if (weight(INT_MAX) != vecDistanceArray[i])
        {
            cout << getData(sourceIndex) << "->" << getData(i) << ": ";
            DijkstraPrint(i, sourceIndex, vecPrevVertex);
            cout << "  " << vecDistanceArray[i];
            cout << endl;
        }
    }
    return 0;
}
template<typename vertexNameType, typename weight>
void graphspace::OLGraph<vertexNameType, weight>::DijkstraPrint(IN int index, IN int sourceIndex, IN vector<int> vecPreVertex)
{
    if (sourceIndex != index)
    {
        DijkstraPrint(vecPreVertex[index], sourceIndex, vecPreVertex);
    }
    cout << getData(index) << " ";
}

template<typename vertexNameType, typename weight>
ostream& operator<<(OUT ostream &out, IN graphspace::OLGraph<vertexNameType,weight> &graphInstance)
{
    int vertexNo = graphInstance.getVertexNumber();
    out << "This graph has " << vertexNo << "vertexes" << endl;
    for(int i = 0; i < vertexNo; i++)
    {
        vertexNameType x1 = graphInstance.getData(i);
        out << x1 << ":    ";
        graphspace::Edge<weight> *p = graphInstance.m_vertexArray.at(i).firstout;
        while (NULL != p)
        {
            out << "(" << x1 << "," << graphInstance.getData(p->headvex) << "," << p->edgeWeight << ")  ";
            p = p->tlink;
        }
        out << endl;
    }
    return out;
}
