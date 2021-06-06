#include <string.h>

#include <lib-keyboard-ninja/auxiliary.h>
#include <lib-keyboard-ninja/round.h>

#include <ctest.h>

CTEST(compare_input_to_text, test1)
{
    c_w current_word;
    char text[MAX_LENGTH_OF_TEXT];
    char input[MAX_LENGTH_OF_TEXT];
    char buffer[MAX_LENGTH_OF_TEXT];

    strcpy(text, "Hello world!");
    strcpy(input, "Hello");
    strcpy(buffer, text);

    current_word.position = 0;
    current_word.start = 0;
    current_word.end = strcspn(buffer, " ");
    buffer[strcspn(buffer, " ")] = '@';

    compare_input_to_text(text, input, &current_word);

    const int exp = 5;

    ASSERT_EQUAL(exp, (int)current_word.position);
}

CTEST(compare_input_to_text, test2)
{
    c_w current_word;
    char text[MAX_LENGTH_OF_TEXT];
    char input[MAX_LENGTH_OF_TEXT];
    char buffer[MAX_LENGTH_OF_TEXT];

    strcpy(text, "Hello world!");
    strcpy(input, "Hel");
    strcpy(buffer, text);

    current_word.position = 0;
    current_word.start = 0;
    current_word.end = strcspn(buffer, " ");
    buffer[strcspn(buffer, " ")] = '@';

    compare_input_to_text(text, input, &current_word);

    const int exp = 3;

    ASSERT_EQUAL(exp, (int)current_word.position);
}

CTEST(compare_input_to_text, test3)
{
    c_w current_word;
    char text[MAX_LENGTH_OF_TEXT];
    char input[MAX_LENGTH_OF_TEXT];
    char buffer[MAX_LENGTH_OF_TEXT];

    strcpy(text, "Hello world!");
    strcpy(input, "Hello ");
    strcpy(buffer, text);

    current_word.position = 0;
    current_word.start = 0;
    current_word.end = strcspn(buffer, " ");
    buffer[strcspn(buffer, " ")] = '@';

    compare_input_to_text(text, input, &current_word);

    const int exp = 5;

    ASSERT_EQUAL(exp, (int)current_word.position);
}

CTEST(shift_current_word, test1)
{
    c_w current_word;
    char text[MAX_LENGTH_OF_TEXT];
    char buffer[MAX_LENGTH_OF_TEXT];

    strcpy(text, "Hello world!");
    strcpy(buffer, text);

    current_word.position = 0;
    current_word.start = 0;
    current_word.end = strcspn(buffer, " ");
    buffer[strcspn(buffer, " ")] = '@';

    shift_current_word(buffer, &current_word);

    const int exp = 12;

    ASSERT_EQUAL(exp, (int)current_word.end);
}

CTEST(shift_current_word, test2)
{
    c_w current_word;
    char text[MAX_LENGTH_OF_TEXT];
    char buffer[MAX_LENGTH_OF_TEXT];

    strcpy(text, "Hello my friend!");
    strcpy(buffer, text);

    current_word.position = 0;
    current_word.start = 0;
    current_word.end = strcspn(buffer, " ");
    buffer[strcspn(buffer, " ")] = '@';

    shift_current_word(buffer, &current_word);

    const int exp = 9;

    ASSERT_EQUAL(exp, (int)current_word.end);
}