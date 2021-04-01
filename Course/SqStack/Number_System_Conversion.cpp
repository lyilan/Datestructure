/*
 * @Author: lyilan
 * @Date: 2021-04-01 18:22:26
 * @Description: for my ying~
 */
#include "SqStack.h"

void conversion() //对于输入的任意一个非负十进制帧数，打印输出与其等值的八进制数
{
    SqStack S;
    InitStack(S); //构造空栈

    int N;
    scanf("%d", &N); //输入十进制数N
    while (N)
    {
        Push(S, N % 8);
        N = N / 8;
    }

    int e;
    while (!StackEmpty(S))
    {
        Pop(S, e);
        printf("%d", e);
    }
    printf("\n");
}

int main()
{
    int N;
    printf("请输入需要转换的数字的个数：");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        conversion();
    }
}