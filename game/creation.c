#include "creation.h"

//#define clear() printf("\033[H\033[J")

int MROWS = 38 ;
int MCOLUMNS = 131 ;

int ROWS = 9 ;
int COLUMNS = 13 ;

int NB_OBST = 3 ;

enum obstacle_e {
    none,
    rock,
    bomb,
    portal
} ;

typedef enum obstacle_e obstacle ;

typedef struct Personnage_s Personnage ;

char obst[4][3][9] = {{"         ", "         ", "         "}} ;

char perso[3][9] = {"  /. .\\  ", "-+\\_@_/+-", "   / \\   "} ;

char rocko[3][9] = {" /##\\/#\\ ", "|##//#\\#|", " \\##/\\#/ "} ;

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

int** create_from(obstacle obst[9][13]) {
    int** n_tab = create_empty () ;
    for (int i = 0; i<ROWS; i++) {
        for (int j = 0; j<COLUMNS; j++) {
            n_tab[i][j] = (int)obst[i][j] ;
        }
    }
    return n_tab ;
}

char** create_map (int** m, Personnage pers) {
    //int** m = create_from(o) ;
    char** map = malloc(sizeof(char*)*MROWS) ;
    for (int i = 0 ; i<MROWS; i++) {
        map[i] = malloc(sizeof(char)*MCOLUMNS) ;
        for (int j = 0; j<MCOLUMNS; j++) {
            map[i][j] = ' ' ;
        }
    }

    map[0][0] = '+' ;
    map[0][MCOLUMNS-1] = '+' ;
    map[MROWS-1][0] = '+' ;
    map[MROWS-1][MCOLUMNS-1] = '+' ;
    map[5][6] = '+' ;
    map[5][MCOLUMNS-7] = '+' ;
    map[MROWS-6][6] = '+' ;
    map[MROWS-6][MCOLUMNS-7] = '+' ;

    for (int i = 1; i < MCOLUMNS - 1; i++) {
        map[0][i] = '-' ;
        map[MROWS-1][i] = '-' ;
        
        if (i >= 7 & i <= MCOLUMNS - 8) {
            map[5][i] = '-' ;
            map[MROWS-6][i] = '-' ;
        }
    }

    for (int i = 1; i < MROWS - 1; i++) {
        map[i][0] = '|' ;
        map[i][MCOLUMNS-1] = '|' ;
        
        if (i >= 6 & i <= MROWS - 7) {
            map[i][6] = '|' ;
            map[i][MCOLUMNS-7] = '|' ;
        }
    }

    for (int i = 0 ; i < 9; i++) {
        map[1][61 + i] = '_' ;
        if (i >= 1 & i <= 7) {
            map[MROWS-3][61 + i] = '_' ;
        }
    }

    


    /*for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 9; l++) {
                    map[(i*3) + 6 + k][(j*7) + 7 + l] = obst[m[i][j]][k][l] ;
                }
            }
        }
    }*/

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (m[i][j] == 1) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 9; l++) {
                        map[(i*3) + 6 + k][(j*9) + 7 + l] = rocko[k][l] ;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            map[(pers.y*3) + 6 + i][(pers.x*9)+ 7 + j] = perso[i][j] ;
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


int** create_random_data(bool portal) {
    srand(time(NULL)) ;
    int nb_obst = 2 + rand() % 4 ;

    int pos[nb_obst] ;
    for (int i = 0; i<nb_obst; i++) {
        pos[i] = -1 ;
    }

    while(cond(pos, nb_obst)) {
        for (int i = 0 ; i<nb_obst; i++) {
            pos[i] = rand() % 117 ;
        }
    }

    int** m = create_empty() ;
    if (portal){
        m[pos[0]/COLUMNS][pos[0]%COLUMNS] = 3 ;
    }
    else {
        m[pos[0]/COLUMNS][pos[0]%COLUMNS] = 1 + rand() % (NB_OBST-1) ;
    }
    for (int i = 1; i<nb_obst; i++) {
        m[pos[i]/COLUMNS][pos[i]%COLUMNS] = 1 + rand() % (NB_OBST-1) ;
    }

    return m ;
}

char** create_random(Personnage pers,bool portal) {
    srand(time(NULL)) ;
    int nb_obst = 2 + rand() % 4 ;

    int pos[nb_obst] ;
    for (int i = 0; i<nb_obst; i++) {
        pos[i] = -1 ;
    }

    while(cond(pos, nb_obst)) {
        for (int i = 0 ; i<nb_obst; i++) {
            pos[i] = rand() % 117 ;
        }
    }

    int** m = create_empty() ;
    for (int i = 0; i<nb_obst; i++) {
        m[pos[i]/COLUMNS][pos[i]%COLUMNS] = 1 + rand() % NB_OBST ;
    }

    return create_map(m, pers) ;
}

/*void print_map(char** map) {
    clear() ;
    for (int i = 0; i<MROWS; i++) {
        for (int j = 0; j<MCOLUMNS; j++) {
            printf("%c", map[i][j]) ;
        }
        printf("\n") ;
    } 
    printf("\n") ;
}*/