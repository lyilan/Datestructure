/*
 * @Author: lyilan
 * @Date: 2021-04-12 13:19:01
 * @Description: for my ying~
 */

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include "Bank.h"
#include <stdio.h>
#include <stdlib.h>

struct QElemType;
typedef struct QNode
{
    QElemType data;
    struct QueueNode *next;
} QNode, QueuePtr;
typedef struct LinkQueue
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

// - - - - - 队列基本操作函数的声明 - - - - -

Status InitQueue(LinkQueue Q);

Status EnQueue(LinkQueue Q, QElemType e);

Status DelQueue(LinkQueue Q, QElemType &e);

Status QueueEmpty(LinkQueue Q);

int QueueLength(LinkQueue Q);

Status GetHead(LinkQueue Q, QElemType e);

#endif
