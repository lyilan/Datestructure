/*
 * @Author: lyilan
 * @Date: 2021-04-01 16:37:48
 * @Description: for my ying~
 */

#ifndef SQSTACK_H
#define SQSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include "../../Status/Status.h"

//————————————栈的顺序存储表示————————————//

#define STACK_INIT_SIZE 100 //存储空间初始分配量
#define STACKINCREMENT 10   //存储空间分配增量

typedef char SElemType;
typedef struct
{
    SElemType *base; //在栈构造之前和销毁之后，base的值为NULL
    SElemType *top;  //栈顶指针
    int stacksize;   //当前已分配的存储空间，以元素为单位
} SqStack;

//————————————基本操作的函数原型说明————————————//

Status InitStack(SqStack &S);
//构造一个空栈S
Status DestroyStack(SqStack &S);
//销毁栈S，S不再存在
Status ClearStack(SqStack &S);
//把S置为空栈
Status StackEmpty(SqStack S);
//若栈S为空栈，则返回TRUE，否则返回FALSE
int StackLength(SqStack S);
//返回S的元素个数，即栈的长度
Status GetTop(SqStack S, SElemType &e);
//若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR
Status Push(SqStack &S, SElemType e);
//插入元素e为栈顶元素
Status Pop(SqStack &S, SElemType &e);
//若栈不空，则删除S的栈顶元素，并返回OK，额否则返回ERROR
Status StackTraverse(SqStack S, Status(*visit()));
//从栈底到栈顶依次对栈中每个元素调用函数visit()。一旦visit()失败，则操作失败

#endif
