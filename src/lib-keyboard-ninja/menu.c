#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib-keyboard-ninja/auxiliary.h>
#include <lib-keyboard-ninja/menu.h>
#include <lib-keyboard-ninja/round.h>
#include <lib-keyboard-ninja/text.h>

void menu_template()
{
    printf("\033[1mДобро пожаловать в клавиатурный тренажёр - ceyboard ");
    printf("ninja!\n");
    printf("№ - Выберите путь:\033[0m\n");
    printf("1 - Начать\n");
    printf("2 - Помощь\n");
    printf("3 - Выход\n");
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

    while (1) {
        system("clear");
        printf("\033[1m№ - START GAME MENU\033[0m\n");
        printf("1 - Начать игру со случайным ID\n");
        printf("2 - Начать игру с определенными ID\n");
        printf("3 - Начать игру со своим текстом\n");
        printf("0 - Выход в меню\n");
        printf("\033[1mINPUT:\033[0m ");
        fgets(input, MAX_LENGTH_OF_INPUT, stdin);
        input[strcspn(input, "\n")] = 0;

        system("clear");

        if (strlen(input) == 1) {
            switch (input[0]) {
            case '1':
                randomize_identifier(identifier);
                read_text(text, identifier, filename);
                error_counter = start_round(identifier, text);
                printf("\n%d\n", error_counter);
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
                    error_counter = start_round(identifier, text);
                    printf("\n%d\n", error_counter);
                }
                break;

            case '3':
                printf("\033[1mВведите свой текст:\033[0m\n");
                fgets(text, MAX_LENGTH_OF_TEXT, stdin);
                text[strcspn(text, "\n")] = 0;
                strcpy(identifier, "CUSTOM");
                if (strlen(text) > 0) {
                    error_counter = start_round(identifier, text);
                    printf("\n%d\n", error_counter);
                }
                break;

            case '0':
                exit_flag = 1;
                break;
            }
        }

        if (exit_flag) {
            printf("Выходим..");
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
        printf("буквам, целиком или вовсе набирать сразу несколько слов ");
        printf("подряд. Так же в любой момент раунда вы можете написать ");
        printf("'/exit' для выхода.\nВ данном приложении вы можете выбирать");
        printf("тип раунда: со случайным текстом из базы, с текстом ");
        printf("определенного типа, с определенным текстом или же со своим.\n");
        printf("После завершения раунда вам будет показана его статистика.\n");
        printf("0 - Выход в меню\n");
        printf("\033[1mINPUT:\033[0m ");
        fgets(input, MAX_LENGTH_OF_INPUT, stdin);
        input[strcspn(input, "\n")] = 0;

        system("clear");

        if (input[0] == '0') {
            printf("Выходим..");
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
            printf("Выходим..");
            system("clear");
            break;
        }
    }
}
