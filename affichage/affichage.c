#include "affichage.h"

int MROWS = 31 ;
int MCOLUMNS = 115 ;

void print_map(char** map) {
    for (int i = 0; i<MROWS; i++) {
        for (int j = 0; j<MCOLUMNS; j++) {
            printf("%c", map[i][j]) ;
        }
        printf("\n") ;
    } 
    printf("\n") ;
}