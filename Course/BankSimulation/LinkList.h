/*
 * @Author: lyilan
 * @Date: 2021-04-12 13:06:24
 * @Description: for my ying~
 */
#ifndef LINKLIST_H
#define LINKLIST_H

#include "Bank.h"
#include "../../Status/Status.h"
#include <stdio.h>
#include <stdlib.h>

struct Event;
typedef Event ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} * Link, *Position;

typedef struct
{
    Link head, tail;
    int len;
} LinkList;

// - - - - - 内部函数声明 - - - - -
Status MakeNode(Link &p, ElemType e);

void FreeNode(Link &p);

// - - - - - 基本操作函数声明 - - - - -

Status InitList(LinkList &L);

Status ListEmpty(LinkList L);

ElemType GetCurElem(Link p);

Position GetHead(LinkList L);

Status DelFirst(Link h, Link &q);

Status OrderInsert(LinkList &L, ElemType e, int (*Compare)(ElemType, ElemType));

#endif