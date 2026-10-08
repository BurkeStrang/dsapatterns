#include "minaddtomakeparen.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *s;
        int want;
    } tests[] = {
        {"Example 1", "(()", 1},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = min_add_to_make_valid(tt->s);
        t_check_int("min_add_to_make_valid()", got, tt->want);
    }
    return t_done();
}
