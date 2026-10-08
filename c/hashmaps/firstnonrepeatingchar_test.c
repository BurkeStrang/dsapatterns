#include "firstnonrepeatingchar.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *s;
        int want;
    } tests[] = {
        {"Example 1: apple", "apple", 0}, {"Example 2: abcab", "abcab", 2},
        {"Example 3: abab", "abab", -1},  {"Single character", "z", 0},
        {"All unique", "abcdef", 0},      {"Last unique", "aabbc", 4},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = first_uniq_char(tt->s);
        t_check_int("first_uniq_char()", got, tt->want);
    }
    return t_done();
}
