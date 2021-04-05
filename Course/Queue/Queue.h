/*
 * @Author: lyilan
 * @Date: 2021-04-05 14:16:02
 * @Description: for my ying~
 */

// = = = = ADT Queue 的表示与实现 = = = =

#include <stdio.h>
#include <stdlib.h>
#include "../../Status/Status.h"

// - - - - - 单链队列————队列的链式存储结构 - - - - -

typedef int QElemType;
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

// - - - - - 基本操作的函数原型说明 - - - - -

Status InitQueue(LinkQueue &Q);
//构造一个空队列
Status DestroyQueue(LinkQueue &Q);
//销毁队列Q，Q不再存在
Status ClearQueue(LinkQueue &Q);
//将Q清为空队列
Status QueueEmpty(LinkQueue Q);
//若队列Q为空队列，则返回TRUE，否则返回FALSE
int QueueLength(LinkQueue Q);
//返回Q的元素的个数，即为队列长度
Status GetHead(LinkQueue Q, QElemType &e);
//若队列不为空，则用e返回Q的队头元素，并返回OK，否则返回ERROR
Status EnQueue(LinkQueue &Q, QElemType e);
//插入元素e为Q的新的队尾元素
Status DeQueue(LinkQueue &Q, QElemType &e);
//若队列不为空，则删除Q的队头元素，用e返回其值，并返回OK；
//否则返回ERROR
Status QueueTraverse(LinkQueue Q, void (*visit)(QElemType));
//从队头到队尾依次对队列Q的每个元素调用visit()。一旦visit()失败，则操作失败
void visit(QElemType e);