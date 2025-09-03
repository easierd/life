#pragma once

#include<stddef.h>
#include<stdbool.h>

typedef struct {
   bool* cells; 
   bool* prev_state;
   size_t rows;
   size_t cols;
} Board;


// return true if initialization is successful
bool board_init(Board*);

void iteration(Board*);

void board_free(Board*);

bool board_is_alive(const Board*, size_t, size_t);

void set_alive(Board*, size_t, size_t);
