#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib-keyboard-ninja/menu.h>
#include <lib-keyboard-ninja/auxiliary.h>
#include <lib-keyboard-ninja/round.h>
#include <lib-keyboard-ninja/text.h>

void menu_template()
{
    printf("Добро пожаловать в клавиатурный тренажёр - ceyboard ninja!\n");
    printf("Выберите путь:\n");
    printf("1 - Начать\n");
    printf("2 - Помощь\n");
    printf("3 - Выход\n");
}

void start_game()
{
    char input[1024];
    char identifier[MAX_LENGTH_OF_IDENTIFIER];
    char text[MAX_LENGTH_OF_TEXT];
    char filename[MAX_LENGTH_OF_FILENAME];

    strcpy(filename, "stdin.txt");

    int exit_flag = 0, error_counter = 0;

    while (1) {
		system("clear");
		printf("№ - START GAME MENU\n");
        printf("1 - Начать игру со случайным ID\n");
        printf("2 - Начать игру с определенными ID\n");
        printf("3 - Начать игру со своим текстом\n");
        printf("0 - Выход в меню\n");
        fgets(input, 1024, stdin);
        input[strcspn(input, "\n")] = 0;

        system("clear");

        if (strlen(input) == 1) {
            switch (input[0]) {
            case '1':
                randomize_identifier(identifier);
                read_text(text, identifier, filename);
                error_counter = start_round(identifier, text);
				printf("\n%d\n",error_counter);
                break;

            case '2':
                printf("Введите ID полностью или только тип текста\n");
                printf("ID состоит из '<тип текста>#<номер текста | >'\n");
                printf("Пример: 'S#1 | ' или 'S'\n");
                fgets(identifier, MAX_LENGTH_OF_IDENTIFIER, stdin);
                identifier[strcspn(identifier, "\n")] = 0;
                if (strlen(identifier) == 1)
                    randomize_identifier(identifier);
                read_text(text, identifier, filename);
                if (strlen(text) > 0) {
                    error_counter = start_round(identifier, text);
					printf("\n%d\n",error_counter);
                }
                break;

            case '3':
                printf("Введите свой текст:\n");
                fgets(text, MAX_LENGTH_OF_TEXT, stdin);
                text[strcspn(text, "\n")] = 0;
                strcpy(identifier, "CUSTOM");
                if (strlen(text) > 0) {
                    error_counter = start_round(identifier, text);
					printf("\n%d\n",error_counter);
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
    char input[1024];
    while (1) {
		system("clear");
        printf("Инструкция:\n");
        printf("0 - Выход в меню\n");
        fgets(input, 1024, stdin);
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
    char input[1024];
    int exit_flag = 0;
    while (1) {
		system("clear");
        menu_template();
        fgets(input, 1024, stdin);
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
