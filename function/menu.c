#include "menu.h"

 int global_start_pos = 2;

 void menu_init(Menu menus, char text[1024], char trigger) {
    strcpy(menus.text, text);
    menus.trigger = trigger;
}

void menu_print(WINDOW *win, char trigger){

}

 void menu_position(Menu menus) {
    menus.start_pos = global_start_pos;
    global_start_pos += (strlen(menus.text) + 1);
}

 void menubar_init(WINDOW *win, Menu menus[], int num_menus){
    global_win = win;
    for(int i=0; i<3; i++){
        global_menus[i] = menus[i];
    }
    num_menus = global_num_menus;
}

 void menubar_draw(){
    for(int i=0; i<global_num_menus; i++){
        int start_x = global_menus[i].start_pos;
        char msg[100];
        strcpy(msg, global_menus[i].text);
        mvwprintw(global_win, 0, start_x, msg);
    }
}
