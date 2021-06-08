#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib-keyboard-ninja/auxiliary.h>
#include <lib-keyboard-ninja/menu.h>
#include <lib-keyboard-ninja/round.h>
#include <lib-keyboard-ninja/text.h>

int check_identifier(char identifier[MAX_LENGTH_OF_IDENTIFIER])
{
    if ((identifier[0] != 'S') && (identifier[0] != 'W')
        && (identifier[0] != 'N') && (identifier[0] != 'L')
        && (identifier[0] != 'M'))
        return 1;

    if (strlen(identifier) == 1)
        return 0;

    if (strlen(identifier) < MIN_LENGTH_OF_IDENTIFIER)
        return 1;

    if (identifier[1] != '#')
        return 1;

    long long unsigned int i;

    for (i = 2; i < strlen(identifier) - 3; i++) {
        if ((identifier[i] < '0') || (identifier[i] > '9'))
            return 1;
    }

    if (identifier[strlen(identifier) - 3] != ' ')
        return 1;
    if (identifier[strlen(identifier) - 2] != '|')
        return 1;
    if (identifier[strlen(identifier) - 1] != ' ')
        return 1;

    return 0;
}

void result_game(
        char text[MAX_LENGTH_OF_TEXT],
        char identifier[MAX_LENGTH_OF_IDENTIFIER],
        int error_counter,
        double time_spent)
{
    char input[MAX_LENGTH_OF_INPUT];
    while (1) {
        system("clear");
        printf("\033[1mROUND RESULTS:\033[0m\n");
        printf("Текст ID: ");
        puts(identifier);
        printf("Длина текста: %d\n", (int)strlen(text));
        if (error_counter != -1) {
            printf("Количество ошибок: \033[31m%d\033[0m\n", error_counter);
            printf("Затраченное время: %.0f с\n", time_spent);
            printf("Средняя скорость печати = %.1f символ/секунда\n",
                   (float)strlen(text) / time_spent);
        } else {
            printf("\033[1mПользователь принудительно покинул раунд\033[0m\n");
        }

        printf("\033[1;32mСчёт: %llu\033[0m\n",
               scoring(text, error_counter, time_spent));

        printf("\n\033[1;31m0 - Выход в меню\033[0m\n");
        printf("\033[1mINPUT:\033[0m ");

        fgets(input, MAX_LENGTH_OF_INPUT, stdin);
        input[strcspn(input, "\n")] = 0;

        system("clear");

        if ((input[0] == '0') && (strlen(input) == 1)) {
            system("clear");
            break;
        }
    }
}

void menu_template()
{
    printf("\033[1;36mДобро пожаловать в клавиатурный тренажёр - ceyboard ");
    printf("ninja!\033[0m\n");
    printf("\033[1m№ - Выберите путь:\033[0m\n");
    printf("\033[1;32m1 - Начать\033[0m\n");
    printf("\033[1;34m2 - Помощь\033[0m\n");
    printf("\033[1;31m3 - Выход\033[0m\n");
    printf("\033[1mINPUT:\033[0m ");
    ;
}

void start_game()
{
    char input[MAX_LENGTH_OF_INPUT];
    char identifier[MAX_LENGTH_OF_IDENTIFIER];
    char text[MAX_LENGTH_OF_TEXT];
    char filename[MAX_LENGTH_OF_FILENAME];

    strcpy(filename, "stdin.txt");

    int exit_flag = 0, error_counter = 0;
    double time_spent = 1;

    while (1) {
        system("clear");
        printf("\033[1;32m№ - START GAME MENU\033[0m\n");
        printf("\033[1m1 - Начать игру со случайным ID\n");
        printf("2 - Начать игру с определенными ID\n");
        printf("3 - Начать игру со своим текстом\033[0m\n");
        printf("\033[1;31m0 - Выход в меню\033[0m\n");
        printf("\033[1mINPUT:\033[0m ");
        fgets(input, MAX_LENGTH_OF_INPUT, stdin);
        input[strcspn(input, "\n")] = 0;

        system("clear");

        if (strlen(input) == 1) {
            memset(identifier, 0, MAX_LENGTH_OF_IDENTIFIER);
            memset(text, 0, MAX_LENGTH_OF_TEXT);

            switch (input[0]) {
            case '1':
                randomize_identifier(identifier);
                read_text(text, identifier, filename);
                error_counter = start_round(identifier, text, &time_spent);
                result_game(text, identifier, error_counter, time_spent);
                break;

            case '2':
                printf("\033[1mВведите ID полностью или только тип ");
                printf("текста\033[0m\n");
                printf("ID состоит из '<тип текста>#<номер текста | >'\n");
                printf("Пример: 'S#1 | ' или 'S'\n");
                printf("\033[1mINPUT:\033[0m ");
                fgets(identifier, MAX_LENGTH_OF_IDENTIFIER, stdin);
                identifier[strcspn(identifier, "\n")] = 0;
                if (strlen(identifier) == 1)
                    randomize_identifier(identifier);
                read_text(text, identifier, filename);
                if (strlen(text) > 0) {
                    error_counter = start_round(identifier, text, &time_spent);
                    result_game(text, identifier, error_counter, time_spent);
                }
                break;

            case '3':
                printf("\033[1mВведите свой текст:\033[0m\n");
                fgets(text, MAX_LENGTH_OF_TEXT, stdin);
                text[strcspn(text, "\n")] = 0;
                strcpy(identifier, "CUSTOM");
                if (strlen(text) > 0) {
                    error_counter = start_round(identifier, text, &time_spent);
                    result_game(text, identifier, error_counter, time_spent);
                }
                break;

            case '0':
                exit_flag = 1;
                break;
            }
        }

        if (exit_flag) {
            system("clear");
            break;
        }
    }
}

void help_game()
{
    char input[MAX_LENGTH_OF_INPUT];
    while (1) {
        system("clear");
        printf("\033[1mПомощь:\033[0m\n");
        printf("Приложение представляет собой клавиатурный тренажёр, где ");
        printf("ваша задача набирать текст.\nВаше текущее слово выделяется");
        printf(" во время раунда синим цветом. Вы можете набирать слово по");
        printf(" буквам, целиком или вовсе набирать сразу несколько слов ");
        printf("подряд. Так же в любой момент раунда вы можете написать ");
        printf("'/exit' для выхода.\nВ данном приложении вы можете выбирать");
        printf(" тип раунда: со случайным текстом из базы, с текстом ");
        printf("определенного типа, с определенным текстом или же со своим.\n");
        printf("После завершения раунда вам будет показана его статистика.\n");
        printf("\n\033[1;31m0 - Выход в меню\033[0m\n");
        printf("\033[1mINPUT:\033[0m ");
        fgets(input, MAX_LENGTH_OF_INPUT, stdin);
        input[strcspn(input, "\n")] = 0;

        system("clear");

        if ((input[0] == '0') && (strlen(input) == 1)) {
            system("clear");
            break;
        }
    }
}

void menu()
{
    char input[MAX_LENGTH_OF_INPUT];
    int exit_flag = 0;
    while (1) {
        system("clear");
        menu_template();
        fgets(input, MAX_LENGTH_OF_INPUT, stdin);
        input[strcspn(input, "\n")] = 0;
        system("clear");

        if (strlen(input) == 1) {
            switch (input[0]) {
            case '1':
                start_game();
                break;
            case '2':
                help_game();
                break;
            case '3':
                exit_flag = 1;
                break;
            }
        }

        if (exit_flag) {
            printf("\033[1mВыходим...\033[0m");
            system("clear");
            break;
        }
    }
}
