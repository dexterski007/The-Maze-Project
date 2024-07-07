#include <SDL2/SDL.h>
#include <stdio.h>
#include "../headers/glob.h"
#include "../headers/demo.h"
#include "../headers/rayc.h"
#include "../headers/textures.h"
#include <stdbool.h>
#include <math.h>

/**
 * calc_rays - Calculate the direction of the rays for a given x-coordinate.
 * @x: The x-coordinate.
 * @raydirX: Pointer to the variable to store the x-coordinate of the ray.
 * @raydirY: Pointer to the variable to store the y-coordinate of the ray.
 * @cameraX: Pointer to the variable to store the x-coordinate of the camera.
 * @state: Pointer to the gamestate data.
 *
 * This function calculates the direction of the rays for a given x-coordinate
 * on the screen. It uses the camera position, direction, and plane vectors
 * from the gamestate data to calculate the ray direction.
 */
void calc_rays(int x, double *raydirX, double *raydirY, double *cameraX,
			   gamestate *state)
{
	*cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
	*raydirX = state->dirX + state->planeX * *cameraX;
	*raydirY = state->dirY + state->planeY * *cameraX;
}

/**
 * calculate_distance - Calculate the distance to the next wall or boundary.
 * @raydirX: The x-coordinate of the ray.
 * @raydirY: The y-coordinate of the ray.
 * @stepX: Pointer to the variable to store the x step.
 * @stepY: Pointer to the variable to store the y step.
 * @sideDistX: Pointer to the variable to store the x side distance.
 * @sideDistY: Pointer to the variable to store the y side distance.
 * @deltaDistX: The difference of distance in x.
 * @deltaDistY: The difference of distance in y.
 * @mapX: The x-coordinate of the map.
 * @mapY: The y-coordinate of the map.
 * @state: Pointer to the gamestate data.
 *
 * This function calculates the distance to the next wall or boundary
 * in the direction of the ray. It uses the ray direction, step size,
 * and side distances to calculate the distance.
 */
void calculate_distance(double raydirX, double raydirY, int *stepX, int *stepY,
						double *sideDistX, double *sideDistY,
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
 * collision_detect - Detect collision with walls.
 * @mapX: Pointer to the variable to store the x-coordinate of the map.
 * @mapY: Pointer to the variable to store the y-coordinate of the map.
 * @stepX: The x step.
 * @stepY: The y step.
 * @sideDistX: The x side distance.
 * @sideDistY: The y side distance.
 * @deltaDistX: The difference of distance in x.
 * @deltaDistY: The difference of distance in y.
 * @side: Pointer to the variable to store the side of the wall.
 * @hit: Pointer to the variable to store the hit flag.
 * @state: Pointer to the gamestate data.
 *
 * This function detects collision with walls by incrementing the
 * map coordinates
 * and side distances until a wall is hit. It updates the map coordinates,
 * side distances, side of the wall, and hit flag accordingly.
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
 * calculate_perp_wall - Calculate the perpendicular distance to the wall.
 * @mapX: The x-coordinate of the map.
 * @mapY: The y-coordinate of the map.
 * @stepX: The x step.
 * @stepY: The y step.
 * @raydirX: The x-coordinate of the ray.
 * @raydirY: The y-coordinate of the ray.
 * @side: The side of the wall.
 * @state: Pointer to the gamestate data.
 *
 * This function calculates the perpendicular distance to the wall
 * based on the map coordinates, step size, ray direction,
 * and side of the wall.
 * Return: the calculated perpendicular wall distance.
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
 * draw_walls - Draw the walls on the screen.
 * @renderer: The SDL renderer.
 * @state: Pointer to the gamestate data.
 * @walltextures: Array of wall textures.
 *
 * This function draws the walls on the screen using the SDL renderer.
 * It calculates the ray direction, distance to the wall,
 * and texture coordinates
 * for each x-coordinate on the screen. It then renders the wall texture
 * on the corresponding portion of the screen.
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
