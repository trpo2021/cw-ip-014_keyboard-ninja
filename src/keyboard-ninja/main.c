#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <lib-keyboard-ninja/auxiliary.h>
#include <lib-keyboard-ninja/round.h>
#include <lib-keyboard-ninja/text.h>

int main()
{
    system("clear");
    srand(time(NULL));

    char identifier[MAX_LENGTH_OF_IDENTIFIER];
    char text[MAX_LENGTH_OF_TEXT];
    char filename[MAX_LENGTH_OF_FILENAME];

    memset(identifier, 0, MAX_LENGTH_OF_IDENTIFIER);

    strcpy(filename, "stdin.txt");

    randomize_identifier(identifier);
    read_text(text, identifier, filename);

    puts(text);

    start_round(identifier, text);

    return 0;
}