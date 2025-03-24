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
    mob* mobs;
} ;

typedef struct salle_s salle;

struct element_s {
    int key ;
    salle* value ;
} ;
typedef struct element_s element;

salle* createRoom(int coord_x, int coord_y) {
    srand(time(NULL));
    salle* room = malloc(sizeof(salle));
    room->coord_x = coord_x;
    room->coord_y = coord_y;
    room->havetp = malloc(sizeof(bool));
    room->map = create_random_data(room->havetp);
    room->tp = NULL;

    // Generate random mobs for the room
    int num_mobs = 3; // Au maximum 3 mobs par salle
    room->mobs = malloc(sizeof(mob) * num_mobs);
    for (int i = 0; i < num_mobs; i++) {
        room->mobs[i].m_type = rand() % 3;
        room->mobs[i].x = malloc(sizeof(int));
        room->mobs[i].y = malloc(sizeof(int));
        do { 
            *(room->mobs[i].x) = rand() % 13;
            *(room->mobs[i].y) = rand() % 8;
        } while (room->map[*(room->mobs[i].y)][*(room->mobs[i].x)] != none || (*(room->mobs[i].x) == 6 && *(room->mobs[i].y) == 0) || \
        (*(room->mobs[i].x) == 6 && *(room->mobs[i].y) == 8) || (*(room->mobs[i].x) == 0 && *(room->mobs[i].y) == 4) ||(*(room->mobs[i].x) == 12 && *(room->mobs[i].y) == 4)) ;
    }
    return room;
}

void destroyRoom(dA* calepin, salle* room) {
    if (room->map != NULL) {
        for (int i = 0; i < 8; i++) {
            free(room->map[i]);
        }
        free(room->map);
    }
    if (room->mobs != NULL) {
        for (int i = 0; i < 3; i++) {
            if (room->mobs[i].x != NULL) {
                free(room->mobs[i].x);
            }
            if (room->mobs[i].y != NULL) {
                free(room->mobs[i].y);
            }
        }
        free(room->mobs);
    }
    if (room->tp != NULL){
        free(room->tp);
    }
    free(room->havetp);
    remove_dico(calepin, room->coord_x, room->coord_y) ;
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

void removeMob(salle* room, int mob_id) {
    room->mobs[mob_id].m_type = 0 ;
}