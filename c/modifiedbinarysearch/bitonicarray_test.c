#include "bitonicarray.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *arr;
        int arr_len;
        int key;
        int want;
    } tests[] = {
        {"Example 1", INTS(1, 3, 8, 4, 3), 4, 3},
        {"Example 2", INTS(3, 8, 3, 1), 8, 1},
        {"Example 3", INTS(1, 3, 8, 12), 12, 3},
        {"Example 4", INTS(10, 9, 8), 10, 0},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = search_bitonic(tt->arr, tt->arr_len, tt->key);
        t_check_int("search_bitonic()", got, tt->want);
    }
    return t_done();
}
