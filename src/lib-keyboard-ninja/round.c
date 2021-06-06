#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib-keyboard-ninja/auxiliary.h>
#include <lib-keyboard-ninja/round.h>

void print_round_interface(
        char identifier[MAX_LENGTH_OF_IDENTIFIER],
        char text[MAX_LENGTH_OF_TEXT],
        c_w current_word,
        int error_counter)
{
    printf("\033[1mROUND | IDENTIFIER \033[0m");

    long long unsigned int i;

    for (i = 0; i < strcspn(identifier, " | "); i++) {
        printf("\033[32m%c\033[0m", identifier[i]);
    }

    printf("\033[1m | \033[0m\033[31;1mERRORS = %d \033[0m", error_counter);

    printf("\033[1m\n   Original text:\n\033[0m");

    for (i = 0; i < current_word.start; i++) {
        printf("\033[90m%c\033[0m", text[i]);
    }

    for (i = current_word.start; i < current_word.position; i++) {
        printf("\033[32m%c\033[0m", text[i]);
    }

    for (i = current_word.position; i < current_word.end; i++) {
        printf("\033[104m%c\033[0m", text[i]);
    }

    for (i = current_word.end; i < strlen(text); i++) {
        printf("%c", text[i]);
    }

    printf("\033[1m\n\n   Input:\n\033[0m");

    for (i = current_word.start; i < current_word.position; i++) {
        printf("\033[32m%c\033[0m", text[i]);
    }
}

void compare_input_to_text(
        char text[MAX_LENGTH_OF_TEXT],
        char input[MAX_LENGTH_OF_TEXT],
        c_w* current_word)
{
    long long unsigned int i;
    int counter = 0;

    for (i = current_word->position; i < current_word->end; i++) {
        if (input[counter++] == text[i]) {
            current_word->position = i + 1;
        } else {
            break;
        }
    }
}

void shift_current_word(char buffer[MAX_LENGTH_OF_TEXT], c_w* current_word)
{
    current_word->position = current_word->end + 1;
    current_word->start = current_word->end + 1;
    current_word->end = strcspn(buffer, " ");
    buffer[strcspn(buffer, " ")] = '@';
}

void start_round(
        char identifier[MAX_LENGTH_OF_IDENTIFIER],
        char text[MAX_LENGTH_OF_TEXT])
{
    c_w current_word;
    char input[MAX_LENGTH_OF_TEXT], buffer[MAX_LENGTH_OF_TEXT];
    int error_counter = 0;

    strcpy(buffer, text);

    current_word.position = 0;
    current_word.start = 0;
    current_word.end = strcspn(buffer, " ");
    buffer[strcspn(buffer, " ")] = '@';

    while (current_word.position < strlen(text)) {
        system("clear");

        print_round_interface(identifier, text, current_word, error_counter);

        fgets(input, MAX_LENGTH_OF_TEXT, stdin);

        if (!strncmp(input, "/exit", strlen("/exit")))
            break;

        compare_input_to_text(text, input, &current_word);

        if (current_word.position == current_word.end) {
            shift_current_word(buffer, &current_word);
        } else {
            error_counter++;
        }
    }
}