#include <time.h>
#include <unistd.h>

#include "board.h"
#include"screen.h"


struct timespec iter_intv =  {0, 100000000L};


int main(void) {
    screen_init();    
    Board b;
    board_init(&b, winrows(), wincols());
    screen_print_board(&b);
    for (int i = 0; i < 5000; i++) {
        nanosleep(&iter_intv, NULL);
        iteration(&b);
        screen_print_board(&b);
    }
    board_free(&b);
    screen_reset();
    
}
