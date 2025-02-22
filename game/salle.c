#include "salle.h"

struct element_s {
    int key ;
    int** value ;
    int teleport ; // convention : 0 si pas de teleporteur, 1 si teleporteur sortant, 2 si teleporteur entrant
} ;
typedef struct element_s element;

struct teleporter_s {
    salle* salle1; 
    salle* salle2;
};

struct salle_s {
    int coord_x;
    int coord_y;
    element* elt;
    teleporteur* tp;
};

typedef struct salle_s salle;
typedef struct teleporter_s teleporteur;


salle* createRoom(int coord_x,int coord_y){
    salle* salle = malloc(sizeof(salle));
    element* e = malloc(sizeof(element));
    e -> key = h(coord_x,coord_y);
    e -> value = create_empty();
    e -> teleport = 0;
    salle -> elt = e;
    salle -> tp = NULL;
    return salle;
}

void destroyRoom(salle* room){
    free(room->elt->value);
    free(room->elt);
    free(room -> tp);
    free(room);
}

teleporteur* createTp(salle* room1, salle* room2){
    teleporteur* tp = malloc(sizeof(teleporteur));
    tp -> salle1 = room1;
    tp -> salle2 = room2;
    return tp;
}

void addTp(salle* room1, salle* room2){
    room1 ->elt -> teleport = 1;
    room2 ->elt -> teleport = 2;
    teleporteur* tp1 = createTp(room1,room2);
    room1 -> tp = tp1;
    room2 -> tp = tp1;
}


void removeTp(salle* room1, salle* room2){
    room1 ->elt -> teleport = 0;
    room2 ->elt -> teleport = 0;
    free(room1 -> tp);
    free(room2 -> tp);
    room1 -> tp = NULL;
    room2 -> tp = NULL;
}


