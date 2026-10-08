#include "largestuniquenum.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *a;
        int a_len;
        int want;
    } tests[] = {
        {"Example 1", INTS(5, 7, 3, 7, 5, 8), 8},
        {"Example 2", INTS(1, 2, 3, 2, 1, 4, 4), 3},
        {"Example 3", INTS(9, 9, 8, 8, 7, 7), -1},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = largest_unique_number(tt->a, tt->a_len);
        t_check_int("largest_unique_number()", got, tt->want);
    }
    return t_done();
}
