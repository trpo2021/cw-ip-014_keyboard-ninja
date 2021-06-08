#include <string.h>

#include <lib-keyboard-ninja/auxiliary.h>
#include <lib-keyboard-ninja/menu.h>

#include <ctest.h>

CTEST(check_identifier, test1)
{
    char identifier[MAX_LENGTH_OF_IDENTIFIER];

    strcpy(identifier, "S#1 | ");

    const int exp = 0;

    ASSERT_EQUAL(exp, check_identifier(identifier));
}

CTEST(check_identifier, test2)
{
    char identifier[MAX_LENGTH_OF_IDENTIFIER];

    strcpy(identifier, "S#1 |");

    const int exp = 1;

    ASSERT_EQUAL(exp, check_identifier(identifier));
}

CTEST(check_identifier, test3)
{
    char identifier[MAX_LENGTH_OF_IDENTIFIER];

    strcpy(identifier, "S#1 ");

    const int exp = 1;

    ASSERT_EQUAL(exp, check_identifier(identifier));
}

CTEST(check_identifier, test4)
{
    char identifier[MAX_LENGTH_OF_IDENTIFIER];

    strcpy(identifier, "S#1");

    const int exp = 1;

    ASSERT_EQUAL(exp, check_identifier(identifier));
}

CTEST(check_identifier, test5)
{
    char identifier[MAX_LENGTH_OF_IDENTIFIER];

    strcpy(identifier, "S#");

    const int exp = 1;

    ASSERT_EQUAL(exp, check_identifier(identifier));
}

CTEST(check_identifier, test6)
{
    char identifier[MAX_LENGTH_OF_IDENTIFIER];

    strcpy(identifier, "S");

    const int exp = 0;

    ASSERT_EQUAL(exp, check_identifier(identifier));
}

CTEST(check_identifier, test7)
{
    char identifier[MAX_LENGTH_OF_IDENTIFIER];

    strcpy(identifier, "S#1b2 | ");

    const int exp = 1;

    ASSERT_EQUAL(exp, check_identifier(identifier));
}

CTEST(check_identifier, test8)
{
    char identifier[MAX_LENGTH_OF_IDENTIFIER];

    strcpy(identifier, "S12 | ");

    const int exp = 1;

    ASSERT_EQUAL(exp, check_identifier(identifier));
}