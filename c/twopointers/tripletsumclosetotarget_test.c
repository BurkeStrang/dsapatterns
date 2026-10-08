#include "tripletsumclosetotarget.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int *arr;
        int arr_len;
        int target;
        int expected;
    } tests[] = {
        {"case 1", INTS(-1, 0, 2, 3), 3, 2},
        {"case 2", INTS(-3, -1, 1, 2), 1, 0},
        {"case 3", INTS(1, 0, 1, 1), 100, 3},
        {"case 4", INTS(0, 0, 1, 1, 2, 6), 5, 4},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = search_triplet(tt->arr, tt->arr_len, tt->target);
        t_check_int("search_triplet()", got, tt->expected);
    }
    return t_done();
}
