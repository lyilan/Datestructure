#include "LinkList.h"

Status InitList(LinkList &L){       //单链表初始化
    L = (LinkList)malloc(sizeof(LNode));
    if(L == NULL) exit(OVERFLOW);   
    L->next = NULL;
    return OK;
}

Status DestroyList(LinkList &L){    //单链表销毁
    LinkList p = L;
    if(L == NULL) return ERROR;
    while(L){
        p = L->next;
        free(L);
        L = p;
    }
    L = NULL;
    return OK;
}
Status ClearList(LinkList &L){      //单链表清空
    LinkList p;
    if(L == NULL) return ERROR;
    while(L->next != NULL){
        p = L->next;
        L->next = p->next;
        free(p);
    }
    return OK;
}

Status ListEmpty(LinkList L){       //判断链表是否为空
    if(L && L->next == NULL) return TRUE;   //链表只有头结点时，认为该链表空；
    else return FALSE;              
}

int ListLength(LinkList L){      //返回链表所含有效数据的数量
    if(L == NULL || L->next == NULL) return 0;
    LinkList p = L->next;
    int i = 0;
    while(p){
        p = p->next;
        i++;
    }
    return i;
}

Status GetELem(LinkList L, int i, ElemType &e){ //获取链表第i个元素,并用e返回
    int j = 0;
    LinkList p = L;
    if(L == NULL || L->next == NULL) return ERROR;
    while(j < i && p){
        p = p->next;
        j++;
    }
    if(!p) return ERROR;
    else e = p->data;
    return OK;
}

int LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType)){  //返回链表中首个与e满足compare()关系的元素位序
    if(L == NULL || L->next == NULL) return 0;
    int i = 1;
    LinkList p = L->next;
    while(p && !compare(e, p->data)){
        p = p->next;
        i++;
    }
    if(!p) return 0;
    else return i;
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e){   //获取cur_e元素前驱
    if(L == NULL || L->next == NULL) return ERROR;
    LinkList p = L->next;
    while(p->next && p->next->data != cur_e){
        p = p->next;
    }
    if(!p->next) return ERROR;
    pre_e = p->data;
    return OK;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e){   //获取cur_e元素后继
    if(L == NULL || L->next == NULL) return ERROR;
    LinkList p = L->next;
    while(p->next && p->data == cur_e){
        p = p->next;
    }
    if(!p->next) return ERROR;
    next_e = L->data;
    return OK;
}

Status ListInsert(LinkList &L, int i, ElemType e){      //向链表第i个位置前插入e
    if(L == NULL) return ERROR;
    int j = 1;
    LinkList p = L;
    while(j < i) p = p->next;
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    s->data = e;
    return OK;
}
Status ListDelete(LinkList &L, int i, ElemType &e){     //删除链表第i个元素，并将删除元素存储到e中
    if(L == NULL || L->next == NULL) return ERROR;
    LinkList p = L, q;
    int j = 1;
    while(j < i && p->next){
        p = p->next;
    }
    if(!p->next) return ERROR;
    q = p->next;
    p->next = q->next;
    free(q);
    return OK;
}

void ListTraverse(LinkList L, void(visit)(ElemType)){   //用visit()遍历整个链表
    if(L == NULL || L->next == NULL) return;
    LinkList p = L->next;
    while(p){
        visit(p->data);
        p = p->next;
    }
}

Status CreateList_H(LinkList &L, int n){   //头插法建立链表
    L = (LinkList)malloc(sizeof(LNode));
    if(!L) return ERROR;
    L->next = NULL;
    for(int i = 0; i < n; i++){
        LinkList p = (LinkList)malloc(sizeof(LNode));
        if(!p) return ERROR;
        p->next = L->next;
        L->next = p;
        scanf("%d", &p->data);
    }
    return OK;
}

Status CreateList_T(LinkList &L, int n){   //尾插法建立链表
    L = (LinkList)malloc(sizeof(LNode));
    if(!L) return ERROR;
    L->next = NULL;
    LinkList tail = L;
    for(int i = 0; i < n; i++){
        LinkList p = (LinkList)malloc(sizeof(LNode));
        if(!p) return ERROR;
        tail->next = p;
        p->next = NULL;
        scanf("%d", &p->data);
        tail = p;
    }
    return OK;
}