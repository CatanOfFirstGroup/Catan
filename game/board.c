#include "hexagonal.h"
#include "board.h"

void board_init(WINDOW *win, GameState *state) {
    // Set up the board
    int layout[5] = {3, 4, 5, 4, 3};
    int spaces[5] = {2, 1, 0, 1, 2};
    board_randomize(state);
    // Connect the hexagons
    int total_hexagons = 19;
    //create a list of hexagons
	Hexagon *hexagons[total_hexagons];
	for (int i = 0; i < total_hexagons; i++) {
		hexagons[i] = &state->board[i];
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
    int i_offset = (row - 26) / 2;
    int j_offset = (col - 30) / 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < layout[i]; j++) {
            char resource;
            switch (state->board[counter].type) {
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
            int board_row = 6 * i + i_offset;
            int board_col = 3 * (spaces[i] + 2 * j) + j_offset;
            hexagon_print(win, board_row, board_col);
            mvwprintw(win, board_row, board_col, "%c%02d", resource,
                      state->board[counter].number_token);
            counter++;
            wrefresh(win);
        }
    }
}

void board_randomize(GameState *state) {
    ResourceType all_resources[] = {
        BRICK, BRICK, BRICK, LUMBER, LUMBER, LUMBER, LUMBER, WOOL, WOOL, WOOL,
        WOOL, GRAIN, GRAIN, GRAIN, GRAIN, ORE, ORE, ORE, DESERT};
    int all_numbers[] = {2, 3, 3, 4, 4, 5, 5, 6, 6,
                         8, 8, 9, 9, 10, 10, 11, 11, 12};
    // Randomize
    srand(time(NULL));
    for (int i = 0, rand_num = 0; i < 100; i++) {
        ResourceType temp_res = all_resources[0];
        rand_num = rand() % 19;
        all_resources[0] = all_resources[rand_num];
        all_resources[rand_num] = temp_res;
        rand_num = rand() % 18;
        int temp_num = all_numbers[0];
        all_numbers[0] = all_numbers[rand_num];
        all_numbers[rand_num] = temp_num;
    }
    // Set up tiles
    for (int i = 0, j = 0; i < TOTAL_TILES; i++) {
        state->board[i].type = all_resources[i];
        if (all_resources[i] != DESERT) {
            state->board[i].number_token = all_numbers[j];
            j++;
        } else
            state->board[i].number_token = 7;
    }
}

void hexagon_print(WINDOW *win, int row, int col) {
    mvwprintw(win, row - 4, col + 1, "*"); // Top vertex
    mvwprintw(win, row - 3, col + 0, "/");
    mvwprintw(win, row - 2, col - 1, "/");
    mvwprintw(win, row - 1, col - 2, "*"); // Top-left vertex
    mvwprintw(win, row - 0, col - 2, "|");
    mvwprintw(win, row + 1, col - 2, "|");
    mvwprintw(win, row + 2, col - 2, "*"); // Bottom-left vertex
    mvwprintw(win, row + 3, col - 1, "\\");
    mvwprintw(win, row + 4, col + 0, "\\");
    mvwprintw(win, row + 5, col + 1, "*"); // Bottom vertex
    mvwprintw(win, row + 4, col + 2, "/");
    mvwprintw(win, row + 3, col + 3, "/");
    mvwprintw(win, row + 2, col + 4, "*"); // Bottom-right vertex
    mvwprintw(win, row + 1, col + 4, "|");
    mvwprintw(win, row + 0, col + 4, "|");
    mvwprintw(win, row - 1, col + 4, "*"); // Top-right vertex
    mvwprintw(win, row - 2, col + 3, "\\");
    mvwprintw(win, row - 3, col + 2, "\\");
}
