//
//  main.cpp
//  十字链表
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>
#include "graph.cpp"
using namespace std;
using namespace graphspace;

int main(int argc, const char * argv[]) {
    // insert code here...
    OLGraph<string, int> g;
    clock_t start1,finish1,time1;
    double duration;
    g.insertAVertex("A");
    g.insertAVertex("B");
    g.insertAEdge("A", "B", 16);
    
    g.insertAEdge("A", "B", 26);
    g.insertAEdge("A", "B", 36);
    g.insertAEdge("A", "B", 46);
    g.insertAEdge("A", "B", 6);
    
    g.insertAVertex("C");
    g.insertAVertex("D");
    g.insertAVertex("E");
    g.insertAVertex("F");
    cout<<g<<endl<<endl;
    g.insertAEdge("A", "B", 6);
    g.insertAEdge("A", "C", 3);
    g.insertAEdge("B", "C", 2);
    g.insertAEdge("B", "D", 5);
    g.insertAEdge("C", "D", 3);
    g.insertAEdge("C", "E", 4);
    g.insertAEdge("D", "E", 2);
    g.insertAEdge("D", "F", 3);
    g.insertAEdge("E", "F", 5);
    
    g.insertAEdge("B", "A", 6);
    g.insertAEdge("C", "A", 3);
    g.insertAEdge("C", "B", 2);
    g.insertAEdge("D", "B", 5);
    g.insertAEdge("D", "C", 3);
    g.insertAEdge("E", "C", 4);
    g.insertAEdge("E", "D", 2);
    g.insertAEdge("F", "D", 3);
    g.insertAEdge("F", "E", 5);
    cout<<g<<endl<<endl;
    
    
    cout<<g<<endl<<endl;
    g.Dijkstra("A");
    g.vertexRAdjEdges("B");
    string vertex1;
    string vertex2;
    int controlNum;
    int value;
    cout<<"查询边请按 1，查询顶点邻接表请按 2，查询顶尖逆邻接表请按3 ,删除边请按4，退出请按 0："<<endl;
    cin>>controlNum;
    while( controlNum != 0 )
    {
        start1 = clock();
        switch ( controlNum ){
            case 1:
                cout<<"entry 2 vertex name"<<endl;
                cin>>vertex1>>vertex2;
                g.edgeExist(vertex1, vertex2);
                cout<<endl;
                break;
            case 2:
                cout<<"entry 1 vertex name"<<endl;
                cin>>vertex1;
                g.vertexAdjEdges(vertex1);
                cout<<endl;
                break;
            case 3:
                cout<<"entry 1 vertex name"<<endl;
                cin>>vertex1;
                g.vertexRAdjEdges(vertex1);
                cout<<endl;
                break;
            case 4:
                cout<<"entry 2 vertex name"<<endl;
                cin>>vertex1>>vertex2;
                cin>>value;
                g.removeAEdge(vertex1, vertex2, value);
                cout<<g<<endl<<endl;
                break;
            default:
                break;
        }
        
        cout<<"查询边请按 1，查询顶点邻接表请按 2，查询顶尖逆邻接表请按3 ,删除边请按4，退出请按 0："<<endl;
        cin>>controlNum;
        finish1 = clock();
        duration = (double)(finish1 - start1) / CLOCKS_PER_SEC;
        cout<<duration<<" seconds"<<endl;
    }
    
    system("pause");
    
    return 0;
}
