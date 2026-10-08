#include "countbst.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int n;
        int want;
    } tests[] = {
        {"Example 1", 2, 2},
        {"Example 2", 3, 5},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = count_trees(tt->n);
        t_check_int("count_trees()", got, tt->want);
    }
    return t_done();
}
