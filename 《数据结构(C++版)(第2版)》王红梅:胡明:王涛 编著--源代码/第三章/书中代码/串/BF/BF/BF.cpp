//
//  BF.cpp
//  BF
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

//#include <stdio.h>
//int BF(char S[ ], char T[ ])
//{
//    int  i=1; int j=1;  //设置比较的起始下标
//    
//    while ((i<=(S[0]-'0')-(T[0]-'0')+1) && (j<=(T[0]-'0')))
//    {
//        if (S[i]==T[j])
//        {
//            i++;
//            j++;
//        }
//        else
//        {
//            i=i-j+2;
//            j=1;
//        } //i和j分别回溯
//        
//    }
//    if (j>(T[0]-'0'))
//        return (i-j+1);  //返回本趟匹配的起始下标
//    else 
//        return 0;
//}