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







void inisialiser_coeur (coeur *c)
{
c->coeur_1=IMG_Load("vie/c.png");
c->coeur_2=IMG_Load("vie/c.png");
c->pos_coeur_1.x=0;
c->pos_coeur_1.y=0;
c->pos_coeur_2.x=0;
c->pos_coeur_2.y=0;
}