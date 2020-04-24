#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

SDL_Rect option_menu(SDL_Surface *screen, int *Volume,SDL_Rect posboutton);
SDL_Surface  *fullscreen_menu(SDL_Surface *screen);
SDL_Rect sound(SDL_Surface *screen , int * Volume,SDL_Rect posboutton);
