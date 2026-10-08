#include "fruitsintobaskets.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *arr;
        int arr_len;
        int want;
    } tests[] = {
        {"basic example", CHARS('A', 'B', 'C', 'A', 'C'), 3},
        {"all same fruit", CHARS('A', 'A', 'A', 'A'), 4},
        {"two types alternating", CHARS('A', 'B', 'A', 'B', 'A', 'B'), 6},
        {"three types", CHARS('A', 'B', 'C', 'B', 'B', 'C', 'A'), 5},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = max_fruit(tt->arr, tt->arr_len);
        t_check_int("max_fruit()", got, tt->want);
    }
    return t_done();
}
