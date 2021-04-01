/*
 * @Author: lyilan
 * @Date: 2021-04-01 20:32:44
 * @Description: for my ying~
 */

#ifndef BRACKETMATCH_H
#define BRACKERMATCH_H

#include "SqStack.h"

void BracketMatch() //括号匹配检验
{
    char c[100], e = '\0';
    printf("请输入需要检测的段：");
    scanf("%s", c);

    SqStack S;
    InitStack(S);
    for (int i = 0; c[i] != '\0'; i++)
    {
        GetTop(S, e);
        switch (c[i])
        {
        case '(':
            Push(S, c[i]);
            break;
        case '[':
            Push(S, c[i]);
            break;
        case '{':
            Push(S, c[i]);
            break;
        case ')':
            if (e == '(')
                Pop(S, e);
            else
            {
                printf("有错误!\n");
                return;
            }
            break;
        case ']':
            if (e == '[')
                Pop(S, e);
            else
            {
                printf("有错误!\n");
                return;
            }
            break;
        case '}':
            if (e == '{')
                Pop(S, e);
            else
            {
                printf("有错误!\n");
                return;
            }
            break;
        }
    }
    if (StackEmpty(S))
        printf("正确\n");
    else
        printf("有错误!\n");
    return;
}

#endif
