#include <SDL2/SDL.h>
#include <stdio.h>
#include "../headers/glob.h"
#include "../headers/demo.h"
#include "../headers/rayc.h"
#include <stdbool.h>
#include <math.h>

/**
 * moveforward - move forward
 * @state: state
 *
 */

void moveforward(gamestate *state)
{
	if (state->worldMap[(int)(state->posX + state->dirX
		* movespeed)][(int)state->posY] == false)
		state->posX += state->dirX * movespeed;
	if (state->worldMap[(int)state->posX][(int)(state->posY + state->dirY
		* movespeed)] == false)
		state->posY += state->dirY * movespeed;
	if (state->posX < 0)
		state->posX = 0;
	if (state->posX >= MAP_WIDTH)
		state->posX = MAP_WIDTH - 1;
	if (state->posY < 0)
		state->posY = 0;
	if (state->posY >= MAP_HEIGHT)
		state->posY = MAP_HEIGHT - 1;

}
/**
 * movebackward - move backward
 * @state: state
 *
 */

void movebackward(gamestate *state)
{
	if (state->worldMap[(int)(state->posX - state->dirX * movespeed)]
		[(int)state->posY] == false)
		state->posX -= state->dirX * movespeed;
	if (state->worldMap[(int)state->posX][(int)
		(state->posY - state->dirY * movespeed)] == false)
		state->posY -= state->dirY * movespeed;
	if (state->posX < 0)
		state->posX = 0;
	if (state->posX >= MAP_WIDTH)
		state->posX = MAP_WIDTH - 1;
	if (state->posY < 0)
		state->posY = 0;
	if (state->posY >= MAP_HEIGHT)
		state->posY = MAP_HEIGHT - 1;
}

/**
 * moveleft - move left
 * @state: state
 *
 */

void moveleft(gamestate *state)
{
	if (state->worldMap[(int)(state->posX - state->planeX * movespeed)]
		[(int)state->posY] == false)
		state->posX -= state->planeX * movespeed;
	if (state->worldMap[(int)state->posX]
		[(int)(state->posY - state->planeY * movespeed)] == false)
		state->posY -= state->planeY * movespeed;
	if (state->posX < 0)
		state->posX = 0;
	if (state->posX >= MAP_WIDTH)
		state->posX = MAP_WIDTH - 1;
	if (state->posY < 0)
		state->posY = 0;
	if (state->posY >= MAP_HEIGHT)
		state->posY = MAP_HEIGHT - 1;
}

/**
 * moveright - move right
 * @state: the game state
 *
 */

void moveright(gamestate *state)
{
	if (state->worldMap[(int)(state->posX + state->planeX * movespeed)]
		[(int)state->posY] == false)
		state->posX += state->planeX * movespeed;
	if (state->worldMap[(int)state->posX]
		[(int)(state->posY + state->planeY * movespeed)] == false)
		state->posY += state->planeY * movespeed;
	if (state->posX < 0)
		state->posX = 0;
	if (state->posX >= MAP_WIDTH)
		state->posX = MAP_WIDTH - 1;
	if (state->posY < 0)
		state->posY = 0;
	if (state->posY >= MAP_HEIGHT)
		state->posY = MAP_HEIGHT - 1;
}
