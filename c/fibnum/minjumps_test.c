#include "minjumps.c"

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
        {"Example 1", INTS(2, 1, 1, 1, 4), 3},
        {"Example 2", INTS(1, 1, 3, 6, 9, 3, 0, 1, 3), 4},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = count_min_jumps(tt->arr, tt->arr_len);
        t_check_int("count_min_jumps()", got, tt->want);
    }
    return t_done();
}
