/*
 * @Author: lyilan
 * @Date: 2021-03-30 20:44:46
 * @Description: for my ying~
 */
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

int Malloc(SLinkList &space); //从备用空间取一个结点

void Free(SLinkList &space, int k); //将下标为K的空闲结点回收到备用链表

//静态链表的操作

Status InitList(SLinkList space, int &S); //单链表初始化

Status DestroyList(SLinkList space, int &S); //单链表销毁

Status ClearList(SLinkList space, int &S); //单链表清空

Status ListEmpty(SLinkList space, int S); //判断链表是否为空

int ListLength(SLinkList space, int S); //返回链表所含有效数据的数量

Status GetELem(SLinkList space, int S, int i, ElemType &e); //获取链表第i个元素

int LocateElem(SLinkList space, int S, ElemType e, Status (*compare)(ElemType, ElemType)); //返回链表中首个与e满足compare()关系的元素位序

Status PriorElem(SLinkList space, int S, ElemType cur_e, ElemType &pre_e); //获取cur_e元素前驱

Status NextElem(SLinkList space, int S, ElemType cur_e, ElemType &next_e); //获取cur_e元素后继

Status ListInsert(SLinkList space, int &S, int i, ElemType e); //向链表第i个位置前插入e

Status ListDelete(SLinkList space, int &S, int i, ElemType &e); //删除链表第i个元素，并将删除元素存储到e中

void ListTraverse(SLinkList space, int S, void(Visit)(ElemType)); //用visit()遍历整个链表

Status CreatListH(SLinkList space, int &S, int len); //头插法建立链表
#endif