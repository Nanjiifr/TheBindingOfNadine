#include "../affichage/affichage.h"
#include "input.h"
#include "creation.h"
#include <stdbool.h>

int main () {
    Personnage pers = {7, 7} ;
    int** m = create_empty() ;
    char** map = create_map(m, pers) ;
    while (true) {
        int n = getch() ;
        if (n == 122) {
            move(&pers, 0) ; //Nord
        }
        if (n == 113) {
            move(&pers, 3) ; //Ouest
        }
        if (n == 115) {
            move(&pers, 1) ; //Sud
        }
        if (n == 100) {
            move(&pers, 2) ; //Est
        }
        char** map = create_map(m, pers) ;
        print_map(map) ;
    }
    return 0 ;
}