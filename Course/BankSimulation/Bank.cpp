/*
 * @Author: lyilan
 * @Date: 2021-04-12 13:55:47
 * @Description: for my ying~
 */

#include "Bank.h"

EventList ev;               //事件表
Event en;                   //事件
LinkQueue q[5];             //四个客户队列
QElemType customer;         //客户记录
int TotalTime, CustomerNum; //累计客户逗留时间，客户数

// - - - - - 基本操作函数实现 - - - - -

void OpenForDay()
{
    //初始化操作
    TotalTime = 0;   //初始化累计时间为0
    CustomerNum = 0; //初始化客户数为0
    InitList(ev);    //初始化事件链表为空表
    en.OccurTime = 0;
    en.NType = 0;
    OrderInsert(ev, en, cmp);
    for (int i = 1; i <= 4; ++i)
    {
        InitQueue(q[i]);
    }
}

void CustomerArrived()
{
    //处理客户到达事件
    ++CustomerNum;
    int durtime, intertime;
    Random(durtime, intertime);       //生成随机数
    int t = en.OccurTime + intertime; //下一客户到达时刻
    if (t < CloseTime)                //银行尚未关门，插入事件表
    {
        OrderInsert(ev, {t, 0}, cmp);
    }
    int i = Minimum(q); //求长度最短队列
    EnQueue(q[i], {en.OccurTime, durtime});
    if (QueueLength(q[i]) == 1)
    {
        OrderInsert(ev, {en.OccurTime + durtime, i}, cmp);
        //设定第i个队列的一个离开事件并插入事件表}
    }
}

void CustomeDepature()
{
    //处理客户离开事件
    int i = en.NType;
    DelQueue(q[i], customer);                         //删除第i队列的排头客户
    TotalTime += en.OccurTime - customer.ArrivalTime; //累计客户逗留时间

    if (!QueueEmpty(q[i])) //设定第i队列的排头客户
    {
        GetHead(q[i], customer);
        OrderInsert(ev, {en.OccurTime + customer.Duration, i}, cmp);
    }
}

void Bank_Simulation()
{
    OpenForDay(); //初始化
    Position p;
    while (!ListEmpty(ev))
    {
        DelFirst(GetHead(ev), p);
        en = GetCurElem(p);
        if (en.NType == 0)
            CustomerArrived(); //处理客户到达事件
        else
            CustomeDepature(); //处理客户离开事件
    }
    printf("The Average Time is %f\n", (float)TotalTime / CustomerNum);
}

// - - - - - 内部函数实现 - - - - -
int cmp(Event a, Event b);

void Random(int DurTime, int InterTime);

int Minimum(LinkQueue *q);