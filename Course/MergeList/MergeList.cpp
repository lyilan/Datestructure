#include "Mergelist.h"

void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc)
{ //La，Lb元素的值按非递减排列，归并得到Lc后，仍然非递减排列
    LinkList pa = La->next;
    LinkList pb = Lb->next;
    Lc = La; //用La的头结点作为Lc的头结点
    LinkList pc = Lc;
    while (pa && pb)
    {
        if (pa->data < pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb; //插入剩余段
    free(Lb);                //释放Lb的头结点
    return;
}