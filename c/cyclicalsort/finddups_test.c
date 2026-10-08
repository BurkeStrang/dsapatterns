#include "finddups.c"

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
        {"Example 1", INTS(3, 4, 4, 5, 5), INTS(5, 4)},
        {"Example 2", INTS(5, 4, 7, 2, 3, 5, 3), INTS(3, 5)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList got = find_dups(tt->nums, tt->nums_len);
        t_check_ints("find_dups()", got.items, got.len, tt->want, tt->want_len);
        intlist_free(&got);
    }
    return t_done();
}
