/*
 * @Author: lyilan
 * @Date: 2021-03-31 16:21:54
 * @Description: for my ying~
 */

#include "DulLinkList.h"

Status InitList(DulLinkList &L) //初始化链表
{
    L = (DulLinkList)malloc(sizeof(DulNode));
    if (!L)
        exit(OVERFLOW);

    L->data = 0;
    L->next = L->prior = L;

    return OK;
}

Status DestroyList(DulLinkList &L) //销毁链表
{
    if (!L)
        return ERROR;

    ClearList(L);

    free(L);
    L = NULL;

    return OK;
}
Status ClearList(DulLinkList &L) //清空链表
{
    if (!L)
        return ERROR;

    DulLinkList p = L->next, q;

    while (p != L)
    {
        q = L->next;
        free(p);
        p = q;
    }

    L->next = L->prior = L;

    return OK;
}

Status ListEmpty(DulLinkList L) //判断链表是否为空；
{
    if (!L)
        return ERROR;
    return (L->next == L && L->prior == L) ? TRUE : FALSE;
}

int ListLength(DulLinkList L) //返回链表长度
{
    if (!L)
        return 0;

    DulLinkList p = L->next;
    int len = 0;

    while (p != L)
    {
        len++;
        p = p->next;
    }

    return len;
}

Status GetElem(DulLinkList L, int i, ElemType &e) //用e返回链表第i个元素
{
    if (!L || L->next == L || L->prior == L)
        return ERROR;

    int j = 1;
    DulLinkList p = L->next;

    while (p != L && j < i)
    {
        p = p->next;
    }

    if (p == L)
        return ERROR;
    e = p->data;

    return OK;
}

int LocateElem(DulLinkList &L, ElemType e, Status (*compare)(ElemType, ElemType)) //返回链表中首个与e满足关系compare()的元素位置
{
    if (!L || L->next == L || L->prior == L)
        return 0;

    DulLinkList p = L->next;
    int i = 1;
    while (p != L && !compare(e, p->data))
    {
        i++;
        p = p->next;
    }
    if (p == L)
        return 0;
    return i;
}

Status PriorElem(DulLinkList L, ElemType cur_e, ElemType &pre_e) //返回cur_e元素的前驱
{
    if (!L || L->next == L || L->prior == L)
        return ERROR;

    DulLinkList p = L->next;
    while (p != L && cur_e != p->data)
    {
        p = p->next;
    }
    if (p == L || p->prior == L)
        return ERROR;
    pre_e = p->prior->data;
    return OK;
}

Status NextElem(DulLinkList L, ElemType cur_e, ElemType &next_e) //返回 cur_e元素的后继
{
    if (!L || L->next == L || L->prior == L)
        return ERROR;
    DulLinkList p = L->next;
    while (p != L && cur_e != p->data)
    {
        p = p->next;
    }
    if (p == L || p->next == L)
        return ERROR;
    next_e = p->next->data;
    return OK;
}
Status ListInsert(DulLinkList &L, int i, ElemType e) //在链表第i个元素前插入e
{
    if (!L)
        return ERROR;
    DulLinkList p = L;
    int j = 1;
    while (j < i && p != L)
    {
        j++;
        p = p->next;
    }
    DulLinkList s = (DulLinkList)malloc(sizeof(DulNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    s->prior = p;
    s->next->prior = s;
    return OK;
}

Status ListDelete(DulLinkList &L, int i, ElemType &e) //删除链表第i个元素，并用e返回
{
    if (!L || L->next == L || L->prior == L)
        return ERROR;
    DulLinkList p = L, q;
    int j = 1;

    while (j < i && p->next != L)
    {
        j++;
        p = p->next;
    }

    q = L->next;
    p->next = q->next;
    free(q);

    return OK;
}

Status ListTraverse(DulLinkList L, Status (*visit)(ElemType)) //用visit()遍历链表所有元素
{
    if (!L || L->next == L || L->prior == L)
        return ERROR;

    DulLinkList p = L->next;
    while (p != L)
    {
        visit(p->data);
    }

    return OK;
}