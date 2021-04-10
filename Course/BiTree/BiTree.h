/*
 * @Author: lyilan
 * @Date: 2021-04-06 10:29:13
 * @Description: for my ying~
 */

// - - - - - 二叉树的二叉链表存储表示 - - - - -
#ifndef BITREE_H
#define BITREE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "LinkQueue.h"
#include "../../Status/Status.h"

typedef char TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// - - - - - 基本操作函数的原型说明 - - - - -
Status InitBitree(BiTree &T);

Status DestroyBiTree(BiTree &T);

Status ClearBiTree(BiTree &T);

Status CreateBiTree(BiTree &T, char *path);

Status BiTreeEmpty(BiTree T);

int BiTreeDepth(BiTree T);

TElemType Root(BiTree T);

TElemType Value(BiTree T, TElemType e);

Status Assign(BiTree T, TElemType e, TElemType value);

TElemType Parent(BiTree T, TElemType e);

TElemType LeftChild(BiTree T, TElemType e);

TElemType RightChild(BiTree T, TElemType e);

TElemType LeftSibling(BiTree T, TElemType e);

TElemType RightSibling(BiTree T, TElemType e);

Status InsertChild(BiTree T, TElemType p, int LR, BiTree c);

Status DeleteChild(BiTree T, TElemType p, int LR);

Status PreOrderTraverse(BiTree T, Status (*Visit)(TElemType));

Status InOrderTraverse(BiTree T, Status (*Visit)(TElemType));

Status PostOrderTraverse(BiTree T, Status (*Visit)(TElemType));

Status LevelOrderTraverse(BiTree T, Status (*Visit)(TElemType));

// - - - - - 仅内部使用的函数 - - - - -
static void CreateTree(BiTree &T, FILE *fp);

static BiTree EPTr(BiTree T, TElemType e);

static BiTree PPTr(BiTree T, TElemType e);

// - - - - - 图形化输出 - - - - -
void PaintTree(BiTree &T);

void PaintBiTree(TElemType **tmp, BiTree &T, int x, int y);

#endif