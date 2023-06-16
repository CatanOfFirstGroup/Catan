#include "board.h"
#include "hexagonal.h"

void board_init(WINDOW *win, GameState *state) {
	// Set up the board
	int layout[5] = {3, 4, 5, 4, 3};
	int spaces[5] = {2, 1, 0, 1, 2};
	int total_hexagons = 0;
	for(int i = 0; i < 5; i++) {
		total_hexagons += layout[i];
	}

	Hexagon *hexagons[total_hexagons];
	int hex_index = 0;

	board_randomize(state);
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < layout[i]; j++) {
			Tile *tile = {
				state->board[hex_index].type,
				state->board[hex_index].number_token};
			hexagons[hex_index] = init_hexagon(hex_index, tile);
			hex_index++;
		}
	}
	connect_hexagon_vertices(hexagons);

	board_print(win, state);
}

void board_print(WINDOW *win, GameState *state) {
	// Get window dimension
	int row, col;
	getmaxyx(win, row, col);

	// Print the board in the center of the window
	int layout[5] = {3, 4, 5, 4, 3};
	int spaces[5] = {2, 1, 0, 1, 2};
	int counter = 0;
	int i_offset = (row - 13) / 2;
	int j_offset = (col - 34) / 2;
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
			mvwprintw(win, 3 * (i) + i_offset, 4 * (spaces[i] + 2 * j) + j_offset, "%c%d", resource, state->board[counter].number_token);
			counter++;
			wrefresh(win);
		}
	}
}

void board_randomize(GameState *state) {
	ResourceType all_resources[] = {BRICK, LUMBER, WOOL, GRAIN, ORE, DESERT};
	int num_tokens[10] = {2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
	// Set up the tiles
	srand(time(NULL));
	for(int i = 0; i < 19; i++) {
		state->board[i].type = all_resources[rand() % 6];
		state->board[i].number_token = num_tokens[rand() % 10];
	}
}
