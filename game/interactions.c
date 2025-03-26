#include "interactions.h"

void clear_input_buffer() {
    tcflush(STDIN_FILENO, TCIFLUSH);
}

typedef struct element_s element ;

struct salle_s {
    int coord_x;
    int coord_y;
    int** map;
    salle* tp;
    mob* mobs;
} ;

typedef struct salle_s salle;


#define clear() printf("\033[H\033[J")

void boom(dA* calepin, int x, int y) {
    int k = get(calepin, x+1, y).key ;
    salle* e = get(calepin, x+1, y).value ;

    
    if (k != -1) {
        destroyRoom(calepin, e) ;
    }

    k = get(calepin, x-1, y).key ;
    e = get(calepin, x-1, y).value ;

    if (k != -1) {
        destroyRoom(calepin, e) ;
    }

    k = get(calepin, x, y+1).key ;
    e = get(calepin, x, y+1).value ;

    if (k != -1) {
        destroyRoom(calepin, e) ;
    }

    k = get(calepin, x, y-1).key ;
    e = get(calepin, x, y-1).value ;

    if (k != -1) {
        destroyRoom(calepin, e) ;
    } 

    clear() ;
    printf("\033[1;31m"); // Set text color to red
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                             888888b.   .d88888b.  .d88888b.  .d88888b. 888b     d888\n");
    printf("                                             888  \"88b d88P\" \"Y88bd88P\" \"Y88bd88P\" \"Y88b8888b   d8888\n");
    printf("                                             888  .88P 888     888888     888888     88888888b.d88888\n");
    printf("                                             8888888K. 888     888888     888888     888888Y88888P888\n");
    printf("                                             888  \"Y88b888     888888     888888     888888 Y888P 888\n");
    printf("                                             888    888888     888888     888888     888888  Y8P  888\n");
    printf("                                             888   d88PY88b. .d88PY88b. .d88PY88b. .d88P888   \"   888\n");
    printf("                                             8888888P\"  \"Y88888P\"  \"Y88888P\"  \"Y88888P\" 888       888\n");
    printf("\033[0m"); // Reset text color
    usleep(500000); // Sleep for 500 milliseconds
    clear() ;
    printf("\033[38;2;40;192;192m") ;
}

void teleporter_personnage(dA* calepin, int* x, int* y ) {
    int k = get(calepin, *x, *y).key ;
    salle* e = get(calepin, *x, *y).value ;

    if (e -> tp == NULL){
        srand(time(NULL));
        int c = rand()%117;
        int d = rand()%112;
        int a = get(calepin, c, d).key ;
        salle* b = get(calepin, c, d).value ;
        if (a == -1) {
            b = createRoom(c,d);
            append(calepin,c,d,b);
        }
        e -> tp = b;
        b -> tp = e;
        *x = c;
        *y = d;
    } else {
        *x = e -> tp -> coord_x;
        *y = e -> tp -> coord_y;
    }
}

void attack_animation(int** m, Personnage pers, mob* mobs, int direction) {
    struct pollfd mypoll = { STDIN_FILENO, POLLIN | POLLPRI };
    char sword_horizontal[3][9] = {
        "         ",
        "----+----",
        "         "
    };

    char sword_vertical[3][9] = {
        "    |    ",
        "    |    ",
        "    +    "
    };

    char sword_diagonal[3][9] = {
        " \\       ",
        "     +   ",
        "       / "
    };

    for (int frame = 0; frame < 4; frame++) {
        char** map = create_map(m, pers, mobs);

        int target_x = pers.x;
        int target_y = pers.y;

        // Détermine la position cible en fonction de la direction
        switch (direction) {
            case 4: // Droite
                target_x = pers.x + 1;
                if (target_x < COLUMNS) {
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 9; j++) {
                            map[3 * target_y + i+ 6][9 * target_x + j + 7] = sword_horizontal[i][j];
                        }
                    }
                }
                break;

            case 0: // Gauche
                target_x = pers.x - 1;
                if (target_x >= 0) {
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 9; j++) {
                            map[3 * target_y + i+ 6][9 * target_x + j + 7] = sword_horizontal[i][j];
                        }
                    }
                }
                break;

            case 2: // Haut
                target_y = pers.y - 1;
                if (target_y >= 0) {
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 9; j++) {
                            map[3 * target_y + i+ 6][9 * target_x + j + 7] = sword_vertical[i][j];
                        }
                    }
                }
                break;

            case 6: // Bas
                target_y = pers.y + 1;
                if (target_y < ROWS) {
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 9; j++) {
                            map[3 * target_y + i+ 6][9 * target_x + j + 7] = sword_vertical[i][j];
                        }
                    }
                }
                break;

            case 1: // Haut-gauche
                target_x = pers.x - 1;
                target_y = pers.y - 1;
                if (target_x >= 0 && target_y >= 0) {
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 9; j++) {
                            map[3 * target_y + i+ 6][9 * target_x + j + 7] = sword_diagonal[i][j];
                        }
                    }
                }
                break;

            case 3: // Haut-droite
                target_x = pers.x + 1;
                target_y = pers.y - 1;
                if (target_x < COLUMNS && target_y >= 0) {
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 9; j++) {
                            map[3 * target_y + i+ 6][9 * target_x + 8 - j + 7] = sword_diagonal[i][j];
                        }
                    }
                }
                break;

            case 7: // Bas-gauche
                target_x = pers.x - 1;
                target_y = pers.y + 1;
                if (target_x >= 0 && target_y < ROWS) {
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 9; j++) {
                            map[3 * target_y + 2 - i + 6][9 * target_x + j + 7] = sword_diagonal[i][j];
                        }
                    }
                }
                break;

            case 5: // Bas-droite
                target_x = pers.x + 1;
                target_y = pers.y + 1;
                if (target_x < COLUMNS && target_y < ROWS) {
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 9; j++) {
                            map[3 * target_y + 2 - i + 6][9 * target_x + 8 - j + 7] = sword_diagonal[i][j];
                        }
                    }
                }
                break;
        }

        print_map(map); // Affiche la carte mise à jour
        usleep(25000); // Pause de 50 millisecondes
        clear_input_buffer();
    }
}

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2) ;
}

void attack(salle* room, Personnage pers) {
    int pers_x = pers.x;
    int pers_y = pers.y;

    for (int dir = 0; dir < 8; dir++) {
        // Appelle l'animation d'attaque avec la direction spécifiée
        attack_animation(room->map, pers, room->mobs, dir);

        // Détermine la position cible en fonction de la direction
        int target_x = pers_x;
        int target_y = pers_y;

        switch (dir) {
            case 4: // Droite
                target_x = pers_x + 1;
                break;
            case 0: // Gauche
                target_x = pers_x - 1;
                break;
            case 2: // Haut
                target_y = pers_y - 1;
                break;
            case 6: // Bas
                target_y = pers_y + 1;
                break;
            case 1: // Haut-gauche
                target_x = pers_x - 1;
                target_y = pers_y - 1;
                break;
            case 3: // Haut-droite
                target_x = pers_x + 1;
                target_y = pers_y - 1;
                break;
            case 7: // Bas-gauche
                target_x = pers_x - 1;
                target_y = pers_y + 1;
                break;
            case 5: // Bas-droite
                target_x = pers_x + 1;
                target_y = pers_y + 1;
                break;
        }

        // Vérifie et tue les mobs dans la salle cible
        for (int i = 0; i < 3; i++) {
            mob m = room->mobs[i];
            if (m.m_type != NONE && *m.x == target_x && *m.y == target_y) {
                // Libère la mémoire associée au mob
                free(room->mobs[i].x);
                free(room->mobs[i].y);

                // Réinitialise le mob
                room->mobs[i].m_type = NONE;
                room->mobs[i].x = malloc(sizeof(int));
                room->mobs[i].y = malloc(sizeof(int));
                *(room->mobs[i].x) = 0;
                *(room->mobs[i].y) = 0;
            }
        }
    }
}