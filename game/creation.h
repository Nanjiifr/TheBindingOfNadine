#ifndef CREATION_H
#define CREATION_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef enum obstacle_e obstacle ;

struct Personnage_s {
    int x ;
    int y ;
} ;

typedef struct Personnage_s Personnage ;

int** create_empty () ;
char** create_map (int** m, Personnage pers) ;
//int** create_from(obstacle obst[9][13]) ;
char** create_random (Personnage pers) ;

#endif //CREATION