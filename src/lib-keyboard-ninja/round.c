#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

    printf("\033[1m | \033[0m\033[31;1mERROR COUNTER : %d \033[0m",
           error_counter);

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

void shift_current_word(char buffer[MAX_LENGTH_OF_TEXT], c_w* current_word)
{
    current_word->position = current_word->end + 1;
    current_word->start = current_word->end + 1;
    current_word->end = strcspn(buffer, " ");
    buffer[strcspn(buffer, " ")] = '@';
}

void compare_input_to_text(
        char text[MAX_LENGTH_OF_TEXT],
        char input[MAX_LENGTH_OF_TEXT],
        c_w* current_word,
        int* error_counter)
{
    long long unsigned int i, end;
    int counter = 0, error_flag = 0;

    if (strlen(input) + current_word->position - 1 > strlen(text)) {
        end = strlen(text);
        error_flag = 1;
    } else
        end = strlen(input) + current_word->position - 1;

    for (i = current_word->position; i < end; i++) {
        if (input[counter++] == text[i]) {
            current_word->position = i + 1;
        } else {
            error_flag = 1;
            break;
        }
    }

    if (error_flag)
        *error_counter = *error_counter + 1;
}

long long unsigned int
scoring(char text[MAX_LENGTH_OF_TEXT], int error_counter, double time)
{
    long long unsigned int score = 0;
    if (error_counter != -1) {
        score = (strlen(text) * 1000) / (time + 10 * error_counter);
    }
    return score;
}

int start_round(
        char identifier[MAX_LENGTH_OF_IDENTIFIER],
        char text[MAX_LENGTH_OF_TEXT],
        double* time_spent)
{
    c_w current_word;
    char input[MAX_LENGTH_OF_TEXT], buffer[MAX_LENGTH_OF_TEXT];
    int error_counter = 0;
    long long unsigned int current_position;
    clock_t start, end;

    start = clock();

    strcpy(buffer, text);

    current_word.position = 0;
    current_word.start = 0;
    current_word.end = strcspn(buffer, " ");
    buffer[strcspn(buffer, " ")] = '@';

    while (current_word.position < strlen(text)) {
        system("clear");

        print_round_interface(identifier, text, current_word, error_counter);

        fgets(input, MAX_LENGTH_OF_TEXT, stdin);

        if (!strncmp(input, "/exit", strlen("/exit"))) {
            error_counter = -1;
            break;
        }

        compare_input_to_text(text, input, &current_word, &error_counter);

        current_position = current_word.position;

        while (current_position >= current_word.end) {
            shift_current_word(buffer, &current_word);
        }

        if (text[(int)current_position] == ' ')
            current_word.position = current_position + 1;
        else
            current_word.position = current_position;
    }

    end = clock();
    *time_spent = (double*)(end - start) / CLOCKS_PER_SEC;

    return error_counter;
}
