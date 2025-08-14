#include "board.h"

#include<stdlib.h>

void board_init(Board* b, size_t rows, size_t cols) {
    b->rows = rows;
    b->cols = cols;
    b->cells = (bool*) malloc(sizeof(bool) * rows * cols);
    for (size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < cols; j++) {
            b->cells[i * cols + j] = false;
        }
    }

    b->cells[cols-1] = true;
    b->cells[cols-2] = true;
    b->cells[cols + cols - 1] = true;
    b->cells[cols + cols - 2] = true;

    b->cells[(rows / 3) * cols + cols/3] = true;
    b->cells[(rows / 3) * cols + cols/3 + 1] = true;
    b->cells[(rows / 3 + 1) * cols + cols/3] = true;
    b->cells[(rows / 3 + 1) * cols + cols/3 + 1] = true;

    b->cells[(rows / 2) * cols + cols/2] = true;
    b->cells[(rows / 2 - 2) * cols + cols/2] = true;
    b->cells[(rows / 2) * cols + cols/2 + 1] = true;
    b->cells[(rows / 2 - 1) * cols + cols/2 + 1] = true;
    b->cells[(rows / 2) * cols + cols/2 - 1] = true;
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


void iteration(Board* b) {
    bool *prev_state = (bool*) malloc(sizeof(bool) * b->rows * b->cols);
    for (size_t i = 0; i < b->rows; i++) {
        for (size_t j = 0; j < b->cols; j++) {
           prev_state[i * b->cols + j]  = b->cells[i * b->cols + j];
        }
    }

    for (size_t i = 0; i < b->rows; i++) {
        for (size_t j = 0; j < b->cols; j++) {
            int neighbours = alive_neighbours(prev_state, b->rows, b->cols, i, j);
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

    free(prev_state);
}


void board_free(Board* b) {
    free(b->cells);
}


bool board_is_alive(Board* b, int i, int j) {
    return b->cells[i * b->cols + j];
}

