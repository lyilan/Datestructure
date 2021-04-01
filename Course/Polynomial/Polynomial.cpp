/*
 * @Author: lyilan
 * @Date: 2021-04-01 13:13:53
 * @Description: for my ying~
 */

#include "Polynomial.h"

int cmp(term e1, term e2) //依指数值分别返回-1，0，1
{
    if (e1.expn < e2.expn)
        return -1;
    else if (e1.expn > e2.expn)
        return 1;
    else
        return 0;
}

void CreatPolyn(polynomial &P, int m) //输入m项的系数和指数，建立表示一元多项式的有序链表P
{
    InitList(P);         //初始化P
    Link h = GetHead(P); //获取P的头结点h

    ElemType e; //设置头结点的数据
    e.coef = 0.0;
    e.expn = -1;
    SetCurElem(h, e);

    Position q;
    for (int i = 0; i < m; i++) //依次输入m个非零项
    {
        scanf("%f %d", &e.coef, &e.expn);
        if (!LocateElem(P, e, q, cmp)) //当前链表中不存在该指数项
        {
            Link s;
            if (MakeNode(s, e))
                InsFirst(q, s);
        }
    }
}

void DestroyPolyn(polynomial &P) //销毁一元多项式P
{
    DestroyList(P); //销毁链表P
    return;
}

void PrintPolyn(polynomial P) //打印输出一元多项式P
{
    if (P->leng == 0)
    {
        printf("0\n");
        return;
    }
    Link h = GetHead(P);
    Position p = NextPos(P, h);
    term e = GetCurElem(p);
    if (e.expn == 0)
        printf("%f", e.expn);
    p = NextPos(P, p);
    while (p)
    {
        e = GetCurElem(p);
        if (e.coef > 0)
        {
            printf("+%dx^%d", e.coef, e.expn); //正数打印
        }
        else
            printf("%dx^%d", e.coef, e.expn); //负数打印
        p = NextPos(P, p);
    }
    printf("\n");
    return; //打印输出
}

int PolynLength(polynomial P) //返回一元多项式P中的项数
{
    return ListLength(P);
}

void AddPolyn(polynomial &Pa, polynomial &Pb) //完成多项式相加运算，即：Pa = Pa + Pb, 并销毁一元多项式 Pb
{
    Link ha = GetHead(Pa), hb = GetHead(Pb);             //ha和hb分别指向Pa和Pb的头结点
    Position qa = NextPos(Pa, ha), qb = NextPos(Pb, hb); //qa和qb分别指向Pa和Pb中当前结点
    while (qa && qb)                                     //qa和qb均非空
    {
        term a = GetCurElem(qa), b = GetCurElem(qb); //a和b为两表中当前比较元素
        switch (cmp(a, b))
        {
        case -1: //多项式Pa中当前结点的指数值较小
            ha = qa;
            qa = NextPos(Pa, qa);
            break;
        case 0: //两者指数值相等
            term sum = {a.coef + b.coef, a.expn};
            if (sum.coef != 0.0) //修改多项式Pa中当前结点的系数值
            {
                SetCurElem(qa, sum);
                ha = qa;
            }
            else
            {
                DelFirst(ha, qa);
                FreeNode(qa);
            }
            DelFirst(hb, qb);
            FreeNode(qb);
            qb = NextPos(Pb, qb);
        case 1: //多项式PB中当前结点的指数值
            DelFirst(hb, qb);
            InsFirst(ha, qb);
            qb = NextPos(Pb, hb);
            ha = NextPos(Pa, ha);
            break;
        }               //switch
    }                   //while
    if (ListLength(Pb)) //链接Pb中剩余结点
        Append(Pa, qb);
    FreeNode(hb); //释放Pb的头结点
}

void SubtractPolyn(polynomial &Pa, polynomial &Pb) //完成多项式相减运算，即：Pa = Pa - Pb, 并销毁一元多项式 Pb
{
    Link ha = GetHead(Pa), hb = GetHead(Pb);             //ha和hb分别指向Pa和Pb的头结点
    Position qa = NextPos(Pa, ha), qb = NextPos(Pb, hb); //qa和qb分别指向Pa和Pb中当前结点
    while (qa && qb)                                     //qa和qb均非空
    {
        term a = GetCurElem(qa), b = GetCurElem(qb); //a和b为两表中当前比较元素
        switch (cmp(a, b))
        {
        case -1: //多项式Pa中当前结点的指数值较小
            ha = qa;
            qa = NextPos(Pa, qa);
            break;
        case 0: //两者指数值相等
            term sum = {a.coef - b.coef, a.expn};
            if (sum.coef != 0.0) //修改多项式Pa中当前结点的系数值
            {
                SetCurElem(qa, sum);
                ha = qa;
            }
            else
            {
                DelFirst(ha, qa);
                FreeNode(qa);
            }
            DelFirst(hb, qb);
            FreeNode(qb);
            qb = NextPos(Pb, qb);
        case 1: //多项式PB中当前结点的指数值
            DelFirst(hb, qb);
            InsFirst(ha, qb);
            qb = NextPos(Pb, hb);
            ha = NextPos(Pa, ha);
            break;
        }               //switch
    }                   //while
    if (ListLength(Pb)) //链接Pb中剩余结点
        Append(Pa, qb);
    FreeNode(hb); //释放Pb的头结点
}