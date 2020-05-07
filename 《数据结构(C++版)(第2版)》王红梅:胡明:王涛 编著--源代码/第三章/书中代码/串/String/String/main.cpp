//
//  main.cpp
//  String
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include <iostream>       //引用输入输出流库函数的头文件
#include "String.cpp"      //引用串表类String
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    char temp[] ="how are yo?";
    String <char> a(temp,11);         //创建一个串a
    char temp1[] ="u";
    String <char> b(temp1,1);         //创建一个串b
    cout<<"执行插入操作前串a为:"<<endl;
    a.PrintList();//输出串a所有元素
    cout<<endl;cout<<endl;
    cout<<"串a的长度为:";
    cout<<a.Length()<<endl;         //返回串长度
    try
    {
        a.StrInsert(11,b);
    }
    catch(char* wrong)
    {
        cout << wrong;     //如失败提示失败信息
    }
    cout<<"执行插入操作后串a为:"<<endl;
    a.PrintList();//输出串a所有元素
    cout<<endl;cout<<endl;
    cout<<"串a的长度为:";
    cout<<a.Length()<<endl;         //返回串长度
    try
    {
        a.StrConcat(b);
    }
    catch(char* wrong)
    {
        cout << wrong;     //如失败提示失败信息
    }
    cout<<"执行合并串b操作后串a为:"<<endl;
    a.PrintList();//输出串a所有元素
    cout<<endl;cout<<endl;
    cout<<"串a的长度为:";
    cout<<a.Length()<<endl;         //返回串长度
    try
    {
        a.StrDelete(13,1);
    }
    catch(char* wrong)
    {
        cout << wrong;     //如失败提示失败信息
    }
    cout<<"执行删除最后一个元素操作后串a为:"<<endl;
    a.PrintList();//输出串a所有元素
    cout<<endl;cout<<endl;
    cout<<"串a的长度为:";
    cout<<a.Length()<<endl;         //返回串长度
    
    return 0;
}
