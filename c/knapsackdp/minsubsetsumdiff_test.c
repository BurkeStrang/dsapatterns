#include "minsubsetsumdiff.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *num;
        int num_len;
        int want;
    } tests[] = {
        {"Example 1", INTS(1, 2, 3, 9), 3},
        {"Example 2", INTS(1, 2, 7, 1, 5), 0},
        {"Example 3", INTS(1, 3, 100, 4), 92},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = can_partition_min(tt->num, tt->num_len);
        t_check_int("can_partition_min()", got, tt->want);
    }
    return t_done();
}
