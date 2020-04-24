#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "multiplayer.h"

int multiplayer(SDL_Surface *screen)
{
	SDL_Surface *bg,*escape,*multi[2];
	SDL_Rect pos;
	SDL_Event event;
	pos.x=0;
	pos.y=0;
	int n=0;
	bg=IMG_Load("bg/Map.jpg");
	escape=IMG_Load("boutton/echaptoreturn.png");
	multi[1]=IMG_Load("fenetre/multiplayer_yes.png");
	multi[0]=IMG_Load("fenetre/multiplayer_no.png");
	do
	{
		SDL_BlitSurface(bg,NULL,screen,&pos);
		SDL_BlitSurface(escape,NULL,screen,&pos);
		SDL_BlitSurface(multi[n],NULL,screen,&pos);
		SDL_Flip(screen);
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button==SDL_BUTTON_LEFT)
				{
					if (event.motion.x>0 && event.motion.y>0 && event.motion.x<230 && event.motion.y<50)
					{
						event.key.keysym.sym=SDLK_ESCAPE;
					}
				}
			break;
			
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_LEFT:
						if (n==0)
						{
							n++;
						}
						else
							n--;
					break;

					case SDLK_RIGHT:
						if (n==1)
						{
							n--;
						}
						else
							n++;
						
					break;

					case SDLK_RETURN:
						
						return n;
					break;
				}
			break;
		}

	} while (event.key.keysym.sym!=SDLK_ESCAPE );

}