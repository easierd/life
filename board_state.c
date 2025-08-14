#include<stdio.h>
#include<stdlib.h>

#include "board_state.h"

bool is_valid_position(Board*b, size_t i, size_t j, size_t width, size_t height) {
    return (i < b->rows - height) && (j < b->cols - width);
}


#define GLIDER_WIDTH 3
#define GLIDER_HEIGHT 3

void glider(Board* b, size_t i, size_t j) {
    if (is_valid_position(b, i, j, GLIDER_WIDTH, GLIDER_HEIGHT)) {
        set_alive(b, i, j + 1);

        set_alive(b, i + 1, j + 2);

        set_alive(b, i + 2, j);
        set_alive(b, i + 2, j + 1);
        set_alive(b, i + 2, j + 2);
    }

}


#define BLINKER_WIDTH 1
#define BLINKER_HEIGHT 3

void blinker(Board* b, size_t i, size_t j) {
    if (is_valid_position(b, i, j, BLINKER_WIDTH, BLINKER_HEIGHT)) {
    set_alive(b, i, j);

    set_alive(b, i + 1, j);

    set_alive(b, i + 2, j);
    }

}


#define R_PENTOMINO_WIDTH 3
#define R_PENTOMINO_HEIGHT 3

void r_pentomino(Board* b, size_t i, size_t j) {
    if (is_valid_position(b, i, j, R_PENTOMINO_WIDTH, R_PENTOMINO_HEIGHT)) {
    set_alive(b, i, j + 1);
    set_alive(b, i, j + 2);

    set_alive(b, i + 1, j);
    set_alive(b, i + 1, j + 1);

    set_alive(b, i + 2, j + 1);
    }
}


#define DIEHARD_WIDTH 8
#define DIEHARD_HEIGHT 3

void diehard(Board* b, size_t i, size_t j) {
    if (is_valid_position(b, i, j, DIEHARD_WIDTH, DIEHARD_HEIGHT)) {
    set_alive(b, i, j + 6);

    set_alive(b, i + 1, j);
    set_alive(b, i + 1, j + 1);

    set_alive(b, i + 2, j + 1);
    set_alive(b, i + 2, j + 5);
    set_alive(b, i + 2, j + 6);
    set_alive(b, i + 2, j + 7);
    }
}

