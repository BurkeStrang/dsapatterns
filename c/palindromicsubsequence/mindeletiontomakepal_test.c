#include "mindeletiontomakepal.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *st;
        int want;
    } tests[] = {
        {"Example 1", "abdbca", 1},
        {"Example 2", "cddpd", 2},
        {"Example 3", "pqr", 2},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_minimum_deletions(tt->st);
        t_check_int("find_minimum_deletions()", got, tt->want);
    }
    return t_done();
}
