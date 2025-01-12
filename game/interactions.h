#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include "creation.h"
#include "salle.h"


typedef struct Objet_s Objet ;
typedef struct Personnage_s Personnage ;
typedef enum obstacle_e obstacle ;

// Fonction pour initialiser une bombe.
void init_bombe(Objet* objet) ;

// Fonction pour initialiser un téléporteur.
void init_teleporteur(Objet* objet) ;

// Fonction pour initialiser un rocher.
void init_rocher(Objet* objet) ;

// Fonction pour gérer l'interaction entre le personnage et un objet.
void interaction_objet(obstacle* obst, salle* salle_act) ;

// Fonction pour supprimer les salles adjacentes (utilisée par la bombe).
void boom(salle* salles, int* nombre_salles) ;

// Fonction pour téléporter le personnage dans une salle aléatoire.
void teleporter_personnage(Personnage* personnage, salle* salles, int nombre_salles) ;

// commentaire test

#endif // INTERACTIONS_H