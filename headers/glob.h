#ifndef _GLOB_H_
#define _GLOB_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

/**
 * struct gamestate - game state
 * @posX: player position X
 * @posY: player position Y
 * @dirX: player direction X
 * @dirY: player direction Y
 * @planeX: player plane X
 * @planeY: player plane Y
 * @worldMap: world map
 * @show_map: show map
 * Description: game state
 */

typedef struct gamestate
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	int worldMap[MAP_WIDTH][MAP_HEIGHT];
	bool show_map;
} gamestate;

#endif
