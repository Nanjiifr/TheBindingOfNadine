#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include "creation.h"
#include "salle.h"
#include <unistd.h>

struct element_s {
    int key ;
    salle* value;
} ;

typedef struct Objet_s Objet ;
typedef struct Personnage_s Personnage ;
typedef enum obstacle_e obstacle ;
typedef struct element_s element ;

// Fonction pour initialiser une bombe.
void init_bombe(Objet* objet) ;

// Fonction pour initialiser un téléporteur.
void init_teleporteur(Objet* objet) ;

// Fonction pour initialiser un rocher.
void init_rocher(Objet* objet) ;

// Fonction pour gérer l'interaction entre le personnage et un objet.
void interaction_objet(obstacle* obst, salle* salle_act) ;

// Fonction pour supprimer les salles adjacentes (utilisée par la bombe).
void boom(dA* calepin, int coordx, int coordy) ;

// Fonction pour téléporter le personnage dans une salle aléatoire.
void teleporter_personnage(dA* calepin, int* x, int* y ) ;

#endif // INTERACTIONS_H