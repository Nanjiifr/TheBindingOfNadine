#ifndef MOB_H
#define MOB_H

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "game.h"
#include "creation.h"


enum mob_type_e {
    NONE,
    HALFON,
    TARGET_NADINE,
} ;

typedef enum mob_type_e mob_type ;

struct mob_s {
    int m_type;
    int* x;
    int* y;
} ;

typedef struct mob_s mob ;

void move_mob(int** map, mob* m, int pers_x, int pers_y, int* lives) ;

#endif //MOB_H