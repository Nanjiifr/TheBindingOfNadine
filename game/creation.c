#include "creation.h"

#define clear() printf("\033[H\033[J")

int MROWS = 31 ;
int MCOLUMNS = 115 ;

int ROWS = 9 ;
int COLUMNS = 15 ;

int NB_OBST = 3 ;

enum obstacle_e {
    none,
    rock,
    bomb,
    portal
} ;

typedef enum obstacle_e obstacle ;

char obst[4][3][7] = {{"       ", "       ", "       "}, 
                    {" ##### ", "#######", " ##### "}, 
                    {"   |   ", " /---\\ ", " \\___/ "}, 
                    {" ____  ", "/    \\ ", "\\____/ "}
} ;

int** create_empty () {
    int** n_tab = malloc(sizeof(int*)*ROWS) ;
    for (int i = 0; i<ROWS; i++) {
        n_tab[i] = malloc(sizeof(int)*COLUMNS) ;
        for (int j = 0 ; j<COLUMNS; j++) {
            n_tab[i][j] = 0 ;
        }
    }
    return n_tab ;
} 

int** create_from(obstacle obst[9][15]) {
    int** n_tab = create_empty () ;
    for (int i = 0; i<ROWS; i++) {
        for (int j = 0; j<COLUMNS; j++) {
            n_tab[i][j] = (int)obst[i][j] ;
        }
    }
    return n_tab ;
}

char** create_map (int** m) {
    //int** m = create_from(o) ;
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

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l<7; l++) {
                    map[(i*3) + 2 + k][(j*7) + 5 + l] = obst[m[i][j]][k][l] ;
                }
            }
        }
    }

    return map ;
}

int cond(int* pos, int nb_obst) {
    int i = 0 ;
    while (i<nb_obst) {
        for (int j = i + 1; j<nb_obst; j++) {
            if (abs(pos[i] - pos[j]) >= 5) return false ;
        }
        i++ ;
    }
    return true ;
}

char** create_random() {
    srand(time(NULL)) ;
    int nb_obst = 2 + rand() % 4 ;

    int pos[nb_obst] ;
    for (int i = 0; i<nb_obst; i++) {
        pos[i] = -1 ;
    }

    while(cond(pos, nb_obst)) {
        for (int i = 0 ; i<nb_obst; i++) {
            pos[i] = rand() % 135 ;
        }
    }

    int** m = create_empty() ;
    for (int i = 0; i<nb_obst; i++) {
        m[pos[i]/COLUMNS][pos[i]%COLUMNS] = 1 + rand() % NB_OBST ;
    }

    return create_map(m) ;
}

void print_map(char** map) {
    clear() ;
    for (int i = 0; i<MROWS; i++) {
        for (int j = 0; j<MCOLUMNS; j++) {
            printf("%c", map[i][j]) ;
        }
        printf("\n") ;
    } 
    printf("\n") ;
}

int main () {
    char** map = create_random() ;

    print_map(map) ;
}