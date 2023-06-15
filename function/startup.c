#include "startup.h"

int startup_init(WINDOW *win, int row, int col) {
    box(win, 0, 0);
    // Print startup ASCII art
    mvwprintw(win, 2, (col - 28) / 2, "   ______      __            ");
    mvwprintw(win, 3, (col - 28) / 2, "  / ____/___ _/ /_____ _____ ");
    mvwprintw(win, 4, (col - 28) / 2, " / /   / __ `/ __/ __ `/ __ \\");
    mvwprintw(win, 5, (col - 28) / 2, "/ /___/ /_/ / /_/ /_/ / / / /");
    mvwprintw(win, 6, (col - 28) / 2, "\\____/\\__,_/\\__/\\__,_/_/ /_/ ");
    wrefresh(win);
    // Call startup menu options
    return startup_menu(win, row, col);
}

int startup_menu(WINDOW *win, int row, int col) {
    // So that the startup screen can detect keyboard input
    keypad(win, true);

    // Choices for the startup menu
    char *choices[3] = {"Start     [S]", "Option    [O]", "Quit      [Q]"};
    int choice, highlight = 0;

    while(1) {
        for(int i = 0; i < 3; i++) {
            if(i == highlight) {
                wattron(win, A_REVERSE);
            }
            mvwprintw(win, 10 + i, (col - 13) / 2, choices[i]);
            wattroff(win, A_REVERSE);
        }
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
            // Pressing 'S' will directly take you to starting screen
            case 's':
                wclear(win);
                return 0;
                break;
            // Pressing 'O' will directly take you to the option menu
            case 'o':
                return 1;
                break;
            // Pressed 'Q' will directly take you to the quit option
            case 'q':
                return 2;
                break;
            // When detected enter key (which is actually newline character),
            // the game will proceed based on the selected option
            case '\n':
                return highlight;
                break;
            default:
                break;
        }
    }
}
