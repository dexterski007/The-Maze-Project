#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "../headers/glob.h"
#include "../headers/demo.h"
#include "../headers/rayc.h"
#include "../headers/textures.h"
#include <stdbool.h>
#include <math.h>

/**
 * init_textures - Initializes textures for a graphics application.
 * @renderer: The renderer used to create the textures.
 *
 * This function initializes textures for a graphics application by loading
 * texture files and creating texture objects from them. The textures are
 * stored in an array and returned to the caller.
 *
 * Return: An array of SDL_Texture pointers representing the
 * initialized textures.
 */

SDL_Texture **init_textures(SDL_Renderer *renderer)
{
	SDL_Texture **textures = malloc(NUM_TEXTURES * sizeof(SDL_Texture *));

	if (textures == NULL)
	{
		fprintf(stderr, "malloc failed\n");
		exit(1);
	}
	const char *textureFiles[NUM_TEXTURES] = {
		"./assets/greystone.jpg",
		"./assets/redbrick.jpg",
		"./assets/floortexture.jpg"
	};
	for (int i = 0; i < NUM_TEXTURES; i++)
	{
		SDL_Surface *surface = IMG_Load(textureFiles[i]);

		if (!surface)
		{
			printf("Failed to load asset %s, %s\n", textureFiles[i],
				   IMG_GetError());
			free(textures);
			return (NULL);
		}
		textures[i] = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
		if (!textures[i])
		{
			printf("Failed to create texture from surface %s, %s\n",
				   textureFiles[i], IMG_GetError());
			for (int j = 0; j < i; j++)
				SDL_DestroyTexture(textures[j]);
			free(textures);
			return (NULL);
		}

	}
	return (textures);
}
/**
 * draw_floor - Draws the floor using the specified
 * renderer and floor texture.
 *
 * @renderer: The renderer used to draw the floor.
 * @floorTexture: The texture used for the floor.
 * @state: A pointer to the gamestate data structure.
 */

void draw_floor(SDL_Renderer *renderer, SDL_Texture *floorTexture,
				gamestate *state)
{
	for (int y = SCREEN_HEIGHT / 2 + 1; y < SCREEN_HEIGHT; y++)
	{
		float rayDirX0 = state->dirX - state->planeX;
		float rayDirY0 = state->dirY - state->planeY;
		float rayDirX1 = state->dirX + state->planeX;
		float rayDirY1 = state->dirY + state->planeY;
		int p = y - SCREEN_HEIGHT / 2;
		float posZ = 0.5 * SCREEN_HEIGHT;
		float rowDistance = posZ / p;
		float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / SCREEN_WIDTH;
		float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / SCREEN_WIDTH;
		float floorX = state->posX + rowDistance * rayDirX0;
		float floorY = state->posY + rowDistance * rayDirY0;

		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			int cellX = (int)floorX;
			int cellY = (int)floorY;
			int tx = (int)(TEXT_WIDTH * (floorX - cellX)) & (TEXT_WIDTH - 1);
			int ty = (int)(TEXT_HEIGHT * (floorY - cellY)) & (TEXT_HEIGHT - 1);

			floorX += floorStepX;
			floorY += floorStepY;
			SDL_Rect src = {tx, ty, 1, 1};
			SDL_Rect dst = {x, y, 1, 1};

			SDL_RenderCopy(renderer, floorTexture, &src, &dst);
		}
	}
}

/**
 * draw_sky - Draws the sky using the specified renderer and sky color.
 *
 * @renderer: The renderer used to draw the sky.
 * @skycolor: The color used for the sky.
 */

void draw_sky(SDL_Renderer *renderer, SDL_Color skycolor)
{
	SDL_SetRenderDrawColor(renderer, skycolor.r,
						   skycolor.g, skycolor.b, skycolor.a);
	SDL_Rect sky = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2};

	SDL_RenderFillRect(renderer, &sky);
}

/**
 * terminate_session - terminate session
 * @instance: instance
 * @walltextures: walltextures
 */

void terminate_session(SDL_Instance instance, SDL_Texture **walltextures)
{
	for (int i = 0; i < NUM_TEXTURES; i++)
		SDL_DestroyTexture(walltextures[i]);
	free(walltextures);
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
}

