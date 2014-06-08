# Création de l'exécutable 'LAPIN'
DESTDIR=
CC= gcc
C_FLAGS= -W -Wall -Iinclude #-g
SDL_FLAGS= -lSDL_image -lSDL_mixer -lSDL_ttf
SRC= src
OBJ= obj
INLCUDE= include
BIN= bin
EXEC= LAPIN

all: directories $(EXEC) 

############ Creation des repertoires bin et obj ############

directories:
	mkdir -p $(OBJ)
	mkdir -p $(BIN)

############ Creation de l'executable LAPIN ############
$(EXEC) : input.o draw.o animation.o font.o map.o monster.o player.o sounds.o menu.o init.o main.o
	$(CC) $(OBJ)/*.o -o $(BIN)/$(EXEC) `sdl-config --cflags --libs` $(SDL_FLAGS) $(C_FLAGS) 

############ Compilation de l'ensemble des fichiers ############
main.o: $(SRC)/main.c 
	$(CC) -c $(SRC)/main.c -o $(OBJ)/main.o `sdl-config --cflags --libs` $(SDL_FLAGS) $(C_FLAGS) 

input.o: $(SRC)/input.c 
	$(CC) -c $(SRC)/input.c -o $(OBJ)/input.o `sdl-config --cflags --libs` $(SDL_FLAGS) $(C_FLAGS) 

draw.o: $(SRC)/draw.c 
	$(CC) -c $(SRC)/draw.c -o $(OBJ)/draw.o `sdl-config --cflags --libs` $(SDL_FLAGS) $(C_FLAGS) 

animation.o: $(SRC)/animation.c 
	$(CC) -c $(SRC)/animation.c -o $(OBJ)/animation.o `sdl-config --cflags --libs` $(SDL_FLAGS) $(C_FLAGS)

font.o: $(SRC)/font.c 
	$(CC) -c $(SRC)/font.c -o $(OBJ)/font.o `sdl-config --cflags --libs` $(SDL_FLAGS) $(C_FLAGS) 

map.o: $(SRC)/map.c 
	$(CC) -c $(SRC)/map.c -o $(OBJ)/map.o `sdl-config --cflags --libs` $(SDL_FLAGS) $(C_FLAGS) 

monster.o: $(SRC)/monster.c 
	$(CC) -c $(SRC)/monster.c -o $(OBJ)/monster.o `sdl-config --cflags --libs` $(SDL_FLAGS) $(C_FLAGS) 

player.o: $(SRC)/player.c 
	$(CC) -c $(SRC)/player.c -o $(OBJ)/player.o `sdl-config --cflags --libs` $(SDL_FLAGS) $(C_FLAGS) 

init.o: $(SRC)/init.c
	$(CC) -c $(SRC)/init.c -o $(OBJ)/init.o `sdl-config --cflags --libs` $(SDL_FLAGS) $(C_FLAGS) 

menu.o: $(SRC)/menu.c 
	$(CC) -c $(SRC)/menu.c -o $(OBJ)/menu.o `sdl-config --cflags --libs` $(SDL_FLAGS) $(C_FLAGS) 

sounds.o: $(SRC)/sounds.c 
	$(CC) -c $(SRC)/sounds.c -o $(OBJ)/sounds.o `sdl-config --cflags --libs` $(SDL_FLAGS) $(C_FLAGS) 

# Suppression des fichiers temporaires
clean:
	rm -rf $(OBJ)/*.o
	rm -rf $(BIN)/$(EXEC)

proper:
	rm -rf */*~
	rm -rf *~

cleanall: clean
	rm -r $(OBJ)
	rm -r $(BIN)

# Lancement de programme LAPIN
run:
	./$(BIN)/$(EXEC)

# Installation de l'executable dans le dossier bin

install: all
