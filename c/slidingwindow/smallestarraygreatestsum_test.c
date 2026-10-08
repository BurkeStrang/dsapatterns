#include "smallestarraygreatestsum.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int s;
        const int *arr;
        int arr_len;
        int want;
    } tests[] = {
        {"Example 1", 7, INTS(2, 1, 5, 2, 3, 2), 2},
        {"Example 2", 7, INTS(2, 1, 5, 2, 8), 1},
        {"Example 3", 8, INTS(3, 4, 1, 1, 6), 3},
        {"No subarray meets S", 20, INTS(1, 2, 3, 4), 0},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_min_sub_array(tt->s, tt->arr, tt->arr_len);
        t_check_int("find_min_sub_array()", got, tt->want);
    }
    return t_done();
}
