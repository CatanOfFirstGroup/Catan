#pragma once
#include <stdio.h>
#include <stdint.h>
#include "startup.h"
#include "menu.h"

#define PRINT_BOLD_LINE(board, line, column, text) \
    do { \
        wattron(board, A_BOLD); \
        mvprintw(line, column, "%s", text); \
        wattroff(board, A_BOLD); \
    } while(0)

void clear_screen();
void erase_lines(WINDOW *win, int start_line, int end);
