#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib-keyboard-ninja/text.h>

void randomize_identifier(char identifier[16])
{
    memset(identifier, 0, sizeof(identifier));
    char text_type;
    char text_number[11];

    randomize_text_type(text_type);
    randomize_text_number(text_number);

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
