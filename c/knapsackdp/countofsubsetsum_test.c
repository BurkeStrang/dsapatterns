#include "countofsubsetsum.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *num;
        int num_len;
        int sum;
        int want;
    } tests[] = {
        {"Example 1", INTS(1, 1, 2, 3), 4, 3},
        {"Example 2", INTS(1, 2, 7, 1, 5), 9, 3},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = count_subsets(tt->num, tt->num_len, tt->sum);
        t_check_int("count_subsets()", got, tt->want);
    }
    return t_done();
}
