#include "salle.h"

struct teleporter_s {
    salle* salle1; 
    salle* salle2;
};
typedef struct teleporter_s teleporteur;


struct salle_s {
    int coord_x;
    int coord_y;
    int** map;
    bool* havetp;
    teleporteur* tp;
};
typedef struct salle_s salle;

struct element_s {
    int key ;
    salle* value ;
} ;
typedef struct element_s element;

salle* createRoom(int coord_x,int coord_y){
    salle* salle = malloc(sizeof(salle));
    salle -> coord_x = coord_x;
    salle -> coord_y = coord_y;
    salle -> havetp = malloc(sizeof(bool)) ;
    salle -> map = create_random_data(salle -> havetp);
    salle -> tp = NULL;
    return salle;
}

void destroyRoom(salle* room){
    free(room->map);
    if (room -> tp != NULL){
        free(room -> tp);
    }
    free(room);
}

teleporteur* createTp(salle* room1, salle* room2){
    teleporteur* tp = malloc(sizeof(teleporteur));
    tp -> salle1 = room1;
    tp -> salle2 = room2;
    return tp;
}

void addTp(salle* room1, salle* room2){
    //room1 -> nb_tp = 1;
    //room2 -> nb_tp = 2;
    teleporteur* tp1 = createTp(room1,room2);
    room1 -> tp = tp1;
    room2 -> tp = tp1;
}


void removeTp(salle* room1, salle* room2){
    //room1 -> nb_tp = 0;
    //room2 -> nb_tp = 0;
    free(room1 -> tp);
    free(room2 -> tp);
    room1 -> tp = NULL;
    room2 -> tp = NULL;
}


