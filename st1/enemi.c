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


void inisialiser_fire (fire *f)
{
f->fire=IMG_Load("enemi/fire.png");
f->rect.x=650;
f->rect.y=400;
f->rect.w=50;
f->rect.h=50;
f->frame=0;
}
void afficher_fire (fire *f,SDL_Surface *screen)
{
	SDL_BlitSurface(f->fire,&f->rects[f->frame],screen,&f->rect);
}
/*********************************************************************************************************/
/*********************************************************************************************************/
void setrects_fire(SDL_Rect* clip)
{
clip[0].x=0;
clip[0].y=0;
clip[0].w=50;
clip[0].h=55;

clip[1].x=75;
clip[1].y=0;
clip[1].w=50;
clip[1].h=55;

clip[2].x=150;
clip[2].y=0;
clip[2].w=50;
clip[2].h=55;

clip[3].x=125;
clip[3].y=0;
clip[3].w=50;
clip[3].h=55;

clip[4].x=190;
clip[4].y=0;
clip[4].w=50;
clip[4].h=50;

clip[5].x=265;
clip[5].y=0;
clip[5].w=50;
clip[5].h=55;

clip[6].x=340;
clip[6].y=0;
clip[6].w=50;
clip[6].h=55;

clip[7].x=405;
clip[7].y=0;
clip[7].w=50;
clip[7].h=55;

clip[8].x=840;
clip[8].y=0;
clip[8].w=100;
clip[8].h=110;

clip[9].x=945;
clip[9].y=0;
clip[9].w=100;
clip[9].h=110;

clip[10].x=0;
clip[10].y=120;
clip[10].w=100;
clip[10].h=110;

clip[11].x=105;
clip[11].y=120;
clip[11].w=100;
clip[11].h=110;

clip[12].x=210;
clip[12].y=120;
clip[12].w=100;
clip[12].h=110;

clip[13].x=315;
clip[13].y=120;
clip[13].w=100;
clip[13].h=110;

clip[14].x=420;
clip[14].y=120;
clip[14].w=100;
clip[14].h=110;

clip[15].x=0;
clip[15].y=120;
clip[15].w=100;
clip[15].h=110;

clip[16].x=105;
clip[16].y=120;
clip[16].w=100;
clip[16].h=110;

clip[17].x=210;
clip[17].y=120;
clip[17].w=100;
clip[17].h=110;

clip[18].x=315;
clip[18].y=120;
clip[18].w=100;
clip[18].h=110;

clip[19].x=420;
clip[19].y=120;
clip[19].w=100;
clip[19].h=110;

clip[20].x=105;
clip[20].y=240;
clip[20].w=100;
clip[20].h=110;

clip[21].x=210;
clip[21].y=240;
clip[21].w=100;
clip[21].h=110;

clip[22].x=315;
clip[22].y=240;
clip[22].w=100;
clip[22].h=110;

clip[23].x=420;
clip[23].y=240;
clip[23].w=100;
clip[23].h=110;

clip[24].x=525;
clip[24].y=240;
clip[24].w=100;
clip[24].h=110;

clip[25].x=630;
clip[25].y=240;
clip[25].w=100;
clip[25].h=110;
}