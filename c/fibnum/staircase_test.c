#include "staircase.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int n;
        int want;
    } tests[] = {
        {"Example 1", 3, 4},
        {"Example 2", 4, 7},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = count_ways(tt->n);
        t_check_int("count_ways()", got, tt->want);
    }
    return t_done();
}
