#include "minjumpswithfee.c"

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
        {"Example 1", INTS(1, 2, 5, 2, 1, 2), 3},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_min_fee(tt->arr, tt->arr_len);
        t_check_int("find_min_fee()", got, tt->want);
    }
    return t_done();
}
