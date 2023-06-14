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
    int action = startup_init(startup, row, col);

    // Generate game screens
    WINDOW *board = newwin(row, col / 2, 0, 0);
    WINDOW *player = newwin(row / 2, col / 2, 0, col / 2);
    WINDOW *progress = newwin(row / 2, col / 2, row - (row / 2), col - (col / 2));

    if (action == 0) {
        GameState state;
        clear_screen();
        game_init(board, player, progress, &state);
        game_loop(board, player, progress, &state);
    } else if (action == 1) {
        // menu_init();
        //  To be implemented
    } else if (action == 2) {
        endwin();
        return 0;
    }

    getch();
    endwin();
    return 0;
}
