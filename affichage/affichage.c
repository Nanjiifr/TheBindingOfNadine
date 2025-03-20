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
    printf("----------------------------\n");
    fflush(stdout);
}