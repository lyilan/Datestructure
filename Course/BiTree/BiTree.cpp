/*
* @Author: lyilan
* @Date: 2021-04-06 13:09:02
* @Description: for my ying~
*/
#include "BiTree.h"

// - - - - - 基本操作函数的实现 - - - - -

Status InitBitree(BiTree &T)
{
    //初始化树
    T == NULL;
    return OK;
}

Status DestroyBiTree(BiTree &T)
{
    //无须销毁，使用清空即可
    return ERROR;
}

Status ClearBiTree(BiTree &T)
{
    if (T != NULL)
    {
        if (T->lchild != NULL)
        {
            ClearBiTree(T->lchild); //清空左子树
        }
        if (T->rchild != NULL)
        {
            ClearBiTree(T->rchild); //清空右子树
        }
        free(T); //释放根结点
        T = NULL;
    }
    return OK;
}

Status CreateBiTree(BiTree &T, char *path)
{
    FILE *fp;
    int ReadFromConsole; //是否从控制台读取程序
    ReadFromConsole = (path == NULL);
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

Status BiTreeEmpty(BiTree T)
{
    return (T == NULL) ? TRUE : FALSE;
}

int BiTreeDepth(BiTree T)
{
    int LD, RD;
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        LD = BiTreeDepth(T->lchild);
        RD = BiTreeDepth(T->rchild);

        return (LD > RD ? LD : RD) + 1;
    }
}

TElemType Root(BiTree T)
{
    if (BiTreeEmpty(T))
        return '\0';
    else
        return T->data;
}

TElemType Value(BiTree T, TElemType e)
{
    BiTree p;

    if (BiTreeEmpty(T))
        return '\0';

    p = EPTr(T, e);

    if (p == NULL)
        return '\0';
    else
        return p->data;
}

Status Assign(BiTree T, TElemType e, TElemType value)
{
    BiTree p;

    if (BiTreeEmpty(T))
        return ERROR;

    p = EPTr(T, e);

    if (p == NULL)
    {
        return ERROR;
    }
    else
    {
        p->data = value;
    }
    return OK;
}

TElemType Parent(BiTree T, TElemType e)
{
    BiTree p;

    if (T == NULL)
        return '\0';

    p = PPTr(T, e);

    if (p == NULL)
        return '\0';
    else
        return p->data;
}

TElemType LeftChild(BiTree T, TElemType e)
{
    BiTree p;

    if (T == NULL)
        return '\0';

    p = EPTr(T, e);

    if (p != NULL && p->lchild != NULL)
        return p->lchild->data;

    return '\0';
}

TElemType RightChild(BiTree T, TElemType e)
{
    BiTree p;

    if (T == NULL)
        return '\0';

    p = EPTr(T, e);

    if (p != NULL && p->rchild != NULL)
        return p->rchild->data;
    return '\0';
}

TElemType LeftSibling(BiTree T, TElemType e)
{
    BiTree p;

    if (T == NULL)
        return '\0';

    p = PPTr(T, e);

    if (p != NULL && p->rchild->data == e || p->lchild != NULL)
        return p->lchild->data;
    return '\0';
}

TElemType RightSibling(BiTree T, TElemType e)
{
    BiTree p;

    if (T == NULL)
        return '\0';

    p = PPTr(T, e);

    if (p != NULL && p->lchild->data == e || p->rchild != NULL)
        return p->rchild->data;
    return '\0';
}

Status InsertChild(BiTree T, TElemType p, int LR, BiTree c)
{
    BiTree p_ptr;

    if (BiTreeEmpty(c))
        return ERROR;

    p_ptr = EPTr(T, p);

    if (p == NULL)
        return ERROR;

    if (LR == 0)
    {
        if (p_ptr->lchild != NULL)
            c->rchild = p_ptr->lchild;
        p_ptr->lchild = c;
    }
    else
    {
        if (p_ptr->rchild != NULL)
            c->rchild = p_ptr->rchild;
        p_ptr->rchild = c;
    }

    return OK;
}

Status DeleteChild(BiTree T, TElemType p, int LR)
{
    BiTree p_ptr;

    if (BiTreeEmpty(T))
        return ERROR;

    p_ptr = EPTr(T, p);

    if (p_ptr != NULL)
        return ERROR;

    if (LR == 0)
        ClearBiTree(p_ptr->lchild);
    else
        ClearBiTree(p_ptr->rchild);

    return OK;
}

Status PreOrderTraverse(BiTree T, Status (*Visit)(TElemType))
{
    if (T)
    {
        Visit(T->data);
        PreOrderTraverse(T->lchild, Visit);
        PreOrderTraverse(T->rchild, Visit);
    }
    return TRUE;
}

Status InOrderTraverse(BiTree T, Status (*Visit)(TElemType))
{
    if (T)
    {
        if (InOrderTraverse(T->lchild, Visit))
        {
            if (Visit(T->data))
            {
                if (InOrderTraverse(T->rchild, Visit))
                    return OK;
            }
        }
    }
    printf("\n");
    return ERROR;
}

Status PostOrderTraverse(BiTree T, Status (*Visit)(TElemType))
{
    if (PostOrderTraverse(T->lchild, Visit))
    {
        if (PostOrderTraverse(T->rchild, Visit))
        {
            if (Visit(T->data))
                return OK;
        }
    }
    printf("\n");
    return ERROR;
}

Status LevelOrderTraverse(BiTree T, Status (*Visit)(TElemType))
{
    LinkQueue Q;
    BiTree e;

    if (T == NULL)
    {
        printf("\n");
        return ERROR;
    }

    InitQueue(Q);

    EnQueue(Q, T);

    while (!QueueEmpty(Q))
    {
        DeQueue(Q, e);

        if (!Visit(e->data))
            return ERROR;

        if (e->lchild != NULL)
            EnQueue(Q, e->lchild);

        if (e->rchild != NULL)
            EnQueue(Q, e->rchild);
    }
    printf("\n");
    return OK;
}

// - - - - - 内部使用函数的实现 - - - - -
static void CreateTree(BiTree &T, FILE *fp)
{
    char ch;

    if (fp == NULL)
    {
        scanf("%c", &ch);
    }
    else
    {
        fscanf(fp, "%c", &ch);
    }

    if (ch == '^')
    {
        T == NULL;
    }
    else
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        if (T == NULL)
            exit(OVERFLOW);
        T->data = ch;
        CreateTree(T->lchild, fp);
        CreateTree(T->rchild, fp);
    }
}

static BiTree EPTr(BiTree T, TElemType e)
{
    BiTree pl, pr;

    if (T == NULL)
        return NULL;

    if (T->data = e)
        return T;

    pl = EPTr(T->lchild, e);
    if (pl != NULL)
    {
        return pl;
    }

    pr = EPTr(T->rchild, e);
    if (pr != NULL)
    {
        return pr;
    }

    return NULL;
}

static BiTree PPTr(BiTree T, TElemType e)
{
    BiTree pl, pr;

    if (T == NULL || T->data == e)
        return NULL;

    if (T->lchild && T->lchild->data == e)
        return T;

    if (T->rchild && T->rchild->data == e)
        return T;

    pl = PPTr(T->lchild, e);
    if (pl != NULL)
        return pl;

    pr = PPTr(T->rchild, e);
    if (pr != NULL)
        return pr;

    return NULL;
}

// - - - - - 图形化输出 - - - - -
void PaintTree(BiTree &T)
{
    int level, width; //二维数组大小
    int depth;        //记录树的高度
    int i, j;
    TElemType **tmp;
    LinkQueue Q;
    BiTree e;

    if (BiTreeEmpty(T))
    {
        printf("\n");
        return;
    }

    depth = BiTreeDepth(T);
    level = (int)pow(2, depth - 1) + depth - 1;
    width = (int)pow(2, depth) - 1;

    //动态创建行
    tmp = (TElemType **)malloc(level * sizeof(TElemType *));

    //动态创建列
    for (i = 0; i < level; i++)
    {
        tmp[i] = (TElemType *)malloc(width * sizeof(TElemType));
        memset(tmp[i], '\0', width);
    }

    //存储要打印树的信息
    PaintBiTree(tmp, T, 0, width / 2);

    for (i = 0; i < level; i++) //打印输出结果
    {
        for (j = 0; j < width; j++)
        {
            if (tmp[i][j] != '\0')
                printf("%c", tmp[i][j]);
            else
                printf(" ");
        }
        printf("\n");
    }
}

void PaintBiTree(TElemType **tmp, BiTree &T, int x, int y)
{
    //将二叉树T存储在tmp中，并将根设置在tmp[x][y]
    int i;
    if (T == NULL)
        return;
    tmp[x][y] = T->data; //存储根的信息
    int d = BiTreeDepth(T);

    if (T->lchild)
    {
        for (i = 1; i <= pow(2, d - 2); i++) //存储根与左子树的连线
        {
            tmp[x + i][y - i] = '/';
        }
        PaintBiTree(tmp, T->lchild, x + i, y - i + 1); //存储左子树
    }
    if (T->rchild)
    {
        for (i = 1; i <= pow(2, d - 2); i++) //存储根与右子树的连线
        {
            tmp[x + i][y + i] = '\\';
        }
        PaintBiTree(tmp, T->rchild, x + i, y + i - 1); //存储右子树
    }
    return;
}