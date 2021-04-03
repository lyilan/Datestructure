/*
 * @Author: lyilan
 * @Date: 2021-04-03 10:34:17
 * @Description: for my ying~
 */

#include "LineEdit.h"

void LineEdit() //利用字符栈S，从终端接受一行并传送至调用过程的数据区
{
    SqStack S;
    InitStack(S);
    char ch = getchar();
    while (ch != EOF)
    {
        while (ch != EOF && ch != '\n')
        {
            char c;
            switch (ch)
            {
            case '#':
                Pop(S, c);
                break;
            case '@':
                ClearStack(S);
            default:
                Push(S, ch);
                break;
            }
            ch = getchar();
        }
        ClearStack(S);
        if (ch != EOF)
            ch = getchar();
    }
    DestroyStack(S);
}