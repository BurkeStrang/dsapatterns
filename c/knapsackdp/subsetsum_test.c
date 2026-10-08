#include "subsetsum.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *num;
        int num_len;
        int sum;
        bool want;
    } tests[] = {
        {"Example 1", INTS(1, 2, 3, 7), 6, true},
        {"Example 2", INTS(1, 2, 7, 1, 5), 10, true},
        {"Example 3", INTS(1, 3, 4, 8), 6, false},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        bool got = can_partition_sum(tt->num, tt->num_len, tt->sum);
        t_check_bool("can_partition_sum()", got, tt->want);
    }
    return t_done();
}
