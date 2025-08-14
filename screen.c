#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/ioctl.h>

#include "screen.h"

struct winsize w;

void screen_init() {
    write(STDIN_FILENO, "\x1b[2J", 4);
    write(STDIN_FILENO, "\x1b[?25l", 6);
    write(STDIN_FILENO, "\x1b[42m", 5);        

    ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
}

void clear_screen() {
    write(STDIN_FILENO, "\x1b[0m", 4);        
    write(STDIN_FILENO, "\x1b[2J", 4);
}


int wincols() {
    return w.ws_col / 2;
}


int winrows() {
    return w.ws_row;
}


int digits(int i) {
    int digits = 0;
    do {
        digits++;
        i /= 10;
    } while(i > 0);

    return digits;
}


void put_cell(int i, int j) {
    if ((i >= 0) && (j >= 0) && (i < winrows()) && ( j < wincols())) {
        int idigits = digits(i + 1);
        int jdigits = digits(2 * j + 1);

        size_t str_command_sz = idigits + jdigits + 4 + 1;
        char* command = malloc(str_command_sz);
        snprintf(command, str_command_sz, "\x1b[%d;%dH", i + 1, 2 * j + 1);

        write(STDIN_FILENO, command, str_command_sz - 1);
        write(STDIN_FILENO, "  ", 2);
        free(command);
        write(STDIN_FILENO, "\x1b[H", 3);
    }
}


void erase_cell(int i, int j) {
    
    write(STDIN_FILENO, "\x1b[0m", 4);        
    put_cell(i, j);
    write(STDIN_FILENO, "\x1b[42m", 5);        
}


void screen_print_board(Board* b) {
    int rows = b->rows;
    int cols = b->cols;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board_is_alive(b, i, j)) {
                put_cell(i, j);
            } else {
                erase_cell(i, j);
            }
        }
    }
}


void screen_reset() {
   clear_screen(); 
   write(STDIN_FILENO, "\x1b[H", 3);
   write(STDIN_FILENO, "\x1b[?25h", 6);
}
