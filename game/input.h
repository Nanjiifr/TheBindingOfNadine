#ifndef INPUT_H
#define INPUT_H

#include <unistd.h>
#include <poll.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <termios.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/time.h>

typedef struct Personnage_s Personnage ;

int getch() ;

void move (Personnage* pers, int dir, int** m) ;

#endif //INPUT_H