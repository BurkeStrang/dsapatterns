#include "orderagnosticbs.c"

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
        {"ascending - key found in middle", INTS(1, 3, 5, 7, 9), 5, 2},
        {"ascending - key found at start", INTS(1, 3, 5, 7, 9), 1, 0},
        {"ascending - key found at end", INTS(1, 3, 5, 7, 9), 9, 4},
        {"ascending - key not found", INTS(1, 3, 5, 7, 9), 4, -1},
        {"descending - key found in middle", INTS(9, 7, 5, 3, 1), 5, 2},
        {"descending - key found at start", INTS(9, 7, 5, 3, 1), 9, 0},
        {"descending - key found at end", INTS(9, 7, 5, 3, 1), 1, 4},
        {"descending - key not found", INTS(9, 7, 5, 3, 1), 4, -1},
        {"single element - found", INTS(42), 42, 0},
        {"single element - not found", INTS(42), 7, -1},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = desc_or_asc_search(tt->arr, tt->arr_len, tt->key);
        t_check_int("desc_or_asc_search()", got, tt->want);
    }
    return t_done();
}
