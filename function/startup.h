#pragma once
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

int startup_init(WINDOW *win, int row, int col);
int startup_menu(WINDOW *win, int row, int col);
