#include <SDL2/SDL.h>
#include <stdio.h>
#include "../headers/glob.h"
#include "../headers/demo.h"
#include "../headers/rayc.h"
#include <stdbool.h>
#include <math.h>

/**
 * moveforward - Moves the player character forward in the game.
 *
 * This function is responsible for moving the player
 * character forward in the game. It takes a gamestate
 * data structure as a parameter.
 *
 * @state: A pointer to the gamestate data structure.
 *
 * Return: void
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
 * movebackward - Moves the player character backward in the game.
 *
 * This function is responsible for moving the player
 * character backward in the game. It takes a gamestate
 * data structure as a parameter.
 *
 * @state: A pointer to the gamestate data structure.
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
 * moveleft - Moves the player character to the left in the game.
 *
 * This function is responsible for moving the player character to the left
 * in the game. It takes a gamestate data structure as a parameter.
 *
 * @state: A pointer to the gamestate data structure.
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
 * moveright - Moves the player character to the right in the game.
 *
 * This function is responsible for moving the player character to the right
 * in the game. It takes a gamestate data structure as a parameter.
 *
 * @state: A pointer to the gamestate data structure.
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
