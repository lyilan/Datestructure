#include "SqList.h"

Status InitList_Sq (SqList &L){
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L.elem) exit(OVERFLOW);         //存储分配失败
    L.length = 0;                       //空表长度为0
    L.listsize = LIST_INIT_SIZE;        //初始存储容量
    return OK;
}

Status ListInsert_Sq(SqList &L, int i, ElemType e){
    if(i < 1 || i > L.length + 1) return ERROR; //i的合法值为[1, L.length + 1]，若i值不合法，输出ERROR
    if(L.length >= L.listsize){                 //当前存储空间已满，增加分配
        ElemType * newbase = (ElemType *)malloc((L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if(!newbase) exit(OVERFLOW);            //存储分配失败
        L.elem = newbase;                       //新基址
        L.listsize += LISTINCREMENT;            //增加存储容量
    }
    for(int j = i - 1; j < L.length; j++){      //插入位置及之后的元素右移
        L.elem[j + 1] = L.elem[j];      
    }
    L.elem[i - 1] = e;                          //插入e
    L.length++;                                 //表长增1
    return OK;
}

Status ListDelete_Sq(SqList &L, int i, ElemType &e){
    if(i < 1 || i > L.length) return ERROR;     //i的合法值为[1, L.length]，若i值不合法，输出ERROR
    e = L.elem[i -1];                           //被删除元素赋值给e
    for(int j = i - 1; j < L.length -1; j++){   //删除位置之后的元素左移
        L.elem[j] = L.elem[j + 1];              
    }                                           
    L.length--;                                 //表长减1
    return OK;
}

int LocateElem_Sq(SqList &L, ElemType e, Status (*compare)(ElemType, ElemType)){
    int i = 1;                                  //i的初值为第一个元素的位序
    while(i <= L.length && (*compare)(L.elem[i-1], e)) i++;    
    if(i <= L.length) return i;
    else return 0;
}

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc){
    int pa = 0, pb = 0, pc = 0;                             //定义pa，pb，pc分别为La，Lb，Lc的起始位置
    Lc.listsize = La.length + Lb.length;
    Lc.length = Lc.listsize;
    Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
    if(!Lc.elem) exit(OVERFLOW);                            //存储分配失败
    while(pa < La.length && pb < Lb.length){                //归并
        if(La.elem[pa] < Lb.elem[pb]) Lc.elem[pc++] = La.elem[pa++];
        else Lc.elem[pc++] = Lb.elem[pb++];
    }
    while(pa < La.length) Lc.elem[pc++] = La.elem[pa++];    //插入La的剩余元素
    while(pb < Lb.length) Lc.elem[pc++] = Lb.elem[pb++];    //插入Lb的剩余元素
}