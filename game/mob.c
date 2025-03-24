#include "mob.h"

int rows = 9 ;
int columns = 13 ;



int* possible_moves(int** map, mob m, int pers_x, int pers_y) {
    int* p = malloc(sizeof(bool)*4) ;
    for (int i = 0; i < 4; i++) {
        p[i] = false ;
    }
    if (m.m_type == HALFON) {
        for (int i = 0; i < 4; i++) {
            p[i] = false;
        }
        if (*m.x > 0 && map[*m.y][*m.x - 1] == 0) {
            p[0] = true ;
        }
        if (*m.y < rows - 1 && map[*m.y + 1][*m.x] == 0) {
            p[1] = true ;
        }
        if (*m.x < columns - 1 && map[*m.y][*m.x + 1] == 0) {
            p[2] = true ;
        }
        if (*m.y > 0 && map[*m.y - 1][*m.x] == 0) {
            p[3] = true ;
        }
    }
    if (m.m_type == TARGET_NADINE) {
        int min_distance = 50;
        int best_direction = -1;

        if (*m.x > 0 && map[*m.y][*m.x - 1] == 0) {
            int distance = abs(*m.x - 1 - pers_x) + abs(*m.y - pers_y);
            if (distance == 0) {
                p[best_direction] = true ;
                return p ;
            }
            if (distance < min_distance) {
                min_distance = distance;
                best_direction = 0;
            }
        }
        if (*m.y < rows - 1 && map[*m.y + 1][*m.x] == 0) {
            int distance = abs(*m.x - pers_x) + abs(*m.y + 1 - pers_y);
            if (distance == 0) {
                p[best_direction] = true ;
                return p ;
            }
            if (distance < min_distance) {
                min_distance = distance;
                best_direction = 1;
            }
        }
        if (*m.x < columns - 1 && map[*m.y][*m.x + 1] == 0) {
            int distance = abs(*m.x + 1 - pers_x) + abs(*m.y - pers_y);
            if (distance == 0) {
                p[best_direction] = true ;
                return p ;
            }
            if (distance < min_distance) {
                min_distance = distance;
                best_direction = 2;
            }
        }
        if (*m.y > 0 && map[*m.y - 1][*m.x] == 0) {
            int distance = abs(*m.x - pers_x) + abs(*m.y - 1 - pers_y);
            if (distance == 0) {
                p[best_direction] = true ;
                return p ;
            }
            if (distance < min_distance) {
                min_distance = distance;
                best_direction = 3;
            }
        }
        p[best_direction] = true ;
    }
    return p ;
}

bool can_kill(int dir, mob m, int pers_x, int pers_y) {
    return (abs(*m.x - pers_x) + abs(*m.y - 1 - pers_y) <= 1) ;
}

void move_mob(int** map, mob* m, int pers_x, int pers_y, int* lives) {
    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        int* p = possible_moves(map, m[i], pers_x, pers_y) ;
        int direction;
        if (m[i].m_type == HALFON) {
            direction = rand() % 4;

            if (can_kill(direction, m[i], pers_x, pers_y)) {
                m[i].m_type = NONE ;
                *lives -= 1 ;
            }
            
            else {
                do {
                    direction = rand() % 4;
                } while (!p[direction] && !can_kill(direction, m[i], pers_x, pers_y)) ;
                switch (direction) {
                    case 0:
                    (*m[i].x)--;
                    break;
                    case 1:
                    (*m[i].y)++;
                    break;
                    case 2:
                    (*m[i].x)++;
                    break;
                    case 3:
                    (*m[i].y)--;
                    break;
                }
            }
        }
        if (m[i].m_type == TARGET_NADINE) {
            int best_direction = -1;
            for (int j = 0; j < 4; j++) {
                if (p[j]) {
                    best_direction = j;
                    break;
                }
            }

            if (can_kill(best_direction, m[i], pers_x, pers_y)) {
                m[i].m_type = NONE ;
                *lives -= 1;
            } else if (best_direction != -1) {
                switch (best_direction) {
                    case 0:
                        (*m[i].x)--;
                        break;
                    case 1:
                        (*m[i].y)++;
                        break;
                    case 2:
                        (*m[i].x)++;
                        break;
                    case 3:
                        (*m[i].y)--;
                        break;
                }
            }
        }

        free(p);
    }
}