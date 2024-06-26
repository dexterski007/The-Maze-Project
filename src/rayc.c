#include <SDL2/SDL.h>
#include <stdio.h>
#include "../headers/glob.h"
#include "../headers/demo.h"
#include "../headers/rayc.h"
#include "../headers/textures.h"
#include <stdbool.h>
#include <math.h>

/**
 * calc_rays - calculate rays
 * @x: x
 * @raydirX: raydirX
 * @raydirY: raydirY
 * @cameraX: cameraX
 * @state: state
 * Return: void
 */

void calc_rays(int x, double *raydirX, double *raydirY, double *cameraX,
			   gamestate *state)
{
	*cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
	*raydirX = state->dirX + state->planeX * *cameraX;
	*raydirY = state->dirY + state->planeY * *cameraX;
}

/**
 * calculate_distance - calculate distance
 * @raydirX: raydirX
 * @raydirY: raydirY
 * @stepX: stepX
 * @stepY: stepY
 * @sideDistX: sideDistX
 * @sideDistY: sideDistY
 * @deltaDistX: deltaDistX
 * @deltaDistY: deltaDistY
 * @mapX: mapX
 * @mapY: mapY
 * @state: state
 * Return: void
 */

void calculate_distance(double raydirX, double raydirY, int *stepX,
						int *stepY, double *sideDistX, double *sideDistY,
						double deltaDistX, double deltaDistY,
						int mapX, int mapY, gamestate *state)
{
	if (raydirX < 0)
	{
		*stepX = -1;
		*sideDistX = (state->posX - mapX) * deltaDistX;
	}
	else
	{
		*stepX = 1;
		*sideDistX = (mapX + 1.0 - state->posX) * deltaDistX;
	}
	if (raydirY < 0)
	{
		*stepY = -1;
		*sideDistY = (state->posY - mapY) * deltaDistY;
	}
	else
	{
		*stepY = 1;
		*sideDistY = (mapY + 1.0 - state->posY) * deltaDistY;
	}
}

/**
 * collision_detect - detect collision
 * @mapX: mapX
 * @mapY: mapY
 * @stepX: stepX
 * @stepY: stepY
 * @sideDistX: sideDistX
 * @sideDistY: sideDistY
 * @deltaDistX: deltaDistX
 * @deltaDistY: deltaDistY
 * @side: side
 * @hit: hit
 * @state: state
 * Return: void
 */

void collision_detect(int *mapX, int *mapY, int stepX, int stepY,
					  double *sideDistX, double *sideDistY,
					  double deltaDistX, double deltaDistY,
					  int *side, int *hit, gamestate *state)
{
	while (*hit == 0)
	{
		if (*sideDistX < *sideDistY)
		{
			*sideDistX += deltaDistX;
			*mapX += stepX;
			*side = 0;
		}
		else
		{
			*sideDistY += deltaDistY;
			*mapY += stepY;
			*side = 1;
		}
		if (state->worldMap[*mapX][*mapY] > 0)
			*hit = 1;
	}
}

/**
 * calculate_perp_wall - calculate perp wall
 * @mapX: mapX
 * @mapY: mapY
 * @stepX: stepX
 * @stepY: stepY
 * @raydirX: raydirX
 * @raydirY: raydirY
 * @side: side
 * @state: state
 * Return: perp wall position
  */

double calculate_perp_wall(int mapX, int mapY, int stepX, int stepY,
						   double raydirX, double raydirY, int side,
						   gamestate *state)
{
	if (side == 0)
		return ((mapX - state->posX + (1 - stepX) / 2) / raydirX);
	else
		return ((mapY - state->posY + (1 - stepY) / 2) / raydirY);
}


/**
 * draw_walls - draw walls
 * @renderer: renderer
 * @state: state
 * @walltextures: walltextures
 */

void draw_walls(SDL_Renderer *renderer, gamestate *state,
				SDL_Texture **walltextures)
{
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		double sideDistX, sideDistY, cameraX, raydirX, raydirY;
		int mapX = (int)state->posX, mapY = (int)state->posY,
		stepX, stepY, hit = 0, side;
		double deltaDistX;
		double deltaDistY, perpWallDist;

		calc_rays(x, &raydirX, &raydirY, &cameraX, state);
		deltaDistX = fabs(1 / raydirX);
		deltaDistY = fabs(1 / raydirY);
		calculate_distance(raydirX, raydirY, &stepX, &stepY, &sideDistX,
						   &sideDistY, deltaDistX, deltaDistY, mapX, mapY, state);
		collision_detect(&mapX, &mapY, stepX, stepY, &sideDistX, &sideDistY,
					     deltaDistX, deltaDistY, &side, &hit, state);
		perpWallDist = calculate_perp_wall(mapX, mapY, stepX, stepY,
					   raydirX, raydirY, side, state);
		int line_height = (int)(SCREEN_HEIGHT / perpWallDist);
		int draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
		int draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
		int text_number = state->worldMap[mapX][mapY] - 1;
		double wallX;

		if (side == 0)
			wallX = state->posY + perpWallDist * raydirY;
		else
			wallX = state->posX + perpWallDist * raydirX;
		wallX -= floor(wallX);
		int textX = (int)(wallX * (double)TEXT_WIDTH);

		if (side == 0 && raydirX > 0)
			textX = TEXT_WIDTH - textX - 1;
		if (side == 1 && raydirY < 0)
			textX = TEXT_WIDTH - textX - 1;
		SDL_Rect source_rect = {textX, 0, 1, TEXT_HEIGHT};
		SDL_Rect dest_rect = {x, draw_start, 1, draw_end - draw_start};

		SDL_RenderCopy(renderer, walltextures[text_number], &source_rect,
					   &dest_rect);
	}
}
