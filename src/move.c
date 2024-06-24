#include <SDL2/SDL.h>
#include <stdio.h>
#include "../headers/glob.h"
#include "../headers/demo.h"
#include "../headers/rayc.h"
#include <stdbool.h>

void turnright()
{
    double oldDirX = dirX;
    dirX = dirX * cos(-movespeed) - dirY * sin(-movespeed);
    dirY = oldDirX * sin(-movespeed) + dirY * cos(-movespeed);
    double oldPlaneX = planeX;
    planeX = planeX * cos(-movespeed) - planeY * sin(-movespeed);
    planeY = oldPlaneX * sin(-movespeed) + planeY * cos(-movespeed);
}

void turnleft()
{
    double oldDirX = dirX;
    dirX = dirX * cos(movespeed) - dirY * sin(movespeed);
    dirY = oldDirX * sin(movespeed) + dirY * cos(movespeed);
    double oldPlaneX = planeX;
    planeX = planeX * cos(movespeed) - planeY * sin(movespeed);
    planeY = oldPlaneX * sin(movespeed) + planeY * cos(movespeed);
}
void moveforward()
{
    if (worldMap[(int)(posX + dirX * movespeed)][(int)posY] == false)
        posX += dirX * movespeed;
    if (worldMap[(int)posX][(int)(posY + dirY * movespeed)] == false)
        posY += dirY * movespeed;
}
void movebackward()
{
    if (worldMap[(int)(posX - dirX * movespeed)][(int)posY] == false)
        posX -= dirX * movespeed;
    if (worldMap[(int)posX][(int)(posY - dirY * movespeed)] == false)
        posY -= dirY * movespeed;
}
void moveleft()
{
    if (worldMap[(int)(posX - planeX * movespeed)][(int)posY] == false)
        posX -= planeX * movespeed;
    if (worldMap[(int)posX][(int)(posY - planeY * movespeed)] == false)
        posY -= planeY * movespeed;
}
void moveright()
{
    if (worldMap[(int)(posX + planeX * movespeed)][(int)posY] == false)
        posX += planeX * movespeed;
    if (worldMap[(int)posX][(int)(posY + planeY * movespeed)] == false)
        posY += planeY * movespeed;
}
