#include "pairwithtargetsum.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *arr;
        int arr_len;
        int target;
        const int *expected;
        int expected_len;
    } tests[] = {
        {"case 1", INTS(1, 2, 3, 4, 6), 6, INTS(1, 3)},
        {"case 2", INTS(2, 5, 9, 11), 11, INTS(0, 2)},
        {"case 3", INTS(1, 2, 3, 4, 5), 10, INTS(-1, -1)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int *result = search(tt->arr, tt->arr_len, tt->target);
        t_check_ints("search()", result, 2, tt->expected, tt->expected_len);
        free(result);
    }
    return t_done();
}
