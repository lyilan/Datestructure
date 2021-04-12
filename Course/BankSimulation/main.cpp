/*
 * @Author: lyilan
 * @Date: 2021-04-12 13:47:32
 * @Description: for my ying~
 */

#include "Bank.h"

EventList ev;               //事件表
EventList en;               //事件
LinkQueue q[5];             //四个客户队列
QElemType customer;         //客户记录
int TotalTime, CustomerNum; //累计客户逗留时间，客户数