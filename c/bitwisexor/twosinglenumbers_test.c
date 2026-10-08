#include "twosinglenumbers.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *nums;
        int nums_len;
        const int *want;
        int want_len;
    } tests[] = {
        {"Example 1", INTS(1, 4, 2, 1, 3, 5, 6, 2, 3, 5), INTS(4, 6)},
        {"Example 2", INTS(2, 1, 3, 2), INTS(1, 3)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int *got = find_single_numbers(tt->nums, tt->nums_len);
        if (got != NULL)
        {
            t_sort_ints(got, 2); // the two numbers can come back in any order
        }
        t_check_ints("find_single_numbers()", got, 2, tt->want, tt->want_len);
        free(got);
    }
    return t_done();
}
