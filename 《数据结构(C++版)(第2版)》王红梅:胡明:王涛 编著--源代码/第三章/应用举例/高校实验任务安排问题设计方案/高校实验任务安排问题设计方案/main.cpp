//
//  main.cpp
//  高校实验任务安排问题设计方案
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include <iostream>      //引用输入输出流
#include "CirQueue.cpp"  //引入成员函数文件
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int which;          //功能选择变量
    int queue;          //队列选择变量
    int i;
    int flag;          //标志
    int choose1=1;     //控制
    int choose;        //控制
    string num;        //学号
    string name;       //姓名
    string grade;
    int where;         //插入位置
    student temp1;
    CirQueue<student> a; //创建模版类的实例
    CirQueue<student> b; //创建模版类的实例
    CirQueue<student> c; //创建模版类的实例
    
    while(choose1==1)
    {
        cout<<"对周一下午试验名单进行操作请按1"<<"\n";
        cout<<"对周三下午试验名单进行操作请按2"<<"\n";
        cout<<"对周五下午试验名单进行操作请按3"<<"\n";
        cout << "需要输出全部信息请按4" << "\n";
        cin>>queue;
        
        switch(queue)
        {
            case 1: flag = 1;choose=1; break;
            case 2: flag = 2;choose=1; break;
            case 3: flag = 3;choose=1; break;
            case 4:
                
                try
            {
                cout<<"周一下午试验名单:"<<"\n";
                a.PrintQueue();
                cout<<"周三下午试验名单:"<<"\n";
                b.PrintQueue();
                cout<<"周五下午试验名单:"<<"\n";
                c.PrintQueue();
            }
                
                catch(char *)
            {
                cout << "fail to enquire\n";     //如失败提示失败信息
            }
                break;
            default: break;
        }
        
        while(choose==1)
        {
            cout << "需要插入信息请按1" << "\n";
            cout << "需要删除信息请按2" << "\n";
            cout << "需要查询信息请按3" << "\n";
            cout << "需要取消预约请按5" << "\n";
            cout << "需要退出请按6" << "\n";
            cin >> which;
            
            switch(which)
            {
                case 1:
                    cout << "需要插入学生学号:" << "\n";
                    cin  >> num;
                    cout << "需要插入学生姓名:" << "\n";
                    cin  >> name;
                    cout << "需要插入学生班级:" << "\n";
                    cin  >> grade;
                    temp1.num = num;
                    temp1.name = name;
                    temp1.grade = grade;
                    
                    try
                {
                    switch(flag)
                    {
                        case 1: a.EnQueue(temp1); break;
                        case 2: b.EnQueue(temp1); break;
                        case 3: c.EnQueue(temp1); break;
                        default: break;
                    }
                    cout<<"插入成功!\n";
                }
                    
                    catch(char *)
                {
                    cout << "fail to insert\n";     //如失败提示失败信息
                }
                    break;
                    
                case 2:
                    
                    try
                {
                    switch(flag)
                    {
                        case 1: a.DeQueue(); break;
                        case 2: b.DeQueue(); break;
                        case 3: c.DeQueue(); break;
                        default: break;
                    }   
                    cout<<"删除成功!"<< "\n";
                }
                    
                    catch(char *)
                {
                    cout << "fail to delete\n";     //如失败提示失败信息
                }
                    break;
                    
                case 3:
                    try
                {
                    switch(flag)
                    {
                        case 1: a.PrintQueue(); break;
                        case 2: b.PrintQueue(); break;
                        case 3: c.PrintQueue(); break;
                        default: break;
                    }
                    
                }
                    
                    catch(char *)
                {
                    cout << "fail to enquire\n";     //如失败提示失败信息
                }
                    break;
                    
                case 5:
                    
                    cout<<"请输入取消预约的学生学号:\n";
                    cin>>num;
                    
                    try
                {
                    switch(flag)
                    {
                        case 1: i=a.Enquire(num);
                            a.Delete(i);
                            break;
                        case 2: i=b.Enquire(num);
                            b.Delete(i);
                            break;
                        case 3: i=c.Enquire(num);
                            c.Delete(i);
                            break;
                        default: break;
                    }
                    cout<<"预约修改成功!"<< "\n";
                }
                    catch(char *)
                {
                    cout << "fail to cancel\n";     //如失败提示失败信息
                }
                    break;
                    
                case 6: 
                    choose=0;
                    
                    break;
                    
                default:  break;
            }
        }
    }
    
    return 0;
}
