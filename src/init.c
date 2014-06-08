
#include "init.h"


void init(char *title)
{
	/* Initialise SDL Video */
	if (SDL_Init(SDL_INIT_VIDEO ) < 0)
	{
		printf("Could not initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	jeu.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);

    if (jeu.screen == NULL)
        {
            printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
            exit(1);
        }

	/* Titre de la fenetre */
	SDL_WM_SetCaption(title, NULL);


	/* Cache le curseur de la souris */
	SDL_ShowCursor(SDL_DISABLE);


	/* Initialise SDL_TTF */
	if (TTF_Init() < 0)
	{
		printf("Couldn't initialize SDL TTF: %s\n", SDL_GetError());

		exit(1);
	}

	/* Chargement de la police */
	font = loadFont("font/GenBasB.ttf", 32);


}


void loadGame(void)
{

    /* Charge l'image du fond et le tileset */
    map.background = loadImage("graphics/background.png");

    //On commence au premier niveau
    jeu.level = 1;
    changeLevel();

    //On initialise le timer
     map.mapTimer = TIME_BETWEEN_2_FRAMES * 3;
     map.tileSetNumber = 0;

    /* On initialise les variables du jeu */
    jeu.vies = 3;
    jeu.etoiles = 0;

    /* On charge le HUD */
    jeu.HUD_vie = loadImage("graphics/life.png");
    jeu.HUD_etoiles = loadImage("graphics/stars.png");

    //On commence par le menu start
    jeu.onMenu = 1;
    jeu.menuType = START;

}



void cleanup()
{

    int i;

    /* Libère l'image du background */
	if (map.background != NULL)
	{
		SDL_FreeSurface(map.background);
	}


    /* Libère l'image des tilesets */
    if (map.tileSet != NULL)
    {
        SDL_FreeSurface(map.tileSet);
    }
    if (map.tileSetB != NULL)
    {
        SDL_FreeSurface(map.tileSetB);
    }


	/* Libère le sprite du héros */
	if (player.sprite != NULL)
	{
		SDL_FreeSurface(player.sprite);
	}

	/* Libère le sprite des monstres */
	for(i = 0 ; i < MONSTRES_MAX ; i++)
    {
        if (monster[i].sprite != NULL)
        {
            SDL_FreeSurface(monster[i].sprite);
        }
    }

	//Libère le HUD
	if (jeu.HUD_etoiles != NULL)
	{
		SDL_FreeSurface(jeu.HUD_etoiles);
	}
	if (jeu.HUD_vie != NULL)
	{
		SDL_FreeSurface(jeu.HUD_vie);
	}

	/* Close the font */
	closeFont(font);

	/* Close SDL_TTF */
	TTF_Quit();

	/* Quitte la SDL */
	SDL_Quit();

}



