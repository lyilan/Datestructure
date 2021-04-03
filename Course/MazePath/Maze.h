/*
 * @Author: lyilan
 * @Date: 2021-04-03 11:37:17
 * @Description: for my ying~
 */
#ifndef MAZE_H
#define MAZE_H

#include "SqStack.h"
#include <time.h>

//————————宏定义————————//

#define M 20 //迷宫行数
#define N 20 //迷宫列数

#define X 4 //迷宫出现障碍的概率；

#define Sleeptime 3 //打印地图时的时间间隔

//————————迷宫类型定义————————//
typedef enum
{
    Wall,     //外墙
    Obstacle, //迷宫内部障碍
    Way,      //通路
    Impasse,  //“死胡同”
    East,     //探索方向
    South,
    West,
    North
} MazeNode;

typedef int MazeType[M][N]; // 迷宫类型

//————————操作函数原型说明————————//
void InitMaze(MazeType maze, PosType &start, PosType &end); //构造一个迷宫

Status MazePath(MazeType maze, PosType start, PosType end); //走迷宫函数

Status Pass(MazeType maze, PosType p); //判断当前位置是否可通，若可通返回TRUE，不可通返回FALSE

Status FootPrint(MazeType maze, PosType p); //留下足迹，也即标记位置p，此处不再可通

Status MarkPrint(MazeType maze, PosType p, int mark); //标记p位置，不同通过

PosType NextPos(PosType p, int di); //返回位置p在di方向上的下一个位置

SElemType Construct(int ord, PosType seat, int di); //构造一个通道信息，并返回

Status Equal(PosType a, PosType b); //比较两个坐标是否相等

void PaintMaze(MazeType maze); //打印迷宫

#endif