#include "cyclicsort.c"

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
        {"Example 1", INTS(3, 1, 5, 4, 2), INTS(1, 2, 3, 4, 5)},
        {"Example 2", INTS(2, 6, 4, 3, 1, 5), INTS(1, 2, 3, 4, 5, 6)},
        {"Example 3", INTS(1, 5, 6, 4, 3, 2), INTS(1, 2, 3, 4, 5, 6)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int *got = sort(tt->nums, tt->nums_len);
        t_check_ints("sort()", got, tt->nums_len, tt->want, tt->want_len);
    }
    return t_done();
}
