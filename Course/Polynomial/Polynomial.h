/*
 * @Author: lyilan
 * @Date: 2021-04-01 01:29:14
 * @Description: for my ying~
 */
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "LinkList.h"

typedef ElemType term;

typedef LinkList polynomial;

int cmp(term e1, term e2); //依指数值分别返回-1，0，1

void CreatPolyn(polynomial &P, int m); //输入m项的系数和指数，建立表示一元多项式的有序链表P

void DestroyPolyn(polynomial &P);

void PrintPolyn(polynomial P);

int PolynLength(polynomial P);

void AddPolyn(polynomial &Pa, polynomial &Pb);

void SubtractPolyn(polynomial &Pa, polynomial &Pb);

void MultiplyPolyn(polynomial &Pa, polynomial &Pb);

#endif