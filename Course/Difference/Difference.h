/*
 * @Author: lyilan
 * @Date: 2021-03-31 13:54:14
 * @Description: 算法   2.16
 */
#ifndef DIFFERENCE_H
#define DIFFERENCE_H

#include <stdio.h>
#include <stdlib.h>
#include "../../Status/Status.h"    //提供状态码
#include "../SLinkList/SLinkList.h" //提供静态链表

void difference(SLinkList &space, int &S)
{
    int m, n;
    scanf("%d %d", &m, &n);

    CreatListH(space, S, m);

    ElemType e;
    int cur;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &e);
        if (cur = LocateElem(space, S, e, equal))
            ListDelete(space, S, cur, e);
    }
}

Status equal(ElemType e1, ElemType e2); //判断e1和e2是否相等，如果相等返回OK，否则返回ERROR

#endif