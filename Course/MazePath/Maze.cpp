/*
 * @Author: lyilan
 * @Date: 2021-04-03 11:37:30
 * @Description: for my ying~
 */

#include "Maze.h"

Status MazePath(MazeType maze, PosType start, PosType end) //迷宫求解
{
    SqStack S;              //存储探索过的通道块
    SElemType e;            //存储路径信息变量 e
    PosType curpos = start; //设定当前位置为入口位置
    int curstep = 1;        //探索第一步

    InitStack(S);

    do
    {
        if (Pass(maze, curpos)) //当前位置可以通过，即是未曾走到的通道块
        {
            FootPrint(maze, curpos); //留下足迹

            //保存路径信息
            e = Construct(curstep, curpos, East);

            Push(S, e); //存入路径

            if (Equal(curpos, end)) //到达终点
            {
                return TRUE;
                printf("\n 寻路成功 ！！！\n\n");
            }
            curpos = NextPos(curpos, East); //下一位置是当前位置的东邻
            curstep++;                      //探索下一步
        }
        else
        {
            if (!StackEmpty(S))
            {
                Pop(S, e);
                while (e.di == North && !StackEmpty(S))
                {
                    MarkPrint(maze, e.seat, Impasse); //留下不能通过的标记
                    Pop(S, e);
                }
                if (e.di < North)
                {
                    e.di++; //换一个方向，继续探索
                    Push(S, e);
                    curpos = NextPos(e.seat, e.di); //设定当前位置是该新方向上的相邻块

                } //if
            }     //if
        }         //else
    } while (!StackEmpty(S));
    printf("\n 寻路失败 \n\n");
    return FALSE;
}

void InitMaze(MazeType maze, PosType &start, PosType &end) //构造一个迷宫
{
    int i, j, tmp;

    srand((unsigned)time(NULL)); //用系统时间作随机数种子

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            //迷宫最外层生成墙
            if (j == 0 || i == 0 || i == M - 1 || j == N - 1)
                maze[i][j] = Wall;
            else
            {
                tmp = rand() % X;
                if (tmp == 0)
                {
                    maze[i][j] = Obstacle;
                }
                else
                {
                    maze[i][j] = Way;
                }
            } //else
        }     //for
    }         //for

    //迷宫入口坐标
    start.x = 1;
    start.y = 0;

    //迷宫出口坐标
    end.x = M - 2;
    end.y = N - 2;

    //开放入口和出口
    maze[1][0] = maze[M - 2][N - 1] = Way;

    maze[1][1] = maze[M - 2][N - 2] = Way;

    PaintMaze(maze);
}

Status Pass(MazeType maze, PosType p) //判断当前位置是否可通，若可通返回TRUE，不可通返回FALSE
{
    //检查越界
    if (p.x < 0 || p.x > M || p.y < 0 || p.y > N)
        return FALSE;

    //要求该位置为未曾探索的块
    if (maze[p.x][p.y] != Way)
        return FALSE;
    else
        return TRUE;
}

Status FootPrint(MazeType maze, PosType p) //留下足迹，也即标记位置p，此处不再可通
{
    MarkPrint(maze, p, East);
    return OK;
}

Status MarkPrint(MazeType maze, PosType p, int mark) //标记p位置，不同通过
{
    maze[p.x][p.y] = mark;
    PaintMaze(maze);
    return OK;
}

PosType NextPos(PosType p, int di) //返回位置p在di方向上的下一个位置
{
    PosType nextp = p;

    switch (di)
    {
    case East:
        nextp.y++;
        break;
    case South:
        nextp.x++;
        break;
    case West:
        nextp.y--;
        break;
    case North:
        nextp.x--;
        break;
    }
    return nextp;
}

SElemType Construct(int ord, PosType seat, int di) //构造一个通道信息，并返回
{
    SElemType e;
    e.di = di;
    e.seat = seat;
    e.ord = ord;
    return e;
}

Status Equal(PosType a, PosType b) //比较两个坐标是否相等
{
    if (a.x == b.x && a.y == b.y)
        return TRUE;
    else
        return FALSE;
}

void PaintMaze(MazeType maze) //打印迷宫
{
    int i, j;

    system("sleep 1");
    system("clear");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (maze[i][j] == Wall)
            { // 外墙
                printf("🧱");
            }
            else if (maze[i][j] == Obstacle)
            { // 迷宫内部的障碍
                printf("🧱");
            }
            else if (maze[i][j] == East)
            { // 正在朝东探索
                printf("🐶");
            }
            else if (maze[i][j] == South)
            { // 正在朝南探索
                printf("🐶");
            }
            else if (maze[i][j] == West)
            { // 正在朝西探索
                printf("🐶");
            }
            else if (maze[i][j] == North)
            { // 正在朝北探索
                printf("🐶");
            }
            else if (maze[i][j] == Impasse)
            { // 死胡同，即四个方向都探索过，但无法通过的位置
                printf("  ");
            }
            else
            { // 还未探索过的路径结点
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
    return;
}