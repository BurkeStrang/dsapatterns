#include "ceiling.c"

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
        {"Exmple 1", INTS(4, 6, 10), 5, 1},
        {"key exists in array", INTS(1, 3, 8, 10, 15), 8, 2},
        {"key between two elements", INTS(1, 3, 8, 10, 15), 12, 4},
        {"key smaller than all elements", INTS(1, 3, 8, 10, 15), 0, 0},
        {"key larger than all elements", INTS(1, 3, 8, 10, 15), 20, -1},
        {"key is smallest element", INTS(1, 3, 8, 10, 15), 1, 0},
        {"key is largest element", INTS(1, 3, 8, 10, 15), 15, 4},
        {"key just below a middle element", INTS(2, 4, 6, 8, 10), 5, 2},
        {"single element - key matches", INTS(5), 5, 0},
        {"single element - key is smaller", INTS(5), 3, 0},
        {"single element - key is larger", INTS(5), 7, -1},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = search_ceiling_of_a_number(tt->arr, tt->arr_len, tt->key);
        t_check_int("search_ceiling_of_a_number()", got, tt->want);
    }
    return t_done();
}
