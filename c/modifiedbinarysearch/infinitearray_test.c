#include "infinitearray.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *arr;
        int arr_len;
        int key;
        int want;
    } tests[] = {
        {"Example 1", INTS(4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30),
         16, 6},
        {"Example 2", INTS(4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30),
         11, -1},
        {"Example 3", INTS(1, 3, 8, 10, 15), 15, 4},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        ArrayReader reader = {tt->arr, tt->arr_len};
        int got = search_infinite_sorted_array(&reader, tt->key);
        t_check_int("search_infinite_sorted_array()", got, tt->want);
    }
    return t_done();
}
