#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"

void play_video1(SDL_Surface *ecran)
{
	SDL_Surface *frame;
	SDL_Event event;
	char chaine2[14];
	char chaine[8];
	int i=0;
	SDL_Rect posframe;
	SDL_Init(SDL_INIT_TIMER);
	posframe.x=0;
	posframe.y=0;
	for(i=0;i<150;i++){
		sprintf(chaine,"%d",i);
		strcat(chaine,".png");
	    strcpy(chaine2,"video1/");
	    strcat(chaine2,chaine);
		frame=IMG_Load(chaine2);
		SDL_BlitSurface(frame,NULL,ecran,&posframe);
		SDL_Flip(ecran);
		SDL_Delay(10);
		SDL_FreeSurface(frame);

	}
}



void play_video(SDL_Surface *ecran)
{
	SDL_Surface *frame;
	SDL_Event event;
	char chaine2[13];
	char chaine[8];
	int i=0;
	SDL_Rect posframe;
	SDL_Init(SDL_INIT_TIMER);
	posframe.x=0;
	posframe.y=0;
	for(i=0;i<200;i++){
		sprintf(chaine,"%d",i);
		strcat(chaine,".jpg");
	    strcpy(chaine2,"video/");
	    strcat(chaine2,chaine);
		frame=IMG_Load(chaine2);
		SDL_BlitSurface(frame,NULL,ecran,&posframe);
		SDL_Flip(ecran);
		SDL_Delay(23);
		SDL_FreeSurface(frame);

	}
}




int Quit(SDL_Surface *ecran)
{
	SDL_Surface *bg,*exit[2];
	int n=0,t;
	SDL_Rect pos;
	SDL_Event event;
	pos.x=0;
	pos.y=0;
	bg=IMG_Load("bg/bqck.png");
	exit[0]=IMG_Load("fenetre/yes_select.png");
    exit[1]=IMG_Load("fenetre/no_select.png");
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
							SDL_FreeSurface(bg);
							SDL_FreeSurface(exit[n]);
							return 1;
						}
						else if (n==1)
						{
							SDL_FreeSurface(bg);
							SDL_FreeSurface(exit[n]);
							return 0;
						}
					break;
						
    			}
    		break;

    		case SDL_MOUSEMOTION:
				if (event.motion.x>170 && event.motion.y>270 && event.motion.x<430 && event.motion.y<350 && n==1)
				{
					n=0;
				}
				else if (event.motion.x>460 && event.motion.y>270 && event.motion.x<700 && event.motion.y<350 && n==0)
				{
					n=1;
				}
			break;

			case SDL_MOUSEBUTTONDOWN:
				if (event.motion.x>170 && event.motion.y>270 && event.motion.x<430 && event.motion.y<350)
				{
					return 1;
				}
				else if (event.motion.x>460 && event.motion.y>270 && event.motion.x<700 && event.motion.y<350)
				{
					return 0;
				}
			break;

    	}
    }

}

CHOIX_MENU menu(SDL_Surface *screen,FILE* saves,FILE* savegame)
{
	SDL_Surface *background,*newgame[2],*loadgame[3],*option[2],*exit[2],
				*newgameclick,*loadgameclick,*optionclick,*exitclik;
	SDL_Rect pos;
	Mix_Chunk *button=NULL;
	button=Mix_LoadWAV("music/button.wav");
	pos.x=0;
	pos.y=0;
	SDL_Event event;
	int ng=1,op=0,ex=0,lg=0,t,s,save;
	//chargement d'image
	background=IMG_Load ("bg/backgroun.png");
    newgame[0]=IMG_Load("boutton/new game.png");
    loadgame[0]=IMG_Load("boutton/load game.png");
    loadgame[2]=IMG_Load("boutton/load_game_cliked.png");
    loadgame[1]=IMG_Load("boutton/load_game2.png");
    option[0]=IMG_Load("boutton/option.png");
    exit[0]=IMG_Load("boutton/exit.png");
    newgame[1]=IMG_Load("boutton/newgameselect.png");
    newgameclick=IMG_Load("boutton/newgame_click.png");
    option[1]=IMG_Load("boutton/optionsselect.png");
    optionclick=IMG_Load("boutton/options_click.png");
    exit[1]=IMG_Load("boutton/exitselect.png");
    exitclik=IMG_Load("boutton/exit_click.png");

    saves = fopen("saves.txt", "r");
    
    if (saves != NULL)

    {
            fscanf(saves,"%d",&save); 

        fclose(saves);

    }
    if (save==1)
    {
        lg=1;
    }
    do{
    //affichage des images
	SDL_BlitSurface(background,NULL,screen,&pos);
    SDL_BlitSurface(loadgame[lg],NULL,screen,&pos);
    SDL_BlitSurface(option[op],NULL,screen,&pos);
    SDL_BlitSurface(exit[ex],NULL,screen,&pos);
    SDL_BlitSurface(newgame[ng],NULL,screen,&pos);
    SDL_Flip(screen);
    	t=0;
    	s=0;
    	SDL_WaitEvent(&event);
    	switch(event.type){
    		case SDL_QUIT:
    			return EXIT;
    		break;
    		case SDL_KEYDOWN:
    			switch(event.key.keysym.sym){
    				case SDLK_ESCAPE:
    					return EXIT;
    				break;
    				case SDLK_UP:
    					if (ng==1 && t==0){
    						ex=1;
    						ng=0;
    						op=0;
    						t=1;
    					}
    					else if(op==1 && t==0){
    						if (lg==1)
                            {
                                ng=0;
                                lg=2;
                                op=0;
                                ex=0;
                                t=1;
                            }
                            else{
                                ng=1;
                                op=0;
                                ex=0;
                                t=1;
                            }
    					}
    					else if (ex==1 && t==0){
    						op=1;
    						ex=0;
    						ng=0;
    						t=1;
    					}
                        else if (lg==2 && t==0)
                        {
                            ng=1;
                            lg=1;
                            op=0;
                            ex=0;
                            t=1;
                        }
    				break;

    				case SDLK_DOWN:
    					if (ng==1 && t==0){
    						if (lg==1)
                            {
                                ng=0;
                                lg=2;
                                op=0;
                                ex=0;
                                t=1;
                            }
                            else{
                                ng=0;
                                op=1;
                                ex=0;
                                t=1;
                            }
    					}
    					else if(op==1 && t==0){
    						ng=0;
    						op=0;
    						ex=1;
    						t=1;
    					}
    					else if (ex==1 && t==0){
    						op=0;
    						ex=0;
    						ng=1;
    						t=1;
    					}
                        else if (lg==2 && t==0)
                        {
                            ng=0;
                            lg=1;
                            op=1;
                            ex=0;
                            t=1;
                        }
    				break;

    				case SDLK_RETURN:
    					if (ng==1)
    					{
    						SDL_BlitSurface(newgameclick,NULL,screen,&pos);
    						SDL_Flip(screen);
    						s=1;
    						return NEW_GAME;
    					}
    					else if (op==1)
    					{
    						SDL_BlitSurface(optionclick,NULL,screen,&pos);
    						SDL_Flip(screen);
    						s=1;
    						return OPTION;
    					}
    					else if (ex==1)
    					{
    						SDL_BlitSurface(exitclik,NULL,screen,&pos);
    						SDL_Flip(screen);
    						s=1;
    						return EXIT;
    					}
                        else if (lg==2)
                        {
                            s=1;
                            return LOAD_GAME;
                        }
    				break;
    			}
    		break;

    		/*case SDL_MOUSEMOTION:
    			if (event.motion.x>70 && event.motion.y>180 && event.motion.x<410 && event.motion.y<250 && t==0 && ng==0)
    			{
    				ex=0;
    				ng=1;
    				op=0;
    				t=1;
    			}
    			else if (event.motion.x>70 && event.motion.y>380 && event.motion.x<410 && event.motion.y<450 && t==0 && op==0)
    			{
    				ex=0;
    				ng=0;
    				op=1;
    				t=1;
    			}
    			else if (event.motion.x>70 && event.motion.y>490 && event.motion.x<410 && event.motion.y<560 && t==0 && ex==0)
    			{
    				ex=1;
    				ng=0;
    				op=0;
    				t=1;
    			}
    		break;

    		case SDL_MOUSEBUTTONDOWN:
    			if (event.button.button==SDL_BUTTON_LEFT)
    			{
    				if (event.motion.x>70 && event.motion.y>180 && event.motion.x<410 && event.motion.y<250 && ng==1)
    				{
    					SDL_BlitSurface(newgameclick,NULL,screen,&pos);
    					SDL_Flip(screen);
    					s=1;
    					return NEW_GAME;
    				}
    				else if (event.motion.x>70 && event.motion.y>380 && event.motion.x<410 && event.motion.y<450 && op==1)
    				{
    					SDL_BlitSurface(optionclick,NULL,screen,&pos);
    					SDL_Flip(screen);
    					s=1;
    					return OPTION;
    				}
    				else if (event.motion.x>70 && event.motion.y>490 && event.motion.x<410 && event.motion.y<560)
    				{
    					SDL_BlitSurface(exitclik,NULL,screen,&pos);
    					SDL_Flip(screen);
    					s=1;
    					return EXIT;
    				}
    			}
    		break;*/
    	}
    	if (s==1)
    	{
    		Mix_PlayChannel( -1, button, 0 );
    	}
    }while(event.key.keysym.sym!=SDLK_ESCAPE);
    	SDL_FreeSurface(background);
    	SDL_FreeSurface(newgameclick);
    	SDL_FreeSurface(optionclick);
    	SDL_FreeSurface(exitclik);
    	SDL_FreeSurface(newgame[0]);
    	SDL_FreeSurface(newgame[1]);
    	SDL_FreeSurface(option[0]);
    	SDL_FreeSurface(option[1]);
    	SDL_FreeSurface(loadgame[0]);
    	SDL_FreeSurface(exit[0]);
    	SDL_FreeSurface(exit[1]);
}