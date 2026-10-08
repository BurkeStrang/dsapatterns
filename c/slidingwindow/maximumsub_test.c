#include "maximumsub.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int k;
        const int *arr;
        int arr_len;
        int want;
    } tests[] = {
        {"basic case", 3, INTS(2, 1, 5, 1, 3, 2), 9},
        {"single element window", 1, INTS(4, 2, 7, 1), 7},
        {"window equals array length", 4, INTS(1, 2, 3, 4), 10},
        {"empty array", 3, NO_INTS, 0},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_max_sum_sub_array(tt->k, tt->arr, tt->arr_len);
        t_check_int("find_max_sum_sub_array()", got, tt->want);
    }
    return t_done();
}
