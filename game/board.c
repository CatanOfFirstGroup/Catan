#include "board.h"

void board_init(WINDOW *win, GameState *state) {
	// Set up the board
	int layout[5] = {3, 4, 5, 4, 3};
	int spaces[5] = {2, 1, 0, 1, 2};
	ResourceType all_resources[] = {BRICK, LUMBER, WOOL, GRAIN, ORE, DESERT};
	// Set up the tiles
	srand(time(NULL));
	for(int i = 0; i < 19; i++) {
		state->board[i].type = all_resources[rand() % 6];
		state->board[i].number_token = (rand() % 6);
	}
	board_print(win, state);
}

void board_print(WINDOW *win, GameState *state) {
	int layout[5] = {3, 4, 5, 4, 3};
	int spaces[5] = {2, 1, 0, 1, 2};
	int counter = 0;
	int start_i = 1;
	int start_j = 1;
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < layout[i]; j++) {
			char resource;
			switch(state->board[counter].type) {
				case BRICK:
					resource = 'B';
					break;
				case LUMBER:
					resource = 'L';
					break;
				case WOOL:
					resource = 'W';
					break;
				case GRAIN:
					resource = 'G';
					break;
				case ORE:
					resource = 'O';
					break;
				case DESERT:
					resource = 'D';
					break;
				default:
					resource = ' ';
					break;
			}
			mvwprintw(win, 3*(i + start_i), 4*(spaces[i] + 2*(j + start_j) - 1), "%c%d", resource, state->board[counter].number_token);
			counter++;
			wrefresh(win);
		}
	}
}
