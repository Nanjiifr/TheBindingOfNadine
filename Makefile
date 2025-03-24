CC = gcc
CFLAGS = -g -gdwarf-4
SRC_GAME = $(wildcard game/*.c)
SRC_DICO = $(wildcard dico/*.c)
SRC_AFFICHAGE = $(wildcard affichage/*.c)
OBJ = $(SRC_GAME:.c=.o) $(SRC_DICO:.c=.o) $(SRC_AFFICHAGE:.c=.o)

jeu: $(OBJ)
	$(CC) $(CFLAGS) -o jeu $(OBJ)

game/%.o: game/%.c
	$(CC) $(CFLAGS) -c $< -o $@

dico/%.o: dico/%.c
	$(CC) $(CFLAGS) -c $< -o $@

affichage/%.o: affichage/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) jeu
