//
//  tree.cpp
//  学生会组织机构的设计方案
//
//  Created by huangaengoln on 15/10/6.
//  Copyright (c) 2015年 huangaengoln. All rights reserved.
//

#include"tree.h"
#include"node.h"
#include"member.h"
#include<string>

typedef void (*Function)(void* node);  //声明函数指针
const int MAX_QUEUE_SIZE = 100;        //声明不变常量用于队列的长度

/*
 *前置条件:树已存在
 *输    入:数据信息newdata,数据信息olddata
 *功    能:将数据域信息为newdata的新结点插入到数据域信息为olddata结点的孩子结点中
 *输    出:无
 *后置条件:如果插入成功,得到一棵新树
 */
template<class T>
void Tree<T>::Insert(T* oldDate, T* newDate)    //插入函数
{
    Node<T>* tempNode = FindNode(oldDate);  //工作指针指向要插入位置的父结点
    
    if (tempNode != NULL)    //若其父结点存在
    {
        InsertChild(tempNode, newDate); // 将新结点插入到其孩子结点中
    }
    else
    {
        throw "插入失败！";           //抛出异常
    }
}
/*
 *前置条件:树已存在
 *输    入:数据信息data
 *功    能:删除树中数据域信息为data的结点及其孩子结点
 *输    出:无
 *后置条件:如果删除成功,得到一棵新树
 */
template<class T>
void Tree<T>::Delete(T* data)					 //删除树中某结点的第i个孩子
{
    int front = 0;
    int rear  = 0;                    //采用顺序队列，并假定不会发生上溢
    
    Node<T>* queue[MAX_QUEUE_SIZE];  //声明一个队列
    Node<T>* tempNode = NULL;        //声明指向结点类型的指针
    Node<T>* brotherNode = NULL;     //工作指针
    
    if (_root == NULL)   throw"失败！";
    
    queue[rear++] = _root;            //根结点入队
    
    while ( front != rear )             //队列中有结点存在
    {
        tempNode = queue[front++];   //头结点出队，同时对头元素的标识符后移
        
        brotherNode = tempNode->getFirstChild(); //工作指针指向出队元素的第一个孩子结点
        
        if (brotherNode != NULL)     //若第一个孩子结点存在
        {
            if (*data == *(brotherNode->getData())) //判断该结点是否为要删除的结点 ，若是
            {
                tempNode->setFirstChild(brotherNode->getBrother());  //将其父结点的第一个孩子指针指向其右兄弟
                brotherNode->setBrother(NULL);   //并将其右兄弟指针置空
                Release(brotherNode);           //释放此结点以及其孩子结点的存储空间
                break;
            }
            queue[rear++]=brotherNode;      //第一个孩子结点不是要删除的结点，则入队
            while (brotherNode->getBrother() != NULL)   //若存在右兄弟结点
            {
                Node<T>* deleteNode = brotherNode->getBrother();//设置工作指针指向其右兄弟
                
                if (*data == *(deleteNode->getData()))  //判断其右兄弟结点是否为要删除结点，若是
                {
                    brotherNode->setBrother(deleteNode->getBrother()); //将其右兄弟指针指向其右兄弟的右兄弟
                    deleteNode->setBrother(NULL);       //将其右兄弟指针置空
                    Release(deleteNode);                //释放此结点以及其孩子结点的存储空间
                    break;
                }
                else
                {                                       //若要删除结点不是此结点
                    queue[rear++] = deleteNode;        //则将此结点入队，同时队尾标识后移
                    brotherNode = brotherNode->getBrother(); //工作指针指向其右兄弟结点
                }
            }
        }
    }
}
/*
 *前置条件:树已存在
 *输    入:数据信息newdata,数据信息olddata
 *功    能:将数据信息为olddata的某结点的数据域信息修改为newdata
 *输    出:无
 *后置条件:如果修改成功,得到一棵新树
 */
template<class T>
void Tree<T>::Update(T* oldData, T* newData)        //修改函数
{
    Node<T>* tempNode = FindNode(oldData); //工作指针指向要修改的结点
    if (tempNode != NULL)   tempNode->setData(newData); //若存在要修改的结点则进行修改
    else  throw "修改失败！";              //抛出异常
}
/*
 *前置条件:树已存在
 *输    入:数据position
 *功    能:查询position的成员信息
 *输    出:position的成员的一个线性排列
 *后置条件:树保持不变
 */
template<class T>
Node<T>* Tree<T>::FindNode(std::string position,Function function) //查询函数
{
    
    int front = 0;
    int rear  = 0;               //采用顺序队列，并假定不会发生上溢
    
    Node<T>* queue[MAX_QUEUE_SIZE]; //声明一个队列
    Node<T>* tempNode = NULL;      //声明指向结点类型的指针
    Node<T>* getNode = NULL;   //工作指针
    
    if (_root == NULL)    throw "查询失败！";      //空树，失败
    queue[rear++] = _root;          //否则根结点指针入队
    while (front != rear)          //若队列中有元素
    {
        tempNode = queue[front++];//头元素出队，同时对头元素的标识符后移
        
        if (position == (tempNode->getData( )->getPosition( )))   //判断出队元素是否为要查询的结点，若是
        {
            function(tempNode);              //输出该结点
        }
        //若不是，再判断其孩子结点
        getNode = tempNode->getFirstChild( );
        while (getNode != NULL)
        {
            queue[rear++] = getNode;
            getNode = getNode->getBrother( );
        }
    }
    return NULL;   //树中没有要查询的结点则返回空
}
/*
 *前置条件:树已存在
 *输    入:无
 *功    能:层序遍历一棵树
 *输    出:树中结点的一个线性排列
 *后置条件:树保持不变
 */
template<class T>
void Tree<T>::LeverOrder(Function function)   //层序遍历树
{
    int front = 0;
    int rear  = 0;  //采用顺序队列，并假定不会发生上溢
    
    Node<T>* queue[MAX_QUEUE_SIZE]; //声明一个队列
    Node<T>* tempNode = NULL;      //声明指向结点类型的指针
    Node<T>* getNode = NULL;   //工作指针
    
    if (_root == NULL) throw "空树";//空树返回
    queue[rear++] = _root;         //否则根结点指针入队
    while (front != rear)         //若队列中有元素
    {
        tempNode = queue[front++];//头元素出队，同时对头元素的标识符后移
        function(tempNode);       //打印出头结点
        getNode = tempNode->getFirstChild();  //工作指针指向根结点的第一个孩子
        while (getNode != NULL)              //若根结点有孩子
        {
            queue[rear++] = getNode;  //孩子结点入队,同时队尾标志后移
            getNode = getNode->getBrother();//工作指针指向下一个孩子
        }
    }
}
/*
 *前置条件：树已存在
 *输    入：指向根结点的指针
 *功    能：释放树的存储空间
 *输    出：无
 *后置条件：树不存在
 */
template<class T>
void Tree<T>::Release(Node<T>* node)   //析构函数调用
{
    if (node != NULL)
    {
        Release(node->getFirstChild( ));   //释放第一个孩子的存储空间
        Release(node->getBrother( ));   //释放右兄弟的存储空间
        delete node;
    }
}
/*
 *前置条件：树已存在
 *输    入：数据信息data
 *功    能：查找数据域的值是data的结点
 *输    出：指向要查询结点的指针
 *后置条件：树保持不变
 */
template<class T>
Node<T>* Tree<T>::FindNode(T* data)
{
    int front = 0;
    int rear  = 0;  //采用顺序队列，并假定不会发生上溢
    
    Node<T>* queue[MAX_QUEUE_SIZE]; //声明一个队列
    Node<T>* tempNode = NULL;      //声明指向结点类型的指针
    Node<T>* brotherNode = NULL;   //工作指针
    
    if (_root == NULL) return NULL;//空树，返回
    queue[rear++] = _root;//否则根结点指针入队
    while (front != rear)    //若队列中有元素
    {
        tempNode = queue[front++];//头元素出队，同时对头元素的标识符后移
        if (*data == *(tempNode->getData( ))) //判断出队元素所指结点是否为要查询的结点，若是
            return tempNode;              //输出该结点
        brotherNode = tempNode->getFirstChild( );
        while (brotherNode != NULL) //判断其孩子结点
        {
            queue[rear++] = brotherNode;
            brotherNode = brotherNode->getBrother( );
        }
    }
    return NULL;   //树中没有要查询的结点则返回空
}
/*
 *前置条件：树已存在
 *输    入: 结点node,数据信息data
 *功    能: 将数据域值为data的结点插入到node的兄弟结点中
 *输    出: 无
 *后置条件:如果插入成功,得到一棵新树
 */
template<class T>
void Tree<T>::InsertBrother(Node<T>* node,T* data)     //在结点node插入兄弟节点
{
    Node<T>* newNode = new Node<T>(data);      //动态生成一个新结点
    if (node->getBrother( ) == NULL)   //若node的右兄弟结点为空
        node->setBrother(newNode);    //将新结点设置为其右兄弟结点
    else{                              //若其右兄弟结点不为空
        Node<T>* lastBrother = node->getBrother( ); //设置工作指针指向其右兄弟
        while (lastBrother->getBrother( ) != NULL) //直到找到其最后一个兄弟
        {
            lastBrother = lastBrother->getBrother( ); 
        }
        lastBrother->setBrother(newNode); //将新结点设置为最后一个兄弟的右兄弟
    }
}
/*
 *前置条件：树已存在
 *输    入: 结点node,数据信息data
 *功    能: 将数据域值为data的结点插入到node的第一个孩子中
 *输    出: 无
 *后置条件:如果插入成功,得到一棵新树
 */
template<class T>
void Tree<T>::InsertChild(Node<T>* node, T* data) 
{
    Node<T>* newNode = new Node<T>(data); //动态生成一个新结点
    if (node->getFirstChild() == NULL)    //若node的没有孩子结点
        node->setFirstChild(newNode);     //将新结点设置为其第一个孩子结点
    else                                  //若node有孩子结点
        InsertBrother(node->getFirstChild(), data);//则将新结点插入到其第一个孩子结点的兄弟结点中
}
