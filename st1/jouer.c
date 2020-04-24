#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
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
#define GRAVITY_SPEED 0.8
#define MAX_FALL_SPEED 5
#define JUMP_HEIGHT 14.5
#define SPEED 2
#define MAX_SPEED 7


void jouer (SDL_Surface *screen)
{


	background b;
	perssonage p;
	coin c,c1,c2,c3,c4;
	char chaine[5];
	coeur co;
	fire f;
	SDL_Rect poskey,poskey1,poskey2,poskey3,poskey4;
	SDL_Color Color;
	SDL_Color couleurnoir = {0,0,0};
	SDL_Surface *grandvie_text;
	SDL_Rect grand_vie_pos;
	bool running=true;
	Input I;
	SDL_Event event;
	int timer=0,instimer=0;
	int grand_vie=5;

screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);

inisialiser_fire (&f);
inisialiser_coeur (&co);
initialiser_backround (&b);
initialiser_perssonage (&p);
initialiser_input (&I);
init_coin(&c,poskey.x,poskey.y);
init_coin(&c1,poskey1.x,poskey1.y);
init_coin(&c2,poskey2.x,poskey2.y);
init_coin(&c3,poskey3.x,poskey3.y);
init_coin(&c4,poskey4.x,poskey4.y);
grand_vie_pos.x=45;
grand_vie_pos.y=10;
poskey.x=475;	
poskey1.x=550;	
poskey2.x=625;		
poskey3.x=700;
poskey.y=330;	
poskey1.y=320;	
poskey2.y=320;		
poskey3.y=330;

setrects_fire(f.rects);	
setrects (p.rects);

if (Mix_OpenAudio (44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
{
	printf("%s",Mix_GetError());
}
Mix_Music *musique;
musique = Mix_LoadMUS("intro.mp3");
Mix_PlayMusic(musique, -1);
Mix_VolumeMusic (MIX_MAX_VOLUME/6);
while(running)
{
	while(SDL_PollEvent(&event))
	{
	p.current_time=SDL_GetTicks();
	p.delta_time+=p.current_time-p.previous_time;
	p.previous_time=p.current_time;
	if (p.delta_time>=0.32)
	{
	p.delta_time=0.29;
	}
		switch(event.type)
		{
		case SDL_QUIT:
			running=false;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_RIGHT:
				I.right=1;
			break;
			case SDLK_LEFT :
				I.left=1;
      		break;
			case SDLK_UP :
				I.jump=1;
			break;
			case SDLK_DOWN :
				I.down=1;
			break;
			case SDLK_ESCAPE :
				running=false;
			break;
			}
		break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_RIGHT:
				I.right=0;

			break;
			case SDLK_LEFT :
				I.left=0;
      		break;
			case SDLK_UP :
				I.jump=0;
			break;
			case SDLK_DOWN :
				I.down=0;
			break;
			}
		break;
		}
	}

SDL_Rect relcoord_fire={f.rect.x-b.x_relative,f.rect.y};
SDL_Rect relcoord2={poskey.x-b.x_relative,poskey.y};
SDL_Rect relcoord3={poskey1.x-b.x_relative,poskey1.y};			
SDL_Rect relcoord4={poskey2.x-b.x_relative,poskey2.y};			
SDL_Rect relcoord5={poskey3.x-b.x_relative,poskey3.y};	

afficher_background_tile (screen,&b);
GetPixelColor(screen,p.rect.x+50,p.rect.y+75,&Color);
	printf ("/////////%d//////////////%d///////////%d\n",Color.r,Color.g,Color.b);


if (I.right==1 && collisionright (screen,&p.rect)==0)
{
	p.xvelocity+=SPEED;
	animation_right(&p);
	mouvementright (&p);
scrolling_right (&b,&p,screen);
}else if (I.left==1 && collisionleft (screen,&p.rect)==0)
{
	p.xvelocity+=SPEED;
	mouvementleft (&p);
// ANIMATION;
	scrolling_left (&b,&p,screen);

}
else if (I.jump==1 && collisiongravite (screen,&p.rect)==0)
{
mouvementjump (&p);
//ANIMATION
}else if (I.down==1 && p.on_water)
{
		p.xvelocity+=SPEED;
mouvementdown (&p);
}
else 
p.frame=0;


if (Color.r==1 && Color.g==31  && Color.b==255 || Color.r==1 && Color.g==255  && Color.b==1)
	p.on_water=true;
else 
	p.on_water=false;

if (Color.r==1 && Color.g==1  && Color.b==1)
	I.jump=1;

if (Color.r==255 && Color.g==1  && Color.b==1)
	p.vie=0;

if (!p.on_water)
{
gravite (screen,&p,&I);
}
else 
{
	p.onground=1;
}
if (p.onground==0 || I.jump==1)
actualiser_perssonage (&p);




co.pos_coeur_1.x=p.rect.x+80;
co.pos_coeur_1.y=p.rect.y-20;
co.pos_coeur_2.x=p.rect.x+60;
co.pos_coeur_2.y=p.rect.y-20;
b.pos_text.x=p.rect.x;
b.pos_text.y=p.rect.y-10;

afficher_background (screen,&b);
afficher_perssonage (&p,screen);
//afficher_fire (&f,screen);
//SDL_BlitSurface(f.fire,&f.rects[f.frame],screen,&relcoord_fire);				
SDL_BlitSurface(c.tab[c.frame],NULL,screen,&relcoord2);
SDL_BlitSurface(c.tab[c.frame],NULL,screen,&relcoord3);
SDL_BlitSurface(c.tab[c.frame],NULL,screen,&relcoord4);
SDL_BlitSurface(c.tab[c.frame],NULL,screen,&relcoord5);
animer_coin(&c);
animer_coin(&c1);
animer_coin(&c2);
animer_coin(&c3);
animer_coin(&c4);
SDL_BlitSurface(b.score_text,NULL,screen,&b.pos_text);
SDL_BlitSurface(grandvie_text,NULL,screen,&grand_vie_pos);
if (p.vie==3)
{
SDL_BlitSurface(co.coeur_1,NULL,screen,&co.pos_coeur_1);
SDL_BlitSurface(co.coeur_2,NULL,screen,&co.pos_coeur_2);
}else if (p.vie==1)
{
SDL_BlitSurface(co.coeur_1,NULL,screen,&co.pos_coeur_1);
}else if (p.vie==0)
{
inisialiser_coeur (&co);
initialiser_backround (&b);
initialiser_perssonage (&p);
initialiser_input (&I);
grand_vie--;
sprintf (chaine,"x%d",grand_vie);
grandvie_text=TTF_RenderText_Blended(b.police,chaine,couleurnoir);
}
if (grand_vie==0)
	running=false;



if (p.invincible)
{
timer=SDL_GetTicks();
if (timer>instimer+3500)
{
instimer=timer;
p.invincible=false;
}
}

/*if (collision(&p.rect,&relcoord_fire) && !p.invincible)
{

p.vie--;
p.invincible=true;
}*/

if (collision(&p.rect,&relcoord2))
{
p.score+=1;
sprintf (b.chaine_score,"[%d]",p.score);
b.score_text=TTF_RenderText_Blended(b.police,b.chaine_score,couleurnoir);
poskey.x=9000;
}
if (collision(&p.rect,&relcoord3))
{
	p.score+=1;
	sprintf (b.chaine_score,"[%d]",p.score);
b.score_text=TTF_RenderText_Blended(b.police,b.chaine_score,couleurnoir);
poskey1.x=9000;
/*b.score_text=TTF_RenderText_Blended(b.police,b.chaine_score,couleurnoir);
SDL_BlitSurface(b.score_text,NULL,screen,&b.pos_text);*/
}
if (collision(&p.rect,&relcoord4))
{
	p.score+=1;
	sprintf (b.chaine_score,"[%d]",p.score);
b.score_text=TTF_RenderText_Blended(b.police,b.chaine_score,couleurnoir);
poskey2.x=9000;
}
if (collision(&p.rect,&relcoord4))
{
	p.score+=1;
	sprintf (b.chaine_score,"[%d]",p.score);
b.score_text=TTF_RenderText_Blended(b.police,b.chaine_score,couleurnoir);
poskey3.x=9000;
}
if (collision(&p.rect,&relcoord5))
{
	p.score+=1;
	sprintf (b.chaine_score,"[%d]",p.score);
b.score_text=TTF_RenderText_Blended(b.police,b.chaine_score,couleurnoir);
poskey4.x=9000;
}

//SDL_Delay(0.5);
SDL_Flip(screen);

}


}