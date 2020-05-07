//
//  graph.cpp
//  校园最短路径的设计方案
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include<iostream>
#include <string>                                     //引入标准库中的头文件
#include "graph.h"                                    //引入头文件
using namespace std;



/*   前置条件：图不存在
 输入：无
 功能：图的初始化
 输出：无
 后置条件：构造一个有值的图
 */
template <class T>
Graph<T>::Graph(int* a,T* v, int n )                     //构造图
{
    int i,j;
    vertexNum=n;                                           //顶点数
    
    for (i=0; i<MaxSize; i++)                              //初始化邻接矩阵
        for (j=0; j<MaxSize; j++)                            //定义边
            arc[i][j] = 10000;
    for ( i=0; i<vertexNum; i++)
        vertex[i]=v[i];                                     //存储顶点信息
    for (i=0; i<vertexNum; i++)                           //给边赋置
        for (j=0; j<vertexNum; j++)
            arc[i][j]=*(a+i*n+j);
    int tt=0;
    
}


/*   前置条件：图已存在
 输入：无
 功能：输出图中所有顶点的数据信息
 输出：图中所有顶点的数据信息
 后置条件：图保持不变
 */
template <class T>
void Graph<T>::PutOutVexInfo()                          //取顶点
{
    int i=0;                                            //假设源点是第0个顶点，即顶点序号是0
    if (i>vertexNum) throw "位置";                      //错误抛出异常
    else{for(i=0;i<vertexNum;i++){                      //输出图中所有的顶点
        cout<<vertex[i]<<"\n";
    }
    }
}


/*   前置条件：图已存在
 输入：顶点v1,v2
 功能：修改顶点v1、v2的路径
 输出：修改后图中所有的路径
 后置条件：图保持不变
 */
template <class T>
void Graph<T>::SetArc(int v1,int v2,int arclength)      //修改路径
{                                                       //假设源点是第0个顶点，即顶点序号是0
    if ( v1>vertexNum|| v2>vertexNum) throw "位置";     //错误抛出异常
    else
    {	arc[v1][v2]=arclength;	                        //修改v1顶点到v2顶点的距离
        arc[v2][v1]=arclength;
    }
}


/*   前置条件：图已存在
 输入：无
 功能：输出图中所有的路径
 输出：图中所有顶点的数据信息
 后置条件：图保持不变
 */
template <class T>
void Graph<T>::PutOutArcInfo()                          //输出图中所有的路径
{
    int i=0;                                            //假设源点是第0个顶点，即顶点序号是0
    int j=0;
    if ( i>vertexNum|| j>vertexNum) throw "位置";       //错误抛出异常
    else
    {        for(i=0;i<vertexNum;i++){                    //输出任意两点之间的路径
        for(j=0;j<i;j++){
            if(arc[i][j]<10000)                //两点之间存在路径
                
                cout<<"从"<<vertex[i]<<"到"<<vertex[j]<<"的路径长度为："<<arc[i][j]<<"\n";                   //若两点间有路，则输出该两点间的路径
            
        }
    }
        
    }
}


/*  前置条件：图已存在
 输入：顶点name,位置i
 功能：在图中i位置插入一个顶点name
 输出：如果插入不成功，抛出异常
 后置条件：如果插入成功，图中增加了一个顶点
 */
template <class T>
void Graph<T>::InsertVex(int num,T name)                //在图中插入一个顶点，其编号为i，值为value
{                                                       //假设源点是第0个顶点，即顶点序号是0
    if ( num<0|| num>vertexNum) throw "位置";              //如果num输入不正确抛出异常
    int row;                                               //行
    int col;                                               //列
    int numv;                                              //最后一个顶点所在的位置
    numv = vertexNum-1;
    if(num>-1)                                             //num存在
        vertexNum++;                                          //顶点数加1
    
    for(int i=numv;i>num-1;i--)                             //i从最后一个顶点的下一个位置开始循环
        vertex[i]=vertex[i-1];                              //把从num位置的顶点到最后一个顶点均向后移一位
    vertex[num]=name;                                   //把要插入的顶点的值放在num位置上
    for(row=numv;row>=0;row--)                             //把从num列到最后一列的元素均向下移一列
    {
        for(col=numv;col>=num;col--)
            arc[row][col+1]=arc[row][col];
        arc[row][num]=10000;
        
    }
    for(row=numv;row>=num;row--)                          //把从num行到最后一行的元素均向下移一行
        for(col=0;col<=numv+1;col++)
            arc[row+1][col]=arc[row][col];
    
    for(col=0;col<vertexNum;col++)
        arc[num][col]=10000;                          //把num位置所在的行、列的值均置为无穷大
    
    
}


/*   前置条件：图已存在
 输入：顶点pos
 功能：在图中删除顶点pos
 输出：如果删除不成功，抛出异常
 后置条件：如果删除成功，图中减少了一个顶点,相应顶点所建立的边也消去
 */
template <class T>
void Graph<T>::DeleteVex(int pos)                       //删除第pos个顶点
{                                                       //假设源点是第0个顶点，即顶点序号是0
    if ( pos<0||  pos>MaxSize) throw "位置";               //如果pos输入不正确抛出异常
    int row;                                               //行
    int col;                                               //列
    int numv=vertexNum;                                    //numv等于顶点数
    if(pos>-1)                                             //pos存在
    {
        for(int i=pos;i<numv-1;i++)
            vertex[i]=vertex[i+1];                               //把从pos到最后的每个点的位置依次向前移一位
        vertexNum--;                                         //顶点数减1
        for(row=0;row<numv;row++)
        {
            for(col=pos;col<numv;col++)
                arc[row][col]=arc[row][col+1];                //把从pos列到最后一列的元素均向前移一列
            arc[row][numv-1]=10000;                            //把pos所在的列上的值置为无穷大
            
        }
        for(row=pos;row<numv;row++)
            for(col=0;col<numv;col++)
                arc[row][col]=arc[row+1][col];                //把从pos行到最后一行的元素均向上移一行
        
        
    }
    
}


/*   前置条件：图已存在
 输入：顶点v ，endv
 功能：假如endv存在，求v到endv的最短路径；假如不输入endv，则求v到任意顶点的最短路径
 输出：所求得的最短路径及所经历的位置
 后置条件：图保持不变
 */
template <class T>
void Graph<T>::Dijkstra(int v,int endv)                 //求最短路径，从v顶点到endv点的最短路径
{
    if ( v>vertexNum) throw "位置";                      //v顶点或endv顶点输出不正确则抛出异常
    int numv=vertexNum;                                  //顶点数
    int dist[MaxSize];       //                            //最短长度
    int path[MaxSize];                                   //当前找到的最短路径
    int s[MaxSize];                                      //存放源点和已生成的终点的集合
    int max= 10000;                                      //代表无穷大
    
    int i,j,k,wm;
    for(i=0;i<numv;i++)                                   //按网的邻接矩阵确定各顶点最短路径的初值
    {
        dist[i]=arc[v][i];
        if(i!=v&& dist[i]< max)                             //如果v、i之间有路
            path[i]=v;                                        //当前找到的最短路径为v
        else
            path[i]=-1;                                       //否则v与i顶点不存在路径
        s[i] = 0;                                           //给s集合确定初值0
    }
    s[v]=1;dist[v]=0;                                     //将顶点v本身排除在外
    for(k =0;k<numv-1;k++)                                //求其他numv-1各顶点的最短路径
    {
        wm = max;j=v;                                       //确定当前最短路径wm及顶点的序号j
        for( i=0;i<numv;i++)
        {
            if(!s[i]&&dist[i]<wm)                             //如果v、i之间有路
            {
                j=i;
                wm = dist[i];                                   //把当前找到的路径确定为最大值
            }
        }
        s[j]=1;
        for(i =0;i<numv;i++)                              //更新未确定最短路径各顶点的当前最短路径
        {
            if(!s[i]&&dist[j]+arc[j][i]<dist[i])            //如果v、i两点的距离加上i、j小于从v点到j点的距离
            {
                dist[i]=dist[j]+arc[j][i];path[i]=j;          //dist[i]取最小值
            }
        }
    }
    
    if (endv < numv && endv >=0 )                       //endv点存在
    {
        string mmm="";                                    //初始化字符串
        int j =endv;
        while(j > -1 )
        {
            string nnn = vertex[j];                         //依次把顶点存放在nnn字符串中
            nnn+=mmm;
            mmm = " "+nnn;
            j = path[j];
        }
        cout<<"从 "<<vertex[v].c_str()<<" 到 "<<vertex[endv].c_str()<<" 的最短路径长度："<<dist[endv]<<" 路径："<<mmm.c_str()<<"\n";//输出从v点到endv点的最短路径
    }
    else                                                //endv点不存在
        for(i=0;i<numv;i++)
        {
            string mmm="";                                    //初始化字符串
            int j =i;
            while(j > -1 )
            {
                string nnn = vertex[j];                         //依次把顶点存放在nnn字符串中
                nnn+=mmm;
                mmm = " "+nnn;
                j = path[j];
            }
            cout<<"从 "<<vertex[v].c_str()<<" 到 "<<vertex[i].c_str()<<" 的最短路径长度："<<dist[i]<<" 路径："<<mmm.c_str()<<"\n";//输出从v点到任意点的最短路径
        }
    
    
    
}


/*   前置条件：图已存在
 输入：顶点n、w
 功能：在图中删除顶点n、w 依附的边
 输出：如果删除不成功，抛出异常
 后置条件：如果删除成功，图中减少了一条边
 */
template <class T>
void Graph<T>::DeleteArc(int n, int w)                  //删除i、j两顶点依附的边
{
    
    if ( n>MaxSize||  w>MaxSize) throw "位置";             //如果输入不正确抛出异常
    arc[n][w]=arc[w][n]=10000;                         //删除w顶点和n顶点之间的路径
    
    
    
}


/*   前置条件：图已存在
 输入：顶点i、j
 功能：在图中插入顶点i、j及其所依附的边 
 输出：如果插入不成功，抛出异常
 后置条件：如果插入成功，图中增加了一条边
 */

template <class T>
void Graph<T>::InsertArc(int i, int j,int n)            //在图中插入一条边，其依附的两个顶点的编号为i和j
{
    if ( i>MaxSize||  j>MaxSize) throw "位置";              //如果输入不正确抛出异常	
    arc[i][j]=n;
    arc[j][i]=n;
    cout<<"从"<<vertex[i]<<"到"<<vertex[j]<<"的路径长度为："<<arc[i][j]<<"\n"; //输出所插入的两个顶点之间的距离
}
