#include "game.h"


struct vt {
    int x ;
    int y ;
} ;

struct element_s {
    int key ;
    salle* value;
} ;

struct teleporter_s {
    salle* salle1; 
    salle* salle2;
};

struct salle_s {
    int coord_x;
    int coord_y;
    int** map;
    teleporteur* tp;
    int nb_tb;
};

typedef struct salle_s salle;
typedef struct teleporter_s teleporteur;
typedef struct element_s element ;



int** changeRoom(dA* calepin, int x , int y){
    element e = get(calepin, x, y);
    if (e.key != -1){
        return (e.value) -> map;
    }
    else{
        salle* salle = createRoom(x,y);
        append(calepin, x, y, salle);
        return salle->map;
    }
}

void party () {
    dA* calepinMap = create();
    Personnage pers = {7, 7} ;
    salle* salle1 = createRoom(0,0);
    int** m = malloc(sizeof(int*)*9) ;
    int* coordx = malloc(sizeof(int));
    int* coordy = malloc(sizeof(int));
    m = salle1-> map; // TODO : ajouter TP ICI
    *coordx = 0;
    *coordy = 0;
    append(calepinMap, 0, 0, salle1);
    char** map = create_map(m, pers) ;
    while (true) {
        int n = getch() ;
        if (n == 122) {
            move(&pers, 0) ; //Nord
        }
        if (n == 113) {
            move(&pers, 3) ; //Ouest
        }
        if (n == 115) {
            move(&pers, 1) ; //Sud
        }
        if (n == 100) {
            move(&pers, 2) ; //Est
        }
        char** map = create_map(m, pers) ;
        print_map(map) ;
        printf("x : %d, y : %d\n", *coordx, *coordy);

        if(pers.x == 6 && pers.y == 0){
            printf("                   Porte Nord - Press [E] to enter\n");
            if (n==101){
                *coordy = *coordy + 1;
                pers.y = 7;
                m = changeRoom(calepinMap, *coordx, *coordy);
            }
        }

        if(pers.x == 6 && pers.y == 8){
            printf("                   Porte Sud - Press [E] to enter\n");
            if (n==101){
                *coordy = *coordy - 1;
                pers.y = 1;
                m = changeRoom(calepinMap, *coordx, *coordy);
            }
        }

        if(pers.x == 0 && pers.y == 4){
            printf("                   Porte Ouest - Press [E] to enter\n");
            if (n==101){
                pers.x = 11;
                *coordx = *coordx - 1;
                m = changeRoom(calepinMap, *coordx, *coordy);
            }
        }

        if(pers.x == 12 && pers.y == 4){
            printf("                   Porte Est - Press [E] to enter\n");
            if (n==101){
                pers.x = 1;
                *coordx = *coordx + 1;
                m = changeRoom(calepinMap, *coordx, *coordy);
            }
        }
        
    }
}