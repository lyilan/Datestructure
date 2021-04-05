/*
 * @Author: lyilan
 * @Date: 2021-04-05 13:51:21
 * @Description: for my ying~
 */

#include "Hanoi.h"

void hanoi(int n, char x, char y, char z)
{
    //将塔座x上按直径由小到大且自上而下编号为1至n的n个圆盘按规则搬到
    //塔座z上，y可用作辅助塔座
    if (n == 1)
        mov(x, 1, z);
    else
    {
        hanoi(n - 1, x, z, y);
        mov(x, n, z);
        hanoi(n - 1, y, x, z);
    }
}
void mov(char x, int n, char z)
{
    printf("将 %d 号圆盘从 %c 移动到 %c\n", n, x, z);
}

//搬动操作mov(x,n,z)定义