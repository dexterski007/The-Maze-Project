#include <SDL2/SDL.h>
#include <stdio.h>
#include "../headers/glob.h"
#include "../headers/demo.h"
#include "../headers/rayc.h"
#include "../headers/textures.h"
#include <stdbool.h>

/**
 * init_gamestate - function to initialize gamestate
 * @state: gamestate to initialize
 */

void init_gamestate(gamestate *state)
{
	state->posX = 22;
	state->posY = 12;
	state->dirX = 0;
	state->dirY = -1;
	state->planeX = -0.66;
	state->planeY = 0;
	state->show_map = true;
	state->keys.left = false;
	state->keys.right = false;
	state->keys.w = false;
	state->keys.s = false;
	state->keys.a = false;
	state->keys.d = false;
}

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
 * @state: state
 *
 * Return: 1 if exit, 0 otherwise
 */

int poll_events(gamestate *state)
{
	SDL_Event event;
	SDL_KeyboardEvent key;
	int xrel;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return (1);
			case SDL_KEYDOWN:
			case SDL_KEYUP:
				key = event.key;
				bool keydown = (event.type == SDL_KEYDOWN);

				if (key.keysym.scancode == SDL_SCANCODE_M)
					state->show_map = !state->show_map;
				if (key.keysym.scancode == SDL_SCANCODE_LEFT)
					state->keys.left = keydown;
				if (key.keysym.scancode == SDL_SCANCODE_RIGHT)
					state->keys.right = keydown;
				if (key.keysym.scancode == SDL_SCANCODE_W)
					state->keys.w = keydown;
				if (key.keysym.scancode == SDL_SCANCODE_S)
					state->keys.s = keydown;
				if (key.keysym.scancode == SDL_SCANCODE_A)
					state->keys.a = keydown;
				if (key.keysym.scancode == SDL_SCANCODE_D)
					state->keys.d = keydown;
				if (key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					return (1);
				break;
			case SDL_MOUSEMOTION:
				xrel = event.motion.xrel;
				mousemove(xrel, state);
		}
	}
	return (0);
}

/**
 * parsemap - parse the map
 * @filename: the map file
 * @state: the game state
 *
 */

void parsemap(const char *filename, gamestate *state)
{
	FILE *file = fopen(filename, "r");

	if (!file)
	{
		fprintf(stderr, "mapfile cannot be opened\n");
		exit(EXIT_FAILURE);
	}

	char line[MAP_WIDTH + 2];
	int i = 0;

	while (fgets(line, sizeof(line), file) && i < MAP_HEIGHT)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (line[j] == '1')
				state->worldMap[i][j] = 1;
			else if (line[j] == '0')
				state->worldMap[i][j] = 0;
			else
			{
				fprintf(stderr, "Invalid char in map at row %d, column %d\n",
						i, j);
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
}

/**
 * input_process - process input
 * @state: the game state
 */

void input_process(gamestate *state)
{
	if (state->keys.left)
		turnleft(state);
	if (state->keys.right)
		turnright(state);
	if (state->keys.w && !state->keys.s)
		moveforward(state);
	if (state->keys.s && !state->keys.w)
		movebackward(state);
	if (state->keys.a && !state->keys.d)
		moveleft(state);
	if (state->keys.d && !state->keys.a)
		moveright(state);
}
