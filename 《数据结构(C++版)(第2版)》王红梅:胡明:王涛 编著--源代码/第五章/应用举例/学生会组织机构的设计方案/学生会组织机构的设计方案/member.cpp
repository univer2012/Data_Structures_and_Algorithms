//
//  member.cpp
//  学生会组织机构的设计方案
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include <iostream>
#include "member.h"

using namespace std;

/*学生会成员(即学生)类的构造函数实现如下:
 *此函数的前置条件: 无
 *输入:成员属性:position,name,sex,garde,classes
 *功能:初始化一个新成员
 *输出:无
 *后置条件:得到一个新成员类
 */
Member::Member(string position, string name, string sex, string grade, int classes)
{                                   //给学生会成员的每一个属性赋值
    _position = position;
    _name = name;
    _sex = sex;
    _grade = grade;
    _classes = classes;
}

void Member::print(void) //打印学生会成员信息的数据格式
{
    cout << "(" << _position << ", " << _name << ", " <<_sex << ", " << _grade ;
    cout << ", " <<_classes<< ")" << endl;
}
