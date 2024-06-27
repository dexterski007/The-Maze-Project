#ifndef _RAYC_H_
#define _RAYC_H_


void draw_walls(SDL_Renderer *renderer, gamestate *state,
				SDL_Texture **walltextures);
void turnleft(gamestate *state);
void turnright(gamestate *state);
void moveforward(gamestate *state);
void movebackward(gamestate *state);
void moveleft(gamestate *state);
void moveright(gamestate *state);
void mousemove(int xrel, gamestate *state);
void showmap(SDL_Renderer *renderer, double posX, double posY,
			 double dirX, double dirY, int map[MAP_WIDTH][MAP_HEIGHT]);
void calc_rays(int x, double *raydirX, double *raydirY, double *cameraX,
			   gamestate *state);
void calculate_distance(double raydirX, double raydirY, int *stepX,
						int *stepY, double *sideDistX, double *sideDistY,
						double deltaDistX, double deltaDistY,
						int mapX, int mapY, gamestate *state);
void collision_detect(int *mapX, int *mapY, int stepX, int stepY,
					  double *sideDistX, double *sideDistY,
					  double deltaDistX, double deltaDistY,
					  int *side, int *hit, gamestate *state);
double calculate_perp_wall(int mapX, int mapY, int stepX, int stepY,
						   double raydirX, double raydirY, int side,
						   gamestate *state);



#endif
