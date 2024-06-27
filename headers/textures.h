#ifndef _TEXTURES_H_
#define _TEXTURES_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define NUM_TEXTURES 3
#define TEXT_WIDTH 64
#define TEXT_HEIGHT 64

SDL_Texture **init_textures(SDL_Renderer *renderer);
void draw_floor(SDL_Renderer *renderer, SDL_Texture *floorTexture,
				gamestate *state);
void draw_sky(SDL_Renderer *renderer, SDL_Color skycolor);
void input_process(gamestate *state);
void terminate_session(SDL_Instance instance, SDL_Texture **walltextures);

#endif
