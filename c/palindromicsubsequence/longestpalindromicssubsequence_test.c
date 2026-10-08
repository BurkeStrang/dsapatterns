#include "longestpalindromicssubsequence.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *st;
        int want;
    } tests[] = {
        {"Example 1", "abdbca", 5},
        {"Example 2", "cddpd", 3},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_lps_length(tt->st);
        t_check_int("find_lps_length()", got, tt->want);
    }
    return t_done();
}
