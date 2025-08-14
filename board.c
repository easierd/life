#include "board.h"

#include<stdlib.h>
#include<stdio.h>
#include<string.h>


void print_alloc_error() {
    fprintf(stderr, "Cannot allocate memory");
    perror(NULL);
}


bool board_init(Board* b, size_t rows, size_t cols) {
    b->rows = rows;
    b->cols = cols;
    b->cells = calloc(rows * cols, sizeof(bool));
    if (b->cells == NULL) {
        print_alloc_error();
        return false;
    }

    b->prev_state = calloc(rows * cols, sizeof(bool));
    if (b->prev_state == NULL) {
        free(b->cells);
        print_alloc_error();
        return false;
    }

    return true;
}


int alive_neighbours(bool* prev_state, size_t rows, size_t cols, size_t i, size_t j) {
    size_t min_i = (i == 0) ? i : i - 1;
    size_t max_i = (i == rows - 1) ? i : i + 1;
    size_t min_j = (j == 0) ? j : j - 1;
    size_t max_j = (j == cols - 1) ? j : j + 1;

    int neigh = 0;

    for (size_t h = min_i; h <= max_i; h++) {
        for (size_t k = min_j; k <= max_j; k++) {
            if (h == i && k == j) continue;
            if (prev_state[h * cols + k]) {
                neigh++;
            }
        }
    }

    return neigh;
} 


// invariant: prev_state is always equal to cells
void iteration(Board* b) {
    if (b->prev_state == NULL) {
        return;
    }


    for (size_t i = 0; i < b->rows; i++) {
        for (size_t j = 0; j < b->cols; j++) {
            int neighbours = alive_neighbours(b->prev_state, b->rows, b->cols, i, j);
            if (board_is_alive(b, i, j)) {
                if (neighbours < 2 || neighbours > 3) {
                    b->cells[i * b->cols + j] = false;
                }
            } else {
                if (neighbours == 3) {
                    b->cells[i * b->cols + j] = true;
                }
            }
        }
    }

    memcpy(b->prev_state, b->cells, b->rows * b->cols * sizeof(bool));
}


void board_free(Board* b) {
    free(b->cells);
    free(b->prev_state);
}


bool board_is_alive(const Board* b, size_t i, size_t j) {
    return b->cells[i * b->cols + j];
}


void set_alive(Board* b, size_t i, size_t j) {
    if ((i >= b->rows) || (j >= b->cols)) {
        fprintf(stderr, "Position %zu,%zu is out of bound\n", i, j);
        return;
    }

    b->cells[i * b->cols + j] = true;
    b->prev_state[i * b->cols + j] = true;
}
