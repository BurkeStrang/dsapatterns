#include "equalsumpartition.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *nums;
        int nums_len;
        bool want;
    } tests[] = {
        {"Example 1", INTS(1, 2, 3, 4), true},
        {"Example 2", INTS(1, 1, 3, 4, 7), true},
        {"Example 3", INTS(2, 3, 4, 6), false},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        bool got = can_partition(tt->nums, tt->nums_len);
        t_check_bool("can_partition()", got, tt->want);
    }
    return t_done();
}
