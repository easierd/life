#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

#include "board_state.h"


typedef struct Piece {
    size_t width;
    size_t height;
    size_t cells;
    int (*offsets)[2];
} Piece;


bool is_valid_position(Board*b, size_t i, size_t j, size_t width, size_t height) {
    return (i < b->rows - height) && (j < b->cols - width);
}


void put_piece(Board *b, size_t i, size_t j, Piece *p, bool h_mirror) {
    if (h_mirror) {
        for (size_t k = 0; k < p->cells; k++) {
            p->offsets[k][1] = p->width - 1 - p->offsets[k][1];
        }
    }

    if (is_valid_position(b, i, j, p->width, p->height)) {
        for (size_t k = 0; k < p->cells; k++) {
            set_alive(b, i + p->offsets[k][0], j + p->offsets[k][1]);
        }
    }
}


void glider(Board* b, size_t i, size_t j, bool h_mirror) {

    size_t w = 3;
    size_t h = 3;
    int offsets[][2] = {
        {0, 1},
        {1, 2},
        {2, 0},
        {2, 1},
        {2, 2},
    };
    size_t cells = sizeof(offsets) / sizeof(int[2]);
    Piece p = {w, h, cells, offsets};

    put_piece(b, i, j, &p, h_mirror);

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


#define PENTADECATHLON_WIDTH 10
#define PENTADECATHLON_HEIGHT 3

void pentadecathlon(Board* b, size_t i, size_t j) {
    if (is_valid_position(b, i, j, PENTADECATHLON_WIDTH , PENTADECATHLON_HEIGHT)) {
        set_alive(b, i, j + 2);
        set_alive(b, i, j + 7);

        set_alive(b, i + 1, j);
        set_alive(b, i + 1, j + 1);
        set_alive(b, i + 1, j + 3);
        set_alive(b, i + 1, j + 4);
        set_alive(b, i + 1, j + 5);
        set_alive(b, i + 1, j + 6);
        set_alive(b, i + 1, j + 8);
        set_alive(b, i + 1, j + 9);
        
        set_alive(b, i + 2, j + 2);
        set_alive(b, i + 2, j + 7);
    }
}


void gosper_glider_gun(Board *b, size_t i, size_t j, bool h_mirror) {

    size_t h = 36;
    size_t w = 9;
    int offsets[][2] = {
        {0, 24},

        {1, 22},
        {1, 24},

        {2, 12},
        {2, 13},
        {2, 20},
        {2, 21},
        {2, 34},
        {2, 35},

        {3, 11},
        {3, 15},
        {3, 20},
        {3, 21},
        {3, 34},
        {3, 35},

        {4, 0},
        {4, 1},
        {4, 10},
        {4, 16},
        {4, 20},
        {4, 21},

        {5, 0},
        {5, 1},
        {5, 10},
        {5, 14},
        {5, 16},
        {5, 17},
        {5, 22},
        {5, 24},

        {6, 10},
        {6, 16},
        {6, 24},
              
        {7, 11},
        {7, 15},
              
        {8, 12},
        {8, 13},
    };

 
    size_t cells = sizeof(offsets) / sizeof(int[2]);

    Piece p = {w, h, cells, offsets};
    put_piece(b, i, j, &p, h_mirror);

 }
 
 

 
 
 
 
 
