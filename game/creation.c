#include "creation.h"

int ROWS = 6 ;
int COLUMNS = 24 ;

enum obstacles_e {
    none,
    rock,
    bomb,
    hole
} ;

typedef enum obstacles_e obstactles ;

char o[4][3][5] = {{"   ", "   ", "   "}, {"   ", " █ ", "   "}, {"   ", " ⬤ ", "   "}, {"   ", " 💣 ", "   "}} ;

int** create_empty () {
    int** n_tab = malloc(sizeof(int*)*ROWS) ;
    for (int i = 0; i<ROWS; i++) {
        n_tab[i] = malloc(sizeof(int)*COLUMNS) ;
    }
    return n_tab ;
}

int** create_from(obstactles** obst, int len) {
    int** n_tab = create_empty () ;
    for (int i = 0; i<ROWS; i++) {
        for (int j = 0; j<COLUMNS; j++) {
            n_tab[i][j] = (int)obst[i][j] ;
        }
    }
    return n_tab ;
}

void print_map(int** map) {
    for (int i = 0; i<ROWS; i++) {
        for (int j = 0; j<COLUMNS; j++) {
            printf("%s", o[map[i][j]]) ;
        }
        printf("\n") ;
    }
    printf("\n") ;
}


int main() {
    obstactles** obstacles = malloc(sizeof(obstactles*) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        obstacles[i] = malloc(sizeof(obstactles) * COLUMNS);
        for (int j = 0; j < COLUMNS; j++) {
            obstacles[i][j] = none; // Initialize all to none
        }
    }

    // Add some obstacles for testing
    obstacles[1][1] = rock;
    obstacles[1][2] = rock ;
    obstacles[2][3] = bomb;
    obstacles[4][5] = hole;

    int** map = create_from(obstacles, ROWS * COLUMNS);
    print_map(map);

    // Free allocated memory
    for (int i = 0; i < ROWS; i++) {
        free(obstacles[i]);
        free(map[i]);
    }
    free(obstacles);
    free(map);

    return 0;
}