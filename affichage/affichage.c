#include "affichage.h"

int M_ROWS = 31 ;
int M_COLUMNS = 115 ;

void print_map(char** map) {
    for (int i = 0; i<M_ROWS; i++) {
        for (int j = 0; j<M_COLUMNS; j++) {
            printf("%c", map[i][j]) ;
        }
        printf("\n") ;
    } 
    printf("\n") ;
}