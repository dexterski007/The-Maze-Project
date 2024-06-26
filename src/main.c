#include <SDL2/SDL.h>
#include <stdio.h>
#include "../headers/glob.h"
#include "../headers/demo.h"
#include "../headers/rayc.h"
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
	gamestate state;

	state.posX = 22;
	state.posY = 12;
	state.dirX = 0;
	state.dirY = -1;
	state.planeX = -0.66;
	state.planeY = 0;
	state.show_map = true;
	parsemap(argv[1], &state);

	SDL_Instance instance;


	if (init_instance(&instance) != 0)
		return (1);

	while ("running")
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_events(&state) == 1)
			break;
		draw_walls(instance.renderer, &state);
		if (state.show_map)
			showmap(instance.renderer, state.posX, state.posY,
					state.dirX, state.dirY, state.worldMap);
		SDL_RenderPresent(instance.renderer);
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}
