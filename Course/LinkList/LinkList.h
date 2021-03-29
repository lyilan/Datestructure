#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Status/Status.h"

typedef int ElemType;   //单链表元素类型定义

typedef struct LNode{   //单链表存储结构
    ElemType data;
    struct LNode * next;
} LNode, * LinkList;

Status InitList(LinkList &L);       //单链表初始化

Status DestroyList(LinkList &L);    //单链表销毁

Status ClearList(LinkList &L);      //单链表清空

Status ListEmpty(LinkList L);       //判断链表是否为空

Status ListLength(LinkList L);      //返回链表所含有效数据的数量

Status GetELem(LinkList L, int i, ElemType &e); //获取链表第i个元素

int LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType));  //返回链表中首个与e满足compare()关系的元素位序

Status PriorElem(LinkList L, ElemType cur_e, ElemType pre_e);   //获取cur_e元素前驱

Status NextElem(LinkList L, ElemType cur_e, ElemType next_e);   //获取cur_e元素后继

Status ListInsert(LinkList &L, int i, ElemType e);      //向链表第i个位置前插入e

Status ListDelete(LinkList &L, int i, ElemType &e);     //删除链表第i个元素，并将删除元素存储到e中

void ListTraverse(LinkList L, void(Visit)(ElemType));   //用visit()遍历整个链表

Status CreateList_H(LinkList &L, int n, char * path);   //头插法建立链表

Status CreateList_T(LinkList &L, int n, char * path);   //尾插法建立链表
#endif