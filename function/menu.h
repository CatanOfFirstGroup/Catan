#pragma once
#include <ncurses.h>
#include <string.h>
#include "../game/properties.h"

int menu_init(WINDOW *win, GameState *state);
int menu_print(WINDOW *win, GameState *state);
