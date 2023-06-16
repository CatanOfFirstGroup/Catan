#include "tool.h"

void clear_screen() {
	clear();
	refresh();
}

void erase_lines(WINDOW *win, int start_line, int end_line) {
	int row, col;
	getyx(win, row, col);

	for(int i = start_line; i <= end_line; i++) {
		wmove(win, i, 0);
		wclrtoeol(win);
	}
	box(win, 0, 0);
	wmove(win, row, col);
	PRINT_BOLD_LINE(win, 0, 2, "GAME STATS");
}
