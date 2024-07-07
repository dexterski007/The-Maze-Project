#include <SDL2/SDL.h>
#include <stdio.h>
#include "../headers/glob.h"
#include "../headers/demo.h"
#include "../headers/rayc.h"
#include "../headers/textures.h"
#include <stdbool.h>


/**
 * main - Entry point of the program.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * This function serves as the entry point for the program.
 * It takes two parameters, argc and argv, which represent
 * the number of command-line arguments and the array
 * of command-line arguments, respectively. The function
 * returns an integer value of 0 on success, indicating
 * that the program executed successfully. If there was an error
 * during execution, the function returns an integer value of 1.
 *
 * Return: 0 on success, 1 on error.
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
