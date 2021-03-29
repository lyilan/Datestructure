#ifndef STATUS_H
#define STATUS_H

#include <stdio.h>

// 状态码
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0

//防止堆栈溢出，并防止与系统代码冲突
#ifndef OVERFLOW
#define OVERFLOW -2
#endif


#ifndef NULL
#define NULL ((void*)0)
#endif

//状态代码类型
typedef int Status;

#endif

