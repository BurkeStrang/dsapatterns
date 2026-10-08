#include "finddup.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int *nums;
        int nums_len;
        int want;
    } tests[] = {
        {"Example 1", INTS(1, 4, 4, 3, 2), 4},
        {"Example 2", INTS(2, 1, 3, 3, 5, 4), 3},
        {"Example 3", INTS(2, 4, 1, 4, 4), 4},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_dup(tt->nums);
        t_check_int("find_dup()", got, tt->want);
    }
    return t_done();
}
