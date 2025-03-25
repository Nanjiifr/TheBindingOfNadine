#include "creation.h"

//#define clear() printf("\033[H\033[J")

int MROWS = 38 ;
int MCOLUMNS = 131 ;

int ROWS = 9 ;
int COLUMNS = 13 ;

int NB_OBST = 3 ;

typedef enum obstacle_e obstacle ;

typedef struct Personnage_s Personnage ;

char obst[4][3][9] = {{"         ", "         ", "         "}} ;

char perso[3][9] = {"  /. .\\  ", "-+\\_@_/+-", "   / \\   "} ;

char rocko[3][9] = {" /##\\/#\\ ", "|##//#\\#|", " \\##/\\#/ "} ;

char halfon[3][9] = {"(o_____o)" , "-\\__^__/-", "//     \\\\"} ;

char target_nadine[3][9] = {".__O_O__.", "(__|_|__)", "/|\\   /|\\"} ;

char booomb[3][9] = {" ___|___ ", "/  TNT  \\", "\\_______/"} ;

char portalo[3][9] = {" /+-*-+\\ " , "|$|   |$|", " \\|   |/ "} ;

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

char** create_map (int** m, Personnage pers, mob* mobs) {
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

    // Adding detailed doors
    for (int i = 0 ; i < 9; i++) {
        map[1][61 + i] = '_' ;
        if (i >= 1 & i <= 7) {
            map[MROWS-3][61 + i] = '_' ;
        }
    }

    // Top door
    map[0][61] = '|' ;
    map[0][69] = '|' ;
    map[1][60] = '/' ;
    map[1][70] = '\\' ;
    map[2][60] = '|' ;
    map[2][70] = '|' ;
    map[3][60] = '|' ;
    map[3][70] = '|' ;
    map[4][60] = '|' ;
    map[4][70] = '|' ;

    // Bottom door
    map[MROWS-1][61] = '|' ;
    map[MROWS-1][69] = '|' ;
    map[MROWS-2][60] = '\\' ;
    map[MROWS-2][70] = '/' ;
    map[MROWS-3][60] = '|' ;
    map[MROWS-3][70] = '|' ;
    map[MROWS-4][60] = '|' ;
    map[MROWS-4][70] = '|' ;
    map[MROWS-5][60] = '|' ;
    map[MROWS-5][70] = '|' ;

    // Left door
    for (int i = 0; i < 5; i++) {
        map[17 + i][0] = '|' ;
        map[17 + i][1] = ' ' ;
        map[17 + i][2] = ' ' ;
        map[17 + i][3] = ' ' ;
        map[17 + i][4] = ' ' ;
        map[17 + i][5] = ' ' ;
        map[17 + i][6] = '|' ;
    }
    map[16][3] = '_' ;
    map[22][3] = '_' ;
    map[15][2] = '/' ;
    map[15][4] = '\\' ;
    map[23][2] = '\\' ;
    map[23][4] = '/' ;
    map[16][2] = '|' ;
    map[16][4] = '|' ;
    map[22][2] = '|' ;
    map[22][4] = '|' ;

    // Right door
    for (int i = 0; i < 5; i++) {
        map[17 + i][MCOLUMNS-1] = '|' ;
        map[17 + i][MCOLUMNS-2] = ' ' ;
        map[17 + i][MCOLUMNS-3] = ' ' ;
        map[17 + i][MCOLUMNS-4] = ' ' ;
        map[17 + i][MCOLUMNS-5] = ' ' ;
        map[17 + i][MCOLUMNS-6] = ' ' ;
        map[17 + i][MCOLUMNS-7] = '|' ;
    }
    map[16][MCOLUMNS-4] = '_' ;
    map[22][MCOLUMNS-4] = '_' ;
    map[15][MCOLUMNS-5] = '/' ;
    map[15][MCOLUMNS-3] = '\\' ;
    map[23][MCOLUMNS-5] = '\\' ;
    map[23][MCOLUMNS-3] = '/' ;
    map[16][MCOLUMNS-5] = '|' ;
    map[16][MCOLUMNS-3] = '|' ;
    map[22][MCOLUMNS-5] = '|' ;
    map[22][MCOLUMNS-3] = '|' ;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (m[i][j] == rock) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 9; l++) {
                        map[(i*3) + 6 + k][(j*9) + 7 + l] = rocko[k][l] ;
                    }
                }
            }
            if (m[i][j] == bomb) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 9; l++) {
                        map[(i*3) + 6 + k][(j*9) + 7 + l] = booomb[k][l] ;
                    }
                } 
            }
            if (m[i][j] == portal) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 9; l++) {
                        map[(i*3) + 6 + k][(j*9) + 7 + l] = portalo[k][l] ;
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

    for (int k = 0; k < 3; k++) {
        if (mobs[k].m_type == HALFON) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 9; j++) {
                    map[(*mobs[k].y * 3) + 6 + i][(*mobs[k].x * 9) + 7 + j] = halfon[i][j];
                }
            }
        }
        if (mobs[k].m_type == TARGET_NADINE) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 9; j++) {
                    map[(*mobs[k].y * 3) + 6 + i][(*mobs[k].x * 9) + 7 + j] = target_nadine[i][j];
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


int** create_random_data() {
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
    bool tp = false ;
    for (int i = 0; i<nb_obst; i++) {
        int r = 1 + rand() % NB_OBST ;
        if (tp == false) {
            m[pos[i]/COLUMNS][pos[i]%COLUMNS] = r ;
            if (r == NB_OBST)
                tp = true ;
        }
        else {
            r =1+ (rand() % (NB_OBST-1)) ;
            m[pos[i]/COLUMNS][pos[i]%COLUMNS] = r ;
        }
    }

    return m ;
}

char** create_random(Personnage pers, mob* mobs) {
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
    bool tp = false ;
    for (int i = 0; i<nb_obst; i++) {
        int r = 1 + rand() % NB_OBST ;
        if (tp == false) {
            m[pos[i]/COLUMNS][pos[i]%COLUMNS] = r ;
            if (r == NB_OBST)
                tp = true ;
        }
        else {
            r =1+ (rand() % (NB_OBST-1)) ;
            m[pos[i]/COLUMNS][pos[i]%COLUMNS] = r ;
        }
    }
    return create_map(m, pers, mobs) ;
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