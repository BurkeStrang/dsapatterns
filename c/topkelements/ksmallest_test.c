#include "ksmallest.c"

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
        {"Example 1", INTS(1, 5, 12, 2, 11, 5), 3, 5},
        {"Example 2", INTS(1, 5, 12, 2, 11, 5), 4, 5},
        {"Example 3", INTS(5, 12, 11, -1, 12), 3, 11},
        {"Example 4", INTS(1, 5, 12, 2, 11, 5), 1, 1},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_kth_smallest_number(tt->nums, tt->nums_len, tt->k);
        t_check_int("find_kth_smallest_number()", got, tt->want);
    }
    return t_done();
}
