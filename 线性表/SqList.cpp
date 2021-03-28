//线性表的动态分配顺序存储结构

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;
typedef int Status;
typedef struct{
    ElemType * elem;
    int length;
    int listsize;
}SqList;

//构造一个空的线性表L
Status InitList_Sq(SqList &L){
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

//在顺序线性表L中第i个位置之前插入新的元素e
Status ListInsert_Sq(SqList &L, int i, ElemType e){
    if(i <= 0 || i > L.length + 1) return ERROR;
    if(L.length == L.listsize){
        ElemType * newbase = (ElemType * )realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if(!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listsize +=LISTINCREMENT;
    }
    for(int j = L.length; j >= i; j--) L.elem[j] = L.elem[j-1];
    L.elem[i - 1] = e;
    L.length++;
    return OK; 
}

//在顺序表L中删除第i个位置，并用e返回其值
Status ListDelete_Sq(SqList &L, int i, ElemType &e){
    if(i < 1 || i > L.length) return ERROR;
    e = L.elem[i-1];
    for(int j = i; j <= L.length; j++) L.elem[j-1] = L.elem[j];
    L.length--;
    return OK;
}

//在顺序线性表L中查找第1个值与e满足compare()的元素的位序
int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType)){
    int i = 1;
    while(i < L.length && !(*compare)(L.elem[i], e)) i++;
    if(i<L.length) return i;
    else return 0;
}

//已知顺序线性表La和Lb的元素按值非递减排列
//归并La和Lb得到的新的顺序表Lc，Lc的元素也按值非递减排列
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc){
    Lc.listsize = La.length + Lb.length;
    Lc.length = Lc.listsize;
    Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
    if(!Lc.elem) exit(OVERFLOW);
    
    int i = 0, j = 0, k = 0;
    while(i < La.listsize && j < Lb.listsize){
        if(La.elem[i] < Lb.elem[j]) Lc.elem[k++] = La.elem[i++];
        else Lc.elem[k++] = Lc.elem[j++];
    }
    while(i < La.listsize) Lc.elem[k++] = La.elem[i++];
    while(i < Lb.listsize) Lc.elem[k++] = Lc.elem[j++];
    return;
}

int main(){
    printf("Hello, world");
    return 0;
}
