#include "maxcapital.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *capital;
        int capital_len;
        const int *profits;
        int profits_len;
        int number_of_projects;
        int initial_capital;
        int expected;
    } tests[] = {
        {"basic example", INTS(0, 1, 2), INTS(1, 2, 3), 2, 1, 6},
        {"not enough capital for any project", INTS(5, 10, 15), INTS(1, 2, 3),
         3, 0, 0},
        {"all projects affordable from start", INTS(0, 0, 0), INTS(1, 2, 3), 2,
         0, 5},
        {"single project", INTS(0), INTS(5), 1, 0, 5},
        {"chain of unlocking projects", INTS(0, 1, 2, 3), INTS(1, 1, 1, 1), 4,
         0, 4},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int result =
            find_maximum_capital(tt->capital, tt->profits, tt->profits_len,
                                 tt->number_of_projects, tt->initial_capital);
        t_check_int("find_maximum_capital()", result, tt->expected);
    }
    return t_done();
}
