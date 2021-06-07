#ifndef MENU_H
#define MENU_H

#include <lib-keyboard-ninja/auxiliary.h>

void result_game(
        char text[MAX_LENGTH_OF_TEXT],
        char identifier[MAX_LENGTH_OF_IDENTIFIER],
        int error_counter,
        double time);
void menu_template();
void start_game();
void help_game();
void menu();

#endif
