#include "housetheif.c"

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
        {"Example 1", INTS(2, 5, 1, 3, 6, 2, 4), 15},
        {"Example 2", INTS(2, 10, 14, 8, 1), 18},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_max_steal(tt->arr, tt->arr_len);
        t_check_int("find_max_steal()", got, tt->want);
    }
    return t_done();
}
