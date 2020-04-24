programme: main.o newgame.o option.o menu.o background.o coin.o collision.o def.o jouer.o mouvement.o personnage.o scroling.o coeur.o enemi.o savegame.o pause.o multiplayer.o
		   gcc main.o savegame.o pause.o newgame.o option.o menu.o background.o coin.o collision.o def.o jouer.o  mouvement.o multiplayer.o personnage.o scroling.o coeur.o enemi.o -lSDL -lSDL_image -lSDL_mixer -lSDL_gfx -lSDL_ttf -o programme

main.o: main.c newgame.c option.c menu.c
		gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -o main.o

option.o: option.c
		  gcc -c option.c -lSDL -lSDL_image -lSDL_mixer -o option.o

newgame.o: newgame.c
		   gcc -c newgame.c -lSDL -lSDL_image -lSDL_mixer -o newgame.o

menu.o: menu.c
		gcc -c menu.c -lSDL -lSDL_image -lSDL_mixer -o menu.o

background.o :background.c
	gcc -c background.c

coin.o :coin.c
	gcc -c coin.c

collision.o :collision.c
	gcc -c collision.c

def.o :def.c
	gcc -c def.c

jouer.o :jouer.c
	gcc -c jouer.c

mouvement.o :mouvement.c
	gcc -c mouvement.c

personnage.o :personnage.c
	gcc -c personnage.c

scroling.o :scroling.c
	gcc -c scroling.c

coeur.o :coeur.c
	gcc -c coeur.c

enemi.o :enemi.c
	gcc -c enemi.c

pause.o : pause.c
	gcc -c pause.c -lSDL -lSDL_image -lSDL_mixer -o pause.o

savegame.o: savegame.c
	gcc -c savegame.c -lSDL -lSDL_image -lSDL_mixer -o savegame.o

multiplayer.o: multiplayer.c
	gcc -c multiplayer.c -lSDL -lSDL_image -o multiplayer.o