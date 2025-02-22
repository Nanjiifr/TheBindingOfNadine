#ifndef SALLE_H
#define SALLE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "../dico/dico.h"
#include "creation.h"

typedef struct salle_s salle;
typedef struct teleporteur_s teleporteur;
typedef struct element_s element ;

salle* createRoom(int coord_x,int coord_y);
void destroyRoom(salle* room);
teleporteur* createTp(salle* room1, salle* room2);
void addTp(salle* room1, salle* room2);
void removeTp(salle* room1, salle* room2);


#endif //SALLE_H