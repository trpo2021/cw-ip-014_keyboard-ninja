#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_template()
{
    system("clear");
    printf("Добро пожаловать в клавиатурный тренажёр - ceyboard ninja!\n");
    printf("Выберите путь:\n");
    printf("1 - Начать\n");
    printf("2 - Помощь\n");
    printf("3 - Выход\n");
}

void start_game()
{
    char input[1024];
    int exit_flag = 0;
    while (1) {
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

                break;
            case '2':

                break;
            case '3':

                break;
            case '0':
                exit_flag = 1;
                break;
            }
        }

        if (exit_flag) {
            printf("Выходим..\n");
            break;
        }
    }
}

void help_game()
{
    char input[1024];
    int exit_flag = 0;
    while (1) {
        printf("Инструкция\n");
        printf("0 - Выход в меню\n");
        fgets(input, 1024, stdin);
        input[strcspn(input, "\n")] = 0;

        system("clear");

        if (input[0] == '0') {
            printf("Выходим..\n");
            break;
        }
    }
}

void menu()
{
    char input[1024];
    int exit_flag = 0;
    while (1) {
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
            printf("Выходим..\n");
            break;
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    menu();
    return 0;
}
