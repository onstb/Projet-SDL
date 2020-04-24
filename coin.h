#ifndef DS5_H_INCLUDED
#define DS5_H_INCLUDED




typedef struct  coin
{
	SDL_Surface *tab[8];
	SDL_Rect pos;
	int frame;
}coin;

void init_coin(coin *c,int x, int y);
void animer_coin(coin *c);

  #endif // DS_H_INCLUDED
