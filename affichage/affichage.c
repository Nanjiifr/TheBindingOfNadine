#include "affichage.h"

#define RED "\033[38;2;192;40;40m"
#define ORANGE "\033[38;2;250;120;0m"
#define YELLOW "\033[38;2;255;255;40m"
#define GREEN "\033[38;2;192;255;0m"
#define TREE "\033[38;2;20;180;20m"
#define CYAN "\033[38;2;12;250;250m"
#define BLUE "\033[38;2;40;192;192m"
#define PURPLE "\033[38;2;250;12;250m"

#define GRAY "\033[38;2;192;192;192m"
#define DARK "\033[38;2;128;128;128m"
#define GRAYB "\033[1;38;2;192;192;192m"
#define RESET "\x1b[0m"
#define clear() printf("\033[H\033[J")

int M_ROWS = 38 ;
int M_COLUMNS = 131 ;

void print_map(char** map) {
    clear() ;
    for (int i = 0; i<M_ROWS; i++) {
        for (int j = 0; j<M_COLUMNS; j++) {
            printf("%c", map[i][j]) ;
        }
        printf("\n") ;
    } 
    printf("\n") ;
}

void print_lives(int l) {
    printf("                                                    Lives : ") ;

    for (int i = 0; i <l; i++) {
        printf("❤️") ;
    }
    printf("\n") ;
}

void printMainMenu(){
    clear();
    printf("%s",BLUE);
    printf("\n");
    printf("\n");

    printf("                                         ");
    printf("████████╗██╗  ██╗███████╗    ██████╗ ██╗███╗   ██╗██████╗ ██╗███╗   ██╗ ██████╗ \n");
    printf("                                         ");
    printf("╚══██╔══╝██║  ██║██╔════╝    ██╔══██╗██║████╗  ██║██╔══██╗██║████╗  ██║██╔════╝\n");
    printf("                                         ");
    printf("   ██║   ███████║█████╗      ██████╔╝██║██╔██╗ ██║██   ██║██║██╔██╗ ██║██║  ███╗\n");
    printf("                                         ");
    printf("   ██║   ██╔══██║██╔══╝      ██╔══██ ██║██║╚██╗██║██╔══██╝██║██║╚██╗██║██║   ██║\n");
    printf("                                         ");
    printf("   ██║   ██║  ██║███████╗    ██████║ ██║██║ ╚████║██████║ ██║██║ ╚████║╚██████╔╝ \n");
    printf("                                         ");
    printf("   ╚═╝   ╚═╝  ╚═╝╚══════╝    ╚═════╝ ╚═╝╚═╝  ╚═══╝╚════╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝\n");
    printf("                                         ");
    printf("                                  ██████╗ ███████╗\n");
    printf("                                         ");
    printf("                                 ██╔═══██╗██╔════╝\n");
    printf("                                         ");
    printf("                                 ██║   ██║█████╗\n");
    printf("                                         ");
    printf("                                 ██║   ██║██╔══╝ \n");
    printf("                                         ");
    printf("                                 ╚██████╔╝██║\n");
    printf("                                         ");
    printf("                                  ╚═════╝ ╚═╝\n");
    printf("                                         ");
    printf("                ███╗   ██╗  █████╗ ██████╗ ██╗███╗   ██╗███████╗ \n");
    printf("                                         ");
    printf("                ████╗  ██║ ██╔══██╗██╔══██╗██║████╗  ██║██╔════╝ \n");
    printf("                                         ");
    printf("                ██╔██╗ ██║ ███████║██   ██║██║██╔██╗ ██║█████╗   \n");
    printf("                                         ");
    printf("                ██║╚██╗██║ ██╔══██║██╔══██╝██║██║╚██╗██║██╔══╝ \n");
    printf("                                         ");
    printf("                ██║ ╚████║ ██║  ██║██████║ ██║██║ ╚████║███████╗ \n");
    printf("                                         ");
    printf("                ╚═╝  ╚═══╝ ╚═╝  ╚═╝╚════╝  ╚═╝╚═╝  ╚═══╝╚══════╝\n");

    printf("\n");
    printf("                                                                  ");
    printf("----------------------------\n");
    printf("                                                                    ");
    printf("Press [E] to launch GAME\n");
    printf("                                                                       ");
    printf("Press[ESC] to quit\n");
    printf("                                                                  ");
    printf("Press [R] to check the rules\n") ;
    printf("                                                                  ");
    printf("----------------------------\n");
    fflush(stdout);
}

void printRules() {
    clear() ;
    printf("%s",BLUE);

    printf("\n\n") ;

    printf("Game logic : \n") ;
    printf("You are Nadine, a little baby trying to explore the dangerous dungeon of the monstruous King Halfon \n") ;
    printf("Keys used : \n") ;
    printf("You can move in the map using the keys [ZQSD]. To enter a door (and change rooms), just press [E] when standing in front of the door \n") ;
    printf("You can press [B] when standing next to a bomb, to destroy all the rooms around you (except the one you are currently in) \n") ;
    printf("To teleport (to a random room), you can press [T] when standing next to a teleporter \n") ;
    printf("Rules : \n") ;
    printf("All the rooms are preserved, including mobs and obstacles. This mean, when you change from one room to another") ;
    printf("then get back to the one you were in before, you will enter in the exact same room \n") ;
    printf("You have 5 lives are the begining of a game. You can play until you have no more left. However, if you happen to loose somes, ") ;
    printf("you can still win them back by defeating mobs, or opening chests. \n") ;
    printf("To open a chest, you need to have a key, that you can get by defeating mobs. You can have a maximum of 3 keys at the same time\n") ;

    printf("\n\n") ;
    printf("                                                                    Happy playing !!") ;


    printf("\n\n") ;
    printf("----------------------------\n") ;
    printf("Press [Backspace] to return to menu") ;
    fflush(stdout) ;
}