#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib-keyboard-ninja/auxiliary.h>
#include <lib-keyboard-ninja/round.h>

void print_round_interface(
        char identifier[MAX_LENGTH_OF_IDENTIFIER],
        char text[MAX_LENGTH_OF_TEXT])
{
    printf("\033[1mROUND | IDENTIFIER \033[0m");

    int i;
    for (i = 0; i < strcspn(identifier, " | "); i++)
        printf("\033[32m%c\033[0m", identifier[i]);
}

void start_round(
        char identifier[MAX_LENGTH_OF_IDENTIFIER],
        char text[MAX_LENGTH_OF_TEXT])
{
    int i, counter = 0, start_of_current_word = 0;
    char input;

    while (counter < strlen(text)) {
        system("cls");

        print_round_interface(identifier);

        printf("\n   Original text:\n");

        for (i = 0; i < start_of_current_word; i++)
            printf("\033[90m%c\033[0m", text[i]);

        printf("\033[104m%c\033[0m", text[counter]);

        for (i = counter + 1; i < strlen(text); i++)
            printf("%c", text[i]);

        printf("\n\n   Input:\n");

        for (i = start_of_current_word; i < counter; i++)
            printf("%c", text[i]);
        input = getche();

        if (text[counter] == ' ')
            start_of_current_word = counter + 1;
        if (input == text[counter])
            counter++;
    }
}