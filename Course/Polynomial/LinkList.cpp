/*
 * @Author: lyilan
 * @Date: 2021-04-01 01:55:45
 * @Description: for my ying~
 */
#include "LinkList.h"

//内存操作——————————————————————————————————————————————————————————————————————————————
Status MakeNode(Link &p, ElemType e) //分配由p指向的值为e的结点，并返回OK，若分配失败，则返回ERROR
{
    p = (Link)malloc(sizeof(LNode));
    if (p == NULL)
        return ERROR;
    p->data = e;
    p->next = NULL;
    return OK;
}

Status FreeNode(Link &p) //释放p所指结点
{
    if (p == NULL)
        return ERROR;
    free(p);
    p = NULL;
    return OK;
}

//链表常规操作———————————————————————————————————————————————————————————————————————————

Status InitList(LinkList &L) //初始化
{
    if (L == NULL)
        return ERROR;
    Link p = (Link)malloc(sizeof(LNode));
    if (p == NULL)
        return ERROR;
    p->next = NULL;
    L->Head = L->Tail = p;
    L->leng = 0;
    return ERROR;
}

Status DestroyList(LinkList &L)
{
    if (L == NULL || L->Head == NULL)
        return ERROR;
    ClearList(L);
    free(L->Head);
    L->Head = NULL;
    return OK;
}

Status ClearList(LinkList &L) //清空
{
    if (ListLength == 0)
        return ERROR;
    Position h = GetHead(L);
    Position p;
    while (NextPos(L, h))
    {
        p = NextPos(L, h);
        InsFirst(h, NextPos(L, p));
        FreeNode(p);
    }
    L->Tail = L->Head;
    L->leng = 0;
    return OK;
}

int ListLength(LinkList L) //返回链表长度
{
    return L->leng;
}

int LocateElem(LinkList L, ElemType e, Position &q, int (*compare)(ElemType, ElemType)) //查找链表首个与e满足compare()==0关系的元素位置,若存在，用q返回其引用，若不存在，返回首个与e满足compare()>0元素的前驱
{                                                                                       //若链表元素均大于e，则返回头结点引用
    if (L == NULL || L->Head == NULL)                                                   //若链表元素均小于e，则返回尾结点引用
    {                                                                                   //其他情形将q置空
        q = NULL;
        return ERROR;
    }
    Link p = L->Head;
    while (p->next && compare(p->next->data, e) < 0)
    {
        p = p->next;
    }
    if (compare(p->next->data, e) == 0)
    {
        q = p->next;
        return OK;
    }
    else
    {
        q = p;
        return ERROR;
    }
}

ElemType GetCurElem(Link p) //获取结点p的元素值
{
    ElemType e;
    if (p == NULL)
    {
        e.coef = 0.0f;
        e.expn = -1;
        return e;
    }
    else
        return p->data;
}

Status SetCurElem(Link &p, ElemType e) //为结点p设置元素值
{
    if (p == NULL)
        return ERROR;
    p->data = e;
    return OK;
}

Position GetHead(LinkList L) //获取头结点引用
{
    return L->Head;
}

Position NextPos(LinkList L, Link p) //获取p结点的后继
{
    if (L->Head == NULL || p->next)
        return ERROR;
    return p->next;
}

Status Insfirst(LinkList &L, Link h, Link s) //h指向L的某个结点，将s插入在h之后；
{
    if (L == NULL || L->Head == NULL || h == NULL || s == NULL)
        return ERROR;
    s->next = h->next;
    h->next = s;
    if (h == L->Tail)
    {
        L->Tail = h->next;
    }
    L->leng++;
    return OK;
}

Status DelFirst(LinkList &L, Link h, Link &s) //h指向L的某个结点，删除h后第一个结点，并以s返回
{
    if (L == NULL || L->Head == NULL || h == NULL)
        ;
}
Status Append(LinkList &L, Link s); //将s所指的一串结点链接到L最后一个结点
