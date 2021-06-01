#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib-keyboard-ninja/text.h>

int main()
{
    char identifier[16] = "S#1 | ";
    char text[512] = {0};
    char filename[256] = "stdin.txt";
    read_text(text, identifier, filename);
    puts(text);

    return 0;
}