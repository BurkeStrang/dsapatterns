#include "findallmissingnum.c"

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
        {"Example 1", INTS(2, 3, 1, 8, 2, 3, 5, 1), INTS(4, 6, 7)},
        {"Example 2", INTS(2, 4, 1, 2), INTS(3)},
        {"Example 3", INTS(2, 3, 2, 1), INTS(4)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList got = find_numbers(tt->nums, tt->nums_len);
        t_check_ints("find_numbers()", got.items, got.len, tt->want,
                     tt->want_len);
        intlist_free(&got);
    }
    return t_done();
}
