#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#include "board.h"
#include "board_state.h"
#include"screen.h"

#define ITERATIONS 10000

struct timespec iter_intv =  {0, 8000000L};


int main(void) {
    screen_init();    

    Board b;
    if (!board_init(&b, winrows(), wincols())) {
        return EXIT_FAILURE;
    }

    blinker(&b, b.rows/2, b.cols/2);
    glider(&b, b.rows / 3, b.cols/2);
    r_pentomino(&b, b.rows / 2, b.cols / 3);

    screen_print_board(&b);
    for (int i = 0; i < ITERATIONS; i++) {
        nanosleep(&iter_intv, NULL);
        iteration(&b);
        screen_print_board(&b);
    }
    board_free(&b);
    screen_reset();
    
}
