#include "kclosestnumbers.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *arr;
        int arr_len;
        int k;
        int x;
        const int *want;
        int want_len;
    } tests[] = {
        {"Example 1", INTS(5, 6, 7, 8, 9), 3, 7, INTS(6, 7, 8)},
        {"Example 2", INTS(2, 4, 5, 6, 9), 3, 6, INTS(4, 5, 6)},
        {"Example 3", INTS(2, 4, 5, 6, 9), 3, 10, INTS(5, 6, 9)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList got = find_closest_elements(tt->arr, tt->arr_len, tt->k, tt->x);
        t_check_ints("find_closest_elements()", got.items, got.len, tt->want,
                     tt->want_len);
        intlist_free(&got);
    }
    return t_done();
}
