#include "SqList.h"

Status InitList_Sq(SqList &L)
{ //构造一个空的线性表L
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        exit(OVERFLOW);          //存储分配失败
    L.length = 0;                //空表长度为0
    L.listsize = LIST_INIT_SIZE; //初始存储容量
    return OK;
}

Status DestroyList_Sq(SqList &L)
{ //销毁线性表L
    if (L.elem == NULL)
        return ERROR; //确保顺序表存在
    free(L.elem);     //释放顺序表内存
    L.elem = NULL;    //释放内存后置空指针
    L.length = 0;
    L.listsize = 0; //顺序表长度和容量归零
    return OK;
}

Status ClearList_Sq(SqList &L)
{ //将L重置为空表
    if (L.elem == NULL)
        return ERROR;
    L.length = 0;
    return OK;
}

Status ListEmpty_Sq(SqList L)
{ //若L为空表，则返回TRUE，否则返回FALSE
    return L.length == 0 ? TRUE : FALSE;
}

Status ListLength_Sq(SqList L)
{ //返回L中数据元素个数
    return L.length;
}

Status GetElem_Sq(SqList L, int i, ElemType &e)
{ //用e返回L中第i个元素的值
    if (i < 1 || i > L.length)
        return ERROR;
    else
        e = L.elem[i - 1];
    return OK;
}

int LocateElem_Sq(SqList &L, ElemType e, Status (*compare)(ElemType, ElemType))
{              //在顺序线性表中查找第1个值与e满足compare()的元素的位序,若找到，则返回其在L中的位序，否则返回0
    int i = 1; //i的初值为第一个元素的位序
    while (i <= L.length && (*compare)(L.elem[i - 1], e))
        i++;
    if (i <= L.length)
        return i;
    else
        return 0;
}

Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType &pre_e)
{ //若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义
    if (L.elem == NULL || L.length < 2)
        return ERROR;
    int i = 2; //从第二个位置开始查找
    while (i <= L.length && L.elem[i - 1] != cur_e)
        i++;
    if (i <= L.length)
        pre_e = L.elem[i - 2];
    else
        return ERROR;
    return OK;
}

Status NextElem_Sq(SqList L, ElemType cur_e, ElemType &next_e)
{ //若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的后继，否则操作失败，pre_e无定义
    if (L.elem == NULL || L.length < 2)
        return ERROR;
    int i = 1; //从对歌位置开始查找
    while (i < L.length && L.elem[i - 1] != cur_e)
        i++;
    if (i < L.length)
        next_e = L.elem[i];
    else
        return ERROR;
    return OK;
}

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{ //在顺序线性表L中第i个位置之前插入新的元素e
    if (i < 1 || i > L.length + 1)
        return ERROR; //i的合法值为[1, L.length + 1]，若i值不合法，输出ERROR
    if (L.length >= L.listsize)
    { //当前存储空间已满，增加分配
        ElemType *newbase = (ElemType *)malloc((L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase)
            exit(OVERFLOW);          //存储分配失败
        L.elem = newbase;            //新基址
        L.listsize += LISTINCREMENT; //增加存储容量
    }
    for (int j = i - 1; j < L.length; j++)
    { //插入位置及之后的元素右移
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e; //插入e
    L.length++;        //表长增1
    return OK;
}

Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{ //在顺序线性表L中删除第i个元素，并用e返回其值
    if (i < 1 || i > L.length)
        return ERROR;  //i的合法值为[1, L.length]，若i值不合法，输出ERROR
    e = L.elem[i - 1]; //被删除元素赋值给e
    for (int j = i - 1; j < L.length - 1; j++)
    { //删除位置之后的元素左移
        L.elem[j] = L.elem[j + 1];
    }
    L.length--; //表长减1
    return OK;
}

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc)
{
    int pa = 0, pb = 0, pc = 0; //定义pa，pb，pc分别为La，Lb，Lc的起始位置
    Lc.listsize = La.length + Lb.length;
    Lc.length = Lc.listsize;
    Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
    if (!Lc.elem)
        exit(OVERFLOW); //存储分配失败
    while (pa < La.length && pb < Lb.length)
    { //归并
        if (La.elem[pa] < Lb.elem[pb])
            Lc.elem[pc++] = La.elem[pa++];
        else
            Lc.elem[pc++] = Lb.elem[pb++];
    }
    while (pa < La.length)
        Lc.elem[pc++] = La.elem[pa++]; //插入La的剩余元素
    while (pb < Lb.length)
        Lc.elem[pc++] = Lb.elem[pb++]; //插入Lb的剩余元素
}

void ListTraverse(SqList L, void(Visit)(ElemType))
{ //依次对L的每个数据元素调用visit()
    for (int i = 1; i <= L.length; i++)
    {
        Visit(L.elem[i - 1]);
    }
}