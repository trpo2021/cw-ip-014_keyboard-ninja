#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <lib-keyboard-ninja/text.h>
#include <lib-keyboard-ninja/auxiliary.h>

int main()
{
    srand(time(NULL));

    char identifier[MAX_LENGTH_OF_IDENTIFIER] = {0};
    char text[MAX_LENGTH_OF_TEXT] = {0};
    char filename[MAX_LENGTH_OF_FILENAME] = "stdin.txt";
	
	identifier[0] = 'M';
	
    randomize_identifier(identifier);
    read_text(text, identifier, filename);
    puts(text);

    return 0;
}