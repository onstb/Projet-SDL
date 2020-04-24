#ifndef DS7_H_INCLUDED
#define DS7_H_INCLUDED




typedef struct fire 
{
SDL_Surface *fire;
SDL_Rect rect;
SDL_Rect rects[26];
int frame;
}fire;





void inisialiser_fire (fire *f);
void afficher_fire (fire *f,SDL_Surface *screen);
void setrects_fire(SDL_Rect* clip);


 #endif // DS_H_INCLUDED