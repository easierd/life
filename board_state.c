#include<stdio.h>
#include<stdlib.h>

#include "board_state.h"


#define GLIDER_WIDTH 3
#define GLIDER_HEIGHT 3


void glider(Board* b, size_t i, size_t j) {
    size_t rows = b->rows;
    size_t cols = b->cols;

    if (i >= rows - GLIDER_HEIGHT || j >= cols - GLIDER_WIDTH) {
        // TODO: keep a line for stderr messages
        fprintf(stderr, "Cannot draw a glider at position %zu:%zu\n", i, j);
        return;
    }

    set_alive(b, i, j + 1);

    set_alive(b, i + 1, j + 2);

    set_alive(b, i + 2, j);
    set_alive(b, i + 2, j + 1);
    set_alive(b, i + 2, j + 2);

}

