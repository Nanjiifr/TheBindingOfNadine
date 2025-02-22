#include "input.h"

struct Personnage_s {
    int x ;
    int y ;
} ;

typedef struct Personnage_s Personnage ;

double acquisition_time = 75.0 ;

int getch() { 
    int ch;
    struct termios oldattr, newattr;

    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~ICANON;
    newattr.c_lflag &= ~ECHO;
    newattr.c_cc[VMIN] = 1;
    newattr.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    struct pollfd mypoll = { STDIN_FILENO, POLLIN|POLLPRI };
    
    if( poll(&mypoll, 1, acquisition_time) )
        ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);

    return ch; 
}

void move (Personnage* pers, int dir) {
    if (dir == 2 && pers->x < 12) { //Est
        pers->x += 1 ;
    }
    if (dir == 3 && pers->x > 0) { //Ouest
        pers->x -= 1 ;
    }
    if (dir == 0 && pers->y > 0) { //Nord
        pers->y -= 1 ;
    }
    if (dir == 1 && pers->y < 8) { //Sud
        pers->y += 1 ;
    }
}