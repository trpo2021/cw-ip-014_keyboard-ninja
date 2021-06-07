#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void menu_template()
{
    system("clear");
    printf("Добро пожаловать в клавиатурный тренажёр - ceyboard ninja!\n");
    printf("Выберите путь:\n");
    printf("1 - Начать\n");
    printf("2 - Помощь\n");
    printf("3 - Выход\n");
}

void exit_menu()
{
    int ex;
    do {
        scanf("%d", &ex);
        if (ex == 0)
            menu_template();
        else
            printf("Ошибка!Проверьте правильность введённых данных\n");
    } while (ex != 0);
}

void start_game()
{
    printf("Начало игры..\n");
    printf("0 - Выход в меню\n");
    exit_menu();
}

void settings_game()
{
    printf("Инструкция\n");
    printf("0 - Выход в меню\n");
    exit_menu();
}

int exit_game()
{
    printf("Выходим..");
    exit(0);
}

void menu()
{
    menu_template();
    int a;
    while (1) {
        scanf("%d", &a);
        switch (a) {
        case 1:
            system("clear");
            start_game();

            break;
        case 2:
            system("clear");
            settings_game();
            break;
        case 3:
            system("clear");
            exit_game();
            break;
        default:
            printf("Ошибка!Проверьте правильность введённых данных\n");
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    menu();
    return 0;
}
