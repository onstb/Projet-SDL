#ifndef DS7_H_INCLUDED
#define DS7_H_INCLUDED




typedef struct enemie
{
SDL_Surface *enemie;
SDL_Rect rect;
SDL_Rect rects[6];
int frame;
int direction;
int moving;
int state;
int onground;
}enemie;



void MoveEnnemi(enemie *E);
void update_ennemi(enemie *E ,SDL_Surface *screen, SDL_Rect r);
void inisialiser_enemie (enemie *f);
void afficher_enemie (enemie *f,SDL_Surface *screen,SDL_Rect pos);
void setrects_enemie(SDL_Rect* clip);
void animation (enemie *p);


 #endif // DS_H_INCLUDED