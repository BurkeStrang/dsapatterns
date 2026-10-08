#include "minwindowsort.c"

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
        {"Example 1", INTS(1, 2, 5, 3, 7, 10, 9, 12), 5},
        {"Example 2", INTS(1, 3, 2, 0, -1, 7, 10), 5},
        {"Example 3", INTS(1, 2, 3), 0},
        {"Example 4", INTS(3, 2, 1), 3},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = min_sort(tt->arr, tt->arr_len);
        t_check_int("min_sort()", got, tt->want);
    }
    return t_done();
}
