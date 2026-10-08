#include "rotatedarraydups.c"

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
        {"Example 1", INTS(3, 7, 3, 3, 3), 7, 1},
        {"Example 2", INTS(3, 3, 3, 7, 3), 7, 3},
        {"Example 3", INTS(3, 3, 7, 3, 3), 7, 2},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = search_rotated_dups(tt->arr, tt->arr_len, tt->key);
        t_check_int("search_rotated_dups()", got, tt->want);
    }
    return t_done();
}
