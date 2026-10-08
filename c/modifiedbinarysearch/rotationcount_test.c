#include "rotationcount.c"

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
        {"Example 1", INTS(10, 15, 1, 3, 8), 2},
        {"Example 2", INTS(4, 5, 7, 9, 10, -1, 2), 5},
        {"Example 3", INTS(1, 3, 8, 10), 0},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = count_rotations(tt->arr, tt->arr_len);
        t_check_int("count_rotations()", got, tt->want);
    }
    return t_done();
}
