#include "mindiff.c"

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
        {"Example 1", INTS(4, 6, 10), 7, 6},
        {"Example 2", INTS(4, 6, 10), 4, 4},
        {"Example 3", INTS(1, 3, 8, 10, 15), 12, 10},
        {"Example 4", INTS(4, 6, 10), 17, 10},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = search_min_diff(tt->arr, tt->arr_len, tt->key);
        t_check_int("search_min_diff()", got, tt->want);
    }
    return t_done();
}
