#include "corruptpair.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int *nums;
        int nums_len;
        const int *want;
        int want_len;
    } tests[] = {
        {"Example 1", INTS(3, 1, 2, 5, 2), INTS(2, 4)},
        {"Example 2", INTS(3, 1, 2, 3, 6, 4), INTS(3, 5)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int *got = find_corrupt(tt->nums, tt->nums_len);
        t_check_ints("find_corrupt()", got, 2, tt->want, tt->want_len);
        free(got);
    }
    return t_done();
}
