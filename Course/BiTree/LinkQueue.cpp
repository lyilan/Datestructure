/*
 * @Author: lyilan
 * @Date: 2021-04-07 09:43:34
 * @Description: for my ying~
 */
#include "LinkQueue.h"

Status InitQueue(LinkQueue &Q)
{
    //初始化队列
    Q.front = (QueuePtr)malloc(sizeof(QNode));

    if (Q.front == NULL)
        exit(OVERFLOW); //结点存储空间分配失败

    Q.rear = Q.front;

    Q.front->next = NULL;

    return OK;
}

Status QueueEmpty(LinkQueue Q)
{
    //队列为空返回TRUE，否则返回ERROR
    if (Q.front != NULL && Q.front == Q.rear)
        return TRUE;
    else
        return ERROR;
}

Status EnQueue(LinkQueue &Q, QElemType e)
{
    //将元素e添加到队尾
    if (Q.front == NULL)
        return ERROR;

    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if (s == NULL)
        return ERROR;

    s->data = e;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;

    return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e)
{
    //删除队头元素，并用e返回
    if (Q.front == NULL && QueueEmpty(Q))
        return ERROR;

    QueuePtr p = Q.front->next;
    Q.front->next = p->next;

    e = p->data;
    if (p == Q.rear)
        Q.rear = Q.front;
    free(p);
    return OK;
}