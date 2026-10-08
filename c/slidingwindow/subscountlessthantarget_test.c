#include "subscountlessthantarget.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *nums;
        int nums_len;
        int target;
        int want;
    } tests[] = {
        {"Example 1", INTS(2, 5, 3, 10), 30, 6},
        {"Example 2", INTS(8, 2, 6, 5), 50, 7},
        {"Example 3 (target 0)", INTS(10, 5, 2, 6), 0, 0},
        {"Single element < target", INTS(1), 2, 1},
        {"Single element >= target", INTS(5), 5, 0},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_subarray_count(tt->nums, tt->nums_len, tt->target);
        t_check_int("find_subarray_count()", got, tt->want);
    }
    return t_done();
}
