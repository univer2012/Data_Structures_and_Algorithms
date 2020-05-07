//
//  main.cpp
//  HelloWorld
//
//  Created by huangaengoln on 15/10/5.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include <iostream>  //引用输入输出流库函数的头文件
#include "LinkList.cpp"  //引用单链表的类
using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    LinkList <int> a;
    cout<<"执行插入操作:"<<endl;
    try {
        a.Insert(1,4);
        a.Insert(2,5);
        a.Insert(3,6);
    } catch(char* wrong) {
        cout << wrong;     //如失败提示失败信息
    }
    cout<<"已经插入“4，5，6”"<<endl;
    cout<<"单链表a的长度为:"<<endl;
    cout<<a.Length()<<endl;         //返回单链表长度
    cout<<endl;
    cout<<"单链表a的元素为:"<<endl;
    a.PrintList();                  //显示链表中所有元素
    cout<<endl;
    cout<<"按位查找第二个元素:"<<endl;
    cout<<"第二个元素为:";
    cout<<a.Get(2)<<endl;           //查找链表中第二个元素
    cout<<endl;
    cout<<"按值查找5"<<endl;
    cout<<"值为5的元素位置为:";
    cout<<a.Locate(5)<<endl;        //查找元素5，并返回在单链表中位置
    cout<<endl;
    cout<<"执行删除4的操作"<<endl;
    a.Delete(1);                    //删除元素4
    cout<<"已删除成功，单链表a的长度为";
    cout<<a.Length()<<endl;
    cout<<endl;
    cout<<"链表a中的元素为:"<<endl;
    a.PrintList();
    
    int r[ ]={1,2,3,4,5};
    LinkList <int> b(r,5);     //根据数组创建单链表
    cout<<"执行插入操作前单链表b为:"<<endl;
    b.PrintList();            //输出单链表所有元素
    cout<<"插入前单链表b的长度为:";
    cout<<b.Length()<<endl;
    try {
        b.Insert(3,8);
    } catch(char* wrong) {
        cout << wrong;     //如失败提示失败信息
    }
    cout<<"执行插入操作后单链表b为:"<<endl;
    b.PrintList();            //输出单链表b所有元素
    cout<<"插入后单链表b的长度为:";
    cout<<b.Length()<<endl;
    cout<<endl;
    try {
        if(a.Length()){
            cout<<"执行删除第一个元素操作:"<<endl;
            cout<<endl;
            b.Delete(1);                //删除b中第一个元素
            cout<<"已删除成功，单链表b的长度为:";
            cout<<b.Length()<<endl;
        } else{
            cout<<"顺序表b长度为0"<<endl;
        }
    } catch(char* wrong) {
        cout << wrong;     //如失败提示失败信息
    }
    cout<<"执行插入操作后单链表b为:"<<endl;
    b.PrintList();            //输出单链表所有元素
    
    return 0;
}
