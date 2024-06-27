#include <SDL2/SDL.h>
#include <stdio.h>
#include "../headers/glob.h"
#include "../headers/demo.h"
#include "../headers/rayc.h"
#include "../headers/textures.h"
#include <stdbool.h>
#include <math.h>

/**
 * turnright - turn right
 * @state: state
 *
 */

void turnright(gamestate *state)
{
	double oldDirX = state->dirX;

	state->dirX = state->dirX * cos(-movespeed) - state->dirY *
				  sin(-movespeed);
	state->dirY = oldDirX * sin(-movespeed) + state->dirY * cos(-movespeed);
	double oldPlaneX = state->planeX;

	state->planeX = state->planeX * cos(-movespeed) -
					state->planeY * sin(-movespeed);
	state->planeY = oldPlaneX * sin(-movespeed) +
					state->planeY * cos(-movespeed);
}

/**
 * turnleft - turn left
 * @state: state
 *
 */

void turnleft(gamestate *state)
{
	double oldDirX = state->dirX;

	state->dirX = state->dirX * cos(movespeed) - state->dirY * sin(movespeed);
	state->dirY = oldDirX * sin(movespeed) + state->dirY * cos(movespeed);
	double oldPlaneX = state->planeX;

	state->planeX = state->planeX * cos(movespeed) - state->planeY *
					sin(movespeed);
	state->planeY = oldPlaneX * sin(movespeed) + state->planeY *
					cos(movespeed);
}

/**
 * mousemove - move the mouse
 * @xrel: the relative x position
 * @state: the game state
 *
 */

void mousemove(int xrel, gamestate *state)
{
	double oldDirX = state->dirX;

	state->dirX = state->dirX * cos(-xrel * mouse_sensivity)
		  - state->dirY * sin(-xrel * mouse_sensivity);
	state->dirY = oldDirX * sin(-xrel * mouse_sensivity)
		  + state->dirY * cos(-xrel * mouse_sensivity);
	double oldPlaneX = state->planeX;

	state->planeX = state->planeX * cos(-xrel * mouse_sensivity)
		    - state->planeY * sin(-xrel * mouse_sensivity);
	state->planeY = oldPlaneX * sin(-xrel * mouse_sensivity)
			+ state->planeY * cos(-xrel * mouse_sensivity);
}

/**
 * showmap - show the map
 * @renderer: the renderer
 * @posX: the x position
 * @posY: the y position
 * @dirX: the x direction
 * @dirY: the y direction
 * @map: the map
 *
 */

void showmap(SDL_Renderer *renderer, double posX, double posY, double dirX,
				double dirY, int map[MAP_WIDTH][MAP_HEIGHT])
{
	int map_scale = 5;

	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if (map[x][y] == 1)
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			else
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_Rect rect = { (MAP_WIDTH - 1 - x) * map_scale,
							(MAP_HEIGHT - 1 - y) * map_scale,
							map_scale, map_scale};

			SDL_RenderFillRect(renderer, &rect);
		}
	}
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_Rect p_position = {(MAP_WIDTH - 1 - posX) * map_scale - map_scale / 2,
						  (MAP_HEIGHT - 1 - posY) * map_scale - map_scale / 2,
						  map_scale, map_scale};

	SDL_RenderFillRect(renderer, &p_position);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderDrawLine(renderer, (MAP_WIDTH - 1 - posX) * map_scale,
					   (MAP_HEIGHT - 1 - posY) * map_scale,
					   (MAP_WIDTH - 1 - (posX + dirX)) * map_scale,
					   (MAP_HEIGHT - 1 - (posY + dirY)) * map_scale);
}
