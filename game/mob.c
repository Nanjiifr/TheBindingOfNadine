#include "mob.h"

int rows = 9 ;
int columns = 13 ;

int* possible_moves(int** map, mob m, int pers_x, int pers_y) {
    int* p = malloc(sizeof(bool)*4) ;
    for (int i = 0; i < 4; i++) {
        p[i] = false;
    }
    if (*m.x > 0 && map[*m.y][*m.x - 1] == 0 && (pers_y != *m.y || pers_x != *m.x - 1)) {
        p[0] = true ;
    }
    if (*m.y < rows - 1 && map[*m.y + 1][*m.x] == 0 && (pers_x != *m.x || pers_y != *m.y + 1)) {
        p[1] = true ;
    }
    if (*m.x < columns - 1 && map[*m.y][*m.x + 1] == 0 && (pers_y != *m.y || pers_x != *m.x + 1)) {
        p[2] = true ;
    }
    if (*m.y > 0 && map[*m.y - 1][*m.x] == 0 && (pers_x != *m.x || pers_y != *m.y - 1)) {
        p[3] = true ;
    }
    return p ;
}

void move_mob(int** map, mob m, int pers_x, int pers_y) {
    if (m.m_type == HALFON) {
        int* p = possible_moves(map, m, pers_x, pers_y) ;
        srand(time(NULL));
        int direction;
        do {
            direction = rand() % 4;
        } while (!p[direction]);

        switch (direction) {
            case 0:
            (*m.x)--;
            break;
            case 1:
            (*m.y)++;
            break;
            case 2:
            (*m.x)++;
            break;
            case 3:
            (*m.y)--;
            break;
        }
        free(p);
    }
}