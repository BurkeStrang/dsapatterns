#include "numberrange.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *arr;
        int arr_len;
        int key;
        const int *want;
        int want_len;
    } tests[] = {
        {"example1", INTS(4, 6, 6, 6, 9), 6, INTS(1, 3)},
        {"example2", INTS(1, 3, 8, 10, 15), 10, INTS(3, 3)},
        {"example3", INTS(1, 3, 8, 10, 15), 12, INTS(-1, -1)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int *got = find_range(tt->arr, tt->arr_len, tt->key);
        t_check_ints("find_range()", got, 2, tt->want, tt->want_len);
        free(got);
    }
    return t_done();
}
