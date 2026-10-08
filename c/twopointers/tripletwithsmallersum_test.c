#include "tripletwithsmallersum.c"

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
        {"case 2", INTS(-1, 4, 2, 1, 3), 5, 4},
        {"case 3", NO_INTS, 5, 0},
        {"case 4", INTS(1, 2), 3, 0},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int result = find_triplets(tt->arr, tt->arr_len, tt->target);
        t_check_int("find_triplets()", result, tt->expected);
    }
    return t_done();
}
