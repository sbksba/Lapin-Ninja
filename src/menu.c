
#include "menu.h"

void updateStartMenu(void)
{
    //Si on appuie sur BAS
    if(input.down == 1)
    {
        //Si choice = O (il est sur start), on le met � 1 (quit)
        if(jeu.choice == 0)
            jeu.choice++;

        input.down = 0;
    }

    //Si on appuie sur HAUT
    if(input.up == 1)
    {
        //Si choice = 1 (il est sur Quit), on le met � 0 (Start)
        if(jeu.choice == 1)
            jeu.choice--;

        input.up = 0;
    }

    //Si on appuie sur Enter et qu'on est sur Start, on recharge le jeu et on quitte l'�tat menu
    if(input.enter)
    {
         if(jeu.choice == 0)
        {
            jeu.level = 1;
            initializePlayer();
            changeLevel();
            /* On r�initialise les variables du jeu */
            jeu.vies = 3;
            jeu.etoiles = 0;
            jeu.onMenu = 0;
        }
        //Sinon, on quitte le jeu
        else if(jeu.choice == 1)
        {
            exit(0);
        }
        input.enter = 0;
    }


}


void drawStartMenu(void)
{

    //On cr�e une varuiable qui contiendra notre texte
    char text[200];

    //Le titre
    sprintf(text, "La vengeance du lapin ninja");
    drawString(text, 110, 50, font);

    //Si l'option n'est pas en surbrillance, on l'affiche normalement, sinon on rajoute ">"
    if(jeu.choice != 0)
    {
        sprintf(text, "START");
        drawString(text, 273, 200, font);
    }
    if(jeu.choice != 1)
    {
        sprintf(text, "QUIT");
        drawString(text, 273, 280, font);
    }

     //Si l'option est en surbrillance, on rajoute ">"
    if(jeu.choice == 0)
    {
        sprintf(text, "> START");
        drawString(text, 250, 200, font);
    }
    else if(jeu.choice == 1)
    {
        sprintf(text, "> QUIT");
        drawString(text, 250, 280, font);
    }

    //Le nom du studio
    sprintf(text, "sbksba games");
    drawString(text, 5, 420, font);



}


void updatePauseMenu(void)
{

    //Si on appuie sur Enter on quitte l'�tat menu
    if(input.enter)
    {
        jeu.onMenu = 0;
        input.enter = 0;
    }

}


void drawPauseMenu(void)
{
    char text[200];

    //On �crit PAUSE
    sprintf(text, "** PAUSE **");
    drawString(text, 240, 240, font);

}


