#include "cycleincircle.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *arr;
        int arr_len;
        bool expected;
    } tests[] = {
        {"Example 1", INTS(1, 2, -1, 2, 2), true},
        {"Example 2", INTS(2, 2, -1, 2), true},
        {"Example 3", INTS(2, 1, -1, -2), false},
        {"No cycle, alternating directions", INTS(1, -1, 1, -1), false},
        {"Simple cycle", INTS(3, 1, 2), true},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        bool result = loop_exists(tt->arr, tt->arr_len);
        t_check_bool("loop_exists()", result, tt->expected);
    }
    return t_done();
}
