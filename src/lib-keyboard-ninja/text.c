#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib-keyboard-ninja/text.h>

const int AMOUNT_OF_S_TEXTS = 25;
const int AMOUNT_OF_W_TEXTS = 10;
const int AMOUNT_OF_N_TEXTS = 10;
const int AMOUNT_OF_L_TEXTS = 10;
const int AMOUNT_OF_M_TEXTS = 1;

void randomize_text_number(char text_type, char text_number[11])
{
    int number;

    switch (text_type) {
    case 'S':
        number = rand() % AMOUNT_OF_S_TEXTS + 1;
        break;
    case 'W':
        number = rand() % AMOUNT_OF_W_TEXTS + 1;
        break;
    case 'N':
        number = rand() % AMOUNT_OF_N_TEXTS + 1;
        break;
    case 'L':
        number = rand() % AMOUNT_OF_L_TEXTS + 1;
        break;
    case 'M':
        number = rand() % AMOUNT_OF_M_TEXTS + 1;
        break;
    }

    sprintf(text_number, "%d", number);
}

char randomize_text_type()
{
	char text_type;
	
    switch (rand() % 5) {
    case 0:
        text_type = 'S';
        break;
    case 1:
        text_type = 'W';
        break;
    case 2:
        text_type = 'N';
        break;
    case 3:
        text_type = 'L';
        break;
    case 4:
        text_type = 'M';
        break;
    }
	
	return text_type;
}

void randomize_identifier(char identifier[16])
{
    memset(identifier, 0, 16);
    char text_type;
    char text_number[11];

    text_type = randomize_text_type();
    randomize_text_number(text_type, text_number);

    identifier[0] = text_type;
    strcat(identifier, "#");
    strcat(identifier, text_number);
    strcat(identifier, " | ");
}

void read_text(char text[512], char identifier[16], char filename[256])
{
    FILE* base;
    long long unsigned int i;
    char string[512 + 16];
    char path[10 + 256] = "../texts/";
    strcat(path, filename);
    base = fopen(path, "r");

    while (fgets(string, 528, base)) {
        if (!strncmp(identifier, string, strlen(identifier))) {
            for (i = strlen(identifier); i < strlen(string); i++) {
                text[i - strlen(identifier)] = string[i];
            }
        }
    }

    text[strcspn(text, "\n")] = 0;

    fclose(base);
}
