#include "palindromicpartition.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *st;
        int want;
    } tests[] = {
        {"Example 1", "abdbca", 3},
        {"Example 2", "cddpd", 2},
        {"Example 3", "pqr", 2},
        {"Example 4", "pp", 0},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_mpp_cuts(tt->st);
        t_check_int("find_mpp_cuts()", got, tt->want);
    }
    return t_done();
}
