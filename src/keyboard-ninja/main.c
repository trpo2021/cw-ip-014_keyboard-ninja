#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <lib-keyboard-ninja/text.h>

int main (){
	char identifier[] = "S#1 | ";
	char text[512] = {0};
	char filename[] = "stdin.txt";
	read_text (text, identifier, filename);
	puts(text);
	
	return 0;
}