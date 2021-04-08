// - - - - - 基本操作的算法描述 - - - - -

#include "SqQueue.h"

Status InitQueue(SqQueue &Q)
{
    //构造一个空队列
    Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
    if (Q.base == NULL)
        return ERROR;
    Q.front = Q.rear = 0;
    return OK;
}

Status DestroyQueue(SqQueue &Q)
{
    //销毁队列Q，Q不再存在
    if (Q.base == NULL)
        return NULL;
    free(Q.base);
    return OK;
}

Status ClearQueue(SqQueue &Q)
{
    //将Q清为空队列
    if (Q.base == NULL)
        return ERROR;
    Q.front = Q.rear = 0;
    return OK;
}

Status QueueEmpty(SqQueue Q)
{
    //若队列Q为空队列，则返回TRUE，否则返回FALSE
    if (Q.base = NULL)
        return FALSE;
    if (Q.front == Q.rear)
        return TRUE;
}

int QueueLength(SqQueue Q)
{
    //返回Q的元素的个数，即为队列长度
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status GetHead(SqQueue Q, QElemType &e)
{
    //若队列不为空，则用e返回Q的队头元素，并返回OK，否则返回ERROR
    if (Q.base == NULL || Q.front == Q.rear)
        return ERROR;
    e = Q.base[Q.front];
    return OK;
}

Status EnQueue(SqQueue &Q, QElemType e)
{
    //插入元素e为Q的新的队尾元素
    if ((Q.rear + 1) % MAXQSIZE == Q.front)
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e)
{
    //若队列不为空，则删除Q的队头元素，用e返回其值，并返回OK；
    //否则返回ERROR
    if (Q.front == Q.rear)
        return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}

Status QueueTraverse(SqQueue Q, void (*visit)(QElemType))
{
    //从队头到队尾依次对队列Q的每个元素调用visit()。一旦visit()失败，则操作失败
    if (Q.rear == Q.front)
        return ERROR;
}
void visit(QElemType e);