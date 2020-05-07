//
//  main.cpp
//  排序技术
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include <iostream>
//#include "sort.cpp"

//#include "BucketSort.cpp"

using namespace std;




void InsertSort(int r[], int n);                  //直接顺序排序
void ShellSort(int r[], int n);                   //希尔排序
void BubbleSort(int r[], int n);                  //起泡排序
int Partition(int r[], int first, int end);       //快速排序一次划分
void QuickSort(int r[], int first, int end);      //快速排序
void SelectSort(int r[ ], int n);                 //简单选择排序
void Sift(int r[], int k, int m);                 //筛选法调整堆
void HeapSort(int r[ ], int n);                   //堆排序
void Merge(int r[], int r1[], int s, int m, int t);//一次归并
void MergePass(int r[ ], int r1[ ], int n, int h); //一趟归并
void MergeSort1(int r[ ], int r1[ ], int n );      //归并排序的非递归算法
void MergeSort2(int r[], int r1[], int r2[],int s, int t);//归并排序的递归算法

//struct Node {       //定义静态链表存储待排序记录序列
//    int key;        //记录的键值
//    int next;       //游标，下一个键值在数组中的下标
//};
//void BuckSort(Node r[],int n,int m);//桶式排序算法
//
//const int radixD = 2;
//struct RadixNode {       //定义静态链表存储待排序记录序列
//    int key[radixD];        //记录的键值，包括d个子关键码
//    int next;       //游标，下一个键值在数组中的下标
//};
//void RadixSort(RadixNode r[],int n,int m,int d);//基数排序算法



void BucketSort(int n,int arr[]);

/*
*求数据的最大位数,决定排序次数
 data   : 要排序的数组
 n      : 数组的元素数量
*/
int maxbit(int data[], int n)
{
    int d = 1; //保存最大的位数
    int p = 10;
    for(int i = 0; i < n; ++i)
    {
        while(data[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    const int numv=11;                                //赋值
    int a[]={0,3,56,32,78,5,24,9,64,34,7};
    int b[]={0,4,6,23,45,15,10,36,25,79,21};
    int c[]={38,23,56,2,79,42,93,29,6,5,57};
    int d[]={50,23,45,67,87,14,29,32,44,97,89};
    int e[]={8,6,1,48,37,63,39,74,52,26,49};
    int f[]={12,23,45,87,2,6,15,43,26,40,44};
    int g[]={13,10,23,45,64,34,24,7,9,3,16};
    int h[]={34,23,54,76,12,13,14,11,78,8};
    int g1[numv];
    int h1[numv];
    int h2[numv];
    int j;
    /* ===============直接顺序排序======================= */
    cout << "\n直接顺序排序前：" << "\n";
    for(j=0;j<numv;j++)
        cout<<a[j]<<" ";
    cout << "\n直接顺序排序结果为：" << "\n";
    InsertSort(a,numv);
    for(int k=0;k<numv;k++)
        cout<<a[k]<<" ";
    cout<<"\n";
    
    /* ===============希尔排序======================= */
    cout << "\n希尔排序前：" << "\n";
    for(j=1;j<numv;j++)
        cout<<b[j]<<" ";
    cout << "\n希尔排序结果为：" << "\n";
    ShellSort(b, numv);
    
    /* ===============起泡排序======================= */
    cout << "\n起泡排序前：" << "\n";
    for(int k=0;k<numv;k++)
        cout<<c[k]<<" ";
    cout << "\n起泡排序结果为：" << "\n";
    BubbleSort(c, numv);
    for(int i=0;i<numv;i++)
        cout<<c[i]<<" ";
    cout<<"\n";
    
    /* ===============快速排序======================= */
    cout << "\n快速排序前：" << "\n";
    for(j=0;j<numv;j++)
        cout<<d[j]<<" ";
    cout << "\n快速排序结果为：" << "\n";
    QuickSort(d,0,numv-1);
    for(int i=0;i<numv;i++)
        cout<<d[i]<<" ";
    cout<<"\n";
    
    /* ===============简单选择排序======================= */
    cout << "\n简单选择排序前：" << "\n";
    for(j=0;j<numv;j++)
        cout<<e[j]<<" ";
    cout << "\n简单选择排序结果为：" << "\n";
    SelectSort(e,numv);
    for(int i = 0;i < numv;i++)
        cout<<e[i]<<" ";
    cout<<"\n";
    
    /* ===============堆排排序======================= */
    cout << "\n堆排序前：" << "\n";
    for(j=0;j<numv;j++)
        cout<<f[j]<<" ";
    cout << "\n堆排序结果为：" << "\n";
    HeapSort(f, numv);
    
    /* ===============归并排序非递归算法======================= */
    cout << "\n归并排序非递归算法前：" << "\n";
    for(j=0;j<numv;j++)
        cout<<g[j]<<" ";
    cout << "\n归并排序非递归算法的结果为：" << "\n";
    MergeSort1(g, g1,numv );
    
    /* ===============归并排序递归算法======================= */
    cout << "\n归并排序递归算法前：" << "\n";
    for(j=0;j<numv;j++)
        cout<<h[j]<<" ";
    cout << "\n归并排序递归算法的结果为：" << "\n";
    MergeSort2(h,h1,h2, 0, numv-1);
    for(int i=0; i < numv; i++)
        cout<<h1[i]<<" ";
    cout<<"\n";
    
    
    /* ===============桶式排序======================= */
    int bucketArr[] = {3,5,3,1,5,6,3,8};
    int num=sizeof(bucketArr)/ sizeof(bucketArr[0]);
    BucketSort(num, bucketArr);
    
    
    return 0;
}
