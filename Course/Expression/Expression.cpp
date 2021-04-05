/*
 * @Author: lyilan
 * @Date: 2021-04-04 15:05:08
 * @Description: for my ying~
 */

#include "Expression.h"

OperandType EvaluateExpression(const char exp[]) //表达式求值
{
    SqStack OPTR; //寄存运算符
    SqStack OPND; //寄存运算数

    SElemType cur_c; //输入序列

    SElemType x, theta; //缓存预算符
    SElemType a, b;     //缓存操作符

    int i = 0;

    InitStack(OPTR);
    InitStack(OPND);

    Push(OPTR, '#'); //表达式起始符‘#’作为运算符栈的栈底元素
    cur_c = exp[i++];

    while (cur_c != '#' || GetTop(OPTR) != '#')
    {
        if (!In(cur_c, OP))
        {
            Push(OPND, cur_c);
            cur_c = exp[i++];
        }
        else
            switch (Precede(GetTop(OPTR), cur_c))
            {
            case '<':
                Push(OPTR, cur_c);
                cur_c = exp[i++];
                break;
            case '=':
                Pop(OPTR, x);
                cur_c = exp[i++];
                break;
            case '>':
                Pop(OPTR, theta);
                Pop(OPND, a);
                Pop(OPND, b);
                Push(OPND, Operate(a, theta, b));
                break;
            }
    }
    return GetTop(OPND);
}

Status In(SElemType c, const char *OP) //判断c是否是运算符
{
    const char *e = strchr(OP, c);
    if (e == NULL)
    {
        return FALSE;
    }
    else
        return TRUE;
}

char Precede(SElemType e1, SElemType e2) //返回运算符e1和e2的优先级关系
{
    int x;
    int y;

    const char *p1 = strchr(OP, e1);
    const char *p2 = strchr(OP, e2);

    x = p1 - OP;
    y = p2 - OP;
    return PrecedeTable[x][y];
}

SElemType Operate(SElemType a, SElemType theta, SElemType b) //将a theta b 运算后的结果返回
{
    int x, y, z;

    x = a - '0';
    y = b - '0';

    switch (theta)
    {
    case '+':
        z = x + y;
        break;
    case '-':
        z = x - y;
        break;
    case '*':
        z = x * y;
        break;
    case '/':
        z = x / y;
        break;
    }
    return z + '0';
}