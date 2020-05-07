//
//  main.cpp
//  校园最短路径的设计方案
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include <iostream>
#include <string>                                                        //引入标准库中的头文件
#include "graph.cpp"                                                     //引用 grsph.cpp 文件
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    const int numv = 8;                                                  //顶点数
    int choose=1;                                                        //控制
    int which;                                                           //功能选择变量
    string name;                                                         //插入顶点的值
    int cost[numv][numv]={	                                             //按邻接矩阵确定顶点的权值
        {10000, 130,    80,     260,    10000,  10000,  10000,  10000},
        {130,   10000,  10000,  75,     10000,  265,    10000,  10000},
        {80,    10000,  10000,  10000,  50,     10000,  10000,  10000},
        {260,   75,     10000,  10000,  120,    85,400, 10000},
        {10000, 10000,  50,     120,    10000,  10000,  350,    200},
        {10000, 265,    10000,  85,     10000,  10000,  120,    10000},
        {10000, 10000,  10000,  400,    350,    120,    10000,  150},
        {10000, 10000,  10000,  10000,  200,    10000,  150,    10000}
    };                                                   //当前找到的最短路径
    string vname[numv]={"第四教学楼","第三教学楼","图书馆","食堂","第一教学楼","第二教学楼","综合实验楼","校医院"};      //初始化各顶点
    int* p;                                                              //定义指针p
    string* q;                                                           //定义指针q
    p = &cost[0][0];                                                     //p指针指向cost数组的起始位置
    q = vname;                                                           //q指针指向vname数组
    Graph<string> g(p, q,  numv );                                       //调用Graph程序
    while ( choose==1 )                                                  //控制
    {
        cout<<"\n";
        cout << "需要输出顶点信息请按0" << "\n";		                     //输入你要进行的操作的序号
        cout << "需要边的信息输出请按1" << "\n";
        cout << "需要修改请按2" << "\n";
        cout << "需要求最短路径请按3" << "\n";
        cout << "需要删除某个顶点请按4" << "\n";
        cout << "需要插入某个顶点请按5" << "\n";
        cout << "需要删除某条边请按6" << "\n";
        cout << "需要插入某条边请按7" << "\n";
        cout << "需要退出请按8" << "\n";
        cin >> which;
        switch( which )                                                    //功能选择
        {
                
            case 0:                                                            //输出图的各顶点的值
                try
            {
                g.PutOutVexInfo();
            }
                catch(char*)
            {
                cout<<"输出不正确！"<<endl;
            }
                
                break;
                
            case 1:                                                            //输出图中的路径
                
                int i;
                int j;
                cout<<"所有的边的信息为:"<<"\n";
                try
            {
                g.PutOutArcInfo();
            }
                catch(char*)
            {
                cout<<"输出不正确！"<<endl;
            }
                break;
            case 2:                                                            //修改图中的边长
                
                cout<<"change";
                cin>>i>>j;
                int length;
                cout<<"length";
                cin>>length;
                try
            {
                g.SetArc(i,j,length);
            }
                catch(char*)
            {
                cout<<"输出顶点不正确！"<<endl;
            }
                
                break;
            case 3:                                                            //求最短路径
                cout<<"请输入源顶点:"<<"\n";
                int vv ;
                cin>>vv;
                cout<<"请输入结束顶点，若要全部显示请输入88:"<<"\n";
                int vvt ;
                cin>>vvt;
                try
            {
                g.Dijkstra(vv,vvt);
            }
                catch(char*)
            {
                cout<<"输出顶点不正确！"<<endl;
            }
                break;
                
            case 4:
                //删除hh顶点
                int hh ;
                cout<<"请输入要删除的顶点"<<"\n";
                cin>>hh;
                try
            {
                g.DeleteVex(hh);
            }
                catch(char*)
            {
                cout<<"删除失败！"<<endl;
            }
                break;
                
                
            case 5:                                                            //在nn位置插入值为name的顶点
                int nn ;
                cout<<"请输入要插入的顶点的位置和名称"<<"\n";
                cin>>nn>>name;
                try
            {
                g.InsertVex(nn,name);
            }
                catch(char*)
            {
                cout<<"插入失败！"<<endl;
            }
                break;
                
                
                
                
            case 6:                                                            //删除pos1到pos2之间的距离
                int pos1;
                int pos2;
                
                cout<<"请输入两顶点："<<"\n";
                cin>>pos1>>pos2;
                try
            {
                g.DeleteArc(pos1,pos2); 
            }
                catch(char*)
            {
                cout<<"插入失败！"<<endl;
            }
                
                break;
                
                
            case 7:                                                            //插入从pos1到pos2的路径
                int m;
                cout<<"请输入两顶点："<<"\n";
                cin>>pos1>>pos2;
                cout<<"请输入路径："<<"\n";
                cin>>m;
                try
            {
                g.InsertArc(pos1,pos2,m);
            }
                catch(char*)
            {
                cout<<"插入失败！"<<endl;
            }
                
                break;        
            case 8:                                                              //退出
                choose=0;
                break;
        }
    }
    
    return 0;
}
