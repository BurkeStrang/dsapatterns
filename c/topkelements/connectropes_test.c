#include "connectropes.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *rope_lengths;
        int ropes;
        int want;
    } tests[] = {
        {"Example 1", INTS(1, 2, 3, 4, 5), 33},
        {"Example 2", INTS(3, 4, 5, 6), 36},
        {"Example 3", INTS(1, 3, 11, 5, 2), 42},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = minimum_cost_to_connect_ropes(tt->rope_lengths, tt->ropes);
        t_check_int("minimum_cost_to_connect_ropes()", got, tt->want);
    }
    return t_done();
}
