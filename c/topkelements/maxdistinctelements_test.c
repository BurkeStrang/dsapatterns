#include "maxdistinctelements.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *nums;
        int nums_len;
        int k;
        int want;
    } tests[] = {
        {"Example 1", INTS(7, 3, 5, 8, 5, 3, 3), 2, 3},
        {"Example 2", INTS(3, 5, 12, 11, 12), 3, 2},
        {"Example 3", INTS(1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5), 2, 3},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_maximum_distinct_elements(tt->nums, tt->nums_len, tt->k);
        t_check_int("find_maximum_distinct_elements()", got, tt->want);
    }
    return t_done();
}
