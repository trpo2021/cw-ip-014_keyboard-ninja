#ifndef ROUND_H
#define ROUND_H

#include <lib-keyboard-ninja/auxiliary.h>

void print_round_interface(
        char identifier[MAX_LENGTH_OF_IDENTIFIER],
        char text[MAX_LENGTH_OF_TEXT],
        c_w current_word,
        int error_counter);

void shift_current_word(char buffer[MAX_LENGTH_OF_TEXT], c_w* current_word);

void compare_input_to_text(
        char text[MAX_LENGTH_OF_TEXT],
        char input[MAX_LENGTH_OF_TEXT],
        c_w* current_word,
        int* error_counter);

long long unsigned int
scoring(char text[MAX_LENGTH_OF_TEXT], int error_counter, double time);

int start_round(
        char identifier[MAX_LENGTH_OF_IDENTIFIER],
        char text[MAX_LENGTH_OF_TEXT],
        double* time_spent);

#endif /* ROUND_H */
