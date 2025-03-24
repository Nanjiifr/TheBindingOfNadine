#include "interactions.h"

typedef struct element_s element ;

#define clear() printf("\033[H\033[J")

void boom(dA* calepin, int x, int y) {
    int k = get(calepin, x+1, y).key ;
    salle* e = get(calepin, x+1, y).value ;

    if (k != -1) {
        destroyRoom(calepin, e) ;
    }

    k = get(calepin, x-1, y).key ;
    e = get(calepin, x-1, y).value ;

    if (k != -1) {
        destroyRoom(calepin, e) ;
    }

    k = get(calepin, x, y+1).key ;
    e = get(calepin, x, y+1).value ;

    if (k != -1) {
        destroyRoom(calepin, e) ;
    }

    k = get(calepin, x, y-1).key ;
    e = get(calepin, x, y-1).value ;

    if (k != -1) {
        destroyRoom(calepin, e) ;
    } 

    clear() ;
    printf("\033[1;31m"); // Set text color to red
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                             888888b.   .d88888b.  .d88888b.  .d88888b. 888b     d888\n");
    printf("                                             888  \"88b d88P\" \"Y88bd88P\" \"Y88bd88P\" \"Y88b8888b   d8888\n");
    printf("                                             888  .88P 888     888888     888888     88888888b.d88888\n");
    printf("                                             8888888K. 888     888888     888888     888888Y88888P888\n");
    printf("                                             888  \"Y88b888     888888     888888     888888 Y888P 888\n");
    printf("                                             888    888888     888888     888888     888888  Y8P  888\n");
    printf("                                             888   d88PY88b. .d88PY88b. .d88PY88b. .d88P888   \"   888\n");
    printf("                                             8888888P\"  \"Y88888P\"  \"Y88888P\"  \"Y88888P\" 888       888\n");
    printf("\033[0m"); // Reset text color
    usleep(500000); // Sleep for 500 milliseconds
    clear() ;
    printf("\033[38;2;40;192;192m") ;
}