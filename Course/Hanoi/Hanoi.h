/*
 * @Author: lyilan
 * @Date: 2021-04-05 13:46:54
 * @Description: for my ying~
 */

#include "stdio.h"

void hanoi(int n, char x, char y, char z);
//将塔座x上按直径由小到大且自上而下编号为1至n的n个圆盘按规则搬到
//塔座z上，y可用作辅助塔座

void mov(char x, int n, char z);

//搬动操作mov(x,n,z)定义
