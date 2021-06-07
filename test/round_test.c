#include <string.h>

#include <lib-keyboard-ninja/auxiliary.h>
#include <lib-keyboard-ninja/round.h>

#include <ctest.h>

CTEST(compare_input_to_text, read1)
{
    c_w current_word;
    char text[MAX_LENGTH_OF_TEXT];
    char input[MAX_LENGTH_OF_TEXT];
    char buffer[MAX_LENGTH_OF_TEXT];
    int error_counter = 0;

    strcpy(text, "Hello world!");
    strcpy(input, "Hello");
    strcpy(buffer, text);

    current_word.position = 0;
    current_word.start = 0;
    current_word.end = strcspn(buffer, " ");
    buffer[strcspn(buffer, " ")] = '@';

    compare_input_to_text(text, input, &current_word, &error_counter);

    const int exp = 4;

    ASSERT_EQUAL(exp, (int)current_word.position);
}

CTEST(compare_input_to_text, read2)
{
    c_w current_word;
    char text[MAX_LENGTH_OF_TEXT];
    char input[MAX_LENGTH_OF_TEXT];
    char buffer[MAX_LENGTH_OF_TEXT];
    int error_counter = 0;

    strcpy(text, "Hello world!");
    strcpy(input, "Hel");
    strcpy(buffer, text);

    current_word.position = 0;
    current_word.start = 0;
    current_word.end = strcspn(buffer, " ");
    buffer[strcspn(buffer, " ")] = '@';

    compare_input_to_text(text, input, &current_word, &error_counter);

    const int exp = 2;

    ASSERT_EQUAL(exp, (int)current_word.position);
}

CTEST(compare_input_to_text, read3)
{
    c_w current_word;
    char text[MAX_LENGTH_OF_TEXT];
    char input[MAX_LENGTH_OF_TEXT];
    char buffer[MAX_LENGTH_OF_TEXT];
    int error_counter = 0;

    strcpy(text, "Hello world!");
    strcpy(input, "Hello ");
    strcpy(buffer, text);

    current_word.position = 0;
    current_word.start = 0;
    current_word.end = strcspn(buffer, " ");
    buffer[strcspn(buffer, " ")] = '@';

    compare_input_to_text(text, input, &current_word, &error_counter);

    const int exp = 5;

    ASSERT_EQUAL(exp, (int)current_word.position);
}

CTEST(compare_input_to_text, read4)
{
    c_w current_word;
    char text[MAX_LENGTH_OF_TEXT];
    char input[MAX_LENGTH_OF_TEXT];
    char buffer[MAX_LENGTH_OF_TEXT];
    int error_counter = 0;

    strcpy(text, "Hello world!");
    strcpy(input, "Hello wor");
    strcpy(buffer, text);

    current_word.position = 0;
    current_word.start = 0;
    current_word.end = strcspn(buffer, " ");
    buffer[strcspn(buffer, " ")] = '@';

    compare_input_to_text(text, input, &current_word, &error_counter);

    const int exp = 8;

    ASSERT_EQUAL(exp, (int)current_word.position);
}

CTEST(compare_input_to_text, read5)
{
    c_w current_word;
    char text[MAX_LENGTH_OF_TEXT];
    char input[MAX_LENGTH_OF_TEXT];
    char buffer[MAX_LENGTH_OF_TEXT];
    int error_counter = 0;

    strcpy(text, "Hello world!");
    strcpy(input, "Hello world!");
    strcpy(buffer, text);

    current_word.position = 0;
    current_word.start = 0;
    current_word.end = strcspn(buffer, " ");
    buffer[strcspn(buffer, " ")] = '@';

    compare_input_to_text(text, input, &current_word, &error_counter);

    const int exp = 11;

    ASSERT_EQUAL(exp, (int)current_word.position);
}

CTEST(compare_input_to_text, error1)
{
    c_w current_word;
    char text[MAX_LENGTH_OF_TEXT];
    char input[MAX_LENGTH_OF_TEXT];
    char buffer[MAX_LENGTH_OF_TEXT];
    int error_counter = 0;

    strcpy(text, "Hello world!");
    strcpy(input, "Hew ");
    strcpy(buffer, text);

    current_word.position = 0;
    current_word.start = 0;
    current_word.end = strcspn(buffer, " ");
    buffer[strcspn(buffer, " ")] = '@';

    compare_input_to_text(text, input, &current_word, &error_counter);

    const int exp = 1;

    ASSERT_EQUAL(exp, error_counter);
}

CTEST(compare_input_to_text, error2)
{
    c_w current_word;
    char text[MAX_LENGTH_OF_TEXT];
    char input[MAX_LENGTH_OF_TEXT];
    char buffer[MAX_LENGTH_OF_TEXT];
    int error_counter = 0;

    strcpy(text, "Hello world!");
    strcpy(input, "Hellow ");
    strcpy(buffer, text);

    current_word.position = 0;
    current_word.start = 0;
    current_word.end = strcspn(buffer, " ");
    buffer[strcspn(buffer, " ")] = '@';

    compare_input_to_text(text, input, &current_word, &error_counter);

    const int exp = 1;

    ASSERT_EQUAL(exp, error_counter);
}

CTEST(compare_input_to_text, error3)
{
    c_w current_word;
    char text[MAX_LENGTH_OF_TEXT];
    char input[MAX_LENGTH_OF_TEXT];
    char buffer[MAX_LENGTH_OF_TEXT];
    int error_counter = 0;

    strcpy(text, "Hello world!");
    strcpy(input, "Hello ");
    strcpy(buffer, text);

    current_word.position = 0;
    current_word.start = 0;
    current_word.end = strcspn(buffer, " ");
    buffer[strcspn(buffer, " ")] = '@';

    compare_input_to_text(text, input, &current_word, &error_counter);

    const int exp = 0;

    ASSERT_EQUAL(exp, error_counter);
}

CTEST(compare_input_to_text, error4)
{
    c_w current_word;
    char text[MAX_LENGTH_OF_TEXT];
    char input[MAX_LENGTH_OF_TEXT];
    char buffer[MAX_LENGTH_OF_TEXT];
    int error_counter = 0;

    strcpy(text, "Hello world!");
    strcpy(input, "Hel");
    strcpy(buffer, text);

    current_word.position = 0;
    current_word.start = 0;
    current_word.end = strcspn(buffer, " ");
    buffer[strcspn(buffer, " ")] = '@';

    compare_input_to_text(text, input, &current_word, &error_counter);

    const int exp = 0;

    ASSERT_EQUAL(exp, error_counter);
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

    const int exp = 8;

    ASSERT_EQUAL(exp, (int)current_word.end);
}

CTEST(scoring, score1)
{
    char text[MAX_LENGTH_OF_TEXT];
    strcpy(text, "Hello world!");
    int error_counter = 0;
    double time = 1.9;

    const int exp = 6315;

    ASSERT_EQUAL(exp, (int)scoring(text, error_counter, time));
}

CTEST(scoring, score2)
{
    char text[MAX_LENGTH_OF_TEXT];
    strcpy(text, "Hello world!");
    int error_counter = 32;
    double time = 1.9;

    const int exp = 37;

    ASSERT_EQUAL(exp, (int)scoring(text, error_counter, time));
}

CTEST(scoring, score3)
{
    char text[MAX_LENGTH_OF_TEXT];
    strcpy(text, "Hello world!");
    int error_counter = -1;
    double time = 1.9;

    const int exp = 0;

    ASSERT_EQUAL(exp, (int)scoring(text, error_counter, time));
}
