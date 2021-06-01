#ifndef TEXT_H
#define TEXT_H

#include <lib-keyboard-ninja/auxiliary.h>

void randomize_text_number(char text_type, char text_number[MAX_LENGTH_OF_TEXT_NUMBER]);
char randomize_text_type();
void randomize_identifier(char identifier[MAX_LENGTH_OF_IDENTIFIER]);
void read_text(char text[MAX_LENGTH_OF_TEXT], char identifier[MAX_LENGTH_OF_IDENTIFIER], char filename[MAX_LENGTH_OF_FILENAME]);

#endif /* TEXT_H */