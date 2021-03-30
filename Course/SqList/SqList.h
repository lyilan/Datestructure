#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../../Status/Status.h"

#define LIST_INIT_SIZE 100 // 顺序表存储空间的初始分配量
#define LISTINCREMENT 10   // 顺序表存储空间的分配增量

typedef int ElemType; //顺序表元素类型定义

typedef struct //顺序表结构
{
    ElemType *elem; //存储空间基址
    int length;     //当前长度
    int listsize;   //当前分配的存储容量（以sizeof（ElemType）为单位）
} SqList;

Status InitList_Sq(SqList &L); //构造一个空的线性表L

Status DestroyList_Sq(SqList &L); //销毁线性表L

Status ClearList_Sq(SqList &L); //将L重置为空表

Status ListEmpty_Sq(SqList L); //若L为空表，则返回TRUE，否则返回FALSE

Status ListLength_Sq(SqList L); //返回L中数据元素个数

Status GetElem_Sq(SqList L, int i, ElemType &e); //用e返回L中第i个元素的值

Status PriorElem_Sq(SqList L, ElemType cur_e, //若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱
                    ElemType &pre_e);         //否则操作失败，pre_e无定义

Status NextElem_Sq(SqList L, ElemType cur_e, //若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的后继
                   ElemType &next_e);        //否则操作失败，pre_e无定义

Status ListInsert_Sq(SqList &L, int i, ElemType e); //在顺序线性表L中第i个位置之前插入新的元素e

Status ListDelete_Sq(SqList &L, int i, ElemType &e); //在顺序线性表L中删除第i个元素，并用e返回其值

int LocateElem_Sq(SqList &L, ElemType e,                  //在顺序线性表中查找第1个值与e满足compare()的元素的位序
                  Status (*compare)(ElemType, ElemType)); //若找到，则返回其在L中的位序，否则返回0

void MergeList_Sq(SqList La, SqList Lb, SqList Lc); //已知顺序线性表La和Lb的元素按值非递减排列
                                                    //归并La和Lb得到的新的顺序线性表Lc，Lc的元素也按值非递减排列

void ListTraverse(SqList L, void(Visit)(ElemType)); //依次对L的每个元素调用函数Visit()，一旦调用失败，则操作失败
#endif