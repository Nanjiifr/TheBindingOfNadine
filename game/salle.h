#ifndef SALLE_H
#define SALLE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "../dico/dico.h"

typedef struct salle_s salle;
typedef struct teleporteur_s teleporteur;

salle* createRoom(int coord_x,int coord_y);
void destroyRoom(salle* room);
void addTp(salle* room, teleporteur* tp);
void removeTp(salle* room);

#endif //SALLE_H