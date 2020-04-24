#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "def.h"
#include "background.h"
#include "perssonage.h"
#include "jouer.h"
#include "mouvement.h"
#include "collision.h"
#include "coin.h"
#include "coeur.h"
#include "enemi.h"



/*#define gravity 9.81;
#define GRAVITY_SPEED 0.6
#define MAX_FALL_SPEED 5
#define JUMP_HEIGHT 14.5
#define SPEED 1.4
#define MAX_SPEED 25*/





void scrolling_right (background *b,perssonage *p,SDL_Surface *screen)
{
	if (b->camera.x<8000-800)
	{
		b->x_relative+=p->xvelocity;
		b->camera.x+=p->xvelocity;
	}
}

void scrolling_left (background *b,perssonage *p,SDL_Surface *screen)
{
	if (b->camera.x>50)
	{
		b->x_relative-=p->xvelocity;
		b->camera.x-=p->xvelocity;
	}


}