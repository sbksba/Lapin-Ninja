Lapin Ninja
===========

Fichiers inclus
---------------

CODE
----
    
> src/animation.c    
> src/draw.c    
> src/font.c    
> src/init.c    
> src/input.c    
> src/map.c    
> src/menu.c    
> src/monster.c    
> src/player.c     
> src/sounds.c    
> src/main.c    

> include/animation.h    
> include/draw.h    
> include/defs.h    
> include/structs.h    
> include/font.h    
> include/init.h    
> include/input.h    
> include/map.h    
> include/menu.h    
> include/monster.h     
> include/player.h    
> include/sounds.h    
> include/main.h    


MAP
----

> map/map1.txt    
> map/map2.txt    


FONT
----   
   
> font/GenBasB.ttf    


GRAPHISME
---------

> graphic/background.png    
> graphic/IdleLeft.png     
> graphic/IdleRight.png     
> graphic/JumpLeft.png     
> graphic/JumpRight.png    
> graphic/life.png     
> graphic/monster1.png    
> graphic/monster1right.png     
> graphic/stars.png    
> graphic/tileset1B.png    
> graphic/tileset1.png    
> graphic/tileset2B.png    
> graphic/tileset2.png    
> graphic/walkleft.png     
> graphic/walkright.png     


Directive du Makefile
----------------------


> make    
> compil le programme    

> clean    
> efface tous les fichiers ".o" et l'executable "LAPIN"     

> proper     
> efface tous les fichiers temporaires du dossier     

> run     
> lance le programme (execute "LAPIN")     


Commandes
----------

> Menu :     
> - ENTER -> permet de valider notre choix     
> - ESCAPE -> permet de sortir du jeu     

> Jeu :     
> - ENTER -> permet de mettre le jeu en pause      
> - ESCAPE -> permet de quitter le jeu     
> - C -> permet de sauter (appuyer une deuxieme permet le double saut)     
> - touches directionnelles Gauche et Droite permettent le deplacement      

	 
Bibliotheques
--------------

Il est necessaire d'avoir installer : SDL_image, SDL_mixer et SDL_ttf.
Sinon le programme risque de ne pas marcher.Merci.


Please distribute this file with the SDL runtime environment:

The Simple DirectMedia Layer (SDL for short) is a cross-platfrom library
designed to make it easy to write multi-media software, such as games and
emulators.

The Simple DirectMedia Layer library source code is available from:
http://www.libsdl.org/

This library is distributed under the terms of the GNU LGPL license:
http://www.gnu.org/copyleft/lesser.html
