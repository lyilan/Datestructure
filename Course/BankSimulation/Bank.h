/*
 * @Author: lyilan
 * @Date: 2021-04-12 13:01:23
 * @Description: for my ying~
 */

#ifndef BANK_H
#define BANK_H

#define CloseTime 100

#include "LinkList.h"
#include "LinkQueue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Event
{
    int OccurTime; //事件发生时刻
    int NType;     //事件类型，0表示到达事件，1至4表示四个窗口的离事件
} Event, ElemType; //事件类型，有序链表LinkList的数据元素类型

typedef LinkList EventList; //事件链表类型，定义为有序链表

typedef struct
{
    int ArrivalTime; //到达时刻
    int Duration;    //办理事务所需时间
} QElemType;         //队列的数据元素类型

// - - - - - 基本操作函数声明 - - - - -

void OpenForDay();
//初始化操作
void CustomerArrived();
//处理客户到达事件
void CustomeDepature();
//处理客户离开事件
void Bank_Simulation();

// - - - - - 内部函数声明 - - - - -
int cmp(Event a, Event b);

void Random(int DurTime, int InterTime);

int Minimum(LinkQueue *q);

#endif