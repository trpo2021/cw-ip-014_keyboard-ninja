#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib-keyboard-ninja/auxiliary.h>
#include <lib-keyboard-ninja/round.h>

void print_round_interface(char identifier[MAX_LENGTH_OF_IDENTIFIER])
{
    printf("\033[1mROUND | IDENTIFIER \033[0m");

    long long unsigned int i;
    for (i = 0; i < strcspn(identifier, " | "); i++)
        printf("\033[32m%c\033[0m", identifier[i]);
}

void start_round(
        char identifier[MAX_LENGTH_OF_IDENTIFIER],
        char text[MAX_LENGTH_OF_TEXT])
{
    long long unsigned int i, start_of_current_word, end_of_current_word,
            position;
    char input[MAX_LENGTH_OF_TEXT], buffer[MAX_LENGTH_OF_TEXT];
    int counter;

    strcpy(buffer, text);

    position = 0;
    start_of_current_word = 0;
    end_of_current_word = strcspn(buffer, " ");

    buffer[strcspn(buffer, " ")] = 64;

    while (position < strlen(text)) {
        system("clear");

        print_round_interface(identifier);

        printf("\033[1m\n   Original text:\n\033[0m");

        for (i = 0; i < start_of_current_word; i++) {
            printf("\033[90m%c\033[0m", text[i]);
        }

        for (i = start_of_current_word; i < position; i++) {
            printf("\033[32m%c\033[0m", text[i]);
        }

        for (i = position; i < end_of_current_word; i++) {
            printf("\033[104m%c\033[0m", text[i]);
        }

        for (i = end_of_current_word; i < strlen(text); i++) {
            printf("%c", text[i]);
        }

        printf("\033[1m\n\n   Input:\n\033[0m");

        for (i = start_of_current_word; i < position; i++) {
            printf("\033[32m%c\033[0m", text[i]);
        }

        fgets(input, MAX_LENGTH_OF_TEXT, stdin);

        if (!strncmp(input, "/exit", 5))
            break;

        for (i = position, counter = 0; i < end_of_current_word; i++) {
            if (input[counter++] == text[i]) {
                position = i + 1;
            } else {
                break;
            }
        }

        if (position == end_of_current_word) {
            position = end_of_current_word + 1;
            start_of_current_word = end_of_current_word + 1;
            end_of_current_word = strcspn(buffer, " ");

            buffer[strcspn(buffer, " ")] = 64;
        }
    }
}