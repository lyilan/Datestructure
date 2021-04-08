/*
 * @Author: lyilan
 * @Date: 2021-04-07 09:44:04
 * @Description: for my ying~
 */

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include "BiTree.h"
#include "../../Status/Status.h"
#include <stdio.h>
#include <stdlib.h>

struct BiTNode;
typedef BiTNode *BiTree;
typedef BiTree QElemType; //队列元素类型定义

typedef struct QNode //队列元素结构定义
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct //队列结构定义
{
    QueuePtr front; //队头指针，指向的头结点，若队列空，则头结点指针域为空
    QueuePtr rear;  //队尾指针，指向队列中最后一位元素
} LinkQueue;

// - - - - - 队列基本操作函数的原型说明 - - - - -

Status InitQueue(LinkQueue &Q);
//初始化队列
Status QueueEmpty(LinkQueue Q);
//队列为空返回TRUE，否则返回ERROR
Status EnQueue(LinkQueue &Q, QElemType e);
//将元素e添加到队尾
Status DeQueue(LinkQueue &Q, QElemType &e);
//删除队头元素，并用e返回

#endif