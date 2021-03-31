/*
 * @Author: lyilan
 * @Date: 2021-03-31 15:38:20
 * @Description: for my ying~
 */

#include "Difference.h"

Status difference(SLinkList &space, int &S) //依次输入集合A和集合B的元素，在一维数组中建立表示（A-B）U（B-A）的静态链表
{
    int m, n; //定义A，B两个集合元素的数量分别为m，n
    scanf("%d %d", &m, &n);

    CreatListH(space, S, m); //首先将A中元素建立为一个静态链表

    ElemType e; //用来接受B中的元素
    int cur;    //指示B中的元素在A中的位置
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &e);
        if (cur = LocateElem(space, S, e, equal)) //如果e在A中，删除A中该结点
            ListDelete(space, S, cur, e);
        else //否则插入链表中
        {
            int s = Malloc(space);
            if (!s)
                return ERROR; //如果申请结点失败，返回ERROR；

            space[s].cur = space[S].cur; //插入
            space[S].cur = s;
            space[s].data = e;
        }
    }
}

Status equal(ElemType e1, ElemType e2) //判断e1和e2是否相等
{
    return e1 == e2 ? TRUE : FALSE;
}