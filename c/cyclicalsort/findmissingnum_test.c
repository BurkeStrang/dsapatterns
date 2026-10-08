#include "findmissingnum.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int *nums;
        int nums_len;
        int want;
    } tests[] = {
        {"Example 1", INTS(4, 0, 3, 1), 2},
        {"Example 2", INTS(8, 3, 5, 2, 4, 6, 0, 1), 7},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_missing_number(tt->nums, tt->nums_len);
        t_check_int("find_missing_number()", got, tt->want);
    }
    return t_done();
}
