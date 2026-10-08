#include "nextgreaterelement.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *arr;
        int arr_len;
        const int *want;
        int want_len;
    } tests[] = {
        {"Example 1", INTS(4, 5, 2, 25), INTS(5, 25, 25, -1)},
        {"Example 2", INTS(13, 7, 6, 12), INTS(-1, 12, 12, -1)},
        {"Example 3", INTS(1, 2, 3, 4, 5), INTS(2, 3, 4, 5, -1)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int *got = next_larger_element(tt->arr, tt->arr_len);
        t_check_ints("next_larger_element()", got, tt->arr_len, tt->want,
                     tt->want_len);
        free(got);
    }
    return t_done();
}
