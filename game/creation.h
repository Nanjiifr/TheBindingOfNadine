#ifndef CREATION_H
#define CREATION_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "mob.h"

typedef enum obstacle_e obstacle ;

struct Personnage_s {
    int x ;
    int y ;
} ;

typedef struct Personnage_s Personnage ;

int ROWS ;
int COLUMNS ;

int** create_empty () ;
char** create_map (int** m, Personnage pers, mob* mobs) ;
//int** create_from(obstacle obst[9][13]) ;
int** create_random_data(bool* tp) ;
char** create_random(Personnage pers, mob* mobs) ;

#endif //CREATION