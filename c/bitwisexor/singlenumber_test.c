#include "singlenumber.c"

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
        {"Example 1", INTS(1, 4, 2, 1, 3, 2, 3), 4},
        {"Example 2", INTS(7, 9, 7), 9},
        {"Example 3", INTS(5, 6, 7, 5, 6), 7},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_single_number(tt->arr, tt->arr_len);
        t_check_int("find_single_number()", got, tt->want);
    }
    return t_done();
}
