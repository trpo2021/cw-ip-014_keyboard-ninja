#ifndef ROUND_H
#define ROUND_H

#include <lib-keyboard-ninja/auxiliary.h>

void print_round_interface(char identifier[MAX_LENGTH_OF_IDENTIFIER]);

void start_round(
        char identifier[MAX_LENGTH_OF_IDENTIFIER],
        char text[MAX_LENGTH_OF_TEXT]);

#endif /* ROUND_H */