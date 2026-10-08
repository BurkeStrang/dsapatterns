#include "findfirstknums.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int *nums;
        int nums_len;
        int k;
        const int *want;
        int want_len;
    } tests[] = {
        {"Example 1", INTS(3, -1, 4, 5, 5), 3, INTS(1, 2, 6)},
        {"Example 2", INTS(2, 3, 4), 3, INTS(1, 5, 6)},
        {"Example 3", INTS(-2, -3, 4), 2, INTS(1, 2)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList got = find_first_k(tt->nums, tt->nums_len, tt->k);
        t_check_ints("find_first_k()", got.items, got.len, tt->want,
                     tt->want_len);
        intlist_free(&got);
    }
    return t_done();
}
