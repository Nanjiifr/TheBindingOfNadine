#include "game.h"

struct vt {
    int x ;
    int y ;
} ;

struct teleporter_s {
    salle* salle1; 
    salle* salle2;
};

struct salle_s {
    int coord_x;
    int coord_y;
    int** map;
    salle* tp;
    mob* mobs;
} ;

typedef struct salle_s salle;
typedef struct teleporter_s teleporteur;
typedef struct element_s element ;



salle* changeRoom(dA* calepin, int x , int y){
    element e = get(calepin, x, y);
    if (e.key != -1){
        return e.value;
    }
    else{
        salle* salle = createRoom(x,y);
        append(calepin, x, y, salle);
        return salle;
    }
}

void party(bool* inGame) {
    *inGame = true;
    dA* calepinMap = create();
    Personnage pers = {7, 7} ;
    int lives = 5 ;
    salle* salle1 = createRoom(0,0);
    int** m = malloc(sizeof(int*)*9) ;
    int* coordx = malloc(sizeof(int));
    int* coordy = malloc(sizeof(int));
    m = salle1->map; // TODO : ajouter TP ICI
    *coordx = 0;
    *coordy = 0;
    append(calepinMap, 0, 0, salle1);
    char** map = create_map(m, pers, salle1->mobs) ;
    while (true) {
        m = salle1->map;
        int n = getch() ;
        if (n == 127) {
            *inGame = false;
            printMainMenu();
            return ;
        }
        if (n == 122) {
            move(&pers, 0, m) ; //Nord
            move_mob(m, salle1->mobs, pers.x, pers.y) ;
        }
        if (n == 113) {
            move(&pers, 3, m) ; //Ouest
            move_mob(m, salle1->mobs, pers.x, pers.y) ;
        }
        if (n == 115) {
            move(&pers, 1, m) ; //Sud
            move_mob(m, salle1->mobs, pers.x, pers.y) ;
        }
        if (n == 100) {
            move(&pers, 2, m) ; //Est
            move_mob(m, salle1->mobs, pers.x, pers.y) ;
        }
        char** map = create_map(m, pers, salle1->mobs) ;
        print_map(map) ;
        print_lives(lives) ;
        printf("Press [Backspace] to quit to title (All game data will be erased)\n");
        
        if(pers.x == 6 && pers.y == 0){
            printf("                                                Porte Nord - Press [E] to enter\n");
            if (n==101){
                *coordy = *coordy + 1;
                pers.y = 7;
                salle1 = changeRoom(calepinMap, *coordx, *coordy);
            }
        }

        if(pers.x == 6 && pers.y == 8){
            printf("                                                 Porte Sud - Press [E] to enter\n");
            if (n==101){
                *coordy = *coordy - 1;
                pers.y = 1;
                salle1 = changeRoom(calepinMap, *coordx, *coordy);
            }
        }

        if(pers.x == 0 && pers.y == 4){
            printf("                                                 Porte Ouest - Press [E] to enter\n");
            if (n==101){
                pers.x = 11;
                *coordx = *coordx - 1;
                salle1 = changeRoom(calepinMap, *coordx, *coordy);
            }
        }

        if(pers.x == 12 && pers.y == 4){
            printf("                                                  Porte Est - Press [E] to enter\n");
            if (n==101){
                pers.x = 1;
                *coordx = *coordx + 1;
                salle1 = changeRoom(calepinMap, *coordx, *coordy);
            }
        }

        if (m[pers.y][pers.x] == bomb) {
            printf("                                                  Bomb - Press [B] to activate\n");
            if (n==98) {
                boom(calepinMap, *coordx, *coordy) ;
            }
        }

        if (m[pers.y][pers.x] == portal) {
            printf("                                                  Teleporter - Press [B] to activate\n");
            if (n==98) {
                teleporter_personnage(calepinMap, coordx, coordy) ;
                salle1 = changeRoom(calepinMap, *coordx, *coordy);
            }
        }
    }
}