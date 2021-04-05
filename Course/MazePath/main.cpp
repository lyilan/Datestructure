/*
 * @Author: lyilan
 * @Date: 2021-04-03 17:20:00
 * @Description: for my ying~
 * 
 */
#include "Maze.h"

int main()
{
    MazeType maze;
    PosType start, end;
    char n, Re = 'Y';

    while (Re == 'Y' || Re == 'y')
    {
        InitMaze(maze, start, end);
        
        MazePath(maze, start, end);

        printf("以莹妹之名再玩一遍：（Y/N）");
        scanf("%c%c", &Re, &n);

        printf("\n");
    }
    return 0;
}