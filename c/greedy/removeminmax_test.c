#include "removeminmax.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *nums;
        int nums_len;
        int want;
    } tests[] = {
        {"Example 1", INTS(3, 2, 5, 1, 4), 3},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = min_moves(tt->nums, tt->nums_len);
        t_check_int("min_moves()", got, tt->want);
    }
    return t_done();
}
