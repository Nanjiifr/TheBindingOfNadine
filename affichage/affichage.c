#include "affichage.h"

#define clear() printf("\033[H\033[J")

int M_ROWS = 38 ;
int M_COLUMNS = 131 ;

void print_map(char** map) {
    clear() ;
    for (int i = 0; i<M_ROWS; i++) {
        for (int j = 0; j<M_COLUMNS; j++) {
            printf("%c", map[i][j]) ;
        }
        printf("\n") ;
    } 
    printf("\n") ;
}