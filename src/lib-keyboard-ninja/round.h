#ifndef ROUND_H
#define ROUND_H

#include <lib-keyboard-ninja/auxiliary.h>

void print_round_interface(
        char identifier[MAX_LENGTH_OF_IDENTIFIER],
        char text[MAX_LENGTH_OF_TEXT],
        c_w current_word,
        int error_counter);

void compare_input_to_text(
        char text[MAX_LENGTH_OF_TEXT],
        char input[MAX_LENGTH_OF_TEXT],
        c_w* current_word,
		int error_counter)

void shift_current_word(char buffer[MAX_LENGTH_OF_TEXT], c_w* current_word);

void start_round(
        char identifier[MAX_LENGTH_OF_IDENTIFIER],
        char text[MAX_LENGTH_OF_TEXT]);

#endif /* ROUND_H */