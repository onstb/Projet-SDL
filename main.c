#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"
#include "newgame.h"
#include "option.h"
#include "savegame.h"
#include "perssonage.h"
#include "background.h"
#include "multiplayer.h"





int main (int argc, char const *argv[])
{
	SDL_Surface *screen;
	FILE* saves=NULL;
	FILE* savegame=NULL;
	SDL_Rect posscreen,posboutton;
	CHOIX_MENU choix;
	perssonage p,p1;
	background b;
	int stage=0;
	int loadtest=0;
	int mp=0;
	int q=0,Volume=MIX_MAX_VOLUME;
	SDL_Init(SDL_INIT_VIDEO);
	putenv("SDL_VIDEO_WINDOW_POS=center");
    screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE |SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        fprintf(stderr,"Impossible de charger le mode video : %s\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("The Cure", NULL);
    if (Mix_OpenAudio (44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		printf("%s",Mix_GetError());
	}
	Mix_Music *musique;
	musique = Mix_LoadMUS("music/intro.mp3");
	Mix_PlayMusic(musique, -1);
	Mix_VolumeMusic (MIX_MAX_VOLUME);
	play_video(screen);
	if (Mix_OpenAudio (44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		printf("%s",Mix_GetError());
	}	
	musique = Mix_LoadMUS("music/hedi.mp3");
	Mix_PlayMusic(musique, -1);
	Mix_VolumeMusic (Volume);
	play_video1(screen);
	posboutton.x=180+150;
	posboutton.y=0;
	while(q!=1){
		loadtest=0;
		choix=menu(screen,saves,savegame);
	switch(choix){
		case NEW_GAME:
			stage=newgame(screen);
			mp=multiplayer(screen);
			if (stage==0 && mp==0)
			{
				jouer(screen,&stage,p,b,loadtest);
			}
			else if (stage==0 && mp==1)
			{
				jouer(screen,&stage,p,b,loadtest);
				printf("player 2");
				SDL_Delay(1000);
				jouer(screen,&stage,p1,b,loadtest);
			}
		break;

		case LOAD_GAME:
			load_game(&p,&stage,&b);
			loadtest=1;
			jouer(screen,&stage,p,b,loadtest);

		break;
		case OPTION:
			posboutton=option_menu(screen,&Volume,posboutton);
		break;
		case EXIT:
			q=Quit(screen);
		break;
		}
	}
	

	return 0;
}
