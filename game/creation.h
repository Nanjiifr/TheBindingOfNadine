#ifndef CREATION_H
#define CREATION_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "mob.h"

enum obstacle_e {
    none,
    rock,
    bomb,
    portal
} ;

typedef enum obstacle_e obstacle ;

struct Personnage_s {
    int x ;
    int y ;
} ;

typedef struct Personnage_s Personnage ;

struct mob_s;
typedef struct mob_s mob;

int ROWS ;
int COLUMNS ;

int** create_empty () ;
char** create_map (int** m, Personnage pers, mob* mobs) ;
//int** create_from(obstacle obst[9][13]) ;
int** create_random_data() ;
char** create_random(Personnage pers, mob* mobs) ;

#endif //CREATION