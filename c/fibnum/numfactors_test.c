#include "numfactors.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int n;
        int want;
    } tests[] = {
        {"Example 1", 4, 4},
        {"Example 2", 5, 6},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = factors(tt->n);
        t_check_int("factors()", got, tt->want);
    }
    return t_done();
}
