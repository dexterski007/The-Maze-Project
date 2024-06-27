#ifndef _GLOB_H_
#define _GLOB_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

/**
 * struct keystate - key state
 * @w: w
 * @a: a
 * @s: s
 * @d: d
 * @left: left
 * @right: right
 */

typedef struct keystate
{
	bool w;
	bool a;
	bool s;
	bool d;
	bool left;
	bool right;
} keystate;

/**
 * struct gamestate - game state
 * @posX: player position X
 * @posY: player position Y
 * @dirX: player direction X
 * @dirY: player direction Y
 * @planeX: player plane X
 * @planeY: player plane Y
 * @worldMap: world map
 * @keys: keys
 * @move_forward: move forward
 * @move_backward: move backward
 * @move_left: move left
 * @move_right: move right
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
	keystate keys;
	bool move_forward;
	bool move_backward;
	bool move_left;
	bool move_right;
	bool show_map;
} gamestate;

#endif
