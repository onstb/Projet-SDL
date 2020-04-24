#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef enum {NEW_GAME,LOAD_GAME,OPTION,EXIT} CHOIX_MENU;

void play_video1(SDL_Surface *ecran);
void play_video(SDL_Surface *ecran);
int Quit(SDL_Surface *ecran);
CHOIX_MENU menu(SDL_Surface *screen,FILE* saves,FILE* savegame);
