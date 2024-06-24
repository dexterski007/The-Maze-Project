#include <SDL2/SDL.h>
#include <stdio.h>
#include "../headers/glob.h"
#include "../headers/demo.h"
#include "../headers/rayc.h"
#include <stdbool.h>



/**
 * main - Entry point
 *
 * Return: 0 on success else 1
 *
 */

int main(void)
{
	SDL_Instance instance;


	if (init_instance(&instance) != 0)
		return (1);

	while ("running")
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_events(&instance) == 1)
			break;
		draw_walls(instance.renderer);
		SDL_RenderPresent(instance.renderer);
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}
