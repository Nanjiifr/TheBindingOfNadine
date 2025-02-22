
jeu : main.o
	gcc -o jeu *.o

main.o : dico.o
	gcc -c game/*.c

dico.o : affichage.o
	gcc -c dico/*.c

affichage.o :
	gcc -c affichage/*.c

clean:
	rm -f *.o





