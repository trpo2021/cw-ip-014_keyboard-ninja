#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <lib-keyboard-ninja/text.h>

int main()
{
	srand(time(NULL));
	
    char identifier[16] = {0};
    char text[512] = {0};
    char filename[256] = "stdin.txt";
	randomize_identifier(identifier);
    read_text(text, identifier, filename);
    puts(text);

    return 0;
}