/*
 * @Author: lyilan
 * @Date: 2021-04-01 20:58:10
 * @Description: for my ying~
 */

#include "BracketMatch.h"

int main()
{
    int N;
    printf("请输入测试数量：");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        BracketMatch();
    }
    printf("测试结束！！！\n");
    return 0;
}
