#include "SLinkList.h"

//用户需要自己实验 malloc 和 free
void InitSpace(SLinkList space) //将整个数组空间初始化为一个静态链表
{
    for (int i = 0; i < MAXSIZE - 1; i++)
        space[i].cur = i + 1;
    space[MAXSIZE - 1].cur = 0; //0表示空指针
}

int Malloc(SLinkList space) //从备用空间取一个结点
{
    int i = space[0].cur;
    if (i)
        space[0].cur = space[i].cur; //如果备用空间非空，返回结点下标，否则返回0
    return i;
}

void Free(SLinkList space, int k) //将下标为K的空闲结点回收到备用链表
{                                 //头插法插入空闲链表
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

//静态链表的操作
Status InitList(SLinkList space, int &S) //单链表初始化，成功则用S存储头结点索引并返回OK，否则返回ERROR
{
    InitSpace(space);          //初始化备用空间
    int index = Malloc(space); //申请头结点空间
    if (!index)
        return ERROR;
    space[index].cur = 0;
    S = index;
    return OK;
}

Status DestroyList(SLinkList space, int &S) //单链表销毁
{
    if (S == NULL || S == 0)
        return ERROR;
    int cur;
    while (!S)
    {
        cur = space[S].cur; //暂存下一个结点的索引；
        Free(space, S);     //回收当前结点所占的空间
        S = cur;            //前进到下一个结点的索引处
    }
    return 0;
}

Status ClearList(SLinkList space, int &S) //单链表清空
{
    if (S == 0)
        return ERROR;
    int cur;
    while (space[S].cur)
    {
        cur = space[S].cur;
        space[S].cur = space[cur].cur;
        Free(space, cur);
    }
    return OK;
}
Status ListEmpty(SLinkList space, int S) //判断链表是否为空
{
    if (S && !space[S].cur)
        return TRUE; //只存在头结点的静态链表被视为空表
    else
        return ERROR;
}
int ListLength(SLinkList space, int S) //返回链表所含有效数据的数量
{
    if (!S)
        return 0;
    int p = space[S].cur, length = 0;
    while (p)
    {
        p = space[p].cur;
        length++;
    }
    return length;
}

Status GetELem(SLinkList space, int S, int i, ElemType &e) //获取链表第i个元素
{
    if (!S)
        return ERROR;
    int p = S, j;
    for (j = 0; j < i && p; i++)
        p = space[S].cur;
    if (!p)
        return ERROR;
    e = space[p].data;
    return OK;
}

int LocateElem(SLinkList space, int S, ElemType e, Status (*compare)(ElemType, ElemType)) //返回链表中首个与e满足compare()关系的元素位序
{
    if (!S)
        return 0;
    int p = space[S].cur, i = 1;
    while (p && !compare(e, space[p].data))
    {
        p = space[p].cur;
        i++;
    }
    if (!p)
        return 0;
    return i;
}
Status PriorElem(SLinkList space, int S, ElemType cur_e, ElemType &pre_e) //获取cur_e元素前驱
{
    if (!S || !space[S].cur)
        return ERROR; //确保链表存在且不为空

    int pre = space[S].cur;
    if (space[pre].data == cur_e)
        return ERROR; //第一个元素没有前驱
    int next = space[pre].cur;
    while (next && space[next].data != cur_e)
    {
        pre = next;
        next = space[next].cur;
    }
    if (!next)
        return ERROR;
    pre_e = space[pre].data;
    return OK;
}
Status NextElem(SLinkList space, int S, ElemType cur_e, ElemType &next_e) //获取cur_e元素后继
{
    if (!S || !space[S].cur)
        return ERROR;
    int p = space[S].cur;
    int next = space[p].data;
    while (next && space[p].data != cur_e)
    {
        p = next;
        next = space[next].cur;
    }
    if (!next)
        return ERROR;
    next_e = space[next_e].data;
    return OK;
}

Status ListInsert(SLinkList space, int &S, int i, ElemType e) //向链表第i个位置前插入e
{
    if (!S)
        return ERROR;
    int pre = S;
    for (int j = 1; j < i && pre; j++)
        pre = space[pre].cur;
    if (!pre)
        return ERROR;
    int s = Malloc(space);
    space[s].cur = space[pre].cur;
    space[pre].cur = s;
    space[s].data = e;
    return OK;
}

Status ListDelete(SLinkList space, int &S, int i, ElemType &e) //删除链表第i个元素，并将删除元素存储到e中{
{
    if (!S || !space[S].cur)
        return ERROR;
    int pre = S, p = space[S].cur;
    for (int j = 1; j < i && p; j++)
    {
        pre = p;
        p = space[p].cur;
    }
    if (!p)
        return ERROR;
    e = space[p].data;
    space[pre].cur = space[p].cur;
    Free(space, p);
    return OK;
}

void ListTraverse(SLinkList space, int &S, void(Visit)(ElemType)) //用visit()遍历整个链表
{
    if (!S || !space[S].cur)
        return;
    int p = space[S].cur;
    while (p)
    {
        Visit(space[p].data);
        p = space[p].cur;
    }
    return;
}

Status CreatListH(SLinkList space, int &S, int len) //头插法建立链表
{
    if (!InitList(space, S))
        return ERROR; //如果初始化失败，返回ERROR；

    for (int i = 0; i < len; i++) //插入len个结点
    {
        int s = Malloc(space); //申请结点空间
        if (!s)
            return ERROR; //申请失败，返回ERROR

        scanf("%d", &space[s].data); //输入结点数据

        space[s].cur = space[S].cur; //头插法插入结点s
        space[S].cur = s;
    }
    return OK;
}