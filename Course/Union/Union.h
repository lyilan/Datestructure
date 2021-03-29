#ifndef UNION_H
#define UNION_H

#include <stdio.h>
#include <stdlib.h>
#include "../SqList/SqList.h"

void Union(SqList &La, SqList Lb);          //将所有在线性表Lb中但不在La中的数据元素插入到La中
Status equal(ElemType e1, ElemType e2);     //判断e1 和 e2 是否相等，相等返回TRUE，不想等返回FALSE

#endif