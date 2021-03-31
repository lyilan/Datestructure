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

Status difference(SLinkList &space, int &S); //依次输入集合A和集合B的元素，在一维数组中建立表示（A-B）U（B-A）的静态链表

Status equal(ElemType e1, ElemType e2); //判断e1和e2是否相等，如果相等返回OK，否则返回ERROR

#endif