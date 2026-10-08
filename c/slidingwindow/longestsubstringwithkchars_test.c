#include "longestsubstringwithkchars.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *str;
        int k;
        int want;
    } tests[] = {
        {"Example 1", "araaci", 2, 4},
        {"Example 2", "araaci", 1, 2},
        {"Example 3", "cbbebi", 3, 5},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_length(tt->str, tt->k);
        t_check_int("find_length()", got, tt->want);
    }
    return t_done();
}
