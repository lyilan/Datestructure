#ifndef MERGELIST_H
#define MERGELIST_H

#include "../LinkList/LinkList.h"

void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc); //La，Lb元素的值按非递减排列，归并得到Lc后，仍然非递减排列

#endif