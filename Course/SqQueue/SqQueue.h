// - - - - - 循环队列————队列的顺序存储结构 - - - - -

#include "../../Status/Status.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXQSIZE 100 //最大队列长度
typedef int QElemType;
typedef struct
{
    QElemType *base; //初始化的动态分配存储空间
    int front;       //头指针，若队列不空，指向队列头元素
    int rear;        //尾指针，若队列不空，指向队列队尾元素的下一位置
} SqQueue;

// - - - - - 循环队列的基本操作的函数原型说明 - - - - -

Status InitQueue(SqQueue &Q);
//构造一个空队列
Status DestroyQueue(SqQueue &Q);
//销毁队列Q，Q不再存在
Status ClearQueue(SqQueue &Q);
//将Q清为空队列
Status QueueEmpty(SqQueue Q);
//若队列Q为空队列，则返回TRUE，否则返回FALSE
int QueueLength(SqQueue Q);
//返回Q的元素的个数，即为队列长度
Status GetHead(SqQueue Q, QElemType &e);
//若队列不为空，则用e返回Q的队头元素，并返回OK，否则返回ERROR
Status EnQueue(SqQueue &Q, QElemType e);
//插入元素e为Q的新的队尾元素
Status DeQueue(SqQueue &Q, QElemType &e);
//若队列不为空，则删除Q的队头元素，用e返回其值，并返回OK；
//否则返回ERROR
Status QueueTraverse(SqQueue Q, void (*visit)(QElemType));
//从队头到队尾依次对队列Q的每个元素调用visit()。一旦visit()失败，则操作失败
void visit(QElemType e);
