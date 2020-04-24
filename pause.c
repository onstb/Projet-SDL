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
#include "pause.h"
#include "savegame.h"

int pause(SDL_Surface *ecran)
{
	SDL_Surface *exit[2],*bg;
	int n=0,t;
	SDL_Rect pos;
	SDL_Event event;
	pos.x=0;
	pos.y=0;
	exit[1]=IMG_Load("fenetre/menu_pause/menu_pasue_noselect.png");
    exit[0]=IMG_Load("fenetre/menu_pause/menu_pause_yesselect.png");
    bg=IMG_Load("bg/Map.jpg");
    while(1)
    {
    	SDL_BlitSurface(bg,NULL,ecran,&pos);
    	SDL_BlitSurface(exit[n],NULL,ecran,&pos);
    	SDL_Flip(ecran);
    	SDL_WaitEvent(&event);
    	t=0;
    	switch(event.type)
    	{
    		case SDL_KEYDOWN:
    			switch(event.key.keysym.sym)
    			{
    				case SDLK_LEFT:
						if (n==0 && t==0)
						{
							n++;
							t=1;
						}
						else if (n==1 && t==0)
						{
							n--;
							t=1;
						}
					break;

					case SDLK_RIGHT:
						if (n==0 && t==0)
						{
							n++;
							t=1;
						}
						else if (n==1 && t==0)
						{
							n--;
							t=1;
						}
					break;

					case SDLK_RETURN:
						if (n==0)
						{
							
							return 1;
						}
						else if (n==1)
						{
							return 0;
						}
					break;
						
    			}
    		break;
    		SDL_FreeSurface(exit[0]);
    		SDL_FreeSurface(exit[1]);
    		SDL_FreeSurface(bg);

    	}
    }

}