#include <SDL2/SDL.h>
#include <stdio.h>
#include "../headers/glob.h"
#include "../headers/demo.h"
#include "../headers/rayc.h"
#include "../headers/textures.h"
#include <stdbool.h>
#include <math.h>

/**
 * turnright - function to turn the camera right
 * @state: A pointer to gamestate data structure
 *
 * This function updates the direction and plane vectors of the camera
 * in the gamestate structure to simulate a right turn.
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
 * turnleft - Function to turn the camera left.
 *
 * This function is responsible for turning the camera left in the game.
 * It takes a gamestate data structure as a parameter.
 *
 * @state: The gamestate data structure.
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
 * mousemove - Moves the mouse to a new position.
 *
 * This function is responsible for moving the mouse
 * to a new position on the screen. It takes the relative
 * x position as a parameter and updates the gamestate accordingly.
 *
 * @xrel: The relative x position to move the mouse to.
 * @state: The gamestate data structure.
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
 * showmap - Function to render the map on the screen.
 *
 * This function takes the renderer instance, player position,
 * player direction, and the map as parameters.
 * It renders the map on the screen using the provided
 * renderer, highlighting walls with black color and empty
 * spaces with white color. It also draws a red rectangle
 * to represent the player's position and a green line
 * to represent the player's line of sight.
 *
 * @renderer: The renderer instance used to render the map.
 * @posX: The x position of the player.
 * @posY: The y position of the player.
 * @dirX: The x direction of the player.
 * @dirY: The y direction of the player.
 * @map: The map array containing the layout of the game world.
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
