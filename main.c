#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#include "board.h"
#include "board_state.h"
#include"screen.h"

#define ITERATIONS 10000

struct timespec iter_intv =  {0, 40000000L};


void sigint_handler(int) {
    screen_reset();
    exit(EXIT_SUCCESS);
}


int main(void) {
    signal(SIGINT, sigint_handler);

    screen_init();    

    Board b;
    if (!board_init(&b)) {
        return EXIT_FAILURE;
    }

    gosper_glider_gun(&b, 15, 15);

    screen_print_board(&b);
    for (int i = 0; i < ITERATIONS; i++) {
        nanosleep(&iter_intv, NULL);
        iteration(&b);
        screen_print_board(&b);
    }
    board_free(&b);
    screen_reset();
    
    return EXIT_SUCCESS;
}
