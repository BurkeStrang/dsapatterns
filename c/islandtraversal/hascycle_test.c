#include "hascycle.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *const *matrix; // one string per row
        int rows;
        bool want;
    } tests[] = {
        {"no cycle", STRS("ABC", "DEF", "GHI"), false},
        {"simple cycle", STRS("AAA", "ABA", "AAA"), true},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        bool got = has_cycle(tt->matrix, tt->rows);
        t_check_bool("has_cycle()", got, tt->want);
    }
    return t_done();
}
