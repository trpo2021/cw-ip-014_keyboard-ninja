#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib-keyboard-ninja/auxiliary.h>
#include <lib-keyboard-ninja/round.h>

void print_round_interface(
        char identifier[MAX_LENGTH_OF_IDENTIFIER],
        char text[MAX_LENGTH_OF_TEXT])
{
    printf("ROUND | IDENTIFIER ");

    int i;
    for (i = 0; i < strcspn(identifier, " | "); i++)
        printf("%c", identifier[i]);

    printf("\n   Original text:\n");
}

void start_round(
        char identifier[MAX_LENGTH_OF_IDENTIFIER],
        char text[MAX_LENGTH_OF_TEXT])
{
    system("cls");

    print_round_interface(identifier);
}