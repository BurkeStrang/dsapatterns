#include "maxsubarrayonesreplace.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *arr;
        int arr_len;
        int k;
        int want;
    } tests[] = {
        {"Example 1", INTS(0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1), 2, 6},
        {"Example 2", INTS(0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1), 3, 9},
        {"Example 3", INTS(1, 0, 0, 1, 1, 0, 1, 1), 2, 6},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = max_ones_length(tt->arr, tt->arr_len, tt->k);
        t_check_int("max_ones_length()", got, tt->want);
    }
    return t_done();
}
