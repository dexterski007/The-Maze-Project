#ifndef _DEMO_H_
#define _DEMO_H_

#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define movespeed 0.05
#define mouse_sensivity 0.01

/**
 * struct SDL_Instance - SDL instance structure
 * @window: SDL window
 * @renderer: SDL renderer
 */

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance *);
void init_gamestate(gamestate *state);
int poll_events(gamestate *state);
void parsemap(const char *filename, gamestate *state);

#endif
