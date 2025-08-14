#pragma once

#include "board.h"

void clear_screen();
void screen_init();
void screen_print_board(Board*);
void screen_reset();

int wincols();
int winrows();
