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

        if(pers.x == 6 && pers.y == 0){
            printf("                   Porte Nord - Press [E] to enter\n");
            if (n==101){
                printf("Vous avez appuyé sur e\n");
                pers.y = 7;
            }
        }

        if(pers.x == 6 && pers.y == 8){
            printf("                   Porte Sud - Press [E] to enter\n");
            if (n==101){
                pers.y = 1;
            }
        }

        if(pers.x == 0 && pers.y == 4){
            printf("                   Porte Ouest - Press [E] to enter\n");
            if (n==101){
                pers.x = 11;
            }
        }

        if(pers.x == 12 && pers.y == 4){
            printf("                   Porte Est - Press [E] to enter\n");
            if (n==101){
                pers.x = 1;
            }
        }
        
    }
    return 0 ;
}