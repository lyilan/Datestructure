/*
 * @Author: lyilan
 * @Date: 2021-04-05 13:58:47
 * @Description: for my ying~
 */

#include "Hanoi.h"

int main()
{
    int N;
    scanf("%d", &N);
    hanoi(N, 'x', 'y', 'z');
    return 0;
}
