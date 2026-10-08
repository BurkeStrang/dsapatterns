#include "findminmissingposnum.c"

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
        {"Example 1", INTS(-3, 1, 5, 4, 2), 3},
        {"Example 2", INTS(3, -2, 0, 1, 2), 4},
        {"Example 3", INTS(3, 2, 5, 1), 4},
        {"Example 4", INTS(33, 37, 5), 1},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_mis(tt->nums, tt->nums_len);
        t_check_int("find_mis()", got, tt->want);
    }
    return t_done();
}
