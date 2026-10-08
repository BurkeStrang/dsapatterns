#include "maxnumballoons.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *s;
        int want;
    } tests[] = {
        {"Example 1", "balloonballoon", 2},
        {"Example 2", "bbaall", 0},
        {"Example 3", "balloonballoooon", 2},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = max_number_of_balloons(tt->s);
        t_check_int("max_number_of_balloons()", got, tt->want);
    }
    return t_done();
}
