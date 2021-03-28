//线性表的单链表存储结构
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;

//结点类型
typedef struct LNode{
    ElemType data;
    struct LNode * next;
} * Link, * Position;

//链表类型
typedef struct{
    Link head, tail;
    int len;
}LinkList;

//分配由p指向的值为e的结点
Status MakeNode(Link &p, ElemType e){
    p = (Link)malloc(sizeof(struct LNode));
    if(!p) return ERROR;
    p->data = e;
    p->next = NULL;
    return OK;
}

//释放p所指的结点
void FreeNode(Link &p){free(p);}

//构造一个空的线性链表L
Status InitList(LinkList &L){
    L.len = 0;
    L.head = (Link)malloc(sizeof(struct LNode));
    L.head->data = 0;
    L.head->next = NULL;
    L.tail = L.head;
    return OK;
}

//销毁线性链表L，L不再存在
Status DestroyList(LinkList &L){
    Link p;
    while(L.head){
        p = L.head;
        L.head = p->next;
        free(p);
    }
    free(&L);
    return OK;
}

//将线性链表L重置为空表，并释放原链表的结点空间
Status ClearList(LinkList &L){
    Link p;
    while(L.head->next){
        p = L.head->next;
        L.head->next = p->next;
        free(p);
    }
    L.tail = L.head;
    L.len = 0;
    return OK;
}

//已知h指向线性链表的头结点，将s所指的结点插入在第一个结点前
Status InsFirst(LinkList &L, Link h, Link s){
    s->next = h->next;
    h->next = s;
    L.len++;
    return OK;
}

//已知h指向线性链表的头结点，删除链表中的第一个结点并以q返回
Status DelFirst(LinkList &L, Link h, Link &q){
    if(L.len == 0) return ERROR;
    q = h->next;
    h->next = q->next;
    L.len--;
    if(!L.len) L.tail = L.head;
    return 0;
}

//将指针s所指的一串结点链接在线性链表L的最后一个结点,并改变链表L的尾指针指向新的尾结点
Status Append(LinkList &L, Link s){
    Link p = s;
    L.tail->next = s;
    while(p->next){p = p->next; L.len++;}
    L.len++;
    L.tail = p;
    return OK;
}

//删除线性链表的尾结点并以q返回，改变链表L的尾指针指向新的尾结点
Status Remove(LinkList &L, Link &q){
    if(L.len == 0) return ERROR;
    Link p = L.tail;
    while(p ->next != L.tail) p = p->next;
    q = p ->next;
    L.tail = p;
    L.len--;
    return OK;
}

//已知p指向线性链表L中的一个结点，将s所指结点插入在p所指结点之前
Status InsBefore(LinkList &L, Link &p, Link s){
    Link q = L.head;
    while(q->next != p) q = q->next;
    s->next = p;
    q->next = s;
    p = s;
    L.len++;
    return OK;
}

//已知p指向线性链表L中的一个结点，将s所指结点插入在p所指结点之后
Status InsAfter(LinkList &L, Link &p, Link s){
    if(p == L.tail){L.tail = s;}
    s->next = p->next;
    p->next = s;
    p = s;
    L.len++;
    return OK;
}

//已知p指向线性链表中的一个结点，用e更新p指向结点中的元素的值
Status SetCurElem(Link &p, ElemType e){
    p->data = e;
    return OK;
}

//已知p指向线性链表中的一个结点，返回p所指结点中数据元素的值
ElemType GetCurElem(Link p){return p->data;}

//若线性链表L为空表，则返回TRUE，否则返回FALSE
Status ListEmpty(LinkList L){
    if(!L.len) return OK;
    else return ERROR;
}

//返回线性链表L中元素的个数
int ListLength(LinkList L){return L.len;}

//返回线性链表L中头结点的位置
Position GetHead(LinkList L){return L.head;}

//返回线性链表L中最后一个结点的位置
Position GetLast(LinkList L){return L.tail;}

//已知p指向线性链表中的一个结点，返回p所指结点的直接前驱的位置，若无前驱，则返回NULL
Position PriorPos(LinkList L, Link p){
    if(p == L.head) return NULL;
    Link q = L.head;
    while(q->next != p) p = p->next;
    return q;
}

//已知p指向线性链表中的一个结点，返回p所指结点的直接后继的位置，若无前驱，则返回NULL
Position NextPos(LinkList L, Link p){return p->next;}

//返回p指示线性链表L中第i个结点的位置并返回OK，i值不合法时，返回ERROR
Status LocatePos(LinkList L, int i, Link &p){
    if(i < 1 || i > L.len) return ERROR;
    Link q = L.head;
    for(int j = 0; j < i; j++){
        q = q->next;
    }
    p = q;
    return OK;
}

//返回线性链表L中第1个与e满足函数compare()判定关系的元素的位置，若不存在这样的元素，则返回NULL
Position LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType)){
    Link p = L.head->next;
    while(p && !(*compare)(p->data, e)){p = p->next;}
    return p;
}

//依次对L的每个元素调用函数visit()。一旦visit()失败，则操作失败
Status ListTraverse(LinkList L, Status(*visit)(Link)){
    Link p = L.head->next;
    while(p) {
        if(visit(p))
            p = p->next;
        else return ERROR;
    }
    return OK;
}



// //带头节点的单链表的头指针
// //当第i个元素存在时，其值赋给e，并返回OK，否则返回ERROR
// Status GetElem_L(LinkList L, int i, ElemType * e){
//     LinkList p = L;
//     for(int j = 0;)
//     return OK;
// }