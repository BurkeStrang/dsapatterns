#include "issubarray.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *nums;
        int nums_len;
        const int *sub;
        int sub_len;
        bool want;
    } tests[] = {
        {"Example 1", INTS(1, 2, 3), INTS(2, 3), true},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        bool got = is_subarray(tt->nums, tt->nums_len, tt->sub, tt->sub_len);
        t_check_bool("is_subarray()", got, tt->want);
    }
    return t_done();
}
