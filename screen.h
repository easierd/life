#pragma once

#include "board.h"

void clear_screen();
void screen_init();
void screen_print_board(const Board*);
void screen_reset();

int wincols();
int winrows();
