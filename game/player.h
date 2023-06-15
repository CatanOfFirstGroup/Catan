#pragma once
#include "game.h"
#include "properties.h"
#include <ncurses.h>

void player_init(WINDOW *win, GameState *state);
void player_print(WINDOW *win, Player *player, int player_num);
void player_clear(GameState *state);

