#include "maxunqiuesubstrings.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *str;
        int want;
    } tests[] = {
        {"Example 1", "ababccc", 5},
        {"Example 2", "aba", 2},
        {"Example 3", "aa", 1},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = max_unique_split(tt->str);
        t_check_int("max_unique_split()", got, tt->want);
    }
    return t_done();
}
