#pragma once
#include <ncurses.h>
#include <string.h>

typedef struct {
	char text[100];
	char trigger;
	int start_pos;
} Menu;

WINDOW *global_win;
Menu global_menus[3];
int global_num_menus;
char global_msg[1024];
char global_trigger;
extern int global_start_pos;

void menu_init(Menu menu, char text[], char trigger);
void menu_position(Menu menu);
void menu_print(Menu menu, WINDOW *win);
void menubar_init(WINDOW *win, Menu menus[], int num_menus);
void menubar_draw();
