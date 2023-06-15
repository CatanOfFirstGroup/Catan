#include "menu.h"

int menu_init(WINDOW *win, GameState *state) {
	box(win, 0, 0);
	mvwprintw(win, 0, 2, "OPTIONS");
	wrefresh(win);
	return menu_print(win, state);
}

int menu_print(WINDOW *win, GameState *state) {
	int row, col;
	getmaxyx(win, row, col);
	keypad(win, TRUE);

	char *choices[4] = {
			"Players: ",
			"Exit menu",
			"Exit game",
	};

	int choice = 0;
	int highlight = 0;
	while(1) {
		for(int i = 0; i < 3; i++) {
			if(i == highlight) {
				wattron(win, A_REVERSE);
			}
			if(i == 0) {
				mvwprintw(win, 2 + i, (col - strlen(choices[i]) - 8) / 2, choices[i]);
				mvwprintw(win, 2 + i, col / 2, " <  %02d  >", state->players_count);
			}
			else {
				mvwprintw(win, 2 + i, (col - strlen(choices[i])) / 2, choices[i]);
			}
			wattroff(win, A_REVERSE);
		}
		wrefresh(win);
		choice = wgetch(win);
		switch(choice) {
			case KEY_UP:
				if(highlight == 0) {
					highlight = 2;
				}
				else {
					highlight--;
				}
				break;
			case KEY_DOWN:
				if(highlight == 2) {
					highlight = 0;
				}
				else {
					highlight++;
				}
				break;
			case KEY_LEFT:
				if(highlight == 0) {
					if(state->players_count > 3) {
						state->players_count--;
					}
				}
				break;
			case KEY_RIGHT:
				if(highlight == 0) {
					if(state->players_count < 6) {
						state->players_count++;
					}
				}
				break;
			case '\n':
				if(highlight == 1) {
					return 1;
				}
				if(highlight == 2) {
					return 2;
				}
				break;
			default:
				break;
		}
	}
}
