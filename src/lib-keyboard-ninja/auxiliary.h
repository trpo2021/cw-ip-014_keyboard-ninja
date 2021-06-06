#ifndef AUXILIARY_H
#define AUXILIARY_H

extern const int AMOUNT_OF_S_TEXTS;
extern const int AMOUNT_OF_W_TEXTS;
extern const int AMOUNT_OF_N_TEXTS;
extern const int AMOUNT_OF_L_TEXTS;
extern const int AMOUNT_OF_M_TEXTS;

extern const int MAX_LENGTH_OF_TEXT;
extern const int MAX_LENGTH_OF_IDENTIFIER;
extern const int MAX_LENGTH_OF_TEXT_NUMBER;
extern const int MAX_LENGTH_OF_FILENAME;

extern const int LENGTH_OF_PATH;

typedef struct current_word{
	long long unsigned int start;
	long long unsigned int end;
	long long unsigned int position;
}c_w;

#endif /* AUXILIARY_H */