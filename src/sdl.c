#include <SDL2/SDL.h>
#include <stdio.h>
#include "../headers/glob.h"
#include "../headers/demo.h"
#include "../headers/rayc.h"
#include <stdbool.h>

/**
 * init_instance - function to initialize instance
 *
 * @instance: instance to initialize
 *
 * Return: 0 if success else 1
 *
 */

int init_instance(SDL_Instance *instance)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return (1);
	}

	instance->window = SDL_CreateWindow("The Maze Project By dexterski007",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
		SCREEN_HEIGHT, 0);
		if (instance->window == NULL)
		{
			fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
			SDL_Quit();
			return (1);
		}

	instance->renderer = SDL_CreateRenderer(instance->window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (instance->renderer == NULL)
		{
			SDL_DestroyWindow(instance->window);
			fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
			SDL_Quit();
			return (1);
		}
	return (0);
}


/**
 * poll_events - function to poll events
 *
 * Return: 1 if exit, 0 otherwise
 *
 */

int poll_events(SDL_Instance *instance)
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return (1);
			case SDL_KEYDOWN:
				key = event.key;
				if (key.keysym.scancode == SDL_SCANCODE_LEFT)
					turnleft(instance->renderer);
				if (key.keysym.scancode == SDL_SCANCODE_RIGHT)
					turnright(instance->renderer);
				if (key.keysym.scancode == SDL_SCANCODE_W)
					moveforward(instance->renderer);
				if (key.keysym.scancode == SDL_SCANCODE_S)
					movebackward(instance->renderer);
				if (key.keysym.scancode == SDL_SCANCODE_A)
					moveleft(instance->renderer);
				if (key.keysym.scancode == SDL_SCANCODE_D)
					moveright(instance->renderer);
				if (key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					return (1);
				break;
		}
	}
	return (0);
}
