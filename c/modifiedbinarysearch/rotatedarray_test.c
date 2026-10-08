#include "rotatedarray.c"

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
        {"Example 1", INTS(10, 15, 1, 3, 8), 15, 1},
        {"Example 2", INTS(4, 5, 7, 9, 10, -1, 2), 10, 4},
        {"Example 3", INTS(10, 15, 1, 3, 8), 100, -1},
        {"Example 4", INTS(10, 15, 1, 3, 8), 1, 2},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = search_rotated(tt->arr, tt->arr_len, tt->key);
        t_check_int("search_rotated()", got, tt->want);
    }
    return t_done();
}
