#include "creation.h"

int ROWS = 6 ;
int COLUMNS = 24 ;

int** create_empty () {
    int** n_tab = malloc(sizeof(int*)*ROWS) ;
    for (int i = 0; i<ROWS; i++) {
        n_tab[i] = malloc(sizeof(int)*COLUMNS) ;
    }
    return n_tab ;
}