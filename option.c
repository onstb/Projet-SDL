#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "option.h"

SDL_Rect option_menu(SDL_Surface *screen, int *Volume,SDL_Rect posboutton)
{	
	SDL_Surface *option[2],*bg,*escape;
	SDL_Rect pos;
	pos.x=0;
	pos.y=0;
	int n=0,q=1;
	SDL_Event event;

	bg=IMG_Load("bg/bqck.png");
	option[0]=IMG_Load("option/fullscreen.png");
	option[1]=IMG_Load("option/sound.png");
	escape=IMG_Load("boutton/echaptoreturn.png");
	do{
	SDL_BlitSurface(bg,NULL,screen,&pos);
	SDL_BlitSurface(escape,NULL,screen,&pos);
	SDL_BlitSurface(option[n],NULL,screen,&pos);
	SDL_Flip(screen);
	SDL_WaitEvent(&event);
	switch(event.type)
	{
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
				case SDLK_UP:
					if (n==0)
					{
						n++;
					}
					else{
						n--;
					}
				break;

				case SDLK_DOWN:
					if (n==1)
					{
						n--;
					}
					else{
						n++;
					}
				break;

				case SDLK_RETURN:
					if (n==0)
					{
						screen=fullscreen_menu(screen);
					}
					else{
						posboutton=sound(screen,Volume,posboutton);
					}
				break;
			}
		case SDL_MOUSEMOTION:
			if (event.motion.x>170 && event.motion.y>130 && event.motion.x<630 && event.motion.y<210 && n==1)
			{
				n=0;
			}
			else if (event.motion.x>170 && event.motion.y>270 && event.motion.x<630 && event.motion.y<350 && n==0)
			{
				n=1;
			}
		break;

		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button==SDL_BUTTON_LEFT)
			{
				if (event.motion.x>0 && event.motion.y>0 && event.motion.x<230 && event.motion.y<50)
				{
						q=0;
				}
				else if (event.motion.x>170 && event.motion.y>130 && event.motion.x<630 && event.motion.y<210)
				{
					screen=fullscreen_menu(screen);
				}
				else if (event.motion.x>170 && event.motion.y>270 && event.motion.x<630 && event.motion.y<350)
				{
					posboutton=sound(screen,Volume,posboutton);
				}
			}
		break;
	}
 	}while(event.key.keysym.sym!=SDLK_ESCAPE && q==1);
 	SDL_FreeSurface(option[0]);
 	SDL_FreeSurface(option[1]);
 	return posboutton;
}

SDL_Surface  *fullscreen_menu(SDL_Surface *screen)
{
	SDL_Surface *fullscreen[2],*bg;
	SDL_Event event;
	SDL_Rect pos;
	pos.x=0;
	pos.y=0;
	int n=0,t=0;
	bg=IMG_Load("bg/bqck.png");
	fullscreen[0]=IMG_Load("option/yes.png");
	fullscreen[1]=IMG_Load("option/no.png");
	do
	{
		SDL_BlitSurface(bg,NULL,screen,&pos);
		SDL_BlitSurface(fullscreen[n],NULL,screen,&pos);
		SDL_Flip(screen);
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
							screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE |SDL_DOUBLEBUF |SDL_FULLSCREEN);
							
						}
						else if (n==1)
						{
							screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE |SDL_DOUBLEBUF);
							SDL_QUIT;
							
						}
						SDL_FreeSurface(fullscreen[n]);
						return screen;
					break;
				}
			break;

			case SDL_MOUSEMOTION:
				if (event.motion.x>210 && event.motion.y>250 && event.motion.x<360 && event.motion.y<330 && n==1)
				{
					n=0;
				}
				else if (event.motion.x>460 && event.motion.y>250 && event.motion.x<640 && event.motion.y<330 && n==0)
				{
					n=1;
				}
			break;

			case SDL_MOUSEBUTTONDOWN:
				if (event.motion.x>210 && event.motion.y>250 && event.motion.x<360 && event.motion.y<330)
				{
					screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE |SDL_DOUBLEBUF |SDL_FULLSCREEN);
				}
				else if (event.motion.x>460 && event.motion.y>250 && event.motion.x<640 && event.motion.y<330)
				{
					screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE |SDL_DOUBLEBUF);
				}
				return screen;
			break;
		}
	}while(event.key.keysym.sym!=SDLK_ESCAPE);
	
	
}

SDL_Rect sound(SDL_Surface *screen , int * Volume,SDL_Rect posboutton)
{
	SDL_Surface *boutton, *barre,*bg;
	SDL_Rect posbarre,posbg;
	SDL_Event event;
	int MAX_VOLUME,MIN_VOLUME;
	boutton=IMG_Load("option/Button.png");
	barre=IMG_Load("option/Barre.png");
	bg=IMG_Load("bg/bqck.png");
	posbg.x=0;
	posbg.y=0;
	posbarre.x=180;
	posbarre.y=0;
	MAX_VOLUME=posbarre.x+150;
	MIN_VOLUME=posbarre.x-220;

	do
	{
		SDL_BlitSurface(bg,NULL,screen,&posbg);
		SDL_BlitSurface(barre,NULL,screen,&posbarre);
		SDL_BlitSurface(boutton,NULL,screen,&posboutton);
		SDL_Flip(screen);
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_LEFT:
						if (posboutton.x>MIN_VOLUME && *Volume>0)
						{
							posboutton.x=posboutton.x-90;
							*Volume=*Volume-32;
							Mix_VolumeMusic(*Volume);
						}
					break;
					case SDLK_RIGHT:
						if (posboutton.x<MAX_VOLUME && *Volume<128)
						{
							posboutton.x=posboutton.x+90;
							*Volume=*Volume+32;
							Mix_VolumeMusic(*Volume);
						}
					break;
					
				}
			break;
		}
		SDL_FillRect(screen,&posboutton,SDL_MapRGB(screen->format ,0, 0 ,0 ));


	}while(event.key.keysym.sym!=SDLK_ESCAPE);
	return posboutton;

}