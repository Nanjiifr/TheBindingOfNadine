#include "input.h"

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

bool count_rocks(Personnage* pers, int dir, int** m, int* n) {
    if (dir == 2) {
        int c = 1;
        while (pers->x + c < 13 && m[pers->y][pers->x + c] == 1) {
            c ++ ;
        }
        if (pers->x + c == 13 || (m[pers->y][pers->x + c] != none && c != 1)) {
            return false ;
        } else if (m[pers->y][pers->x + c - 1] == 1) {
            *n = c ;
            return true ;
        } else {
            *n = -1 ;
            return false ;
        }
    }
    if (dir == 3) {
        int c = 1;
        while (pers->x - c >= 0 && m[pers->y][pers->x - c] == 1) {
            c ++ ;
        }
        if (pers->x - c == -1|| (m[pers->y][pers->x - c] != none && c != 1)) {
            return false ;
        } else if (m[pers->y][pers->x - c + 1] == 1) {
            *n = c ;
            return true ;
        } else {
            *n = -1 ;
            return false ;
        }
    }
    if (dir == 0) {
        int c = 1;
        while (pers->y - c >= 0 && m[pers->y - c][pers->x] == 1) {
            c ++ ;
        }
        if (pers->y - c == -1 || (m[pers->y - c][pers->x] != none && c != 1)) {
            return false ;
        } else if (m[pers->y - c + 1][pers->x] == 1) {
            *n = c ;
            return true ;
        } else {
            *n = -1 ;
            return false ;
        }
    }
    if (dir == 1) {
        int c = 1;
        while (pers->y + c < 9 && m[pers->y + c][pers->x] == 1) {
            c ++ ;
        }
        if (pers->y + c == 9 || (m[pers->y + c][pers->x] != none && c != 1)) {
            return false ;
        } else if (m[pers->y + c - 1][pers->x] == 1) {
            *n = c ;
            return true ;
        } else {
            *n = -1 ;
            return false ;
        }
    }
    return false ; //Ce cas ne devrait jamais arriver, c'est juste pour éviter les warnings (c'est moche à la compil)
}

void move (Personnage* pers, int dir, int** m) {
    int n = 0;
    if (count_rocks(pers, dir, m, &n)) {
        if (dir == 2 && pers->x < 12) { // Est
            pers->x += 1;
            for (int i = 1; i < n; i++) {
                m[pers->y][pers->x + i] = 1;
            }
            m[pers->y][pers->x] = 0;
        }
        if (dir == 3 && pers->x > 0) { // Ouest
            pers->x -= 1;
            for (int i = 1; i < n; i++) {
                m[pers->y][pers->x - i] = 1;
            }
            m[pers->y][pers->x] = 0;
        }
        if (dir == 0 && pers->y > 0) { // Nord
            pers->y -= 1;
            for (int i = 1; i < n; i++) {
                m[pers->y - i][pers->x] = 1;
            }
            m[pers->y][pers->x] = 0;
        }
        if (dir == 1 && pers->y < 8) { // Sud
            pers->y += 1;
            for (int i = 1 ; i < n; i++) {
                m[pers->y + i][pers->x] = 1;
            }
            m[pers->y][pers->x] = 0;
        }
    } else {
        if (dir == 2 && pers->x < 12 && n == -1) { // Est
            pers->x += 1;
        }
        if (dir == 3 && pers->x  > 0 && n == -1) { // Ouest
            pers->x -= 1;
        }
        if (dir == 0 && pers->y > 0 && n == -1) { // Nord
            pers->y -= 1;
        }
        if (dir == 1 && pers->y < 8 && n == -1) { // Sud
            pers->y += 1;
        }
    }
}