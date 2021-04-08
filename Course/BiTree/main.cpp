/*
 * @Author: lyilan
 * @Date: 2021-04-07 12:42:42
 * @Description: for my ying~
 */

#include "BiTree.h"

int main()
{
    printf("测试开始：\n");

    BiTree T;
    if (InitBitree(T))
        printf("初始化成功！\n");

    if (CreateBiTree(T, "PreT.txt"))
        printf("创建二叉树成功！");

    //绘制二叉树
    PaintTree(T);
}