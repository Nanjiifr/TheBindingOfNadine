# Structure du projet  

## La structure de donnée utilisée (dictionnaires & listes chainées)  
-> fichiers `dico.h` et `dico.c`\
-> fonction de hashage pour le dictionnaire : h(i, j) = (2^(2*i si i >= 0 ; -2*i - 1 sinon) * 3^(2*j si j >= 0 ; -2*j - 1 sinon ))\
-> structure de données choisie (non définitif) : Dictionnaire dynamique (tableau), composé de tableaux de tupes : element, values. Les principales fonctions sont listées sur le `dico.h`\

## Les fichiers affichages  
-> fichers `affichage.c` et `affichage.h`\

## Moteur du jeu  
-> fichier `game.c`\

## Données supplémentaires  
-> Données utiles au jeu\
-> ex : visuels, ascii, sauvegarde de partie (inventer une manière de stocker efficacement pour récupérer sans trop de problèmes)\

# Questions :  

-> Utilisation d'une librairie graphique ou du terminal directement ?
