#include "sumofsumarraymin.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *arr;
        int arr_len;
        int want;
    } tests[] = {
        {"Example 1", INTS(3, 1, 2, 4, 5), 30},
        {"Example 2", INTS(2, 6, 5, 4), 36},
        {"Example 3", INTS(7, 3, 8), 27},
        {"Single element", INTS(5), 5},
        {"All same elements", INTS(2, 2, 2), 12},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = sum_subarray_mins(tt->arr, tt->arr_len);
        t_check_int("sum_subarray_mins()", got, tt->want);
    }
    return t_done();
}
