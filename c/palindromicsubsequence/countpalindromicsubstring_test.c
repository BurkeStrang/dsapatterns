#include "countpalindromicsubstring.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *st;
        int want;
    } tests[] = {
        {"Example1", "abdbca", 7},
        // {"Example2", "cddpd", 7},
        // {"Example3", "pqr", 3},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_cps(tt->st);
        t_check_int("find_cps()", got, tt->want);
    }
    return t_done();
}
