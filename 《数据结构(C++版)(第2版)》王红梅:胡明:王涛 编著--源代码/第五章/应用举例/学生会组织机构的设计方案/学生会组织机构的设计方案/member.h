//
//  member.h
//  学生会组织机构的设计方案
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#ifndef ________________member__
#define ________________member__

#include <stdio.h>
#include<string>
using namespace std;

class Member
{
public:
    Member(string position, string name, string sex, string grade, int classes); //有参构造函数
    void print(void);  //打印数据
    string getPosition() const { return _position; }//获取学生职务
    string getName() const { return _name; } //获取学生姓名
    string getSex() const { return _sex; } //获取学生性别
    string getGrade() const { return _grade; }//获取学生所在年级
    int getClasses() const { return _classes; }//获取学生所在班级
    
    
    //操作符重载用来判断结点中数据是否相等,若相等则返回1,否则返回0
    
    int operator==(Member& stu) const
    {
        return _name == stu.getName()
        && _sex == stu.getSex()
        && _grade == stu.getGrade()
        && _classes == stu.getClasses()
        && _position == stu.getPosition();
    }
    
    
private:      //学生会成员属性
    string _position;   //职位
    string _name;       //姓名
    string _sex;        //性别
    string _grade;      //年级
    int _classes;       //班级
};

#endif /* defined(________________member__) */
