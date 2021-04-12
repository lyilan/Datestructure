/*
 * @Author: lyilan
 * @Date: 2021-04-10 19:29:17
 * @Description: for my ying~
 */

#include "BiThrTree.h"

// - - - - - 二叉中序线索树操作的实现 - - - - -
Status CreateBiThrTree(BiThrTree &T, char *path) //先序建立二叉树
{
    FILE *fp;
    int ReadFromConsole;

    ReadFromConsole = (path == NULL || strcmp(path, "") == 0);

    if (ReadFromConsole)
    {
        printf("请输入二叉树的先序序列，如果没有子结点，使用^代替：");
        CreateTree(T, NULL);
    }
    else
    {
        fp = fopen(path, "r");
        if (fp == NULL)
            return ERROR;
        CreateTree(T, fp);
        fclose(fp);
    }
    return OK;
}

Status InOrderTraverse_Thr(BiThrTree &T, Status (*Visit)(TElemType))
{
    BiThrTree p = T->lchild;
    while (p != T)
    {
        while (p->LTag == Link)
            p = p->lchild;
        if (!Visit(p->data))
            return ERROR;
        while (p->RTag == Thread && p->rchild != T)
        {
            p = p->rchild;
            Visit(p->data);
        }
        p = p->rchild;
    }
    return OK;
}

Status InorderThreading(BiThrTree &Thrt, BiThrTree T)
{
    if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))
        exit(OVERFLOW);

    Thrt->LTag = Link;
    Thrt->RTag = Thread;

    Thrt->lchild = Thrt;
    if (!T)
        Thrt->lchild = Thrt;
    else
    {
        Thrt->lchild = T;
        pre = Thrt;

        InThreading(T);

        pre->rchild = Thrt;
        pre->RTag = Thread;
        Thrt->rchild = pre;
    }
    return OK;
}

// - - - - - 内部函数的实现 - - - - -
static void CreateTree(BiThrTree &T, FILE *fp)
{
    char ch;

    if (fp == NULL)
        scanf("%c", &ch);
    else
    {
        fscanf(fp, "%c", &ch);
    }
    if (ch == '^')
        T = NULL;
    else
    {
        T = (BiThrTree)malloc(sizeof(BiThrNode));
        if (T == NULL)
            exit(OVERFLOW);
        T->data = ch;
        CreateTree(T->lchild, fp); //创建左子树
        CreateTree(T->rchild, fp); //创建右子树
    }
}

static void InThreading(BiThrTree p)
{
    if (p)
    {
        InThreading(p->lchild);

        if (!p->lchild)
        {
            p->LTag = Thread;
            p->lchild = pre;
        }
        if (!pre->rchild)
        {
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}

// - - - - - 图形化输出实现 - - - - -
