/*
 * @Author: lyilan
 * @Date: 2021-04-05 14:28:27
 * @Description: for my ying~
 */
#include "Queue.h"

// - - - - - 基本操作的算法描述 - - - - -
Status InitQueue(LinkQueue &Q)
{
    //构造一个空队列
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (Q.front == NULL)
        exit(OVERFLOW); //存储分配失败
    Q.front->next = NULL;
    return OK;
}

Status DestroyQueue(LinkQueue &Q)
{
    //销毁队列Q，Q不再存在
    while (Q.front != NULL)
    {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return OK;
}
Status ClearQueue(LinkQueue &Q)
{
    //将Q清为空队列
    while (Q.front->next != NULL)
    {
        Q.rear = Q.front;
        free(Q.front);
        Q.front = Q.rear;
    }
    return OK;
}

Status QueueEmpty(LinkQueue Q)
{
    //若队列Q为空队列，则返回TRUE，否则返回FALSE
    if (Q.front == NULL)
        return FALSE; //队列不存在
    if (Q.front->next == NULL)
        return TRUE;
}

int QueueLength(LinkQueue Q)
{
    //返回Q的元素的个数，即为队列长度
    int length = 0;
    if (Q.front == NULL)
        return length;
    while (Q.front != Q.rear)
    {
        Q.front = Q.front->next;
        length++;
    }
    return length;
}

Status GetHead(LinkQueue Q, QElemType &e)
{
    //若队列不为空，则用e返回Q的队头元素，并返回OK，否则返回ERROR
    if (Q.front == NULL)
        return ERROR;
    else
    {
        e = Q.front->next->data;
        return TRUE;
    }
}

Status EnQueue(LinkQueue &Q, QElemType e)
{
    //插入元素e为Q的新的队尾元素
    QNode *p = (QueuePtr)malloc(sizeof(QNode));
    if (p == NULL)
        exit(OVERFLOW); //存储分配失败
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e)
{
    //若队列不为空，则删除Q的队头元素，用e返回其值，并返回OK；
    //否则返回ERROR
    if (Q.front == Q.rear)
        return ERROR;
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return OK;
}

Status QueueTraverse(LinkQueue Q, void (*visit)(QElemType))
{
    if (Q.front == Q.rear)
        return ERROR;
    while (Q.front != Q.rear)
    {
        Q.front = Q.front->next;
        visit(Q.front->data);
    }
    printf("\n");
    return OK;
}

void visit(QElemType e)
{
    printf("%4d", e);
}