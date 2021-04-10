/*
 * @Author: lyilan
 * @Date: 2021-04-07 12:42:42
 * @Description: for my ying~
 */

#include "BiTree.h"

Status Visit(TElemType e)
{
    printf("%c", e);
}

int main()
{
    printf("测试开始：\n");

    BiTree T;
    if (InitBitree(T))
        printf("初始化成功！\n");

    if (CreateBiTree(T, NULL))
        printf("创建二叉树成功！\n");

    if (BiTreeEmpty(T))
    {
        printf("空二叉树！\n");
    }

    PreOrderTraverse(T, Visit);
    printf("\n");

    //绘制二叉树
    PaintTree(T);
    printf("绘制二叉树成功\n");
    return 0;
}