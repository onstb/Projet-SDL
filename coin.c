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




#define gravity 9.81;
#define GRAVITY_SPEED 0.6
#define MAX_FALL_SPEED 5
#define JUMP_HEIGHT 14.5
#define SPEED 0.5
#define MAX_SPEED 5


void init_coin(coin *c,int x, int y)
{
	c->tab[0]=IMG_Load("coin/coin1.png");
	c->tab[1]=IMG_Load("coin/coin2.png");
	c->tab[2]=IMG_Load("coin/coin3.png");
	c->tab[3]=IMG_Load("coin/coin4.png");
	c->tab[4]=IMG_Load("coin/coin5.png");
	c->tab[5]=IMG_Load("coin/coin6.png");
	c->tab[6]=IMG_Load("coin/coin7.png");
	c->tab[7]=IMG_Load("coin/coin8.png");

	c->pos.x=x;
	c->pos.y=y;
	c->frame=0;
}
/********************************************************************************************************/
/********************************************************************************************************/
void animer_coin(coin *c)
{
	//SDL_Delay(40);
	if(c->frame==7)
		c->frame=0;
	else
		c->frame++;
}
/********************************************************************************************************/
/********************************************************************************************************/