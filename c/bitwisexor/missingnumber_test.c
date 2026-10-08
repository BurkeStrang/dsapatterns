#include "missingnumber.c"

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
        {"Example 1", INTS(1, 2, 3, 5), 4},
        {"Example 2", INTS(1, 2, 4, 5), 3},
        {"Example 3",
         INTS(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
              20),
         21},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_missing_number(tt->arr, tt->arr_len);
        t_check_int("find_missing_number()", got, tt->want);
    }
    return t_done();
}
