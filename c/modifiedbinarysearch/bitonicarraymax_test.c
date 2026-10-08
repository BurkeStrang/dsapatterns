#include "bitonicarraymax.c"

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
        {"Example 1", INTS(1, 3, 8, 12, 4, 2), 12},
        {"Example 2", INTS(3, 8, 3, 1), 8},
        {"Example 3", INTS(1, 3, 8, 12), 12},
        {"Example 4", INTS(10, 9, 8), 10},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_max_in_bitonic_array(tt->arr, tt->arr_len);
        t_check_int("find_max_in_bitonic_array()", got, tt->want);
    }
    return t_done();
}
