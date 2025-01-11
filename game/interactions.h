#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include "creation.h"
#include "salle.h"

// Fonction pour initialiser une bombe.
void init_bombe(Objet* objet);

// Fonction pour initialiser un téléporteur.
void init_teleporteur(Objet* objet);

// Fonction pour initialiser un rocher.
void init_rocher(Objet* objet);

// Fonction pour gérer l'interaction entre le personnage et un objet.
void interaction_objet(Obstacle* obst, Salle* salle_act);

// Fonction pour supprimer les salles adjacentes (utilisée par la bombe).
void boom(Salle* salles, int* nombre_salles);

// Fonction pour téléporter le personnage dans une salle aléatoire.
void teleporter_personnage(Personnage* personnage, Salle* salles, int nombre_salles)

// commentaire test

#endif // INTERACTIONS_H