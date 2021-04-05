/*
 * @Author: lyilan
 * @Date: 2021-04-04 14:49:04
 * @Description: for my ying~
 */

#ifndef EPRESSION_H
#define EPRESSION_H

#include "SqStack.h"
#include "../../Status/Status.h"

typedef SElemType OperandType;
typedef SElemType OperatorType;

//运算符表
static const char OP[] = {'+', '-', '*', '/', '(', ')', '#'};

//运算符优先级表
static const char PrecedeTable[7][7] = {{'>', '>', '<', '<', '<', '>', '>'},
                                        {'>', '>', '<', '<', '<', '>', '>'},
                                        {'>', '>', '>', '>', '<', '>', '>'},
                                        {'>', '>', '>', '>', '<', '>', '>'},
                                        {'<', '<', '<', '<', '<', '=', ' '},
                                        {'>', '>', '>', '>', ' ', '>', '>'},
                                        {'<', '<', '<', '<', '<', ' ', '='}};

//————————操作函数原型说明————————//

OperandType EvaluateExpression(const char exp[]); //表达式求值

Status In(SElemType c, const char *OP); //判断c是否是运算符

char Precede(OperatorType e1, OperatorType e2); //返回运算符e1和e2的优先级关系

SElemType Operate(OperatorType a, OperandType theta, OperatorType b); //将a theta b 运算后的结果返回

#endif