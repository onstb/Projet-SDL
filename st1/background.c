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
#define SPEED 2
#define MAX_SPEED 7


void initialiser_backround (background *b)
{
b->pos_text.x=0;
b->pos_text.y=0;
b->police = TTF_OpenFont ("text/GenBasB.ttf",20);
//b.couleurnoir ={255,255,255};
b->x_relative=0;
b->y_relative=0;
b->background=NULL;
b->background_tile=NULL;
b->score_text=NULL;
b->camera.x=0;
b->camera.y=0;
b->camera.w=800;
b->camera.h=600;
b->background=IMG_Load("backgrounds/20.png");
b->background_tile=IMG_Load("backgrounds/201.png");
}
/******************************************************************************************************/
/******************************************************************************************************/
void afficher_background (SDL_Surface *screen,background *b)
{
SDL_BlitSurface(b->background,&b->camera,screen,NULL);
}
/*****************************************************************************************************/
/*****************************************************************************************************/
void afficher_background_tile (SDL_Surface *screen,background *b)
{
SDL_BlitSurface(b->background_tile,&b->camera,screen,NULL);
}


/*void afficher_score (SDL_Surface *screen,background *b)
{
b->score_text=TTF_RenderText_Blended(b->police,b->chaine_score,b->couleurnoir);
SDL_BlitSurface(b->score_text,NULL,screen,&b->pos_text);
}*/