#pragma once

#include<stddef.h>
#include<stdbool.h>

typedef struct {
   bool* cells; 
   size_t rows;
   size_t cols;
} Board;


void board_init(Board*, size_t, size_t);
void iteration(Board*);
void board_free(Board*);

bool board_is_alive(Board*, int, int);
