#include <unistd.h>
#include <poll.h>
#include <stdio.h>
#include <stdbool.h>
#include <termios.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>

#include <sys/time.h>

#include "creation.h"
#include "../affichage/affichage.h"


/// Alternative plus 'trans-plateforme' que 'system("clear")'
#define clear_screen() printf("\033[H\033[J")

/// /!\ Ne pas toucher à cette fonction, je ne la comprend pas.
// Gets a char from STDIN
// Returns immediatly, even if STDIN is empty
// in which case it returns ?
int getch() {
    int acquisition_time = 50 ;
    
    int ch;
    struct termios oldattr, newattr;

    if (tcgetattr(STDIN_FILENO, &oldattr) != 0) {
        perror("tcgetattr");
    }

    newattr = oldattr;

    // Disable canonical mode and echo
    newattr.c_lflag &= ~(ICANON | ECHO);

    // Set VMIN and VTIME to control read behavior
    newattr.c_cc[VMIN] = 1;   // Minimum number of characters to read
    newattr.c_cc[VTIME] = 0;  // Timeout value (0 = no timeout)
    
    if (tcsetattr(STDIN_FILENO, TCSANOW, &newattr) != 0) {
        perror("tcsetattr");
    }
    struct pollfd mypoll = { STDIN_FILENO, POLLIN | POLLPRI };

    // Poll the input
    if (poll(&mypoll, 1, acquisition_time) > 0) {
        ch = getchar();
    } else if (errno != 0) {
        perror("poll");
    }

    // Flush remaining input to avoid characters "remaining"
    tcflush(STDIN_FILENO, TCIFLUSH);

    // Restore the original terminal settings
    if (tcsetattr(STDIN_FILENO, TCSANOW, &oldattr) != 0) {
        perror("tcsetattr");
    }

    return ch; 
}
/// Fin /!\


// Initialize the board.
/// FIN FONCTION TESTS.

int main () {
    /// A adapter.
    // Global Variable For Timers
    double refresh_rate = 0.05;

    /// A adapter.
    // Init Board
    Personnage pers;
    pers.x = 0;
    pers.y = 0;
    //test
    char** board = create_random(pers);

    // Time variables
    struct timeval last, now; 

    /// A comprendre pour adapter.
    // Game Loopgravity_time
    print_map(board);
    int n = 0 ;
    gettimeofday(&last, NULL);
    
    while (n != -1) {
        int n  = getch() - 48;

        gettimeofday(&now, NULL);
        double time_taken;

        time_taken = (now.tv_sec - last.tv_sec) + (now.tv_usec - last.tv_usec) * 1e-6;

        if (time_taken > refresh_rate) {
            print_map(board);
            last = now ;
        }
    } 
}
