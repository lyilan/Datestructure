# include "Union.h"

void Union(SqList &La, SqList Lb){         //将所有在线性表Lb中但不在La中的数据元素插入到La中
    int La_len = ListLength_Sq(La), Lb_len = ListLength_Sq(Lb); //求线性表长度
    int e;
    for(int i = 1; i <= Lb_len; i++){
        GetElem_Sq(Lb, i, e);               //取Lb中第i个元素赋值给e
        if(!LocateElem_Sq(La, e, equal)) ListInsert_Sq(La, ++La_len, e);
                                            //La中不存在和e相同的数据元素，则插入之
    }
}

Status equal(ElemType e1, ElemType e2){     //判断e1 和 e2 是否相等，相等返回TRUE，不想等返回FALSE
    return e1 == e2 ? TRUE : FALSE;
}