#include "../affichage/affichage.h"
#include "input.h"
#include "creation.h"
#include <stdbool.h>
#include "game.h"

#define RESET "\x1b[0m"
#define clear() printf("\033[H\033[J")

int main () {
    printMainMenu();
    bool inGame = false;
    while(true){
        int n = getch();

        if(!inGame && n == 101){
            party();
        }

        if(inGame && n==127){
            inGame = false;
            printMainMenu();
            continue;
        }

        if(!(inGame) && n==27){
            clear();
            printf("Thank you for playing! \n");
            printf("%s\n",RESET);
            break;
        }
    }
    
    return 0 ;
}