#ifndef CREATION
#define CREATION

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef enum obstacle_e obstacle ;

char** create_map (int** m) ;
int** create_from(obstacle obst[9][15]) ;
char** create_random () ;

#endif //CREATION