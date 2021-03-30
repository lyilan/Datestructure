#ifndef SLINKLIST_H
#define DLINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../../Status/Status.h"

#define MAXSIZE 1000 //链表最大长度

typedef int ElemType;
typedef struct
{ //定义静态链表结构
    ElemType data;
    int cur; //指针
} component, SLinkList[MAXSIZE];


//用户需要自己实验 malloc 和 free 
void InitSpace(SLinkList &space); //将整个数组空间初始化为一个静态链表

void Malloc(SLinkList &space);//从备用空间取一个结点

void Free(SLinkList &space);//

//静态链表的操作

Status InitList(SLinkList &L);       //单链表初始化

Status DestroyList(SLinkList &L);    //单链表销毁

Status ClearList(SLinkList &L);      //单链表清空

Status ListEmpty(SLinkList L);       //判断链表是否为空

Status ListLength(SLinkList L);      //返回链表所含有效数据的数量

Status GetELem(SLinkList L, int i, ElemType &e); //获取链表第i个元素

int LocateElem(SLinkList L, ElemType e, Status (*compare)(ElemType, ElemType));  //返回链表中首个与e满足compare()关系的元素位序

Status PriorElem(SLinkList L, ElemType cur_e, ElemType pre_e);   //获取cur_e元素前驱

Status NextElem(SLinkList L, ElemType cur_e, ElemType next_e);   //获取cur_e元素后继

Status ListInsert(SLinkList &L, int i, ElemType e);      //向链表第i个位置前插入e

Status ListDelete(SLinkList &L, int i, ElemType &e);     //删除链表第i个元素，并将删除元素存储到e中

void ListTraverse(SLinkList L, void(Visit)(ElemType));   //用visit()遍历整个链表
#endif