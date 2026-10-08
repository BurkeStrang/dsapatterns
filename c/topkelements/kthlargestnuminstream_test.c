#include "kthlargestnuminstream.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *nums;
        int nums_len;
        int k;
        int num;
        int want;
    } tests[] = {
        {"Example 1", INTS(3, 1, 5, 12, 2, 11), 4, 6, 5},
        {"Example 2", INTS(3, 1, 5, 12, 2, 11), 4, 13, 5},
        {"Example 3", INTS(3, 1, 5, 12, 2, 11), 4, 4, 4},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        KthLargest stream = kth_largest_new(tt->nums, tt->nums_len, tt->k);
        int got = kth_largest_add(&stream, tt->num);
        t_check_int("kth_largest_add()", got, tt->want);
        kth_largest_free(&stream);
    }
    return t_done();
}
