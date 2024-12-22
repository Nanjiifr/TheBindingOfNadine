#include "creation.h"

int MROWS = 31 ;
int MCOLUMNS = 125 ;

int ROWS = 9 ;
int COLUMNS = 38 ;

enum obstacle_e {
    none,
    rock,
    bomb,
    hole
} ;

typedef enum obstacle_e obstacle ;

int** create_empty () {
    int** n_tab = malloc(sizeof(int*)*ROWS) ;
    for (int i = 0; i<ROWS; i++) {
        n_tab[i] = malloc(sizeof(int)*COLUMNS) ;
    }
    return n_tab ;
} 

int** create_from(obstacle** obst, int len) {
    int** n_tab = create_empty () ;
    for (int i = 0; i<ROWS; i++) {
        for (int j = 0; j<COLUMNS; j++) {
            n_tab[i][j] = (int)obst[i][j] ;
        }
    }
    return n_tab ;
}

char** create_map () {
    char** map = malloc(sizeof(char*)*MROWS) ;
    for (int i = 0 ; i<MROWS; i++) {
        map[i] = malloc(sizeof(char)*MCOLUMNS) ;
        for (int j = 0; j<MCOLUMNS; j++) {
            map[i][j] = ' ' ;
        }
    }

    for (int j = 0; j<MCOLUMNS; j++) {
        if (j==0 | j==MCOLUMNS - 1) {
            map[0][j] = '+' ;
            map[1][j] = '|' ;
            map[MROWS - 2][j] = '|' ;
            map[MROWS - 1][j] = '+' ;
        } else if (j == (MCOLUMNS/2) - 2 | j==MCOLUMNS/2 + 2) {
            map[0][j] = '-' ;
            map[1][j] = '|' ;
            map[MROWS - 2][j] = '|' ;
            map[MROWS - 1][j] = '-' ;
        } else if ((1 <= j & j <= 3) | (MCOLUMNS-4 <= j & j <= MCOLUMNS-2)) {
            map[0][j] = '-' ;
            map[1][j] = ' ' ;
            map[MROWS - 2][j] = ' ' ;
            map[MROWS - 1][j] = '-' ;
        } else if (j == 4) {
            map[0][j] = '-' ;
            map[1][j] = '\\' ;
            map[MROWS - 2][j] = '/' ;
            map[MROWS - 1][j] = '-' ;
        } else if (j == MCOLUMNS - 5) {
            map[0][j] = '-' ;
            map[1][j] = '/' ;
            map[MROWS - 2][j] = '\\' ;
            map[MROWS - 1][j] = '-' ;
        } else {
            map[0][j] = '-' ;
            map[1][j] = '-' ;
            map[MROWS - 2][j] = '-' ;
            map[MROWS - 1][j] = '-' ;
        }
    }

    for (int i = 2; i<MROWS-2; i++) {
        map[i][0] = '|' ;
        map[i][4] = '|' ;
        map[i][MCOLUMNS - 5] = '|' ;
        map[i][MCOLUMNS - 1] = '|' ;
        if (i == (MROWS/2) - 1 | i == (MROWS/2)) {
            map[i][1] = '-' ;
            map[i][2] = '-' ;
            map[i][3] = '-' ;
            map[i][MCOLUMNS - 4] = '-' ;
            map[i][MCOLUMNS - 3] = '-' ;
            map[i][MCOLUMNS - 2] = '-' ;
        }
    }
    return map ;
}

void print_map(char** map) {
    for (int i = 0; i<MROWS; i++) {
        for (int j = 0; j<MCOLUMNS; j++) {
            printf("%c", map[i][j]) ;
        }
        printf("\n") ;
    } 
    printf("\n") ;
}

int main () {
    char** map = create_map() ;
    print_map(map) ;
    return 0 ;
}