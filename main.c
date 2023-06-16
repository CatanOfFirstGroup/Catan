#include "function/tool.h"
#include "game/game.h"
#include <ncurses.h>

int main() {
	// Initialization
	initscr();
	cbreak();
	noecho();

	// Read the terminal screen size
	int row, col;
	getmaxyx(stdscr, row, col);
	curs_set(0);
	refresh();

	// Generate startup screen
	WINDOW *startup = newwin(row, col, 0, 0);

	// Menubar Setup
	WINDOW *options = NULL;

	// Generate game screens
	WINDOW *board = newwin(row, col / 2, 0, 0);
	WINDOW *player = newwin(row / 2, col - (col / 2), 0, col / 2);
	WINDOW *progress = newwin(row - (row / 2), col - (col / 2), row / 2, col / 2);

	GameState state = {
		// Set the default players count at 4
		.players_count = 4,
	};

	while(1) {
		int action = startup_init(startup, row, col);
		if(action == 0) {
			clear_screen();
			game_init(board, player, progress, &state);
			game_loop(board, player, progress, &state);
		}
		else if(action == 1) {
			options = newwin(row / 3 * 2, col / 3 * 2, row / 6, col / 6);
			int opt = menu_init(options, &state);
			if(opt == 1) {
				delwin(options);
				options = NULL;
				wrefresh(startup);
			}
			else if(opt == 2) {
				endwin();
				return 0;
			}
		}
		else if(action == 2) {
			endwin();
			return 0;
		}
	}

	getch();
	endwin();
	return 0;
}
