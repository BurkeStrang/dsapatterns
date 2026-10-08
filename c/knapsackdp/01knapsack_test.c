#include "01knapsack.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *profits;
        int profits_len;
        const int *weights;
        int weights_len;
        int capacity;
        int want;
    } tests[] = {
        {"Example", INTS(4, 5, 3, 7), INTS(2, 3, 1, 4), 5, 10},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = solve_knapsack(tt->profits, tt->profits_len, tt->weights,
                                 tt->weights_len, tt->capacity);
        t_check_int("solve_knapsack()", got, tt->want);
    }
    return t_done();
}
