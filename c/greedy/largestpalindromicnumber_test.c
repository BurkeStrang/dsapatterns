#include "largestpalindromicnumber.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *s;
        const char *want;
    } tests[] = {
        {"Example 1", "323211444", "432141234"},
        {"Example 3", "54321", "5"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        char *got = largest_palindromic(tt->s);
        t_check_str("largest_palindromic()", got, tt->want);
        free(got);
    }
    return t_done();
}
