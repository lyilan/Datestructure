/*
 * @Author: lyilan
 * @Date: 2021-04-10 19:29:08
 * @Description: for my ying~
 */

// - - - - - 二叉树的二叉中序线索存储表示 - - - - -
#ifndef BITHRTREE_H
#define BITHRTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Status/Status.h"

//Link == 0:指针，Thread == 1:线索
typedef enum PointerTag
{
    Link,
    Thread
};

typedef char TElemType;

typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild, *rchild; //左右孩子指针
    PointerTag LTag, RTag;             //左右标志
} BiThrNode, *BiThrTree;

// - - - - - 二叉树中序线索树的操作声明 - - - - -
Status CreateBiThrTree(BiThrTree &T, char *path); //先序建立二叉树

Status InOrderTraverse_Thr(BiThrTree &T, Status (*Visit)(TElemType));

Status InorderThreading(BiThrTree &Thrt, BiThrTree T);

// - - - - - 内部函数的声明 - - - - -
Status CreateTree(BiThrTree &T, FILE *fp);

// - - - - -图形化输出 - - - - -
void PaintTree(BiThrTree &T);

void PaintBiTree(TElemType **tmp, BiThrTree &T, int x, int y);

#endif