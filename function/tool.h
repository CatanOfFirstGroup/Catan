#pragma once
#include <stdio.h>
#include <stdint.h>
#include "startup.h"
#include "menu.h"

#define PRINT_BOLD_LINE(win, row, col, text) \
    do { \
        wattron(win, A_BOLD); \
        mvwprintw(win, row, col, text); \
        wattroff(win, A_BOLD); \
    } while(0)

void clear_screen();
void erase_lines(WINDOW *win, int start_line, int end);
