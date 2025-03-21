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

void party(bool* inGame) {
    *inGame = true;
    dA* calepinMap = create();
    Personnage pers = {7, 7} ;
    int lives = 5 ;
    mob h ;
    h.m_type = HALFON ;
    h.x = malloc(sizeof(int)) ;
    h.y = malloc(sizeof(int)) ;
    salle* salle1 = createRoom(0,0);
    int** m = malloc(sizeof(int*)*9) ;
    int* coordx = malloc(sizeof(int));
    int* coordy = malloc(sizeof(int));
    m = salle1-> map; // TODO : ajouter TP ICI
    srand(time(NULL));
    do {
        *h.x = rand() % 9;
        *h.y = rand() % 9;
    } while (m[*h.x][*h.y] != 0);
    *coordx = 0;
    *coordy = 0;
    append(calepinMap, 0, 0, salle1);
    char** map = create_map(m, pers, &h) ;
    while (true) {
        int n = getch() ;
        if (n == 127) {
            *inGame = false;
            printMainMenu();
            return ;
        }
        if (n == 122) {
            move_mob(m, h, pers.x, pers.y) ;
            move(&pers, 0, m) ; //Nord
        }
        if (n == 113) {
            move_mob(m, h, pers.x, pers.y) ;
            move(&pers, 3, m) ; //Ouest
        }
        if (n == 115) {
            move_mob(m, h, pers.x, pers.y) ;
            move(&pers, 1, m) ; //Sud
        }
        if (n == 100) {
            move_mob(m, h, pers.x, pers.y) ;
            move(&pers, 2, m) ; //Est
        }
        char** map = create_map(m, pers, &h) ;
        print_map(map) ;
        print_lives(lives) ;
        printf("Press [Backspace] to quit to title\n");
        
        if(pers.x == 6 && pers.y == 0){
            printf("                                                Porte Nord - Press [E] to enter\n");
            if (n==101){
                *coordy = *coordy + 1;
                pers.y = 7;
                m = changeRoom(calepinMap, *coordx, *coordy);
                srand(time(NULL));
                do {
                    *h.x = rand() % 9;
                    *h.y = rand() % 9;
                } while (m[*h.x][*h.y] != 0);
            }
        }

        if(pers.x == 6 && pers.y == 8){
            printf("                                                 Porte Sud - Press [E] to enter\n");
            if (n==101){
                *coordy = *coordy - 1;
                pers.y = 1;
                m = changeRoom(calepinMap, *coordx, *coordy);
                srand(time(NULL));
                do {
                    *h.x = rand() % 9;
                    *h.y = rand() % 9;
                } while (m[*h.x][*h.y] != 0);
            }
        }

        if(pers.x == 0 && pers.y == 4){
            printf("                                                 Porte Ouest - Press [E] to enter\n");
            if (n==101){
                pers.x = 11;
                *coordx = *coordx - 1;
                m = changeRoom(calepinMap, *coordx, *coordy);
                srand(time(NULL));
                do {
                    *h.x = rand() % 9;
                    *h.y = rand() % 9;
                } while (m[*h.x][*h.y] != 0);
            }
        }

        if(pers.x == 12 && pers.y == 4){
            printf("                                                  Porte Est - Press [E] to enter\n");
            if (n==101){
                pers.x = 1;
                *coordx = *coordx + 1;
                m = changeRoom(calepinMap, *coordx, *coordy);
                srand(time(NULL));
                do {
                    *h.x = rand() % 9;
                    *h.y = rand() % 9;
                } while (m[*h.x][*h.y] != 0);
            }
        }
    }
}