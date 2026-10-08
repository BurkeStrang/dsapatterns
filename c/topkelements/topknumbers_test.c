#include "topknumbers.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *nums;
        int nums_len;
        int k;
        int *want;
        int want_len;
    } tests[] = {
        {"Example 1", INTS(3, 1, 5, 12, 2, 11), 3, INTS(5, 12, 11)},
        {"Example 2", INTS(5, 12, 11, -1, 12), 3, INTS(12, 11, 12)},
        {"All negative", INTS(-3, -1, -5, -12, -2, -11), 3, INTS(-1, -2, -3)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int *got = find_k_largest_numbers(tt->nums, tt->nums_len, tt->k);
        // the numbers can come back in any order
        if (got != NULL)
        {
            t_sort_ints(got, tt->k);
        }
        t_sort_ints(tt->want, tt->want_len);
        t_check_ints("find_k_largest_numbers()", got, tt->k, tt->want,
                     tt->want_len);
        free(got);
    }
    return t_done();
}
