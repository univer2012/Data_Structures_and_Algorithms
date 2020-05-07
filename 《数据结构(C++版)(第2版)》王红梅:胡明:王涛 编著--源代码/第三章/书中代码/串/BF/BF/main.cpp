//
//  main.cpp
//  BF
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include <iostream>      //引入输入输出流
using namespace std;

int BF(char S[ ], char T[ ])
{
    int  i=1; int j=1;  //设置比较的起始下标
    
    while ((i<=(S[0]-'0')-(T[0]-'0')+1) && (j<=(T[0]-'0')))
    {
        if (S[i]==T[j]){
            i++;
            j++;
        }
        else{
            i=i-j+2;
            j=1;
        } //i和j分别回溯
        
    }
    if (j>(T[0]-'0'))
        return (i-j+1);  //返回本趟匹配的起始下标
    else 
        return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<"主串的元素为:fgfggabc\n";
    cout<<"子串的元素为:gg\n";
    
    char a[9]={'8','f','g','f','g','g','a','b','c'};
    char b[3]={'2','g','g'};
    
    cout<<"进行串匹配,所得的结果为:"<<endl;
    cout<<BF(a,b)<<endl;
    
    return 0;
}
