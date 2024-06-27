#include <SDL2/SDL.h>
#include <stdio.h>
#include "../headers/glob.h"
#include "../headers/demo.h"
#include "../headers/rayc.h"
#include "../headers/textures.h"
#include <stdbool.h>



/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0 on success else 1
 *
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "You need to provide a 24 x 24 map as argument\n");
		return (EXIT_FAILURE);
	}
	SDL_Color skycolor = {39, 121, 245, 0.8};
	int leave = 0;
	gamestate state;

	init_gamestate(&state);
	parsemap(argv[1], &state);

	SDL_Instance instance;

	if (init_instance(&instance) != 0)
		return (1);
	SDL_Texture **walltextures = init_textures(instance.renderer);

	if (walltextures == NULL)
		return (1);
	while (!leave)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		leave = poll_events(&state);
		input_process(&state);
		draw_sky(instance.renderer, skycolor);
		draw_floor(instance.renderer, walltextures[2], &state);
		draw_walls(instance.renderer, &state, walltextures);
		if (state.show_map)
			showmap(instance.renderer, state.posX, state.posY,
					state.dirX, state.dirY, state.worldMap);
		SDL_RenderPresent(instance.renderer);
	}
	terminate_session(instance, walltextures);
	return (0);
}
