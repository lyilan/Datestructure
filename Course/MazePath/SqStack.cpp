/*
 * @Author: lyilan
 * @Date: 2021-04-01 16:58:49
 * @Description: for my ying~
 */

#include "SqStack.h"

//————————————基本操作的算法描述————————————//

Status InitStack(SqStack &S)
{
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (S.base == NULL)
        exit(OVERFLOW); //存储分配失败
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}
Status DestroyStack(SqStack &S) //销毁栈S，S不再存在
{
    if (S.base == NULL)
        return ERROR;
    free(S.base);
    S.base == NULL;
    return OK;
}

Status ClearStack(SqStack &S) //把S置为空栈
{
    if (S.base == NULL)
        return ERROR;
    S.top = S.base;
    return OK;
}
Status StackEmpty(SqStack S) //若栈S为空栈，则返回TRUE，否则返回FALSE
{
    if (S.base == NULL)
        return FALSE;
    else if (S.top == S.base)
        return TRUE; //栈顶指针指向栈底时，栈空
    else
        return FALSE;
}

int StackLength(SqStack S) //返回S的元素个数，即栈的长度
{
    if (S.base == NULL || S.base == S.top)
        return 0;
    return S.top - S.base; //求栈中元素个数
}

Status GetTop(SqStack S, SElemType &e) //若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR
{
    if (S.top == S.base)
        return ERROR;
    e = *(S.top - 1);
    return OK;
}

Status Push(SqStack &S, SElemType e) //插入元素e为栈顶元素
{
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (S.base == NULL)
            return ERROR;

        S.top = S.base + S.stacksize;  //更新栈顶
        S.stacksize += STACKINCREMENT; //更新栈存储容量
    }
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S, SElemType &e) //若栈不空，则删除S的栈顶元素，并返回OK，额否则返回ERROR
{
    if (S.top == S.base)
        return ERROR;
    e = *--S.top;
    return OK;
}

Status StackTraverse(SqStack S, Status(*visit(SElemType))) //从栈底到栈顶依次对栈中每个元素调用函数visit()。一旦visit()失败，则操作失败
{
    if (S.base == NULL || S.top == S.base)
        return ERROR;
    SElemType *p = S.base;
    while (p < S.top)
    {
        visit(*p);
        p++;
    }
    return OK;
}