/*
 * @Author: lyilan
 * @Date: 2021-03-31 16:00:36
 * @Description: 双向循环链表
 */

#ifndef DULLINKLIST_H
#define DULLINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../../Status/Status.h"

typedef int ElemType;

typedef struct DulNode //双向链表定义
{
    ElemType data;         //数据
    struct DulNode *prior; //前驱
    struct DulNode *next;  //后继
} DulNode, *DulLinkList;

Status InitList(DulLinkList &L); //初始化链表

Status DestroyList(DulLinkList &L); //销毁链表

Status ClearList(DulLinkList &L); //清空链表

Status ListEmpty(DulLinkList L); //判断链表是否为空；

int ListLength(DulLinkList L); //返回链表长度

Status GetElem(DulLinkList L, int i, ElemType &e); //用e返回链表第i个元素

int LocateElem(DulLinkList &L, ElemType e, Status (*compare)(ElemType, ElemType)); //返回链表中首个与e满足关系compare()的元素位置

Status PriorElem(DulLinkList L, ElemType cur_e, ElemType &pre_e); //返回cur_e元素的前驱

Status NextElem(DulLinkList L, ElemType cur_e, ElemType &next_e); //返回 cur_e元素的后继

Status ListInsert(DulLinkList &L, int i, ElemType e); //在链表第i个元素前插入e

Status ListDelete(DulLinkList &L, int i, ElemType &e); //删除链表第i个元素，并用e返回

Status ListTraverse(DulLinkList L, Status (*visit)(ElemType)); //用visit()遍历链表所有元素
#endif