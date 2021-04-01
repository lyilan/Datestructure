/*
 * @Author: lyilan
 * @Date: 2021-04-01 01:36:08
 * @Description: for my ying~ 有序单链表
 */
#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../../Status/Status.h"

typedef struct
{
    float coef; //多项式系数
    int expn;   //多项式指数
} ElemType;

typedef struct
{
    ElemType data;
    LNode *next;
} LNode, *Link, *Position;

typedef struct
{
    Link Head, Tail; //非别指向线性链表头结点和尾结点
    int leng;        //链表长度
} * LinkList;

//内存操作——————————————————————————————————————————————————————————————————————————————
Status MakeNode(Link &p, ElemType e); //分配由p指向的值为e的结点，并返回OK，若分配失败，则返回ERROR

Status FreeNode(Link &p); //释放p所指结点

//链表常规操作———————————————————————————————————————————————————————————————————————————

Status InitList(LinkList &L); //构造一个空的线性链表L

Status DestroyList(LinkList &L); //销毁线性链表L，L不再存在

Status ClearList(LinkList &L);

int ListLength(LinkList L); //返回线性链表L中元素的个数

Status LocateElem(LinkList L, ElemType e, Position &q, int (*compare)(ElemType, ElemType));
//若有序链表L中存在与e满足判定函数compare()取值为0的元素，则q指示L中第一个值为e的结点的位置，并返回TRUE，
//否则q指示第一个与e满足判定函数compare()取值>0的元素的前驱位置，并返回FALSE

//链表扩展操作————————————————————————————————————————————————————————————————————————————

ElemType GetCurElem(Link p); //已知p指向线性链表中的一个结点，返回p所指结点中数据元素的值

Status SetCurElem(Link &p, ElemType e); //已知p指向线性链表中的一个结点，用e更新p所指结点中数据元素的值

Position GetHead(LinkList L); //返回线性链表L中头结点的位置

Position NextPos(LinkList L, Link p); //已知p指向线性链表L中的一个结点，返回p所指结点的直接后继的位置

Status InsFirst(Link h, Link s); //已知h指向线性链表的头结点，将s所指结点插入在第一个结点之前

Status DelFirst(Link h, Link &q); //已知h指向线性链表的头结点，删除链表中第一个结点，并以q返回

Status Append(LinkList &L, Link s); //将s所🈯️的一串结点链接到L最后一个结点

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e);

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e);

Status ListInsert(LinkList &L, ElemType e);

Status ListDelete(LinkList &L, ElemType e);

Status ListTraverse(LinkList &L, Status(*visit(ElemType)));

#endif