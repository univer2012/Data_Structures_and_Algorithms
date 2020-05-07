//
//  main.cpp
//  学生会组织机构的设计方案
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include <iostream>
#include <string>
#include"tree.cpp"
#include"member.h"
using namespace std;

void printMemberFunction(void* node)          //打印函数
{
    Node<Member>* memberNode = (Node<Member>*)node;
    (memberNode->getData( ))->print( );
}

int main(int argc, const char * argv[]) {
    // insert code here...
#if 0
    Member* memberChair = new Member("学生会主席", "张三", "男", "三", 2);      //初始化一棵树
    Member* memberSubChairOne = new Member("副主席", "李一", "男", "三", 2);
    Member* memberSubChairTwo = new Member("副主席", "李二", "男", "二", 2);
    Member* memberSubChairThree = new Member("副主席", "李三", "女", "三", 3);
    Member* memberSubChairFour = new Member("秘书长", "李四", "女", "一", 4);
    
    Member* member1 = new Member("文艺部长", "王一", "女", "一", 5);
    Member* member2 = new Member("女生部长", "王二", "女", "二", 4);
    Member* member3 = new Member("外联部长", "王三", "男", "二", 5);
    
    Member* member4 = new Member("舍管部长", "赵一", "男", "三", 1);
    Member* member5 = new Member("体育部长", "赵二", "男", "一", 4);
    Member* member6 = new Member("治保部长", "赵三", "男", "三", 3);
    
    Member* member7 = new Member("学习部长", "刘一", "女", "二", 4);
    Member* member8 = new Member("生活部长", "刘二", "女", "二", 6);
    
    Member* member9 = new Member("秘书部长", "周一", "女", "一", 3);
    Member* member10 = new Member("宣传部长", "周二", "男", "一", 4);
#elif 1
    Member* memberChair = new Member("学生会主席", "张三", "男", "三", 2);      //初始化一棵树
    Member* memberSubChairOne = new Member("副主席", "李一", "男", "三", 2);
    Member* memberSubChairTwo = new Member("副主席", "李二", "男", "二", 2);
    Member* memberSubChairThree = new Member("副主席", "李三", "女", "三", 3);
    Member* memberSubChairFour = new Member("秘书长", "李四", "女", "一", 4);
    
    Member* member1 = new Member("文艺部长", "王一", "女", "一", 5);
    Member* member2 = new Member("女生部长", "王二", "女", "二", 4);
    Member* member3 = new Member("外联部长", "王三", "男", "二", 5);
    
    Member* member4 = new Member("舍管部长", "赵一", "男", "三", 1);
    Member* member5 = new Member("体育部长", "赵二", "男", "一", 4);
    Member* member6 = new Member("治保部长", "赵三", "男", "三", 3);
    
    Member* member7 = new Member("学习部长", "刘一", "女", "二", 4);
    Member* member8 = new Member("生活部长", "刘二", "女", "二", 6);
    
    Member* member9 = new Member("秘书部长", "周一", "女", "一", 3);
    Member* member10 = new Member("宣传部长", "周二", "男", "一", 4);
#endif
    
    Tree<Member> tree = Tree<Member>(memberChair);       //构造树的根结点
    
    tree.Insert(memberChair, memberSubChairOne);
    tree.Insert(memberChair, memberSubChairTwo);
    tree.Insert(memberChair, memberSubChairThree);
    tree.Insert(memberChair, memberSubChairFour);
    
    tree.Insert(memberSubChairOne, member1);
    tree.Insert(memberSubChairOne, member2);
    tree.Insert(memberSubChairOne, member3);
    
    tree.Insert(memberSubChairTwo, member4);
    tree.Insert(memberSubChairTwo, member5);
    tree.Insert(memberSubChairTwo, member6);
    
    tree.Insert(memberSubChairThree, member7);
    tree.Insert(memberSubChairThree, member8);
    
    tree.Insert(memberSubChairFour, member9);
    tree.Insert(memberSubChairFour, member10);       //初始化结束
    
    
    int control=1;          //声明控制变量来控制程序的执行与结束
    int which;              //选择变量用来选择执行的操作
    char flag;               //标志变量用来确认是否执行操作
    
    //声明要插入结点的父结点数据域的信息属性
    string parentposition;
    string parentname;
    string parentsex;
    string parentgrade;
    int parentclasses;
    //声明新结点数据域的信息属性
    string position;
    string name;
    string sex;
    string grade;
    int classes;
    //声明要删除结点数据域的信息属性
    string oldposition;
    string oldname;
    string oldsex;
    string oldgrade;
    int oldclasses;
    
    while(control)
    {
        
        cout<<"请选择你要进行的操作："<<endl;  //选择你要进行的操作
        cout<<"插入请选择1"<<endl;
        cout<<"删除请选择2"<<endl;
        cout<<"修改请选择3"<<endl;
        cout<<"查询请选择4"<<endl;
        cout<<"输出请选择5"<<endl;
        cout<<"退出请选择6"<<endl;
        cin>>which;
        switch (which)
        {
            case 1:                                    //插入一个学生会成员
                cout<<"插入的学生职务:";
                cin>>position;
                cout<<"插入的学生姓名:";
                cin>>name;
                cout<<"插入的学生性别:";
                cin>>sex;
                cout<<"插入的学生所在年级:";
                cin>>grade;
                cout<<"插入的学生所在班级:";
                cin>>classes;
                
                cout<<"插入在某职位下:";
                cin>>parentposition;
                cout<<"该职位的学生姓名:";
                cin>>parentname;
                cout<<"该职位的学生性别:";
                cin>>parentsex;
                cout<<"该职位的学生所在年级:";
                cin>>parentgrade;
                cout<<"该职位的学生所在班级:";
                cin>>parentclasses;
                cout<<"确定要插入？确定请按Y或y:" ;
                cin>>flag;
                if(flag=='Y'||'y')
                {
                    Member* newmember=new Member(position,name,sex,grade,classes);
                    Member* parentmember=new Member(parentposition,parentname,parentsex,parentgrade,parentclasses);
                    try
                    {
                        tree.Insert(parentmember,newmember);
                        cout<<"插入成功!\n";
                    }
                    catch(char*)
                    {
                        cout<<"插入失败!\n";
                    }
                    delete parentmember;    //释放结点的存储空间
                }
                break;
            case 2:                       //删除学生会成员
                
                cout<<"删除的学生职务:";
                cin>>position;
                cout<<"删除的学生姓名:";
                cin>>name;
                cout<<"删除的学生性别:";
                cin>>sex;
                cout<<"删除的学生所在年级:";
                cin>>grade;
                cout<<"删除的学生所在班级:";
                cin>>classes;
                cout<<"确定要删除？确定请按Y或y:" ;
                cin>>flag;
                if(flag=='Y'||flag=='y')
                {
                    Member* member=new Member(position,name,sex,grade,classes);
                    try
                    {
                        tree.Delete(member);
                        cout<<"删除成功!\n";
                    }
                    catch(char*)
                    {
                        cout<<"删除失败!!!"<<endl;
                    }
                }
                break;
            case 3:                               //修改学生会的成员信息
                cout<<"要修改的学生职位:";
                cin>>oldposition;
                cout<<"要修改的学生姓名:";
                cin>>oldname;
                cout<<"要修改的学生性别:";
                cin>>oldsex;
                cout<<"要修改的学生所在年级:";
                cin>>oldgrade;
                cout<<"要修改的学生所在班级:";
                cin>>oldclasses;
                
                cout<<"新职位:";
                cin>>position;
                cout<<"新学生的姓名:";
                cin>>name;
                cout<<"新学生的性别:";
                cin>>sex;
                cout<<"新学生所在年级:";
                cin>>grade;
                cout<<"新学生所在班级:";
                cin>>classes;
                
                cout<<"确定要修改？确定请按Y或y:" ;
                cin>>flag;
                
                if(flag=='Y'||flag=='y')                   //修改学生会的成员信息
                {
                    Member* oldmember=new Member(oldposition,oldname,oldsex,oldgrade,oldclasses);
                    Member* newmember=new Member(position,name,sex,grade,classes);
                    try                         //捕捉异常
                    {
                        tree.Update(oldmember,newmember);
                        cout<<"修改成功!\n";
                    }
                    catch(char*)
                    {
                        cout<<"修改失败!"<<endl;
                    }
                    delete oldmember;
                }
                break;
            case 4:                    //输出学生会组织情况 			  
                cout<<"请输入你要查询的职务名称"<<endl;
                cin>>position;			  
                cout<<"确定要查询？确定请按Y或y:" ;
                cin>>flag;
                if(flag=='Y'||flag=='y')
                {
                    try
                    {
                        tree.FindNode(position,printMemberFunction);
                    }
                    catch(char*)
                    {
                        cout<<"查询失败！"<<endl;	
                    }
                }
                break;
            case 5:                    //输出学生会所有成员
                try
            {
                tree.LeverOrder(printMemberFunction);
            }
                catch(char*)
            {
                cout<<"没有任何成员！"<<endl;
                control=0;
            }
                break;
            case 6:                     //退出操作
                control=0;
                break;
            default: 
                cout<<"请选择正确的操作：\n";
                break;
        }
    }
    
    return 0;
}
